//
//  DrawView.m
//  DrawALineSample
//
//  Created by mac on 20/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "DrawView.h"

@implementation DrawView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        aryPath = [[NSMutableArray alloc] init];
        self.backgroundColor = [UIColor redColor];
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    path = [[UIBezierPath alloc] init];
    CGPoint point = [[touches anyObject] locationInView:self];
    [path setLineWidth:2.0];
    //[path addLineToPoint:point];
    [path moveToPoint:point];
    
    [aryPath addObject:path];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    CGPoint point = [[touches anyObject] locationInView:self];
    [path addLineToPoint:point];
    [self setNeedsDisplay];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    [path release];
}

- (void)drawRect:(CGRect)rect { 
    [[UIColor blackColor] set];
    for (UIBezierPath *temp in aryPath){
        [temp stroke];
    }
}

@end
