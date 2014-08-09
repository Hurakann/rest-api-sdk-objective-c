//  Notification.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "JSONModel.h"
#import <Foundation/Foundation.h>

/**
 * POJO class for Notification information json structure based on HOVER API request.
 */
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
