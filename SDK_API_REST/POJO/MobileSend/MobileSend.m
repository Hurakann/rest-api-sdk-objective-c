//
//  MobileSend.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "MobileSend.h"

@implementation MobileSend

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"expiry"] || [propertyName isEqualToString:@"identifier"]) return YES;
    return NO;
    
}

@end
