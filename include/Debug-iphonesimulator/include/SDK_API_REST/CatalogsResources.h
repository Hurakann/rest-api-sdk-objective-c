//
//  CatalogsResources.h
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

@interface CatalogsResources : NSObject


/*!To get list of countries is not required any parameter
 *
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation
 *   is returned on given completion handler.
 */
+ (void) getCountryList:(void (^)(Response *))block ;


/*!To get list of estates is required to choose a country
 *
 * \param NSString country_id: The id of the country
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation
 *   is returned on given completion handler.
 */
+ (void) getEstatesList:(void (^)(Response *))block ByCountryID:(NSString *)country_id;


/*!To get list of towns is required to choose a estate
 *
 * \param NSString estate_id: The id of the estate
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation
 *   is returned on given completion handler.
 */
+ (void) getTownsList:(void (^)(Response *))block ByEstateID:(NSString *)estate_id TypeSite:(NSString *) type;
@end
