//
//  CatalogsResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "CatalogsResources.h"

@implementation CatalogsResources

+(void)getCountryList:(void (^)(Response *))block{

    NSString *uri=@"/v1/geo/country";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"countries_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:nil andURI:uri];
    
}

+(void)getEstatesList:(void (^)(Response *))block ByCountryID:(NSString *)country_id{

    NSString *uri=@"/v1/geo/estate";
    NSDictionary *parameters=[[NSDictionary alloc] initWithObjectsAndKeys:country_id,@"country_id", nil];
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"estates_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:parameters andURI:uri];

}

+ (void) getTownsList:(void (^)(Response *))block ByEstateID:(NSString *)estate_id TypeSite:(NSString *) type{


    NSString *uri=@"/v1/geo/town";
    NSDictionary *parameters=[[NSDictionary alloc] initWithObjectsAndKeys:estate_id,@"estate_id",type,@"type_site", nil];
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:nil];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"towns_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:parameters andURI:uri];
    
}

@end
