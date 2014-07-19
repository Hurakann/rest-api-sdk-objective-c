//
//  FingerprintResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "FingerprintResources.h"

@implementation FingerprintResources

+(void)matchFingerprint:(void (^)(Response *))block FMDRight:(NSString *)right FMDLeft:(NSString *)left{

    NSDictionary *dicParameters=[[NSDictionary alloc] initWithObjectsAndKeys:right,@"fmd_rigth",left,@"fmd_left", nil];
    NSString *uri=@"/v1/match/fingerprint";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:dicParameters andURI:uri];
    
}

+(void)verifyFingerprint:(void (^)(Response *))block withUserID:(NSString *)userID andID:(NSString *)identifier{

    NSDictionary *dicParameters=[[NSDictionary alloc] initWithObjectsAndKeys:userID,@"user_id",identifier,@"id", nil];
    NSString *uri=@"/v1/match/fingerprint";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:dicParameters andURI:uri];

}
@end
