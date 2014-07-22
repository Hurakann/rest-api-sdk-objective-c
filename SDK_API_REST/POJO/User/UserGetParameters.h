//
//  UserGetParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "User.h"
#import "Profile.h"
#import "PhaseEditedParameters.h"

/**
 * POJO class for UserParameters json structure based on API responses.
 */
@interface UserGetParameters : JSONModel


/** Branch id for the parent user (owner of the user) */
@property (nonatomic, strong) NSString *branch_id;
/** User id of the parent user */
@property (nonatomic, strong) NSString *user_id;
/** Phase to keep the user (1, 2, 3 or 4) */
@property (nonatomic, strong) NSString *phase;


@end

@protocol UserGetParameters;
