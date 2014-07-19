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
@property (nonatomic, strong) NSString *userId;
/** old password to your account */
@property (nonatomic, strong) NSString *oldPassword;
/** new password to user account */
@property (nonatomic, strong) NSString *nPassword;

@end
