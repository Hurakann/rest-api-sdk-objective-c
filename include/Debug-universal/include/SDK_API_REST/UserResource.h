//  UserResource.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "User.h"
#import "ClientPOST.h"
#import "ClientGET.h"
#import "ClientPUT.h"
#import "UserGetInformationParameters.h"
#import "UserRefreshInformation.h"
#import <objc/runtime.h>

/**
 * The class is responsible for posting, getting, updating and deleting data
 *  of the user in the Hover system using the Hover API.
 */
@interface UserResource : NSObject

/*!Create a user in the Hover system using Hover API, the next attributes in the User class must be required, not null:
 *  branch_id, user_id, profile_id, phase, coloruser
 *
 * \param userInformation class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+ (void) createUser:(void (^)(Response *))block withParameters:(User *) userParameters;


/*!Get the user info on a specific phase using the Hover API.
 *
 * \param userGetInformationParameters object. This class contains basic parameters to get information about user
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+ (void) getUser:(void (^)(Response *))block withUserGetParameters:(UserGetInformationParameters *)parameters;


/*!Update user information and related data
 *
 * \param UserRefreshInfromation object. This class contains basic parameters to update information about user
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+ (void) updateUserInformation:(void (^)(Response *))block withParameters:(UserRefreshInformation *)parameters;
@end
