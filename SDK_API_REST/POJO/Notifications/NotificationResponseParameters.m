//
//  NotificationResponseParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "NotificationResponseParameters.h"

@implementation NotificationResponseParameters


+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"read"]) return YES;
    return NO;
    
}

@end
