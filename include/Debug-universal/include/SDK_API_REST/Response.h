//  Response.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>

/**
 * HTTP Code and Body as the API responses on the requested resource.
 */
@interface Response : NSObject

/** Status code of petition */
@property (assign) NSInteger statusCode;
/** Response body of petition */
@property (nonatomic, strong) NSData *responseBody;
/** Response body to translate class */
@property (nonatomic, strong) NSDictionary *responseBodyT;

@end
