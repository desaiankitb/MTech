//
//  ViewController.m
//  ScrollViewSample
//
//  Created by mac on 19/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize scrollView;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    int originX = 0, originY = 0, width = 320, height = 460;
    for (int i = 0;  i < 1; i++) {
        imv = [[[UIImageView alloc] initWithFrame:CGRectMake(originX, originY, width, height)] retain];
        [imv setImage:[UIImage imageNamed:[NSString stringWithFormat:@"image%i.png", i+1]]];
    
        [imv setTag:101];
        [scrollView addSubview:imv];
        [imv release];
        originX += height;
        
    }
    [scrollView setContentSize:CGSizeMake(originX, width)];
    [scrollView setBounces:NO];
    [scrollView setShowsVerticalScrollIndicator:YES];
    scrollView.showsHorizontalScrollIndicator = YES;
   // [scrollView setContentOffset:CGPointMake(320, 0) animated:NO];
    [scrollView setPagingEnabled:YES];
    [scrollView setDelegate:self];
    [scrollView setMinimumZoomScale:0.5];
    [scrollView setMaximumZoomScale:2.0];
    [scrollView setZoomScale:1.5];
 //   [scrollView 
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [self setScrollView:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (void)dealloc {
    [scrollView release];
    [super dealloc];
}
/*
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView {
    if (isImgAdded) {
        CGRect rect = imv.frame;
        CGFloat scal = self.scrollView.zoomScale;
        rect.size.width *= scal;
        rect.size.height *= scal;
        [imv setFrame:rect];
        [imv retain];
        return imv; 
    }
    return nil;
}
 */
@end
