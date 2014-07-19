//  LoginChangePassword.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "LoginChangePasswordParameters.h"
#import "ClientPOST.h"

/**
 * The class is responsible for change the password of the user account
 */
@interface LoginChangePassword : NSObject

/*!Change the password for the user account, the previous password must be provided for safety reasons
 *
 * \param a LoginChangePasswordParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginChangePassword:(void (^)(Response *))block withParameters:(LoginChangePasswordParameters *)parameters;

@end
