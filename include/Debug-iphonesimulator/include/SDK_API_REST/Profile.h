//
//  Profile.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "General.h"

/**
 * POJO class for Profile json structure based on API responses and request.
 */
@interface Profile : JSONModel

/** User id for current user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** name of the profile (type) */
@property (nonatomic, strong) NSString <Optional> *name;

/** id of the profile */
@property (nonatomic, strong) NSString <Optional> *profile_id;

/** id of the profile */
@property (nonatomic, strong) NSString <Optional> *id;
/** id of the three where the profile is located */
@property (nonatomic, strong) NSString <Optional> *tree_id;


/** Based on information */
@property (nonatomic, strong) General <Optional> *based_on;

@end
