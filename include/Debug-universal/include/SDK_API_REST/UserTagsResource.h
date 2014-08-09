//
//  UserTagsResource.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "ClientGET.h"

@interface UserTagsResource : NSObject

/*!All data are required, the tags is an array of strings, and you could customize as you want.
 *
 * \param NSString user_id: user_id to user.
 * \param NSArray tags: tags for user.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) addTagsToUser:(void (^)(Response *))block WithUserID:(NSString *) userId AndTags:(NSArray *)tags;


/*!All data are required, the tags is an array of strings, and you could customize as you want.
 *
 * \param NSString user_id: user_id to user.
 * \param NSArray tags: tags for user.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) updateTagsToUser:(void (^)(Response *))block WithUserID:(NSString *) userId AndTags:(NSArray *)tags;


/*!Get specific features of the user
 *
 * \param NSString user_id: user_id to user.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) getUserTags:(void (^)(Response *))block withUserID:(NSString *) userId;

@end
