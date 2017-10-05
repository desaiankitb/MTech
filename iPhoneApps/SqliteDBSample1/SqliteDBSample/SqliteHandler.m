//
//  SqliteHandler.m
//  SqliteDBSample
//
//  Created by mac on 08/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SqliteHandler.h"

@implementation SqliteHandler

- (id)init 
{
    if (self = [super init]) 
    {
        appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
        strDBName = [[[NSString alloc] initWithString:appDelegate.strDBPath] retain];
    }
    return  self;
}


- (BOOL)insertRecordInDB:(NSString*)query 
{
    BOOL isSucceed = NO;
   NSLog(@"%@", strDBName);
    
    if (sqlite3_open([strDBName UTF8String], &database) == SQLITE_OK)
    {
        NSString *strQuery = [NSString stringWithString:query];
        
        sqlite3_stmt *compiledStms;
        
        //
        if (sqlite3_prepare_v2(database, [strQuery UTF8String], -1, &compiledStms, NULL) == SQLITE_OK) {
            sqlite3_step(compiledStms);
            isSucceed = YES;
        }
   
        sqlite3_finalize(compiledStms);
        
        //
        
        //sqlite3_exec(database, [strQuery UTF8String], NULL, NULL, NULL)==SQLITE_OK
        
        sqlite3_close(database);
    }

    return isSucceed;
}

-(NSMutableArray *)Selectrecord:(NSString *)strquer
{
    myarray =[[NSMutableArray alloc]init];
    if(sqlite3_open([strDBName UTF8String],&database)==SQLITE_OK)
    {
        NSString *strquery=[NSString stringWithFormat:@"select * from tblUser where firstName='%@'",strquer];
        
        sqlite3_stmt *compilest;
        if(sqlite3_prepare_v2(database,[strquery UTF8String],-1,&compilest,NULL)==SQLITE_OK)
        {
            while (sqlite3_step(compilest)==SQLITE_ROW) {
                NSString *lname=[NSString stringWithUTF8String:(char *)sqlite3_column_text(compilest,1)];
                NSString *email=[NSString stringWithUTF8String:(char *)sqlite3_column_text(compilest,2)];
                NSString *phone=[NSString stringWithUTF8String:(char *)sqlite3_column_text(compilest,3)];
                
                [myarray addObject:lname];
                [myarray addObject:email];
                [myarray addObject:phone];
                               
            }
        }
        sqlite3_finalize(compilest);
        sqlite3_close(database);
        
    }
    return myarray;



}
@end
