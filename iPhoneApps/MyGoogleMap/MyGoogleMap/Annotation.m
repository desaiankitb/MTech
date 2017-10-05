//
//  Annotation.m
//  MyGoogleMap
//
//  Created by mac on 5/8/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import "Annotation.h"

@implementation Annotation
@synthesize  title;
@synthesize cordinate;
-(id)initWithTitle:(NSString *)strTitle andCoordinate:(CLLocationCoordinate2D)coord
{
    
    if (self = [super init]) {
        self.title = strTitle;//[strTitle copy];
        self.cordinate = coord;
    }

    return  self;
}
@end
