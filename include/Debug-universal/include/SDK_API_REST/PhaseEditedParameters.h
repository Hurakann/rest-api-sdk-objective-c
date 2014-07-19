//
//  PhaseEditedParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface PhaseEditedParameters : JSONModel

/** Branch id of user was edit*/
@property (nonatomic, strong) NSString <Optional> *branchId;
/** Name of user was edit*/
@property (nonatomic, strong) NSString <Optional> *name;

@end
