//
//  ViewController.h
//  MessagingSample
//
//  Created by mac on 11/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

@interface ViewController : UIViewController <MFMailComposeViewControllerDelegate, UINavigationControllerDelegate, MFMessageComposeViewControllerDelegate>{
    MFMailComposeViewController *mailComposer;
    
    MFMessageComposeViewController *messageComposer;
}
- (IBAction)btnSendMailTapped:(id)sender;
- (IBAction)btnSendMessageTapped:(id)sender;

@end
