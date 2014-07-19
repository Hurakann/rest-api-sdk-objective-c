//  UserResourceServices.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "UserInformationService.h"
#import "ClientGET.h"
#import "ClientPUT.h"
#import "ClientPOST.h"

/**
 * The class is responsible for posting, getting, updating and deleting data of
 * the user services in the Hover system using the Hover API.
 */
@interface UserResourceServices : NSObject


/*!Assign a user into a new service
 *
 * \param UserInformationService object contains datas, parameteres are required are: 
 *        service_id: The id of the service to assign,
 *        user_id: The user id to assign into service,
 *        status: The status for the service, can be true or false.
 *
 * \return a Response instance with the http status code and the body decoded as json and in a class translation,
 *          is returned on given completion handler.
*/
+ (void) assignUserByService:(void (^)(Response *))block withParameters:(UserInformationService *) userServiceParameters;


/*!Update information service assigned to the user, you must send only parameters to change.
 *
 * \param UserInformationService object contains datas, parameteres are required are:  
 *        service_id: The id of the service to assign,
 *        user_id: The user id to assign into service,
 *        status: The status for the service, can be true or false
 *
 * \return a Response instance with the http status code, is returned on given completion handler.
 *
 */
+ (void) updateUserService:(void (^)(Response *))block withParameters:(UserInformationService *) userServiceParameters;


/*!Get service(s) assigned to the user,  check if user has assigned a specific service or if user is owner of the service
 *
 * \param UserInformationService object contains datas, parameteres are required are: user_id: The user id to assign into service.
 *
 *
 * \return a Response instance with the http status code, is returned on given completion handler.
 *
 */
+ (void) getUserService:(void (^)(Response *))block withParameters:(UserInformationService *) userServiceParameters;
@end
