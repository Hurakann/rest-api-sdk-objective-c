//
//  HoverBoxResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "HoverBoxResources.h"

@implementation HoverBoxResources

+(void)activateHoverBox:(void (^)(Response *))block WithParameters:(HoverBox *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/hoverbox";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}

+(void)getHoverBoxes:(void (^)(Response *))block WithBranchID:(NSString *)branch_id{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:branch_id,@"branch_id",nil];
    NSString *uri=@"/v1/user/hoverboxes";

    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
    
    } parametersURL:params andURI:uri];
    
}

+ (void) getNetworkConfiguration:(void (^)(Response *))block WithHoverBox:(NSString *) hover AndLink:(NSString *)link{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:hover,@"hoverbox",link,@"link", nil];
    NSString *uri=@"/v1/user/hoverboxnet";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];
    
}

+(void)getStaticsOf:(void (^)(Response *))block HoverBox:(NSString *)hover{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:hover,@"hoverbox", nil];
    NSString *uri=@"/v1/user/hoverboxestats";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];

}

@end
