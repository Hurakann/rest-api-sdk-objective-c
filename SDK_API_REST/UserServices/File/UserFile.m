//
//  UserFile.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserFile.h"

@implementation UserFile

+(NSURL *)getProxyURL{
    
    SharedData *instance=[SharedData instance];
    return instance.proxyURL;
    
}

+(void)uploadFile:(void (^)(Response *))block WithData:(NSData *)data andName:(NSString *)name ofType:(NSString *)type{

    NSString *uri=@"/v1/user/file";
    SharedData *instance=[SharedData instance];
    NSString *contentType = [NSString stringWithFormat:@"multipart/form-data; boundary=E19zNvXGzXaLvS5C"];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setCachePolicy:NSURLRequestReloadIgnoringLocalCacheData];
    [request setHTTPShouldHandleCookies:NO];
    
     NSTimeInterval timeOut=[instance.filetimeOutInterval doubleValue];
    [request setTimeoutInterval:timeOut];
    [request setHTTPMethod:@"POST"];
    [request setValue:contentType forHTTPHeaderField: @"Content-Type"];
    
    NSMutableData *body = [NSMutableData data];
    
    if (data) {
        
        [body appendData:[[NSString stringWithFormat:@"--E19zNvXGzXaLvS5C\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
        [body appendData:[[NSString stringWithFormat:@"Content-Disposition: form-data; name=\"%@\"; filename=\"%@\"\r\n",name,name] dataUsingEncoding:NSUTF8StringEncoding]];
        
        if([type caseInsensitiveCompare:@"image"] == NSOrderedSame)
            [body appendData:[@"Content-Type: image/jpeg\r\n\r\n" dataUsingEncoding:NSUTF8StringEncoding]];
        else
            [body appendData:[@"Content-Type: application/octet-stream\r\n\r\n" dataUsingEncoding:NSUTF8StringEncoding]];
        
        [body appendData:data];
        [body appendData:[[NSString stringWithFormat:@"\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
    
    }
    
    [body appendData:[[NSString stringWithFormat:@"--E19zNvXGzXaLvS5C--\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
    
    NSString *postLength = [NSString stringWithFormat:@"%d",(int) [body length]];
    NSURL *url=[NSURL URLWithString:[NSString stringWithFormat:@"%@%@",[self getProxyURL],uri]];
    [request setHTTPBody:body];
    [request setValue:postLength forHTTPHeaderField:@"Content-Length"];
    [request setURL:url];
    
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];
    
    [NSURLConnection sendAsynchronousRequest:request queue:queue completionHandler:^(NSURLResponse *response, NSData *data, NSError *error)
     {
         if(error)
             block(nil);
         else{
             NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
             NSDictionary *jsonObject=[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:nil];
             Response *resp=[[Response alloc] init];
             resp.statusCode=[httpResponse statusCode];
             resp.responseBody=data;
             resp.responseBodyT=jsonObject;
             block(resp);
         }
     }];
    
}

+ (void) deleteFile:(void (^)(Response *))block WithFileID:(NSString *) idFile{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:idFile,@"file_id", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/file";
    
    [ClientDELETE deleteRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
}
@end



