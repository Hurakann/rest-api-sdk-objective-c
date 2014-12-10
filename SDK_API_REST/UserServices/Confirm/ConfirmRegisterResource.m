//
//  ConfirmRegisterResource.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 14/10/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "ConfirmRegisterResource.h"

@implementation ConfirmRegisterResource

+(void)confirmRegister:(void (^)(Response *))block withInfo:(ConfirmRegister *)confirm ToServer:(NSString *)server AndURI:(NSString *) uri{

    
    SharedData *instance=[SharedData instance];
    NSURL *url;
    //NSString *uri=@"/activateaccount";
    
    url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",server,uri]];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[confirm toDictionary] options:kNilOptions error:&error];
    
    

    NSTimeInterval timeOut=(double) instance.timeOutInterval;
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    [req setTimeoutInterval:timeOut];
    [req setCachePolicy:kNilOptions];
    [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [req setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [req setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [req setValue:[NSString stringWithFormat:@"%d",(int) [[confirm toJSONString] length]] forHTTPHeaderField:@"Content-Length"];
    [req setHTTPMethod:@"POST"];
    [req setHTTPBody:jsonData];
    
    if(instance.logs){
        NSLog(@"URL : %@",url);
        NSLog(@"HEADERS %@",[req allHTTPHeaderFields]);
        NSLog(@"Body JSON: %@",[confirm toJSONString]);
    }
    
    NSOperationQueue *queue=[[NSOperationQueue alloc] init];
    [NSURLConnection sendAsynchronousRequest:req queue:queue completionHandler: ^(NSURLResponse *response, NSData *data, NSError *connectionError){
        if(connectionError){
            if (block){
                Response *response=[[Response alloc] init];
                block(response);
            }
        }else{
            NSHTTPURLResponse *responseCode=[[NSHTTPURLResponse alloc] init];
            responseCode=(NSHTTPURLResponse *)response;
            if (block){
                NSDictionary *jsonObject=[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:nil];
                Response *response=[[Response alloc] init];
                response.responseBody=data;
                response.responseBodyT=jsonObject;
                response.statusCode=responseCode.statusCode;
                block(response);
            }
        }
    }];
}

@end
