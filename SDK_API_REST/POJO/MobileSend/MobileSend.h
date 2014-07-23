//  MobileSend.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"


/**
 * POJO class for MobileSend information json structure based on API request.
 */
@interface MobileSend : JSONModel

/** All users id's  */
@property (nonatomic, strong) NSArray <Optional> *users_d;
/** Payloads */
@property (nonatomic, strong) NSArray <Optional> *payload;
/** Expiry */
@property (assign) int expiry;
/** Identifier */
@property (assign) int identifier;

@end
