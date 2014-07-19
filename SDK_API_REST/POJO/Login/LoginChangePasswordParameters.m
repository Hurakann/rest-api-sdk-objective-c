//
//  LoginChangePasswordParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 02/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "LoginChangePasswordParameters.h"

@implementation LoginChangePasswordParameters

+(JSONKeyMapper*)keyMapper
{
    return [JSONKeyMapper mapperFromUnderscoreCaseToCamelCase];
}

@end
