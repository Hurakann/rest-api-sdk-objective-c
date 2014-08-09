//  NotificationParametersResponse.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Notification Parameters Response information json structure based on HOVER API response.
 */
@interface NotificationParametersResponse : JSONModel

/** Title for notification */
@property (nonatomic, strong) NSString <Optional> *title;
/** Status of notification */
@property (nonatomic, assign) BOOL read;
/** Identifier for notification */
@property (nonatomic, strong) NSString <Optional> *notification_id;
/** Time for notification */
@property (nonatomic, strong) NSString <Optional> *time;
/** Date for notification */
@property (nonatomic, strong) NSString <Optional> *date;
/** Message for notification */
@property (nonatomic, strong) NSString <Optional> *message;


@end
