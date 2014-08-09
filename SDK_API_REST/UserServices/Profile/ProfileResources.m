//
//  ProfileResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "ProfileResources.h"

@implementation ProfileResources

+(void)getProfilesList:(void (^)(Response *))block WithUserID:(NSString *)user_id{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:user_id,@"user_id", nil];
    NSString *uri=@"profiles";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSError *error;
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"profiles_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];
    
}

+(void)createNewProfile:(void (^)(Response *))block WithInformation:(Profile *)info{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[info toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"profiles";
   
    NSLog(@"LOG %@",[info toJSONString]);
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSLog(@"SI PASO");
            NSError *error;
            NSDictionary *jsonObject=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonObject;
            
            if(block)
                block(resp);
            
        }else
            if(block)
                block(nil);
    
    } body:jsonData andURI:uri];

}

+(void)updateProfile:(void (^)(Response *))block WithProfileID:(NSString *)profile_id AndProfileName:(NSString *)name{

    NSDictionary *profileParams=[[NSDictionary alloc] initWithObjectsAndKeys:profile_id,@"profile_id",name,@"name", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:profileParams options:kNilOptions error:&error];
    NSString *uri=@"profiles";

    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];

}

@end
