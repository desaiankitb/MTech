//
//  ViewController.h
//  SqliteDBSample
//
//  Created by mac on 08/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SqliteHandler.h"

@interface ViewController : UIViewController<UITextFieldDelegate, UIAlertViewDelegate> {
    NSMutableArray *arrayrecord;
    
}

@property (retain, nonatomic) IBOutlet UITextField *txtFname;

@property (retain, nonatomic) IBOutlet UITextField *txtLname;
@property (retain, nonatomic) IBOutlet UITextField *txtEmail;
@property (retain, nonatomic) IBOutlet UITextField *txtPhone;
- (IBAction)tbnSaveTapped:(id)sender;
-(IBAction)tbnUpdateTapped:(id)sender;
- (IBAction)selectrecord:(id)sender;
- (IBAction)btndelete:(id)sender;

@end
