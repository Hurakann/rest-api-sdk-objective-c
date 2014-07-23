//  UserResourceSearch.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "UserSearch.h"
#import "ClientGET.h"

/**
 * The class is responsible for getting data of the user in the Hover system
 * using the Hover API via riak search.
 */
@interface UserResourceSearch : NSObject


/*!Find all users matching the incoming data set
   \param UserInformationSearch object. Contains basics datas to find a user
   \return a response instance with the http status code and the body decoded as json and in a class translation,
        is returned on given completion handler.
 */
+ (void) searchUser:(void (^)(Response *))block WithParameters:(UserSearch *) searchParameters;

/*!Search a user by nfc card, the response is the same as user search resource, but the total results is always 1.
 *
 * \param NSString nfc_id.
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *          is returned on given completion handler.
 */
+ (void) searchUser:(void (^)(Response *))block ByNFC:(NSString *) nfc_id;

@end
