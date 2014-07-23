//
//  LoginChangePasswordParameters.h
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
 * POJO class for Login change password information json structure based on HOVER API request.
 */
@interface LoginChangePasswordParameters : JSONModel

/** Id for this user */
@property (nonatomic, strong) NSString *userI_id;
/** old password to your account */
@property (nonatomic, strong) NSString *old_password;
/** new password to user account */
@property (nonatomic, strong, getter = nPassword) NSString *new_password;

@end
