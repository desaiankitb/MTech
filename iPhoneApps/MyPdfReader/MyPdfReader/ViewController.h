//
//  ViewController.h
//  MyPdfReader
//
//  Created by mac on 5/2/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
{

    IBOutlet  NSURL *url;

    IBOutlet UIWebView *webView;


}

@property (strong, nonatomic) IBOutlet UIWebView *webView;
@property (strong, nonatomic) IBOutlet NSURL *url;



@end
