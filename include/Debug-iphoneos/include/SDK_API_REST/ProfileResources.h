//
//  ProfileResources.h
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
#import "Profile.h"
#import "ClientPOST.h"
#import "ClientPUT.h"

@interface ProfileResources : NSObject


/*!To create a new profile are required the next parameters: user_id: id of the current user, parent user, name: name of the profile, based_on_id: id of base profile
 *
 * \param ProfileParameters object
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) createNewProfile:(void (^)(Response *))block WithInformation:(Profile *)info;


/*!Get a profiles list of user
 *
 * \param NSString branch_id: The profile of the user to register
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getProfilesList:(void (^)(Response *))block WithUserID:(NSString *)user_id;

/*!Update profile information
 *
 * \param NSString profile_id: Identifier to profile.
 * \param NSString name: Name to profile.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) updateProfile:(void (^)(Response *))block WithProfileID:(NSString *)profile_id AndProfileName:(NSString *)name;

@end
