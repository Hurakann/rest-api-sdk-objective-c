//
//  AvailabilityResources.h
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

@interface AvailabilityResources : NSObject

/*!Check for the existence of a user through a unique and unrepeatable data, avoiding duplication of information
 *
 * \param NSString identy: Can be used as unique data: email, RFC, CURP, credit card, etc...
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) userAvailability:(void (^)(Response *))block WithIdentity:(NSString *) identy;


@end
