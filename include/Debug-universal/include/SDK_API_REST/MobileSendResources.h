//
//  MobileSendResources.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "MobileSend.h"
#import "Response.h"
#import "ClientPOST.h"

@interface MobileSendResources : NSObject

/*!Send native notifications to a mobile devices already linked to users, All data are required.
 *
 * \param MobileSendParameters object.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) sendNativeNotification:(void (^)(Response *))block WithParameters:(MobileSend *)parameters;


@end
