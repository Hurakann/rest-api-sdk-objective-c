//
//  UserGetParametersResponse.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "UserGetParametersResponse.h"

@implementation UserGetParametersResponse

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"fmd"]) return YES;
    return NO;
    
}

@end
