//
//  PlayerView.m
//  MyAudioPlayer
//
//  Created by mac on 5/3/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import "PlayerView.h"

@implementation PlayerView

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    onoff = nil;
    steper = nil;
    progress = nil;
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (IBAction)onoff:(id)sender {
    NSURL *url = [NSURL fileURLWithPath:[[NSBundle mainBundle] pathForResource:@"1" ofType:@"mp3"]];
     player = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:nil];
    if([sender isOn])
    {
    
        [player play];
        NSLog(@"Duration = %lf, Current Time = %lf",[player duration],[player currentTime]);
    
//player.volume = 1.0;   
    
  
    }
    else
        [player pause];
}

- (IBAction)steper:(id)sender {
    
  //  progress.    
    player.volume += 1.0; 
    
}
@end
