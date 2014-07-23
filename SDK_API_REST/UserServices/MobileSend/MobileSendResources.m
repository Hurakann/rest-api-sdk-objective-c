//
//  MobileSendResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "MobileSendResources.h"

@implementation MobileSendResources

+(void)sendNativeNotification:(void (^)(Response *))block WithParameters:(MobileSend *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/mobile/send";

    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}
@end
