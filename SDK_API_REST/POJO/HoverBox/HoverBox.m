//
//  HoverBox.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "HoverBox.h"

@implementation HoverBox

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"flush"]) return YES;
    return NO;
    
}

@end
