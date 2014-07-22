//
//  UserTagsResource.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserTagsResource.h"

@implementation UserTagsResource

+ (void) addTagsToUser:(void (^)(Response *))block WithUserID:(NSString *) userId AndTags:(NSArray *)tags{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:userId,@"user_id",tags,@"tags", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/tags";
    
    [self getUserTags:^(Response *resp){
    
        if(resp.statusCode!=200){
        
            [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
                
                if(error==nil){
                    Response *resp=[[Response alloc] init];
                    resp.statusCode=statusCode;
                    block(resp);
                }else
                    block(nil);
                
            } body:jsonData andURI:uri];
        
        }else
            block(nil);
        
    } withUserID:userId];

}

+ (void) updateTagsToUser:(void (^)(Response *))block WithUserID:(NSString *) userId AndTags:(NSArray *)tags{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:userId,@"user_id",tags,@"tags", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/tags";
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
}

+ (void) getUserTags:(void (^)(Response *))block withUserID:(NSString *) userId{
    
    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:userId,@"user_id", nil];
    NSString *uri=@"/v1/user/tags";

    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
       
        if(error==nil){
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
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
