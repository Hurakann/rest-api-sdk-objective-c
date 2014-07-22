//
//  NFCResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NFC.h"
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "ClientGET.h"
#import "Response.h"

@interface NFCResources : NSObject

/*!Assign NFC card to the user and link to services if you need, the nfc provides access to system using it.
 *  The next are the required data: nfc_id, user_id, status
 *
 * \param NFCParameters object.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) assignNFCtoUser:(void (^)(Response *))block withParameters:(NFC *) parameters;


/*!Update information and services on assigned nfc card to the user. You must send only parameters to change
 *  The next are the required data: nfc_id, user_id, status
 *
 * \param NFCParameters object.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) updateNFCtoUser:(void (^)(Response *))block withParameters:(NFC *) parameters;


/*!Get information about nfc card assigned to the user. The next parameters are required.
 *  The next are the required data: user_id.
 *
 * \param NFCParameters object.
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) getNFCtoUser:(void (^)(Response *))block withUserID:(NSString *) userId;

@end
