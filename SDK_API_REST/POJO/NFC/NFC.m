//
//  NFC.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "NFC.h"

@implementation NFC

+(BOOL)propertyIsOptional:(NSString *)propertyName{
    
    if ([propertyName isEqualToString: @"status"]) return YES;
    return NO;
    
}

@end
