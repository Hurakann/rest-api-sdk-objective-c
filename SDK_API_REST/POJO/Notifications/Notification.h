//
//  Notification.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "JSONModel.h"
#import <Foundation/Foundation.h>

@interface Notification : JSONModel

/** Message for notification */
@property (nonatomic, strong) NSString <Optional> *message;
/** Branch id of parent user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Broot of user */
@property (nonatomic, strong) NSString <Optional> *broot;
/** Title for notification */
@property (nonatomic, strong) NSString <Optional> *title;

@end
