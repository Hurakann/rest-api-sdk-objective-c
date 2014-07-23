//
//  UserPhoneExtensionResources.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "ClientGET.h"
#import "Response.h"

@interface UserPhoneExtensionResources : NSObject


/*!Assign a valid extension to the user for make video calls with other users using extensions.
 *
 * \param branch_id: The branch_id of the user
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *   is returned on given completion handler.
 */
+ (void) getUserPhoneExtension:(void (^)(Response *))block withBranchID:(NSString *) branchID;


@end
