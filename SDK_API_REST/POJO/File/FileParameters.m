//
//  FileParameters.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 10/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "FileParameters.h"

@implementation FileParameters
+(JSONKeyMapper*)keyMapper
{
    return [JSONKeyMapper mapperFromUnderscoreCaseToCamelCase];
}
@end
