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
            
            if([confParams objectForKey:@"proxyURL"] != nil && [confParams objectForKey:@"port"]!=nil){
                _instance.proxyURL=[NSURL URLWithString:[NSString stringWithFormat:@"%@:%@",[confParams objectForKey:@"proxyURL"], [confParams objectForKey:@"port"]]];
                
                if([confParams objectForKey:@"proxyURL"] != nil)
                    _instance.socketURL=[NSURL URLWithString:[NSString stringWithFormat:@"%@:%@",[confParams objectForKey:@"webSocketURL"], [confParams objectForKey:@"port"]]];
                
            if([confParams objectForKey:@"timeOutInterval"] != nil)
                 _instance.timeOutInterval=[confParams objectForKey:@"timeOutInterval"];
                
            if([confParams objectForKey:@"fileTimeOutInterval"] != nil)
                _instance.filetimeOutInterval=[confParams objectForKey:@"fileTimeOutInterval"];
      
            }
        }
    }
    
    return _instance;
}

- (void)resetModel
{
    _instance.proxyURL=nil;
    _instance.socketURL=nil;
    _instance.timeOutInterval=nil;
    _instance.filetimeOutInterval=nil;
}

@end
