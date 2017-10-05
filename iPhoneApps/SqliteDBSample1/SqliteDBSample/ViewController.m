//
//  ViewController.m
//  SqliteDBSample
//
//  Created by mac on 08/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize txtFname;
@synthesize txtLname;
@synthesize txtEmail;
@synthesize txtPhone;

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
    [self setTxtFname:nil];
    [self setTxtLname:nil];
    [self setTxtEmail:nil];
    [self setTxtPhone:nil];
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
    [txtFname release];
    [txtLname release];
    [txtEmail release];
    [txtPhone release];
    [super dealloc];
}
- (IBAction)tbnSaveTapped:(id)sender {
    
    SqliteHandler *objHandler = [[SqliteHandler alloc] init];
    //[objHandler insertRecordInDB:@"Insert into tblUser (firstName, lastName, email, phone) values ('Kapil', 'Choubisa', 'abc@test.com', '03848484')"];
    
    NSString *strQuery = [NSString stringWithFormat:@"Insert into tblUser (firstName, lastName, email, phone) values ('%@', '%@', '%@', '%@')", txtFname.text, txtLname.text, txtEmail.text, txtPhone.text];
    if ([objHandler insertRecordInDB:strQuery]) {
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Insert" message:@"Record Inserted" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    }
    else{
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Insert" message:@"Record Not Inserted" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    }
}
-(IBAction)tbnUpdateTapped:(id)sender
{
    SqliteHandler *objHandler = [[SqliteHandler alloc] init];
   
    
    NSString *strQuery = [NSString stringWithFormat:@"update tblUser set lastName='%@',email='%@',phone='%@' where firstName='%@'",txtLname.text,txtEmail.text,txtPhone.text,txtFname.text];
    
    if ([objHandler insertRecordInDB:strQuery]) {
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Update" message:@"UpdateRecord" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    }
    else{
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Insert" message:@"Record Not Inserted" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    }


}

- (IBAction)selectrecord:(id)sender {
    
    SqliteHandler *objHandler = [[SqliteHandler alloc] init];
    arrayrecord =[objHandler Selectrecord:txtFname.text];
    int i=[arrayrecord count];
    if(i!=0 )
    {
        txtLname.text=[arrayrecord objectAtIndex:0];
        txtEmail.text=[arrayrecord objectAtIndex:1];
        txtPhone.text=[arrayrecord objectAtIndex:2];
        
    }
    else
    {
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Delete" message:@"Record not found" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    
    }
    
    
}

- (IBAction)btndelete:(id)sender {
    
    
    SqliteHandler *objHandler = [[SqliteHandler alloc] init];
      NSString *strQuery = [NSString stringWithFormat:@"delete from tblUser where firstName='%@'",txtFname.text];
    
    if ([objHandler insertRecordInDB:strQuery]) {
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Delete" message:@"Record Deleted" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
    }
    else{
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Insert" message:@"Record Not deleted" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles: nil] autorelease];
        [alert show];
  
    }
    
}



- (BOOL)textFieldShouldReturn:(UITextField *)textField {

    [textField resignFirstResponder];
    return YES;
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    txtFname.text = @"";
    txtLname.text = @"";
    txtEmail.text = @"";
    txtPhone.text = @"";
}


@end
