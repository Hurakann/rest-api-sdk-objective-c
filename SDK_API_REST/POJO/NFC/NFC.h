//
//  NFC.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

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