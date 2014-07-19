//  Login.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "LoginParameters.h"
#import "SharedData.h"
#import "Response.h"
#import "ClientGET.h"

/**
 * The class is responsible for trying login
 * of the user in the Hover system using the Hover API.
 */
@interface Login : NSObject

/*!Try user login, if it's successfully get the basic user info using the Hover API.
 *
 * \param a LoginParameters object, that contains a basic parameters (username and password) for login.
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *         is returned on given completion handler.
 */
+ (void)getLogin:(void (^)(Response *))block withParameters:(LoginParameters *)parameters;

@end
