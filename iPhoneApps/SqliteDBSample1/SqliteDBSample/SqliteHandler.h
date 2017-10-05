//
//  SqliteHandler.h
//  SqliteDBSample
//
//  Created by mac on 08/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "AppDelegate.h"

@interface SqliteHandler : NSObject {
    sqlite3 *database;
    AppDelegate *appDelegate;
    NSString *strDBName;
    NSMutableArray *myarray;
}
- (BOOL)insertRecordInDB:(NSString*)query;
-(NSMutableArray *)Selectrecord:(NSString *)strquery;
@end
