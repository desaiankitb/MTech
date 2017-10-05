//
//  Annotation.h
//  MyGoogleMap
//
//  Created by mac on 5/8/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface Annotation : NSObject<MKAnnotation>
{
    NSString *title;
    CLLocationCoordinate2D cordinate;

}
@property(strong,nonatomic) NSString *title;
@property (nonatomic) CLLocationCoordinate2D cordinate;

- (id)initWithTitle:(NSString*)strTitle andCoordinate:(CLLocationCoordinate2D)coord;
@end
