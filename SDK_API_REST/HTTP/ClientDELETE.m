
//  ClientDELETE.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "ClientDELETE.h"

@implementation ClientDELETE

+(NSURL *)getProxyURL{
    SharedData *instance=[SharedData instance];
    return instance.proxyURL;
}

+(void)deleteRequestWithBODYParameters:(void (^)(NSData *, NSError *, NSInteger))block body:(NSData *)bodyParameters andURI:(NSString *)uri{

    SharedData *instance=[SharedData instance];
    NSString *jsonDecode=[[NSString alloc] initWithData:bodyParameters encoding:NSUTF8StringEncoding];
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",[self getProxyURL],uri]];
    NSTimeInterval timeOut=[instance.timeOutInterval doubleValue];
    
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:kNilOptions];
    [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [req setValue:[NSString stringWithFormat:@"%d",(int) [jsonDecode length]] forHTTPHeaderField:@"Content-Length"];
    [req setHTTPMethod:@"DELETE"];
    [req setHTTPBody:bodyParameters];
    
    NSOperationQueue *queue=[[NSOperationQueue alloc] init];
    [NSURLConnection sendAsynchronousRequest:req queue:queue completionHandler: ^(NSURLResponse *response, NSData *data, NSError *connectionError){
        if(connectionError){
            if (block)
                block(nil,connectionError,0);
        }else{
            NSHTTPURLResponse *responseCode=[[NSHTTPURLResponse alloc] init];
            responseCode=(NSHTTPURLResponse *)response;
            if (block)
                block(data,nil,responseCode.statusCode);
        }
    }];
 
}
@end
