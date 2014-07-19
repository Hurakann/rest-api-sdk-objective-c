//  UserResource.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.
#import "UserResource.h"

@implementation UserResource

+(NSDictionary *) completeParametersNameToRequest:(User *) user{

    
    NSDictionary *propInClass=[[NSDictionary alloc] initWithDictionary:[user toDictionary]];
    NSArray *keysInObject=[propInClass allKeys];
    NSArray *properties = [self allPropertyNames];
    
    NSMutableDictionary *mutDic=[[NSMutableDictionary alloc] init];
    
    for(int x=0; x<keysInObject.count; x++){
        
        if(!([properties containsObject:[keysInObject objectAtIndex:x]])){
            [mutDic setObject:[propInClass objectForKey:[keysInObject objectAtIndex:x]] forKey:[NSString stringWithFormat:@"_%@",[keysInObject objectAtIndex:x]]];
        }else
            [mutDic setObject:[propInClass objectForKey:[keysInObject objectAtIndex:x]] forKey:[keysInObject objectAtIndex:x]];
        
    }
    
    NSLog(@"mutDIc %@",mutDic);
    return mutDic;
    
}

+ (NSArray *)allPropertyNames
{
    
    unsigned count;
    objc_property_t *properties = class_copyPropertyList([User class], &count);
    
    NSMutableArray *rv = [NSMutableArray array];
    
    unsigned i;
    for (i = 0; i < count; i++)
    {
        objc_property_t property = properties[i];
        NSString *name = [NSString stringWithUTF8String:property_getName(property)];
        [rv addObject:name];
    }
    
    free(properties);
    
    return rv;
}

+ (void) createUser:(void (^)(Response *))block withParameters:(User *) userParameters;{
    
    /*NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[self completeParametersNameToRequest:userParameters] options:kNilOptions error:&error];*/
    
    NSString *requestBodyString=[userParameters toJSONString];
    
    NSLog(@"JSON String: %@",requestBodyString);
    
    NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
    NSString *uri=@"/v1/user";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        Response *response;
        if(error)
            block(response);
        else{
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            response =[[Response alloc] init];
            response.statusCode=statusCode;
            response.responseBody=responseBody;
            response.responseBodyT=jsonDecode;
            block(response);
        }
        
    } body:requestBodyJSON andURI:uri];
    
}

+(void)getUser:(void (^)(Response *))block withUserGetParameters:(UserGetInformationParameters *)parameters{

    NSString *uri=@"/v1/user";

    NSLog(@"JSON String %@",[parameters toJSONString]);
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error)
            block(nil);
        else{
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            Response *res=[[Response alloc] init];
            res.statusCode=statusCode;
            res.responseBody=responseBody;
            res.responseBodyT=jsonDecode;
            block(res);
        }
        
    } parametersURL:[parameters toDictionary] andURI:uri];
}

+(void)updateUserInformation:(void (^)(Response *))block withParameters:(UserRefreshInformation *)parameters{
    
    NSString *uri=@"/v1/user";
    NSString *requestBodyString=[parameters toJSONString];
    
    NSLog(@"JSON String %@",requestBodyString);
    
    NSData *requestBodyJSON = [requestBodyString dataUsingEncoding:NSUTF8StringEncoding];
    
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error)
            block(nil);
        else{
            Response *res=[[Response alloc] init];
            res.statusCode=statusCode;
            block(res);
        }
        
    } body:requestBodyJSON andURI:uri];

}
@end
