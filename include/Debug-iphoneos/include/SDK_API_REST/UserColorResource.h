//
//  UserColorResource.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "ClientGET.h"

@interface UserColorResource : NSObject

/*!This resource retrieves the branch id of the user if the comparison is successfully.
 *
 * \param NSString color: color to check, could be blue or black.
 * \param NSString email: user email.
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+ (void) userIsColor:(void (^)(Response *))block withEmail:(NSString *) email AndColor:(NSString *)color;

@end
