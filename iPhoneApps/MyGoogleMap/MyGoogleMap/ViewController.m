//
//  ViewController.m
//  MyGoogleMap
//
//  Created by mac on 5/8/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"
#import "Annotation.h"

@implementation ViewController
@synthesize myMapView;
@synthesize xxxxx;
@synthesize myMapView;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    cityName=[[NSArray alloc] initWithObjects:@"Ahmedabad",@"Baroda",@"Delhi", nil];
    cityLocation= [[NSArray alloc] initWithObjects:@"23.0333,72.6167",
                   @"24.0333,73.6167", @"28.635308,77.224960", nil];
 
   // [myMapView setAnimationDelegate:self];
    CLLocationManager *locmanager=[[CLLocationManager alloc]init];
    [locmanager setDelegate:self];
    [locmanager startUpdatingLocation];
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    
    [self setMyMapView:nil];
    [self setMyMapView:nil];
    [self setXxxxx:nil];
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

@end
