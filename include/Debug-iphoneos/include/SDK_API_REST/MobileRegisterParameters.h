//
//  MobileRegisterParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface MobileRegisterParameters : JSONModel

@property (nonatomic, strong) NSString <Optional> *userId;
@property (nonatomic, strong) NSString <Optional> *branchId;
@property (nonatomic, strong) NSString <Optional> *broot;
@property (nonatomic, strong) NSString <Optional> *token;
@property (nonatomic, strong) NSString <Optional> *status;
@property (nonatomic, strong) NSString <Optional> *platform;

@end
