//
//  UserPhoneExtensionResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserPhoneExtensionResources.h"

@implementation UserPhoneExtensionResources

+(void)getUserPhoneExtension:(void (^)(Response *))block withBranchID:(NSString *)branchID{

    NSDictionary *dicParameters=[[NSDictionary alloc] initWithObjectsAndKeys:branchID,@"branch_id", nil];
    NSString *uri=@"user/phone/extension";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else{
            block(nil);
        }
        
    } parametersURL:dicParameters andURI:uri];
    
}

@end
