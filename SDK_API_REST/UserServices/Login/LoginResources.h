//
//  LoginResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Login.h"
#import "LoginChangePasswordParameters.h"
#import "LoginResetParameters.h"
#import "Response.h"
#import "ClientGET.h"
#import "ClientPOST.h"
#import "ClientPUT.h"

@interface LoginResources : NSObject


/*!Try user login, if it's successfully get the basic user info using the Hover API.
 *
 * \param a LoginParameters object, that contains a basic parameters (username and password) for login.
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *         is returned on given completion handler.
 */
+ (void)getLogin:(void (^)(Response *))block withParameters:(Login *)parameters;


/*!Sends an email with a recuperation code, the code is valid only for the next 48 hours
 *
 * \param a LoginRestoreParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginRestore:(void (^)(Response *))block withUserEmail:(NSString *) email;

/*!Change the password for the user account, the previous password must be provided for safety reasons
 *
 * \param a LoginChangePasswordParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginChangePassword:(void (^)(Response *))block withParameters:(LoginChangePasswordParameters *)parameters;

/*!Reset the password using the recuperation code sent to the user email, the code must be valid to change the password
 *
 * \param a LoginResetParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginReset:(void (^)(Response *))block withParameters:(LoginResetParameters *)parameters;
@end
