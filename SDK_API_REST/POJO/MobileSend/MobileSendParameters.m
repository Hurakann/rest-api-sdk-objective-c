//
//  MobileSendParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "MobileSendParameters.h"

@implementation MobileSendParameters
+(JSONKeyMapper*)keyMapper
{
    return [JSONKeyMapper mapperFromUnderscoreCaseToCamelCase];
}

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"expiry"] || [propertyName isEqualToString:@"identifier"]) return YES;
    return NO;
    
}

@end
