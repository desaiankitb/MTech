//
//  PlayerView.h
//  MyAudioPlayer
//
//  Created by mac on 5/3/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
@interface PlayerView : UIViewController
{


    IBOutlet UIProgressView *progress;

    IBOutlet UISwitch *onoff;
    AVAudioPlayer *player;

    IBOutlet UIStepper *steper;
}


- (IBAction)onoff:(id)sender;
 
- (IBAction)steper:(id)sender;

@end
