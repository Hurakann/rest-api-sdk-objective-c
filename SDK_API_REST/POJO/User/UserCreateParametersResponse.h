//
//  UserCreateParametersResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface UserCreateParametersResponse : JSONModel

/** user id of the registered user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** if services tag is sent, then return i_services_resolved otherwise i_services_unresolved */
@property (nonatomic, strong) NSString <Optional> *i_services;
/** if nfc tag is sent, then return i_nfc_resolved otherwise i_nfc_unresolved */
@property (nonatomic, strong) NSString <Optional> *i_nfc;

@end
