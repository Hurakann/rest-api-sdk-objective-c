//
//  UserService.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for User services information on json structure based on API request.
 */
@interface UserService : JSONModel

/** Activation date of the service (format YYYY-MM-DD) */
@property (nonatomic, strong) NSString <Optional> *activation_date;
/** Status for the service (true or false) */
@property (nonatomic, strong) NSString <Optional> *status;
/** Expiration date of the service (format YYYY-MM-DD) */
@property (nonatomic, strong) NSString <Optional> *expiration_date;
/** Validity for the service (yearly, monthly, so on ...) */
@property (nonatomic, strong) NSString <Optional> *validity;
/** The id of the service in which user could be assigned */
@property (nonatomic, strong) NSString <Optional> *service_id;
/** The user id that could be assigned to the service */
@property (nonatomic, strong) NSString <Optional> *user_id;

/** The owner assigned to the service */
@property (nonatomic, strong) NSString <Optional> *owner;


/** The icon assigned to the service */
@property (nonatomic, strong) NSString <Optional> *icon_url;
/** The name assigned to the service */
@property (nonatomic, strong) NSString <Optional> *name;
/** The identifier assigned to the service */
@property (nonatomic, strong) NSString <Optional> *identifier;

@end

@protocol ServiceProtocol ;