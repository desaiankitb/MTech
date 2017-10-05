//
//  ViewController.h
//  VideoPlayback
//
//  Created by Sandeep Padhiyar on 29/04/12.
//  Copyright (c) 2012 snpadhiyar@hotmail.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@interface ViewController : UIViewController
{
    MPMoviePlayerViewController *mp;
}
-(IBAction)playButtonPressed;
@end
