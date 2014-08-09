//
//  UserGetParametersResponse.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "User.h"
#import "Profile.h"
#import "PhaseEditedParameters.h"


/**
 * POJO class for user paramters related data in json structure based on API responses.
 */
@interface UserGetParametersResponse : JSONModel

/** User object to get branch_id property */
@property (nonatomic, strong)  User <Optional> *user;
/** Profile object to get profile_id and name properties */
@property (nonatomic, strong)  Profile <Optional> *profile;
/** Data source fro user */
@property (nonatomic, strong) NSString <Optional> *data_source;
/** Name for the user */
@property (nonatomic, strong) NSString <Optional> *name;
/** Lastname for the user */
@property (nonatomic, strong) NSString <Optional> *lastname;
/** Lastname2 for the user */
@property (nonatomic, strong) NSString <Optional> *lastname2;
/** Birthday for current user */
@property (nonatomic, strong) NSString <Optional> *birthday;
/** Gender for the user */
@property (nonatomic, strong) NSString <Optional> *gender;
/** Profile id assigned to this user */
@property (nonatomic, strong) NSString <Optional> *profile_id;
/** Type profile of current user */
@property (nonatomic, strong) NSString <Optional> *type_profile;
/** Country for current user */
@property (nonatomic, strong) General <Optional> *from_country;
/** Estate for current user */
@property (nonatomic, strong) General <Optional> *from_estate;
/** Town for current user */
@property (nonatomic, strong) General <Optional> *from_town;
/** Phase for current user */
@property (nonatomic, strong) NSString <Optional> *phase;
/** Creation date for current user */
@property (nonatomic, strong) NSString <Optional> *creation_date;
/** Zip code for current user */
@property (nonatomic, strong) NSString <Optional> *live_zip_code;
/** Language short description for the user (es, en, so on....) */
@property (nonatomic, strong) NSString <Optional> *language;
/** Live country for current user */
@property (nonatomic, strong) General <Optional> *live_country;
/** Live estate for current user */
@property (nonatomic, strong) General <Optional> *live_estate;
/** Live town for current user */
@property (nonatomic, strong) General <Optional> *live_town;
/** Live locality for current user */
@property (nonatomic, strong) General <Optional> *live_locality;
/** fmd to current user */
@property (assign, nonatomic) BOOL fmd;
/** Information for user was edit information of current user*/
@property (nonatomic, strong) PhaseEditedParameters <Optional> *phase1_edited_by;
/** Information for user was edit information of current user*/
@property (nonatomic, strong) PhaseEditedParameters <Optional> *phase2_edited_by;
/** Information for user was edit information of current user*/
@property (nonatomic, strong) PhaseEditedParameters <Optional> *phase3_edited_by;
/** Information for user was edit information of current user*/
@property (nonatomic, strong) PhaseEditedParameters <Optional> *phase4_edited_by;
/** Merge type */
@property (nonatomic, strong) NSString <Optional> *merge;
/** Broot of current user */
@property (nonatomic, strong) NSString <Optional> *broot;
/** User id of current user */
@property (nonatomic, strong) NSString <Optional> *user_id;
@end

@protocol UserGetParametersResponse;
