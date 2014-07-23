//
//  NFCResources.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "NFCResources.h"

@implementation NFCResources

+(void)assignNFCtoUser:(void (^)(Response *))block withParameters:(NFC *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/nfc_card";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];

}

+(void)updateNFCtoUser:(void (^)(Response *))block withParameters:(NFC *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/nfc_card";

    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}

+(void)getNFCtoUser:(void (^)(Response *))block withUserID:(NSString *)userId{

    NSDictionary *param=[[NSDictionary alloc] initWithObjectsAndKeys:userId,@"user_id", nil];
    NSString *uri=@"/v1/user/nfc_card";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSArray *array=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *jsonDecode=[[NSDictionary alloc] initWithObjectsAndKeys:array,@"nfcCards_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:param andURI:uri];
    
}
@end
