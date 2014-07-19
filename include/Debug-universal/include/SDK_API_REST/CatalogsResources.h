//
//  CatalogsResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

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
