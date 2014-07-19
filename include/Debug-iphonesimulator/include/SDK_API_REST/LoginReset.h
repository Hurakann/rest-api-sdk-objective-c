//  LoginReset.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import <Foundation/Foundation.h>
#import "Response.h"
#import "LoginResetParameters.h"
#import "ClientPOST.h"

/**
 * The class is responsible for reset the password of the user account using a valid recuperation code
 */
@interface LoginReset : NSObject

/*!Reset the password using the recuperation code sent to the user email, the code must be valid to change the password
 *
 * \param a LoginResetParameters object.
 *
 * \return a response instance with the http status code is returned on given completion handler.
 */
+ (void)loginReset:(void (^)(Response *))block withParameters:(LoginResetParameters *)parameters;

@end
