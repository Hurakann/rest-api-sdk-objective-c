//  ClientGET.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "ClientGET.h"

@implementation ClientGET

+(NSURL *)getProxyURL{
    
    SharedData *instance=[SharedData instance];
    return instance.proxyURL;
}

+ (NSString *)buildURLWithParameters:(NSDictionary *) parameters{
    
    NSString *basicUrl=@"";
    NSArray *keys=[parameters allKeys];
    
    for(int x=0;x<parameters.count;x++){
        if(x==0){
            basicUrl=[NSString stringWithFormat:@"?%@=%@",[keys objectAtIndex:x],[parameters objectForKey:[keys objectAtIndex:x]]];
        }else
            basicUrl=[basicUrl stringByAppendingString:[NSString stringWithFormat:@"&%@=%@",[keys objectAtIndex:x],[parameters objectForKey:[keys objectAtIndex:x]]]];
    }
    
    return basicUrl;
}

+ (void)getRequestWithURLParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block parametersURL:(NSDictionary *)urlQueryStringParameters andURI:(NSString *)uri{
    
    SharedData *instance=[SharedData instance];
    NSURL *url;
    
    NSString *basicParams=[[self buildURLWithParameters:urlQueryStringParameters] stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    
    if(uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@%@",[self getProxyURL],uri,basicParams]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }
    
    NSLog(@"URL %@",url);
    
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    [req setHTTPMethod:@"GET"];
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData];
    
    NSOperationQueue *queue=[[NSOperationQueue alloc] init];
    [NSURLConnection sendAsynchronousRequest:req queue:queue completionHandler: ^(NSURLResponse *response, NSData *data, NSError *connectionError){
        
        if(connectionError!=nil){
            if (block)
                block(nil,connectionError,0);
        }else{
            NSHTTPURLResponse *responseCode=[[NSHTTPURLResponse alloc] init];
            responseCode=(NSHTTPURLResponse *)response;
            NSInteger resCode= responseCode.statusCode;
            
            if (block)
                block(data,nil,resCode);
        }
    }];
    
}

@end
