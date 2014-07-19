//  User.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "Branches.h"
#import "FileParameters.h"
#import "UserInformationService.h"
#import "NFCParameters.h"

/**
 * POJO class for user json structure based on API responses.
 */
@interface User : JSONModel

/** Branch id for the parent user (owner of the user) */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Password to assign to this user*/
@property (nonatomic, strong) NSString <Optional> *password;
/** Town to this user */
@property (nonatomic, strong) NSString <Optional> *from_town;
/** Locality for this user */
@property (nonatomic, strong) NSString <Optional> *live_locality;
/** Data source for this user */
@property (nonatomic, strong) NSString <Optional> *data_source;
/** Estate for the user */
@property (nonatomic, strong) NSString <Optional> *from_estate;
/** Gender for this user (MALE or FEMALE)*/
@property (nonatomic, strong) NSString <Optional> *gender;
/** Color for distinct the user (use black please!!) */
@property (nonatomic, strong) NSString <Optional> *coloruser;
/** Name for the user */
@property (nonatomic, strong) NSString <Optional> *name;
/** Live street number for the user */
@property (nonatomic, strong) NSString <Optional> *live_street_number;
/** Phone number for the user (home) */
@property (nonatomic, strong) NSString <Optional> *home_phone;
/** Phone number for the user (mobile)*/
@property (nonatomic, strong) NSString <Optional> *cell_phone;
/** Country for the user */
@property (nonatomic, strong) NSString <Optional> *from_country;
/** Birthday for the user */
@property (nonatomic, strong) NSString <Optional> *birthday;
/** Live town for the user */
@property (nonatomic, strong) NSString <Optional> *live_town;
/** CURP for the user */
@property (nonatomic, strong) NSString <Optional> *curp;
/** Email for the user */
@property (nonatomic, strong) NSString <Optional> *email;
/** User name for the user */
@property (nonatomic, strong) NSString <Optional> *username;
/** RFC for the user */
@property (nonatomic, strong) NSString <Optional> *rfc;
/** Latitude for the user */
@property (nonatomic, strong) NSString <Optional> *latitude;
/** External address number for the user */
@property (nonatomic, strong) NSString <Optional> *external_addr_number;
/** Longitude for the user */
@property (nonatomic, strong) NSString <Optional> *longitude;
/** Internal address number for the user */
@property (nonatomic, strong) NSString <Optional> *internal_addr_number;
/** Live country for the user */
@property (nonatomic, strong) NSString <Optional> *live_country;
/** Zip code for the user */
@property (nonatomic, strong) NSString <Optional> *live_zip_code;
/** Edit phase1 for the user */
@property (nonatomic, strong) NSString <Optional> *phase1_edited_by;
/** Edit phase2 for the user */
@property (nonatomic, strong) NSString <Optional> *phase2_edited_by;
/** Edit phase3 for the user */
@property (nonatomic, strong) NSString <Optional> *phase3_edited_by;
/** Edit phase4 for the user */
@property (nonatomic, strong) NSString <Optional> *phase4_edited_by;
/** Live etate for the user */
@property (nonatomic, strong) NSString <Optional> *live_estate;
/** Lastname for the user */
@property (nonatomic, strong) NSString <Optional> *lastname;
/** Lastname2 for the user */
@property (nonatomic, strong) NSString <Optional> *lastname2;
/** Language short description for the user (es, en, so on....) */
@property (nonatomic, strong) NSString <Optional> *language;
/** Information to service assigned to this user */
@property (nonatomic, strong) UserInformationService <ServiceProtocol, ConvertOnDemand, Optional> *services;
/** NFC paramters to this user */
@property (nonatomic, strong) NFCParameters <NFCProtocol, ConvertOnDemand, Optional> *nfc;
/** Files information added to this user */
@property (nonatomic, strong) FileParameters <FileProtocol, ConvertOnDemand, Optional> *files;
/** FMD datas to this user */
@property (nonatomic, strong) NSArray <Optional> *fmd;
/** Phase to keep the user (1, 2, 3 or 4) */
@property (nonatomic, strong) NSString <Optional> *phase;
/** Profile that could take the user */
@property (nonatomic, strong) NSString <Optional> *profile_id;
/** User id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;

@end


