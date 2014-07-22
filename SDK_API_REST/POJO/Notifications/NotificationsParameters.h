//
//  NotificationsParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface NotificationsParameters : JSONModel

/** Message for notification */
@property (nonatomic, strong) NSString <Optional> *message;
/** Branch id of parent user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Broot of user */
@property (nonatomic, strong) NSString <Optional> *broot;
/** Title for notification */
@property (nonatomic, strong) NSString <Optional> *title;

@end
