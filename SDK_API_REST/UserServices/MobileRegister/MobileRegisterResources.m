//
//  MobileRegisterResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "MobileRegisterResources.h"

@implementation MobileRegisterResources

+(void)addMobileDeviceToUser:(void (^)(Response *))block WithParameters:(MobileRegister *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/mobile/register";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block (nil);
    
    } body:jsonData andURI:uri];
    
}

+(void)updateMobileDevice:(void (^)(Response *))block ToUserID:(NSString *)user_id Token:(NSString *)token WithStatus:(NSString *)status{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:user_id,@"user_id",token,@"token",status,@"status", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/mobile/register";
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block (resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
    
}
@end
