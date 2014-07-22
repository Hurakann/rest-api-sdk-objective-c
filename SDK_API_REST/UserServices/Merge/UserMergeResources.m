//
//  UserMergeResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserMergeResources.h"

@implementation UserMergeResources

+ (void) mergeUsers:(void (^)(Response *))block withParameters:(Merge *) userParameters{

    NSString *uri=@"/v1/user/merge";
    NSString *requestBodyString=[userParameters toJSONString];
    NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
    
    } body:requestBodyJSON andURI:uri];
    
}

+ (void) changeMainUser:(void (^)(Response *))block OfMergedUsers:(Merge *) userParameters{

    NSString *uri=@"/v1/user/merge";
    NSString *requestBodyString=[userParameters toJSONString];
    NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
    
    } body:requestBodyJSON andURI:uri];
    
}

+ (void) getMergeUsersInformation:(void (^)(Response *))block withUserID:(NSString *) user_id{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:user_id,@"user_id", nil];
    NSString *uri=@"/v1/user/merge";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSArray *array=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *jsonDecode=[[NSDictionary alloc] initWithObjectsAndKeys:array,@"users_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];

}
@end
