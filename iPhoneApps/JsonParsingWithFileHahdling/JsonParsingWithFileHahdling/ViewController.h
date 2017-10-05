//
//  ViewController.h
//  JsonParsingWithFileHahdling
//
//  Created by mac on 5/4/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JSON.h"

@interface ViewController : UIViewController<UITableViewDataSource,UITableViewDelegate>
{
    NSArray *arr;
     NSFileManager *filemgr;
    
    
}

@end
