//
//  UserPhoneExtensionResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

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
