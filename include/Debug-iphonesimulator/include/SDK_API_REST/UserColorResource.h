//
//  UserColorResource.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

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
