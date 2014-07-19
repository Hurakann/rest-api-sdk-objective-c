//
//  NotificationsResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "NotificationsResources.h"

@implementation NotificationsResources

+(void)createNewNotification:(void (^)(Response *))block WithParameters:(NotificationsParameters *) params{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[params toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/notifications";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}

+(void)updateNotification:(void (^)(Response *))block WithNotificationId:(NSString *)notifyId statusRead:(BOOL)read{

    NSNumber *isRead=[NSNumber numberWithBool:read];
    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:notifyId,@"notification_id",isRead,@"read",nil];
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/notifications";
    
    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];

    
}


+(void)getAllNotifications:(void (^)(Response *))block WithBranchID:(NSString *)branch_id{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:branch_id,@"branch_id",nil];
    NSString *uri=@"/v1/user/notifications";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error == nil){
            NSArray *array = [NSKeyedUnarchiver unarchiveObjectWithData:responseBody];
            NSDictionary *dic=[[NSDictionary alloc] initWithObjectsAndKeys:array,@"notifications_list", nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=dic;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];
    
}

+(void)getSpecificNotification:(void (^)(Response *))block WithBranchID:(NSString *)branch_id NotificationID:(NSString *)notifyID{

    NSDictionary *params=[[NSDictionary alloc] initWithObjectsAndKeys:branch_id,@"branch_id",notifyID,@"notification_id",nil];
    NSString *uri=@"/v1/user/notifications";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
        
        if(error == nil){
            NSDictionary *jsonObject=[NSJSONSerialization JSONObjectWithData:responseBody options:NSJSONReadingMutableLeaves error:nil];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonObject;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:params andURI:uri];

}


@end
