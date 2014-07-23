//
//  UserUpdateParameters.h
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
 * POJO class for update user information and related data in json structure based on API responses.
 */
@interface UserUpdateParameters : JSONModel

/** Branch id for the parent user (owner of the user) */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** User id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;


@end
