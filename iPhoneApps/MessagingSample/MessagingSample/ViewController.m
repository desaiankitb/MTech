//
//  ViewController.m
//  MessagingSample
//
//  Created by mac on 11/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
   
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
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

- (IBAction)btnSendMailTapped:(id)sender {
    
    mailComposer = [[MFMailComposeViewController alloc] init];
   [mailComposer setSubject:@"abc"];
    [mailComposer setToRecipients:[NSArray arrayWithObjects:@"ayushi_rajkot@tops-int.com", @"xyz@gd.sg", nil]];
  //  [mailComposer setCcRecipients:<#(NSArray *)#>
   // [mailComposer setBccRecipients:<#(NSArray *)#>
    [mailComposer setDelegate:self];
    NSLog(@"%@", [[mailComposer delegate] description]);
    NSData *attachmentData = [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"Dandelion" ofType:@"jpg"]];
    [mailComposer addAttachmentData:attachmentData mimeType:@"image/jpg" fileName:@"flower"];
    [mailComposer setMessageBody:@"Hi I am <b>Kapil</b>" isHTML:YES];
    if (mailComposer != nil) {
        [self presentModalViewController:mailComposer animated:YES];
    }
    //[mailComposer release];
}

- (IBAction)btnSendMessageTapped:(id)sender {
    messageComposer = [[MFMessageComposeViewController alloc] init];
    [messageComposer setDelegate:self];
    [messageComposer setBody:@"This is Test Sms"];
    [messageComposer setRecipients:[NSArray arrayWithObjects:@"674586587578", nil]];
    
    if (messageComposer != nil) {
        [self presentModalViewController:messageComposer animated:YES];
    }
}

- (void)mailComposeController:(MFMailComposeViewController *)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error {
    switch (result) {
        case MFMailComposeResultSent:
            //do something
            NSLog(@"MAil sent");
            break;
            
        default:
            NSLog(@"MAil Not sent");
            break;
    }
    [mailComposer dismissModalViewControllerAnimated:YES];
}

- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result {
 //   [self dismissModalViewControllerAnimated:YES];
    [messageComposer dismissModalViewControllerAnimated:YES];
}

@end
