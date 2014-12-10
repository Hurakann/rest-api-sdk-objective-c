//
//  LoginResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "LoginResources.h"

@implementation LoginResources

+ (void)getLogin:(void (^)(Response *))block withParameters:(Login *)parameters{
    
    NSString *URI=@"user/login";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        Response *responseBlock;
        
        if(error)
            block(nil);
        else{
            
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            NSLog(@"KEYS %@",[jsonDecode allKeys]);
            responseBlock=[[Response alloc] init];
            responseBlock.statusCode=statusCode;
            responseBlock.responseBody=responseBody;
            responseBlock.responseBodyT=jsonDecode;
            
            if (block)
                block(responseBlock);
        }
        
    } parametersURL:[parameters toDictionary] andURI:URI];
}

+ (void)loginRestore:(void (^)(Response *))block withUserEmail:(NSString *) email{
    
    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:email,@"email", nil];
    NSString *uri=@"user/login/restore";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error)
            block(nil);
        else{
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }
        
    } parametersURL:params andURI:uri];
}

+(void)loginChangePassword:(void (^)(Response *))block withParameters:(LoginChangePasswordParameters *)parameters{
    
    NSString *requestBodyString=[parameters toJSONString];
    
    if (!([requestBodyString rangeOfString:@"n_password"].location == NSNotFound)) {
        [requestBodyString stringByReplacingOccurrencesOfString:@"n_password" withString:@"new_password"];
    }
    
    NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
    NSString *uri=@"user/login/change_password";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statuscode){
        
        if(error){
            block(nil);
        }else{
            Response *res=[[Response alloc] init];
            res.statusCode=statuscode;
            block(res);
        }
        
    } body:requestBodyJSON andURI:uri];
}


+(void)loginReset:(void (^)(Response *))block withParameters:(LoginResetParameters *)parameters{
    
   
    //NSString *requestBodyString=[parameters toJSONString];
   
   /* if (!([requestBodyString rangeOfString:@"n_password"].location == NSNotFound)) {
        [requestBodyString stringByReplacingOccurrencesOfString:@"n_password" withString:@"new_password"];
    }*/
    
    NSData *requestBodyJSON = [[parameters toJSONString] dataUsingEncoding:NSUTF8StringEncoding];
    NSString *uri=@"user/login/reset";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statuscode){
        
        if(error){
            block(nil);
        }else{
            Response *res=[[Response alloc] init];
            res.statusCode=statuscode;
            block(res);
        }
        
    } body:requestBodyJSON andURI:uri];
    
}

@end
