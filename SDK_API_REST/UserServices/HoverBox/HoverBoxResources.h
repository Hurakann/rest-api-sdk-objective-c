//
//  HoverBoxResources.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "HoverBox.h"
#import "Response.h"
#import "ClientPOST.h"
#import "ClientGET.h"

@interface HoverBoxResources : NSObject

/*!Active message reception on websocket
 *
 * \param HoverBoxParameters object
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) activateHoverBox:(void (^)(Response *))block WithParameters:(HoverBox *) parameters;


/*!To get list of hoverboxes is required the blue user branch_id
 *
 * \param NSString branch_id: The user_id of the registered user
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getHoverBoxes:(void (^)(Response *))block WithBranchID:(NSString *) branch_id;


/*!Obtain information about the network configuration of hover box
 *
 * \param NSString hoverbox: Hoverbox Id which requires statistical
 * \param NSString link: Port conexion ethernet
 * 
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getNetworkConfiguration:(void (^)(Response *))block WithHoverBox:(NSString *) hover AndLink:(NSString *)link;


/*!Show use statistics of hoverbox
 *
 * \param NSString hoverbox: Hoverbox Id which requires statistical
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getStaticsOf:(void (^)(Response *))block HoverBox:(NSString *) hover;

@end
