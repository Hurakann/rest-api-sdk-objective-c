//
//  MobileRegisterResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobileRegister.h"
#import "Response.h"
#import "ClientPOST.h"
#import "ClientPUT.h"

@interface MobileRegisterResources : NSObject

/*!Link a user with a mobile device so the mobile app using Hover API could receive native notifications. 
 *   The platform can be IOS or Android. All data are required.
 *
 * \param MobileRegisterParameters object.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) addMobileDeviceToUser:(void (^)(Response *))block WithParameters:(MobileRegister *)parameters;

/*!Disable or enable the status of the mobile device, indicating that user can receive notifications or not. 
 *  All data are required.
 *
 * \param NSString user_id: User id to current user.
 * \param NSString token: Token to mobile register.
 * \param NSString status: Status to mobile.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) updateMobileDevice:(void (^)(Response *))block ToUserID:(NSString *)user_id Token:(NSString *)token WithStatus:(NSString *) status;

@end
