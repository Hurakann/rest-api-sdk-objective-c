//
//  PhoneExtension.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Phone Extension information json structure based on HOVER API request.
 */
@interface PhoneExtension : JSONModel

/** Secret password */
@property (nonatomic, strong) NSString <Optional> *pass;
/** IP direction to r5 */
@property (nonatomic, strong) NSString <Optional> *r5;
/** IP direction to freeswitch */
@property (nonatomic, strong) NSString <Optional> *freeswitch;
/** Name extension */
@property (nonatomic, strong) NSString <Optional> *extension;

@end
