//
//  UserColorResource.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserColorResource.h"

@implementation UserColorResource

+ (void) userIsColor:(void (^)(Response *))block withEmail:(NSString *) email AndColor:(NSString *)color{

    NSDictionary *dicParams=[[NSDictionary alloc] initWithObjectsAndKeys:email,@"email",color,@"color", nil];
    NSString *uri=@"/v1/user/is_color";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            Response *resp=[[Response alloc] init];
            resp.responseBody=responseBody;
            resp.statusCode=statusCode;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:dicParams andURI:uri];
}
@end
