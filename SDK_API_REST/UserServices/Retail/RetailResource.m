//
//  RetailResource.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 30/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "RetailResource.h"

@implementation RetailResource

+(void)getRetails:(void (^)(Response *))block ForEstimote:(NSString *)estimote withStatus:(NSString *)status{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:estimote,@"estimote",status,@"status", nil];
    NSString *uri=@"retail";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            NSError *error;
            NSArray *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:jsonDecode,@"reatils_list", nil];
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
