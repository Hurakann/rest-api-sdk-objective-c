//  MobileRegister.h
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
 * POJO class for MobileResgister information json structure based on API request.
 */
@interface MobileRegister : JSONModel

/** User id of current user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** Branch id of current user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Broot id of current user */
@property (nonatomic, strong) NSString <Optional> *broot;
/** Token to assign */
@property (nonatomic, strong) NSString <Optional> *token;
/** Status for this asignation*/
@property (nonatomic, strong) NSString <Optional> *status;
/** Platform of device (Android, iOS !!, etc.) */
@property (nonatomic, strong) NSString <Optional> *platform;


@end
