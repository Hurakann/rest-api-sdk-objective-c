//
//  AvailabilityResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


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
