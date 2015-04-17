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


+ (void)putRequestWithBODYParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block body:(NSData *)bodyParameters andURI:(NSString *)uri{

    NSURL *url;
    SharedData *instance=[SharedData instance];
    
    if(bodyParameters!=nil && uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",instance.proxyURL,uri]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }

    NSString *jsonDecode=[[NSString alloc] initWithData:[self checVoidParametersWithData:bodyParameters] encoding:NSUTF8StringEncoding];
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:kNilOptions];
    [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [req setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [req setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [req setValue:[NSString stringWithFormat:@"%d",(int) [jsonDecode length]] forHTTPHeaderField:@"Content-Length"];
    [req setHTTPMethod:@"PUT"];
    [req setHTTPBody:bodyParameters];
    
    if(instance.logs){
        NSLog(@"Body JSON %@",jsonDecode);
        NSLog(@"URL %@",url);
    }
    
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

+(NSData *)checVoidParametersWithData:(NSData *) data{

    NSError *error;
    NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    NSMutableDictionary *jsonWithoutVoidParameters=[[NSMutableDictionary alloc] init];
    NSArray *keys=[jsonDecode allKeys];
    
    for(int x=0;x<jsonDecode.count;x++){
    
        if(!([[[jsonDecode objectForKey:[keys objectAtIndex:x]] description] isEqualToString:@"0"] || [[[jsonDecode objectForKey:[keys objectAtIndex:x]] description] isEqualToString:@""]))
            [jsonWithoutVoidParameters setObject:[jsonDecode objectForKey:[keys objectAtIndex:x]] forKey:[keys objectAtIndex:x]];
    }
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:jsonWithoutVoidParameters options:kNilOptions error:&error];
    
    return jsonData;
    
}

+(void)putRequestWithBODYParameters:(void (^)(NSData *, NSError *, NSInteger))block body:(NSData *)bodyParameters ToServer:(NSString *)server andURI:(NSString *)uri{

    NSURL *url;
    SharedData *instance=[SharedData instance];
    
    if(bodyParameters!=nil && uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",server,uri]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }
    
    NSString *jsonDecode=[[NSString alloc] initWithData:[self checVoidParametersWithData:bodyParameters] encoding:NSUTF8StringEncoding];
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:kNilOptions];
    [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [req setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [req setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [req setValue:[NSString stringWithFormat:@"%d",(int) [jsonDecode length]] forHTTPHeaderField:@"Content-Length"];
    [req setHTTPMethod:@"PUT"];
    [req setHTTPBody:bodyParameters];
    
    if(instance.logs){
        NSLog(@"Body JSON %@",jsonDecode);
        NSLog(@"URL %@",url);
    }
    
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
