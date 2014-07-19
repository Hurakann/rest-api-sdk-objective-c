//
//  Profile.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "Profile.h"

@implementation Profile


+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"id"]) return YES;
    return NO;
    
}

@end
