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

+ (NSString *)buildURLWithParameters:(NSDictionary *) parameters{
    
    NSString *basicUrl=@"";
    NSArray *keys=[parameters allKeys];
    
    for(int x=0;x<parameters.count;x++){
        if(x==0){
            if([[parameters objectForKey:[keys objectAtIndex:x]] isKindOfClass:[NSString class]])
                basicUrl=[NSString stringWithFormat:@"?%@=%@",[keys objectAtIndex:x],[self encodeURL:[parameters objectForKey:[keys objectAtIndex:x]]]];
            else
                basicUrl=[NSString stringWithFormat:@"?%@=%@",[keys objectAtIndex:x],[parameters objectForKey:[keys objectAtIndex:x]]];
        }else{
            if([[parameters objectForKey:[keys objectAtIndex:x]] isKindOfClass:[NSString class]])
                basicUrl=[basicUrl stringByAppendingString:[NSString stringWithFormat:@"&%@=%@",[keys objectAtIndex:x],[self encodeURL:[parameters objectForKey:[keys objectAtIndex:x]]]]];
            else
                basicUrl=[basicUrl stringByAppendingString:[NSString stringWithFormat:@"&%@=%@",[keys objectAtIndex:x],[parameters objectForKey:[keys objectAtIndex:x]]]];
        }
    }
    
    keys=nil;
    
    return basicUrl;
}

+(NSString *)encodeURL:(NSString *)urlString
{
    CFStringRef newString = CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault, (CFStringRef)urlString, NULL, CFSTR("!|*'();:&=+$,/?%#[]"), kCFStringEncodingUTF8);
    return (NSString *)CFBridgingRelease(newString);
}

+ (void)getRequestWithURLParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block parametersURL:(NSDictionary *)urlQueryStringParameters andURI:(NSString *)uri{
    
    SharedData *instance=[SharedData instance];
    NSURL *url;
    
    NSString *basicParams=[self buildURLWithParameters:urlQueryStringParameters];
    
    if(uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@%@",instance.proxyURL,uri,basicParams]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }
    
    /////    MUTABLE REQUEST    ////
    
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    [req setHTTPMethod:@"GET"];
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData];
    [req setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [req setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [req setValue:@"text/plain; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    [req setValue:@"es-ES,es;q=0.8,en;q=0.6" forHTTPHeaderField:@"Accept-Language"];
    
    if(instance.logs){
        NSLog(@"HEADERS %@",[req allHTTPHeaderFields]);
        NSLog(@"URL %@",url);
    }
    
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
