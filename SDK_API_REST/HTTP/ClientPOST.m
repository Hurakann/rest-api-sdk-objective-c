//  ClientPOST.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "ClientPOST.h"

@implementation ClientPOST

+ (void)postRequestWithBODYParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block body:(NSData *)bodyParameters andURI:(NSString *)uri{
    
    SharedData *instance=[SharedData instance];
    NSURL *url;
    
    if(bodyParameters!=nil && uri!=nil)
        url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",instance.proxyURL,uri]];
    else{
        if (block)
            block(nil,nil,0);
        return ;
    }
    
    NSString *jsonDecode=[[NSString alloc] initWithData:[self checkVoidParametersWithData:bodyParameters] encoding:NSUTF8StringEncoding];
    
    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:kNilOptions];
    [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [req setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [req setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [req setValue:[NSString stringWithFormat:@"%d",(int) [jsonDecode length]] forHTTPHeaderField:@"Content-Length"];
    [req setHTTPMethod:@"POST"];
    [req setHTTPBody:bodyParameters];
	
    if(instance.logs){
        NSLog(@"HEADERS %@",[req allHTTPHeaderFields]);
        NSLog(@"Body JSON: %@",jsonDecode);
        NSLog(@"URL: %@",url);
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

+(NSData *)checkVoidParametersWithData:(NSData *) data{
    
    NSError *error;
    NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    NSMutableDictionary *jsonWithoutVoidParameters=[[NSMutableDictionary alloc] init];
    NSArray *keys=[jsonDecode allKeys];
    
    for(int x=0;x<jsonDecode.count;x++)
        if(!([[[jsonDecode objectForKey:[keys objectAtIndex:x]] description] isEqualToString:@"0"] || [[[jsonDecode objectForKey:[keys objectAtIndex:x]] description] isEqualToString:@""]))
            [jsonWithoutVoidParameters setObject:[jsonDecode objectForKey:[keys objectAtIndex:x]] forKey:[keys objectAtIndex:x]];
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:jsonWithoutVoidParameters options:kNilOptions error:&error];
    
    return jsonData;
    
}

@end
