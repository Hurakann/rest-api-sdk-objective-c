//
//  UserTagsResource.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

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
+ (void) postUserTags:(void (^)(Response *))block withUserID:(NSString *) userId AndTags:(NSArray *)tags;


/*!All data are required, the tags is an array of strings, and you could customize as you want.
 *
 * \param NSString user_id: user_id to user.
 * \param NSArray tags: tags for user.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) putUserTags:(void (^)(Response *))block withUserID:(NSString *) userId AndTags:(NSArray *)tags;


/*!Get specific features of the user
 *
 * \param NSString user_id: user_id to user.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) getUserTags:(void (^)(Response *))block withUserID:(NSString *) userId;

@end
