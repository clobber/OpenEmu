/***************************************************************************
 * Gens: (GTK+) Select CD-ROM Drive Window - Callback Functions.           *
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

#include "select_cdrom_window.h"
#include "select_cdrom_window_callbacks.h"
#include "select_cdrom_window_misc.hpp"

#include "emulator/gens.hpp"


/**
 * Window is closed.
 */
gboolean on_select_cdrom_window_close(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
	GENS_UNUSED_PARAMETER(widget);
	GENS_UNUSED_PARAMETER(event);
	GENS_UNUSED_PARAMETER(user_data);
	
	gtk_widget_destroy(select_cdrom_window);
	select_cdrom_window = NULL;
	return FALSE;
}


/**
 * Cancel
 */
void on_button_SelCD_Cancel_clicked(GtkButton *button, gpointer user_data)
{
	GENS_UNUSED_PARAMETER(button);
	GENS_UNUSED_PARAMETER(user_data);
	
	gtk_widget_destroy(select_cdrom_window);
	select_cdrom_window = NULL;
}


/**
 * Apply
 */
void on_button_SelCD_Apply_clicked(GtkButton *button, gpointer user_data)
{
	GENS_UNUSED_PARAMETER(button);
	GENS_UNUSED_PARAMETER(user_data);
	
	SelCD_Save();
}


/**
 * Save
 */
void on_button_SelCD_Save_clicked(GtkButton *button, gpointer user_data)
{
	GENS_UNUSED_PARAMETER(button);
	GENS_UNUSED_PARAMETER(user_data);
	
	if (!SelCD_Save())
		return;
	
	gtk_widget_destroy(select_cdrom_window);
	select_cdrom_window = NULL;
}
