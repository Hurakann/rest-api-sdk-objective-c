//  ClientPUT.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "SharedData.h"

/**
 * Creates a correct PUT HTTP request with a json encoded as a body.
 */
@interface ClientPUT : NSObject

/*!Execute the PUT HTTP request building previously with the attributes
 *  passed into this class constructor.
 *
 * \param query string to make request
 * \param uri to specific service
 *
 * \return status code, body response and if error exist this parameters will not nil. All of them is returned on given completion handler.
 */
+ (void)putRequestWithBODYParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block body:(NSData *)bodyParameters andURI:(NSString *)uri;


/*!Execute the PUT HTTP request building previously with the attributes
 *  passed into this class constructor.
 *
 * \param query string to make request
 * \param uri to specific service
 *
 * \return status code, body response and if error exist this parameters will not nil. All of them is returned on given completion handler.
 */
+ (void)putRequestWithBODYParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block body:(NSData *)bodyParameters ToServer:(NSString*)server andURI:(NSString *)uri;

@end
