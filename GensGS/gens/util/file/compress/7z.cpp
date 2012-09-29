/***************************************************************************
 * Gens: 7z File Compression Class.                                        *
 *                                                                         *
 * Copyright (c) 1999-2002 by Stéphane Dallongeville                       *
 * Copyright (c) 2003-2004 by Stéphane Akhoun                              *
 * Copyright (c) 2008 by David Korth                                       *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify it *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2 of the License, or (at your  *
 * option) any later version.                                              *
 *                                                                         *
 * This program is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc., *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.           *
 ***************************************************************************/

#include "7z.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "emulator/g_main.hpp"
#include "ui/gens_ui.hpp"

// Error number variable.
#include <cerrno>

// popen wrapper
#include "popen_wrapper.h"

#include <sstream>
using std::string;
using std::stringstream;
using std::list;

// Newline constant: "\r\n" on Win32, "\n" on everything else.
#ifdef GENS_OS_WIN32
#define _7Z_NEWLINE "\r\n"
#define _7Z_NEWLINE_LENGTH 2
#else
#define _7Z_NEWLINE "\n"
#define _7Z_NEWLINE_LENGTH 1
#endif


_7z::_7z(const bool showErrMsg)
{
	m_showErrMsg = showErrMsg;
}

_7z::~_7z()
{
}


void _7z::errOpening7z(int errorNumber)
{
	fprintf(stderr, "Error opening p_7z: %s.\n", strerror(errorNumber));
	
	if (m_showErrMsg)
	{
		string sErr = "Could not open 7-Zip. Please make sure 7-Zip is installed\n"
			      "and is configured properly in the \"BIOS/Misc Files\" window.\n\n"
			      "Error description: " + string(strerror(errorNumber)) + ".";
		
		GensUI::msgBox(sErr, "7-Zip Error", GensUI::MSGBOX_ICON_WARNING);
	}
}


/**
 * detectFormat(): Detect if a file is in 7z format.
 * @param f File pointer of the file to check.
 * @return True if this file is in 7z format.
 */
bool _7z::detectFormat(FILE *f)
{
	// Magic Number for 7z:
	// First six bytes: "7z\xBC\xAF\x27\x1C"
	static const unsigned char magic7z[6] = {'7', 'z', 0xBC, 0xAF, 0x27, 0x1C};
	
	unsigned char buf[6];
	fseek(f, 0, SEEK_SET);
	fread(buf, 6, sizeof(unsigned char), f);
	
	return (memcmp(buf, magic7z, sizeof(magic7z)) == 0);
}


bool _7z::checkExternalExec(void)
{
	// Check that the external 7z executable is working.
	FILE *p_7z;
	char buf[512];
	
	// Build the command line.
	stringstream ssCmd;
	ssCmd << "\"" << Misc_Filenames._7z_Binary << "\"";
#ifndef GENS_OS_WIN32
	ssCmd << " 2>&1";
#endif
	
	p_7z = gens_popen(ssCmd.str().c_str(), "r");
	if (!p_7z)
	{
		// External 7z executable is broken.
		errOpening7z(errno);
		return false;
	}
	
	// Read the first 512 bytes from the pipe.
	fread(buf, 1, sizeof(buf), p_7z);
	gens_pclose(p_7z);
	
	// Check if the header matches 7-Zip's header.
	const char* str7zHeader = _7Z_NEWLINE "7-Zip";
	if (strncmp(buf, str7zHeader, strlen(str7zHeader)) != 0)
	{
		// Incorrect header. External 7z executable is broken.
		// Assume that this means the file wasn't found.
		// TODO: More comprehensive error handling.
		errOpening7z(ENOENT);
		return false;
	}
	
	// Correct header. External 7z executable is working.
	return true;
}


/**
 * getNumFiles(): Gets the number of files in the specified archive.
 * @param filename Filename of the archive.
 * @return Number of files, or 0 on error. (-1 if 7-Zip couldn't be opened.)
 */
int _7z::getNumFiles(const string& zFilename)
{
	FILE *p_7z;
	char buf[1025];
	int rv;
	stringstream ss;
	string data;
	int numFiles = 0;
	
	// Build the command line.
	stringstream ssCmd;
	ssCmd << "\"" << Misc_Filenames._7z_Binary << "\" l \"" << zFilename << "\"";
	
	// Open the 7z file.
	p_7z = gens_popen(ssCmd.str().c_str(), "r");
	if (!p_7z)
	{
		errOpening7z(errno);
		return -1;
	}
	
	// Read from the pipe.
	while ((rv = fread(buf, 1, 1024, p_7z)))
	{
		buf[rv] = 0x00;
		ss << buf;
	}
	gens_pclose(p_7z);
	
	// Get the string and go through it to get the number of files.
	data = ss.str();
	ss.clear();
	
	// Find the ---, which indicates the start of the file listing.
	unsigned int listStart = data.find("---");
	if (listStart == string::npos)
	{
		// Not found. Either there are no files, or the archive is broken.
		return 0;
	}
	
	// Find the newline after the list start.
	unsigned int listStartLF = data.find(_7Z_NEWLINE, listStart);
	if (listStart == string::npos)
	{
		// Not found. Either there are no files, or the archive is broken.
		return 0;
	}
	
	// Parse all lines until we hit another "---" (or EOF).
	unsigned int curStartPos = listStartLF + _7Z_NEWLINE_LENGTH;
	unsigned int curEndPos;
	string curLine;
	bool endOf7z = false;
	while (!endOf7z)
	{
		curEndPos = data.find(_7Z_NEWLINE, curStartPos);
		if (curEndPos == string::npos)
		{
			// End of list.
			break;
		}
		
		// Get the current line.
		curLine = data.substr(curStartPos, curEndPos - curStartPos);
		
		// Check the contents of the line.
		if (curLine.substr(20, 1) == "D")
		{
			// Directory. Don't add this entry.
		}
		else if (curLine.substr(0, 3) == "---")
		{
			// End of file listing.
			endOf7z = true;
		}
		else
		{
			// File. Add this entry.
			numFiles++;
		}
		
		// Go to the next file in the listing.
		curStartPos = curEndPos + _7Z_NEWLINE_LENGTH;
	}
	
	// Return the number of files found.
	return numFiles;
}


/**
 * getFileInfo(): Get information about all files in the specified archive.
 * @param zFilename Filename of the archive.
 * @return Pointer to list of CompressedFile structs, or NULL on error.
 */
list<CompressedFile>* _7z::getFileInfo(const string& zFilename)
{
	list<CompressedFile> *lst;
	CompressedFile file;
	
	FILE *p_7z;
	char buf[1025];
	int rv;
	stringstream ss;
	string data;
	int numFiles = 0;
	
	// Build the command line.
	stringstream ssCmd;
	ssCmd << "\"" << Misc_Filenames._7z_Binary << "\" l \"" << zFilename << "\"";
	
	// Open the 7z file.
	p_7z = gens_popen(ssCmd.str().c_str(), "r");
	if (!p_7z)
	{
		errOpening7z(errno);
		return 0;
	}
	
	// Read from the pipe.
	while ((rv = fread(buf, 1, 1024, p_7z)))
	{
		buf[rv] = 0x00;
		ss << buf;
	}
	gens_pclose(p_7z);
	
	// Get the string and go through it to get the number of files.
	data = ss.str();
	ss.clear();
	
	// Find the ---, which indicates the start of the file listing.
	unsigned int listStart = data.find("---");
	if (listStart == string::npos)
	{
		// Not found. Either there are no files, or the archive is broken.
		return NULL;
	}
	
	// Find the newline after the list start.
	unsigned int listStartLF = data.find(_7Z_NEWLINE, listStart);
	if (listStart == string::npos)
	{
		// Not found. Either there are no files, or the archive is broken.
		return NULL;
	}
	
	// Create the list.
	lst = new list<CompressedFile>;
	
	// Parse all lines until we hit another "---" (or EOF).
	unsigned int curStartPos = listStartLF + _7Z_NEWLINE_LENGTH;
	unsigned int curEndPos;
	string curLine;
	bool endOf7z = false;
	while (!endOf7z)
	{
		curEndPos = data.find(_7Z_NEWLINE, curStartPos);
		if (curEndPos == string::npos)
		{
			// End of list.
			break;
		}
		
		// Get the current line.
		curLine = data.substr(curStartPos, curEndPos - curStartPos);
		
		// Check the contents of the line.
		if (curLine.substr(20, 1) == "D")
		{
			// Directory. Don't add this entry.
		}
		else if (curLine.substr(0, 3) == "---")
		{
			// End of file listing.
			endOf7z = true;
		}
		else
		{
			// File. Add this entry.
			file.filename = curLine.substr(53);
			file.filesize = atoi(curLine.substr(26, 12).c_str());
			lst->push_back(file);
			numFiles++;
		}
		
		// Go to the next file in the listing.
		curStartPos = curEndPos + _7Z_NEWLINE_LENGTH;
	}
	
	// Return the list of files.
	return lst;
}


/**
 * getFile(): Gets the specified file from the specified archive.
 * @param zFilename Filename of the archive.
 * @param fileInfo Information about the file to extr
 * @param buf Buffer to write the file to.
 * @param size Size of the buffer, in bytes.
 * @return Number of bytes read, or -1 on error.
 */
int _7z::getFile(const string& zFilename, const CompressedFile *fileInfo,
		 unsigned char *buf, const int size)
{
	FILE *p_7z;
	char buf7z[1024];
	int rv;
	stringstream ss;
	string data;
	int totalSize = 0;
	
	// Build the command line.
	stringstream ssCmd;
	ssCmd << "\"" << Misc_Filenames._7z_Binary << "\" e \"" << zFilename
	      << "\" \"" << fileInfo->filename << "\" -so";
#ifndef GENS_OS_WIN32
	ssCmd << " 2>/dev/null";
#endif
	
	p_7z = gens_popen(ssCmd.str().c_str(), "r");
	if (!p_7z)
	{
		errOpening7z(errno);
		return -1;
	}
	
	// Read from the pipe.
	while ((rv = fread(buf7z, 1, 1024, p_7z)))
	{
		if (totalSize + rv > size)
			break;
		memcpy(&buf[totalSize], &buf7z, rv);
		totalSize += rv;
	}
	gens_pclose(p_7z);
	
	// Return the filesize.
	return totalSize;
}