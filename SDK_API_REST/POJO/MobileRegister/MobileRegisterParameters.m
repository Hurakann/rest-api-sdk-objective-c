//
//  MobileRegisterParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "MobileRegisterParameters.h"

@implementation MobileRegisterParameters

+(JSONKeyMapper*)keyMapper
{
    return [JSONKeyMapper mapperFromUnderscoreCaseToCamelCase];
}

@end
