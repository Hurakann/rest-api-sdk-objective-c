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

+(NSDictionary *) completeParametersWithParameters:(NSDictionary *) params AndClass:(Class) clase{
    
    NSArray *keysInObject=[params allKeys];
    NSArray *properties = [self allPropertyNamesOfClass:[clase class]];
    
    NSMutableDictionary *mutDic=[[NSMutableDictionary alloc] init];

    for(int x=0; x<keysInObject.count; x++){
        
        if(!([properties containsObject:[keysInObject objectAtIndex:x]])){
            [mutDic setObject:[params objectForKey:[keysInObject objectAtIndex:x]] forKey:[NSString stringWithFormat:@"_%@",[keysInObject objectAtIndex:x]]];
        }else
            [mutDic setObject:[params objectForKey:[keysInObject objectAtIndex:x]] forKey:[keysInObject objectAtIndex:x]];
        
    }
    
    return mutDic;
}

+ (NSArray *)allPropertyNamesOfClass:(Class) className{
    
    unsigned count;
    objc_property_t *properties=class_copyPropertyList([className class], &count);;
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
    
    NSString *uri=@"/v1/user";
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[self completeParametersWithParameters:[userParameters toDictionary] AndClass:[User class]] options:kNilOptions error:&error];

    NSLog(@"JSON String %@",[[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding]);
    
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
        
    } body:jsonData andURI:uri];
    
}

+(void)getUser:(void (^)(Response *))block withUserGetParameters:(UserGetParameters *)parameters{

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

+(void)updateUserInformation:(void (^)(Response *))block withParameters:(UserUpdateParameters *)parameters{
    
    NSString *uri=@"/v1/user";
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[self completeParametersWithParameters:[parameters toDictionary] AndClass:[UserUpdateParameters class]] options:kNilOptions error:&error];
    
    NSLog(@"JSON String %@",[[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding]);
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error)
            block(nil);
        else{
            Response *res=[[Response alloc] init];
            res.statusCode=statusCode;
            block(res);
        }
    } body:jsonData andURI:uri];

    
}
@end
