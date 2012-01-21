/*
 Copyright (c) 2009, OpenEmu Team
 

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "SNESGameEmu.h"
#import <OERingBuffer.h>
#import "OESNESSystemResponderClient.h"
#import <OpenGL/gl.h>

#include "libsnes.hpp"

#define SAMPLERATE 32040
#define SAMPLEFRAME 800
#define SIZESOUNDBUFFER SAMPLEFRAME*4

@interface BSNESGameEmu () <OESNESSystemResponderClient>
@end

NSUInteger BSNESEmulatorValues[] = { SNES_DEVICE_ID_JOYPAD_R, SNES_DEVICE_ID_JOYPAD_L, SNES_DEVICE_ID_JOYPAD_X, SNES_DEVICE_ID_JOYPAD_A, SNES_DEVICE_ID_JOYPAD_RIGHT, SNES_DEVICE_ID_JOYPAD_LEFT, SNES_DEVICE_ID_JOYPAD_DOWN, SNES_DEVICE_ID_JOYPAD_UP, SNES_DEVICE_ID_JOYPAD_START, SNES_DEVICE_ID_JOYPAD_SELECT, SNES_DEVICE_ID_JOYPAD_Y, SNES_DEVICE_ID_JOYPAD_B };
NSString *BSNESEmulatorNames[] = { @"Joypad@ R", @"Joypad@ L", @"Joypad@ X", @"Joypad@ A", @"Joypad@ Right", @"Joypad@ Left", @"Joypad@ Down", @"Joypad@ Up", @"Joypad@ Start", @"Joypad@ Select", @"Joypad@ Y", @"Joypad@ B" };

BSNESGameEmu *current;
@implementation BSNESGameEmu

//BSNES callbacks
static void audio_callback(uint16_t left, uint16_t right)
{
	NSLog(@"audio callback");
    //[ringBuffer write:&left maxLength:2];
	[[current ringBufferAtIndex:0] write:&left maxLength:2];
    [[current ringBufferAtIndex:0] write:&right maxLength:2];
}

static void video_callback(const uint16_t *data, unsigned width, unsigned height)
{
	NSLog(@"video callback");
	memcpy(current->videoBuffer, data, width * height * 2);
}

static void input_poll_callback(void)
{
	NSLog(@"poll callback");
}

static int16_t input_state_callback(bool port, unsigned device, unsigned index, unsigned id)
{
	NSLog(@"state callback");
	return 0;
}

- (void)didPushSNESButton:(OESNESButton)button forPlayer:(NSUInteger)player;
{
    pad[player-1][BSNESEmulatorValues[button]] = 0xFFFF;
}

- (void)didReleaseSNESButton:(OESNESButton)button forPlayer:(NSUInteger)player;
{
    pad[player-1][BSNESEmulatorValues[button]] = 0;
}

- (id)init
{
	self = [super init];
    if(self != nil)
    {
		soundBuffer = (UInt16*)malloc(SIZESOUNDBUFFER* sizeof(UInt16));
		memset(soundBuffer, 0, SIZESOUNDBUFFER*sizeof(UInt16));
		videoBuffer = (unsigned char*) malloc(512 * 478 * 2);
	}
	
	current = self;
    
	return self;
}

#pragma mark Exectuion

- (void)executeFrame
{
    [self executeFrameSkippingFrame:NO];
}

- (void)executeFrameSkippingFrame: (BOOL) skip
{
    NSLog(@"snes run called");
    snes_run();
    //SNES::system.run();
    //[self reportControlPad:0 withFlags:controlPad[0]];
    
    //    IPPU.RenderThisFrame = !skip;
    //    S9xMainLoop();
    //
    //S9xMixSamples((unsigned char*)soundBuffer, SAMPLEFRAME * [self channelCount]);
    //[[self ringBufferAtIndex:0] write:soundBuffer maxLength:sizeof(UInt16) * [self channelCount] * SAMPLEFRAME];
}
/*
bool loadCartridge(const char *filename, SNES::MappedRAM &memory) {
    if(file::exists(filename) == false) return false;
    //Reader::Type filetype = Reader::detect(filename, true);
    
    uint8_t *data;
    unsigned size;
    
    NSData* dataObj = [NSData dataWithContentsOfFile:[[NSString stringWithUTF8String:filename] stringByStandardizingPath]];
    if(dataObj == nil) return false;
    size = [dataObj length];
    data = (uint8_t*)[dataObj bytes];
    
    //remove copier header, if it exists
    if((size & 0x7fff) == 512) memmove(data, data + 512, size -= 512);
    
    memory.copy(data, size);
    return true;
}

- (BOOL)loadFileAtPath: (NSString*) path
{
    //system = new SNES::System();
    
    //[self mapButtons];
    
    interface = new BSNESInterface();
    
    memset(&interface->pad, 0, sizeof(int16_t) * 24);
    interface->video = (uint16_t*)malloc(512*478*sizeof(uint16_t));
    interface->ringBuffer = [self ringBufferAtIndex:0];
    SNES::system.init(interface);
    
    
    
    SNES::MappedRAM memory;
    if(loadCartridge([path UTF8String], memory) == false) return NO;
    SNES::Cartridge::Type type = SNES::cartridge.detect_image_type(memory.data(), memory.size());
    memory.reset();
    
    if(loadCartridge([path UTF8String], SNES::memory::cartrom))
    {
        SNES::cartridge.load(SNES::Cartridge::ModeNormal);
        SNES::system.power();
        SNES::input.port_set_device(0, SNES::Input::DeviceJoypad);
        SNES::input.port_set_device(1, SNES::Input::DeviceJoypad);
    }
    return YES;
}
*/
- (BOOL)loadFileAtPath: (NSString*) path
{
	//NSData* theData;
	//theData = [NSData dataWithContentsOfFile:path];
	//memset(pad, 0, sizeof(int16_t) * 24);
    //video = (uint16_t*)malloc(512*478*sizeof(uint16_t));
    
    uint8_t *data;
    unsigned size;
    const char *filename;
    filename = [path UTF8String];
    
    NSData* dataObj = [NSData dataWithContentsOfFile:[[NSString stringWithUTF8String:filename] stringByStandardizingPath]];
    if(dataObj == nil) return false;
    size = [dataObj length];
    data = (uint8_t*)[dataObj bytes];

    /*
    FILE* file = fopen([path UTF8String], "rb");
    long file_size;
    
    fseek (file , 0 , SEEK_END);
    file_size = ftell (file);
    rewind (file);
    
    uint8_t* file_buffer = (uint8_t *) malloc (sizeof(uint8_t)*file_size);
    long read_bytes =fread(file_buffer, sizeof(uint8_t), file_size, file);
    if( read_bytes != file_size )
    {
        NSLog(@"Couldn't read file");
        return NO;
    }*/
    
    //soundBuffer = (UInt16*)malloc(SIZESOUNDBUFFER* sizeof(UInt16));
    //memset(soundBuffer, 0, SIZESOUNDBUFFER*sizeof(UInt16));
    //videoBuffer = (unsigned char*) malloc(512 * 478 * 2);
    
	snes_init();
	
    snes_set_audio_sample(audio_callback);
    snes_set_video_refresh(video_callback);
	snes_set_input_poll(input_poll_callback);
	snes_set_input_state(input_state_callback);
	
	snes_set_controller_port_device(SNES_PORT_1, SNES_DEVICE_JOYPAD);
	snes_set_controller_port_device(SNES_PORT_2, SNES_DEVICE_JOYPAD);
	
	//if (snes_load_cartridge_normal(NULL, [theData bytes], [theData length]))
	if (snes_load_cartridge_normal(NULL, data, size))
    {
        
	}
    //snes_get_memory_*
    snes_get_region();

    return YES;
}

#pragma mark Video
- (const void *)videoBuffer
{
    //return interface->video;
    //return video;
    return videoBuffer;
}

/*
 return 512 / 2;

 return (SNES::system.region() == SNES::System::NTSC ? 448 : 478) / 2;
*/ 

- (OEIntRect)screenRect
{
    // hope this handles hires :/
    //return OERectMake(0, 0, interface->width, interface->height);
    return OERectMake(0, 0, 256, 224);
}

- (OEIntSize)bufferSize
{
    return OESizeMake(512, 478);
}

- (void)setupEmulation
{
    //soundBuffer = (UInt16*)malloc(SIZESOUNDBUFFER* sizeof(UInt16));
    //memset(soundBuffer, 0, SIZESOUNDBUFFER*sizeof(UInt16));
}

- (void)resetEmulation
{
    snes_reset();
}

- (void)stopEmulation
{
    /*
     NSString *path = [NSString stringWithUTF8String:Memory.ROMFilename];
     NSString *extensionlessFilename = [[path lastPathComponent] stringByDeletingPathExtension];
     
     NSString *batterySavesDirectory = [self batterySavesDirectoryPath];
     
     [[NSFileManager defaultManager] createDirectoryAtPath:batterySavesDirectory withIntermediateDirectories:YES attributes:nil error:NULL];
     
     NSLog(@"Trying to save SRAM");
     
     NSString *filePath = [batterySavesDirectory stringByAppendingPathComponent:[extensionlessFilename stringByAppendingPathExtension:@"sav"]];
     
     Memory.SaveSRAM([filePath UTF8String]);
     */
    NSLog(@"snes term");
    snes_term();
    [super stopEmulation];
}

- (GLenum)pixelFormat
{
    return GL_RGB;
}

- (GLenum)pixelType
{
    return GL_UNSIGNED_SHORT_5_6_5;
}

- (GLenum)internalPixelFormat
{
    return GL_RGB5;
}

- (NSUInteger)soundBufferSize
{
    return SIZESOUNDBUFFER;
}

- (NSUInteger)frameSampleCount
{
    return SAMPLEFRAME;
}

- (NSUInteger)frameSampleRate
{
    return SAMPLERATE;
}

- (NSTimeInterval)frameInterval
{
    //return 60;
    return (snes_get_region() == SNES_REGION_PAL) ? 50 : 60;
}

- (NSUInteger)channelCount
{
    return 2;
}

- (BOOL)saveStateToFileAtPath:(NSString *)fileName
{
//    SNES::system.runtosave();
//    serializer state = SNES::system.serialize();
//    FILE *state_file = fopen([fileName UTF8String], "w+b");
//    long bytes_written = fwrite(state.data(), sizeof(uint8_t), state.size(), state_file);
//    if( bytes_written != state.size() )
//    {
//        NSLog(@"Couldn't write state");
//        return NO;
//    }
//    fclose( state_file );
    return YES;
}

- (BOOL)loadStateFromFileAtPath:(NSString *)fileName
{
//    FILE* state_file = fopen([fileName UTF8String], "rb");
//    if( !state_file )
//    {
//        NSLog(@"Could not open state file");
//        return NO;
//    }
//    long file_size;
//    
//    fseek (state_file , 0 , SEEK_END);
//    file_size = ftell (state_file);
//    rewind (state_file);
//    
//    uint8_t* state_buffer = (uint8_t *) malloc (sizeof(uint8_t)*file_size);
//    long read_bytes =fread(state_buffer, sizeof(uint8_t), file_size, state_file);
//    if( read_bytes != file_size )
//    {
//        NSLog(@"Couldn't read file");
//        return NO;
//    }
//    
//    serializer state(state_buffer,sizeof(uint8_t)*file_size);
//    bool loaded = SNES::system.unserialize(state);
//    if(!loaded)
//    {
//        NSLog(@"Couldn't unpack state");
//        return NO;
//    }
//    fclose(state_file);
//    free(state_buffer);
    return YES;
}

@end
