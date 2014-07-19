//
//  NFCParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"


@protocol NFCProtocol @end

@interface NFCParameters : JSONModel

/** The id of the nfc card */
@property (nonatomic, strong) NSString <Optional> *nfcId;
/** The id of the user */
@property (nonatomic, strong) NSString <Optional> *userId;
/** status for nfc card, can be true or false */
@property (assign) BOOL *status;
/** Services to NFC */
@property (nonatomic, strong) NSArray <Optional> *services;
/** Delivery date to NFC  */
@property (nonatomic, strong) NSString <Optional> *deliveryDate;
/** Renewal to NFC */
@property (nonatomic, strong) NSString <Optional> *renewal;
/** Cost to NFC */
@property (nonatomic, strong) NSString <Optional> *cost;
/** Validuty to NFC */
@property (nonatomic, strong) NSString <Optional> *validity;

@end
