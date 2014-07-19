//  UserResourceServices.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserResourceServices.h"


@implementation UserResourceServices

+(void)assignUserByService:(void (^)(Response *))block withParameters:(UserInformationService *)userServiceParameters{
    
    NSMutableDictionary *mutDict=[NSMutableDictionary alloc];
    
    if([userServiceParameters.userId isEqualToString:@"all"] && userServiceParameters.owner==nil){
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
    }else if (userServiceParameters.owner!=nil){
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
        [mutDict setObject:userServiceParameters.owner forKey:@"owner"];
    }else{
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
        [mutDict setObject:userServiceParameters.owner forKey:@"service_id"];
    }
    
    NSString *uri=@"/v1/user/services";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(statusCode == 200){
            
            NSString *requestBodyString=[userServiceParameters toJSONString];
            NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
            [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
                
                if(error)
                    block(nil);
                else {
                    Response *resp=[[Response alloc] init];
                    resp.statusCode=statusCode;
                    block(resp);
                }
            } body:requestBodyJSON andURI:uri];
            
        }else
            block(nil);
        
    } parametersURL:mutDict andURI:uri];
    
}

+(void)updateUserService:(void (^)(Response *))block withParameters:(UserInformationService *)userServiceParameters{

    NSString *uri=@"/v1/user/services";
    NSString *requestBodyString=[userServiceParameters toJSONString];
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

+(void)getUserService:(void (^)(Response *))block withParameters:(UserInformationService *)userServiceParameters{

    NSMutableDictionary *mutDict=[NSMutableDictionary alloc];
    
    if([userServiceParameters.userId isEqualToString:@"all"] && userServiceParameters.owner==nil){
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
    }else if (userServiceParameters.owner!=nil){
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
        [mutDict setObject:userServiceParameters.owner forKey:@"owner"];
    }else{
        [mutDict setObject:userServiceParameters.userId forKey:@"user_id"];
        [mutDict setObject:userServiceParameters.owner forKey:@"service_id"];
    }
    
    NSString *uri=@"/v1/user/services";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSArray *array = [NSKeyedUnarchiver unarchiveObjectWithData:responseBody];
            NSDictionary *jsonDecode=[[NSDictionary alloc] initWithObjectsAndKeys:array,@"Services", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:mutDict andURI:uri];
    
}

@end
