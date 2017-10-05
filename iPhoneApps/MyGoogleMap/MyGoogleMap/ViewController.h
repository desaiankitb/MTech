//
//  ViewController.h
//  MyGoogleMap
//
//  Created by mac on 5/8/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@interface ViewController : UIViewController
<MKMapViewDelegate,CLLocationManagerDelegate>
{
    NSArray *cityName;
    NSArray *cityLocation;
    
}
@property (strong, nonatomic) IBOutlet MKMapView *myMapView;




//@property (retain, nonatomic) IBOutlet MKMapView *myMapView;
- (void)ShowAnnotationOnMap;

@end
