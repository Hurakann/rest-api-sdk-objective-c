//
//  UserFile.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserFile.h"

@implementation UserFile


+(void)uploadFile:(void (^)(Response *))block WithData:(NSData *)data andName:(NSString *)name ofType:(NSString *)type{

    NSString *uri=@"user/file";
    SharedData *instance=[SharedData instance];
    NSString *contentType = [NSString stringWithFormat:@"multipart/form-data; boundary=E19zNvXGzXaLvS5C"];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setCachePolicy:NSURLRequestReloadIgnoringLocalCacheData];
    [request setHTTPShouldHandleCookies:NO];
    
    NSURL *url=[NSURL URLWithString:[NSString stringWithFormat:@"%@%@",instance.proxyURL,uri]];
    
    NSTimeInterval timeOut=(double) instance.filetimeOutInterval;
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
    
    [request setHTTPBody:body];
    [request setValue:[NSString stringWithFormat:@"rest-api-sdk-objective-c-version-%@",instance.sdk_version] forHTTPHeaderField:@"User-Agent"];
    [request setValue:[NSString stringWithFormat:@"%@",instance.c_key] forHTTPHeaderField:@"Ckey"];
    [request setValue:postLength forHTTPHeaderField:@"Content-Length"];
    [request setURL:url];
    
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];
    
    if(instance.logs){
        NSLog(@"HEADERS %@",[request allHTTPHeaderFields]);
        NSLog(@"URL : %@",url);
    }
    
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
    NSString *uri=@"user/file";
    
    [ClientDELETE deleteRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
}

+(void)getFile:(void (^)(Response *))block WithFileID:(NSString *)idFile{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:idFile,@"file_id", nil];
    NSString *uri=@"user/file";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            block(resp);
        }else
            block(nil);
    
    } parametersURL:params andURI:uri];
    
}
@end



