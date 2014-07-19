//
//  AvailabilityResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Response.h"
#import "ClientGET.h"

@interface AvailabilityResources : NSObject

/*!Check for the existence of a user through a unique and unrepeatable data, avoiding duplication of information
 *
 * \param NSString identy: Can be used as unique data: email, RFC, CURP, credit card, etc...
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) userAvailability:(void (^)(Response *))block WithIdenty:(NSString *) identy;


@end
