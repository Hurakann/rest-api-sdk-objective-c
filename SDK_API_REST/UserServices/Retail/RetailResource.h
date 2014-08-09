//
//  RetailResource.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 30/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClientGET.h"
#import "Response.h"

@interface RetailResource : NSObject

/*!Get retails fro beacon
 *
 * \param NSStrign estimote: user_id for estimote
 * \param NSStrign status: status
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getRetails:(void (^)(Response *))block ForEstimote:(NSString *)estimote withStatus:(NSString *)status;

@end
