//
//  ConfirmRegisterResource.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 14/10/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConfirmRegister.h"
#import "Response.h"
#import "SharedData.h"

@interface ConfirmRegisterResource : NSObject

/*!Create a user in the Hover system using Hover API, the next attributes in the User class must be required, not null:
 *  branch_id, user_id, profile_id, phase, coloruser
 *
 * \param userInformation class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+(void)confirmRegister:(void (^)(Response *))block withInfo:(ConfirmRegister *)confirm ToServer:(NSString *)server AndURI:(NSString *) uri;


@end
