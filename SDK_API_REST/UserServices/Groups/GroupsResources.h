//
//  GroupsResources.h
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
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "Group.h"

@interface GroupsResources : NSObject

/*!Assigns the user to a group
 *
 * \param NSString branch_id: The branch_id for group
 * \param NSString name: The name for group
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) createGroup:(void (^)(Response *))block WithBranchID:(NSString *)branch_id andName:(NSString *) name;


/*!Update the status of the group
 *
 * \param GroupParameters object.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) updateGroup:(void (^)(Response *))block WithParameters:(Group *)parameters ;


/*! Obtain the groups list of user
 *
 * \param NSString branch_id: The branch_id for group
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation
 *   is returned on given completion handler.
 */
+ (void) getGroupList:(void (^)(Response *))block WithBranchID:(NSString *)branch_id;

@end
