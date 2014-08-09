//
//  NFC.h
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
 * POJO class for NFC information json structure based on HOVER API request.
 */
@interface NFC : JSONModel

/** The id of the nfc card */
@property (nonatomic, strong) NSString <Optional> *nfc_id;
/** The id of the user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** status for nfc card, can be true or false */
@property (nonatomic) BOOL status;
/** Services to NFC */
@property (nonatomic, strong) NSArray <Optional> *services;
/** Delivery date to NFC  */
@property (nonatomic, strong) NSString <Optional> *delivery_date;
/** Renewal to NFC */
@property (nonatomic, strong) NSString <Optional> *renewal;
/** Cost to NFC */
@property (nonatomic, strong) NSString <Optional> *cost;
/** Validuty to NFC */
@property (nonatomic, strong) NSString <Optional> *validity;

@end

@protocol NFCProtocol;