///  SharedData.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "SharedData.h"

@implementation SharedData

static SharedData *_instance;

+ (SharedData *) instance {
    
    if ( _instance == nil ) {
        
        _instance = [[SharedData alloc] init];
        
        NSString *path = [[NSBundle mainBundle] pathForResource:
                          @"Configuration" ofType:@"plist"];
        
        NSDictionary *confParams = [[NSDictionary alloc] initWithContentsOfFile:path];
        
        if(confParams != nil){
            
            _instance.logs=NO;
            
            if(![[confParams objectForKey:@"endpoint"] isEqualToString:@""]){
                if([[confParams objectForKey:@"port"] isEqualToString:@""])
                    _instance.proxyURL=[NSURL URLWithString:[NSString stringWithFormat:@"%@/%@/",[confParams objectForKey:@"endpoint"],[confParams objectForKey:@"api-version"]]];
                else
                    _instance.proxyURL=[NSURL URLWithString:[NSString stringWithFormat:@"%@:%@/%@/",[confParams objectForKey:@"endpoint"], [confParams objectForKey:@"port"],[confParams objectForKey:@"api-version"]]];
                
            }
                
            if([confParams objectForKey:@"connection-timeout"] != nil)
                 _instance.timeOutInterval=[[confParams objectForKey:@"connection-timeout"] intValue];
                
            if([confParams objectForKey:@"connection-readtimeout"] != nil)
                _instance.filetimeOutInterval=[[confParams objectForKey:@"connection-readtimeout"] intValue];
      
            if([confParams objectForKey:@"branch_id"] != nil)
                _instance.branch_id=[confParams objectForKey:@"branch_id"];

            if([confParams objectForKey:@"user_id"] != nil)
                _instance.user_id=[confParams objectForKey:@"user_id"];

            if([confParams objectForKey:@"api-version"] != nil)
                _instance.user_id=[confParams objectForKey:@"api-version"];
            
            if([confParams objectForKey:@"Ckey"] != nil)
                _instance.c_key=[confParams objectForKey:@"Ckey"];
            
            if([[confParams objectForKey:@"logs"] isEqualToString:@"YES"])
                _instance.logs=YES;
            
            _instance.sdk_version=[[NSBundle mainBundle] objectForInfoDictionaryKey: @"CFBundleShortVersionString"];
            
        }
    }
    
    return _instance;
}

- (void)resetModel
{
    _instance.proxyURL=nil;
    
}

@end
