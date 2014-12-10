//
//  UserGetParameters.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

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
