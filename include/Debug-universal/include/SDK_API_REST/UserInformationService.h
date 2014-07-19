//  UserInformationService.h
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
 * POJO class for UserInformationService json structure based on API responses.
 */
@protocol ServiceProtocol @end

@interface UserInformationService : JSONModel

/** Activation date of the service (format YYYY-MM-DD) */
@property (nonatomic, strong) NSString <Optional> *activationDate;
/** Status for the service (true or false) */
@property (nonatomic, strong) NSString <Optional> *status;
/** Expiration date of the service (format YYYY-MM-DD) */
@property (nonatomic, strong) NSString <Optional> *expirationDate;
/** Validity for the service (yearly, monthly, so on ...) */
@property (nonatomic, strong) NSString <Optional> *validity;
/** The id of the service in which user could be assigned */
@property (nonatomic, strong) NSString <Optional> *serviceId;
/** The user id that could be assigned to the service */
@property (nonatomic, strong) NSString <Optional> *userId;

/** The owner assigned to the service */
@property (nonatomic, strong) NSString <Optional> *owner;


/** The icon assigned to the service */
@property (nonatomic, strong) NSString <Optional> *iconUrl;
/** The name assigned to the service */
@property (nonatomic, strong) NSString <Optional> *name;
/** The identifier assigned to the service */
@property (nonatomic, strong) NSString <Optional> *identifier;

@end
