//
//  UserMergeResources.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "Merge.h"
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "ClientGET.h"

@interface UserMergeResources : NSObject

/*!Merge users for avoid duplicates, selecting by similiarities, one of the user must be the main user, the rest of users are merge. If a user is not merge with another then the state of merge is free. All data are required.
 *      branch_id, main_user_id, users_id
 *
 * \param MergeParameters class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) mergeUsers:(void (^)(Response *))block withParameters:(Merge *) userParameters;

/*!You can use this resource to change the main user in a group of merged users, for delete or append a user in the same group.
 *  The optional data is:
 *  new_main_user_id: The new main user of the merge group
 *
 * \param MergeParameters class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code, is returned on given completion handler.
 */
+ (void) changeMainUser:(void (^)(Response *))block OfMergedUsers:(Merge *) userParameters;


/*!To obtain the merge users information is necessary user_id parameter.
 *
 * \param NSString user_id : current user_id
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *         is returned on given completion handler.
 */
+ (void) getMergeUsersInformation:(void (^)(Response *))block withUserID:(NSString *) user_id;

@end
