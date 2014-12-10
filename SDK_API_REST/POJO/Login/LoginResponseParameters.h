//
//  LoginResponseParameters.h
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

/**
 * POJO class for Login response parameters information json structure based on HOVER API response.
 */
@interface LoginResponseParameters : JSONModel

/** User id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** Name for the user */
@property (nonatomic, strong) NSString <Optional> *name;
/** Lastname for the user */
@property (nonatomic, strong) NSString <Optional> *lastname;
/** Lastname2 for the user */
@property (nonatomic, strong) NSString <Optional> *lastname2;
/** Language short description for the user (es, en, so on....) */
@property (nonatomic, strong) NSString <Optional> *language;
/** Branches for the user */
@property (nonatomic, strong) NSArray <Branches, ConvertOnDemand, Optional>* branches;

@end


