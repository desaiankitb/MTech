//
//  AppDelegate.h
//  SqliteDBSample
//
//  Created by mac on 08/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ViewController;

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
    NSString *strDBPath;
}

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) ViewController *viewController;

@property (strong, nonatomic) NSString *strDBPath;


- (void)copyAndCheckDatabase;

@end
