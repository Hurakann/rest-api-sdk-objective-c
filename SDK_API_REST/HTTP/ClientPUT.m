//  ClientPUT.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "ClientPUT.h"

@implementation ClientPUT

+(NSURL *)getProxyURL{    
    SharedData *instance=[SharedData instance];
    return instance.proxyURL;
}

+ (void)putRequestWithBODYParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block body:(NSData *)bodyParameters andURI:(NSString *)uri{

    NSURL *url;
    SharedData *instance=[SharedData instance];
    
    if(bodyParameters!=nil && uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",[self getProxyURL],uri]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }

     NSString *jsonDecode=[[NSString alloc] initWithData:bodyParameters encoding:NSUTF8StringEncoding];
    
    NSLog(@"JSON req: %@",jsonDecode);
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    
     NSTimeInterval timeOut=[instance.timeOutInterval doubleValue];
     [req setTimeoutInterval:timeOut];
     [req setCachePolicy:kNilOptions];
     [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
     [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
     [req setValue:[NSString stringWithFormat:@"%d",(int) [jsonDecode length]] forHTTPHeaderField:@"Content-Length"];
     [req setHTTPMethod:@"PUT"];
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
