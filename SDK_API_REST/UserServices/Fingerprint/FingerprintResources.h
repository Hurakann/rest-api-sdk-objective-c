//
//  FingerprintResources.h
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

@interface FingerprintResources : NSObject

/*!Use fingerprint to biometric verification using hoverbox or any device that supports read fingerprints. All paramas are required.
 *
 * \param NSString fmd_right: fingerprint right of the user
 * \param NSString fmd_left: fingerprint left of the user
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) matchFingerprint:(void (^)(Response *))block FMDRight:(NSString *)right FMDLeft:(NSString *)left;


/*!Verify the fingerprint of the user is already registered. All paramas are required.
 *
 * \param NSString user_id: The id of the user
 * \param NSString id: Fingerprint of the user
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) verifyFingerprint:(void (^)(Response *))block withUserID:(NSString *)userID andID:(NSString *)identifier;

@end
