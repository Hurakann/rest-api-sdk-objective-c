//
//  NotificationParametersResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

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
