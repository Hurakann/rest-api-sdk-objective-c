//
//  UserCreateParametersResponse.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

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
