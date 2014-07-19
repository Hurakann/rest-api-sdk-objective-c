//
//  UserGetParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserGetParameters.h"

@implementation UserGetParameters

+(BOOL)propertyIsOptional:(NSString *)propertyName{

    if ([propertyName isEqualToString: @"fmd"]) return YES;
    return NO;
    
}

@end
