//
//  UserPhoneExtensionResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserPhoneExtensionResources.h"

@implementation UserPhoneExtensionResources

+(void)getUserPhoneExtension:(void (^)(Response *))block withBranchID:(NSString *)branchID{

    NSDictionary *dicParameters=[[NSDictionary alloc] initWithObjectsAndKeys:branchID,@"branch_id", nil];
    NSString *uri=@"/v1/user/phone/extension";
    
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
