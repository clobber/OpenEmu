/*
 Copyright (c) 2012, OpenEmu Team
 
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

#import "OE5200SystemController.h"
#import "OE5200SystemResponder.h"
#import "OE5200SystemResponderClient.h"

@implementation OE5200SystemController

- (NSUInteger)numberOfPlayers;
{
    return 2;
}

- (Class)responderClass;
{
    return [OE5200SystemResponder class];
}

- (NSDictionary *)defaultControls
{
    NSDictionary *controls = [NSDictionary dictionaryWithObjectsAndKeys:
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardUpArrow]   , @"OE5200ButtonUp[1]"    ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardDownArrow] , @"OE5200ButtonDown[1]"  ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardLeftArrow] , @"OE5200ButtonLeft[1]"  ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardRightArrow], @"OE5200ButtonRight[1]" ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardX]         , @"OE5200ButtonFire1[1]"     ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardC]         , @"OE5200ButtonFire2[1]"     ,
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardSpacebar]    , @"OE5200ButtonStart[1]",
							  [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardDeleteOrBackspace]    , @"OE5200ButtonPause[1]",
                              [NSNumber numberWithUnsignedInt:kHIDUsage_KeyboardR]    , @"OE5200ButtonReset[1]",
                              nil];
    return controls;
}

@end
