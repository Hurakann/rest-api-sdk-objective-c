//
//  MobileSend.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

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
