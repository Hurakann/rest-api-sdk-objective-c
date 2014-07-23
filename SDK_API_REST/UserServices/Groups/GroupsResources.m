//
//  GroupsResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "GroupsResources.h"

@implementation GroupsResources

+(void)createGroup:(void (^)(Response *))block WithBranchID:(NSString *)branch_id andName:(NSString *)name{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:branch_id,@"branch_id",name,@"name", nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/groups";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];

}

+(void)updateGroup:(void (^)(Response *))block WithParameters:(Group *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/groups";
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}

+(void)getGroupList:(void (^)(Response *))block WithBranchID:(NSString *)branch_id{
    
    
    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:branch_id,@"branch_id", nil];
    NSString *uri=@"/v1/groups";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"groups_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];
    
}

@end
