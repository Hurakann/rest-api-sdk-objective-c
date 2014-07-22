//
//  LoginChangePasswordParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 02/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for channge password to login based on API responses.
 */
@interface LoginChangePasswordParameters : JSONModel

/** Id for this user */
@property (nonatomic, strong) NSString *userI_id;
/** old password to your account */
@property (nonatomic, strong) NSString *old_password;
/** new password to user account */
@property (nonatomic, strong, getter = nPassword) NSString *new_password;

@end
