//  UserResourceSearch.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserResourceSearch.h"

@implementation UserResourceSearch

+(void)searchUser:(void (^)(Response *))block WithParameters:(UserSearch *)searchParameters{

    NSString *uri=@"user/search";
    //SharedData *instance=[SharedData instance];
    NSMutableDictionary *paramsSend=[[NSMutableDictionary alloc] init];
    paramsSend=[[searchParameters toDictionary] mutableCopy];
    //NSArray *keys=[paramsSend allKeys];
    
    if([[paramsSend objectForKey:@"pagination"] intValue] == 0)
        [paramsSend removeObjectForKey:@"pagination"];
    
    if([[paramsSend objectForKey:@"page"] intValue] == 0)
        [paramsSend removeObjectForKey:@"page"];
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        Response *res=[[Response alloc] init];
        res.statusCode=statusCode;
        
        if(responseBody!=nil){
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            res.responseBody=responseBody;
            res.responseBodyT=jsonDecode;
        }else{
            res.responseBody=nil;
            res.responseBodyT=nil;
        }
        
        block(res);
        
    } parametersURL:paramsSend andURI:uri];

}

+(void)searchUser:(void (^)(Response *))block ByNFC:(NSString *)nfc_id{

    NSDictionary *params =[[NSDictionary alloc] initWithObjectsAndKeys:nfc_id,@"nfc_id", nil];
    NSString *uri=@"search/nfc";
    
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
        
    } parametersURL:params andURI:uri];

}

@end
