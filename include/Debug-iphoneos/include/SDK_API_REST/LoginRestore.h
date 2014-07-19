//  LoginRestore.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import <Foundation/Foundation.h>
#import "Response.h"
#import "LoginRestoreParameters.h"
#import "ClientGET.h"

/**
 * The class is responsible for restore the password for a user account with email activated
 */
@interface LoginRestore : NSObject


/*!Sends an email with a recuperation code, the code is valid only for the next 48 hours
 *
 * \param a LoginRestoreParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginRestore:(void (^)(Response *))block withParameters:(LoginRestoreParameters *)parameters;

@end
