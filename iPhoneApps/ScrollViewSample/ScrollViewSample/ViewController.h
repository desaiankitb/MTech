//
//  ViewController.h
//  ScrollViewSample
//
//  Created by mac on 19/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UIScrollViewDelegate> {
    UIImageView *imv;
    BOOL isImgAdded;
}
@property (retain, nonatomic) IBOutlet UIScrollView *scrollView;

@end
