//
//  AvailabilityResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "AvailabilityResources.h"

@implementation AvailabilityResources


+(void)userAvailability:(void (^)(Response *))block WithIdenty:(NSString *)identy{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:identy,@"identity",nil];
    NSString *uri=@"/v1/user/availability";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error == nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];
    
}
@end
