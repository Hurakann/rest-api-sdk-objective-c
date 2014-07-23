//  MobileSend.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import "MobileSend.h"

@implementation MobileSend

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"expiry"] || [propertyName isEqualToString:@"identifier"]) return YES;
    return NO;
    
}

@end
