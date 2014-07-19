//
//  MobileSendResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobileSendParameters.h"
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
+ (void) sendNativeNotification:(void (^)(Response *))block WithParameters:(MobileSendParameters *)parameters;


@end
