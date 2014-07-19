//  UserGetInformationParameters.h
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
 * POJO class for UserGetInformationParameters json structure based on API responses.
 */
@interface UserGetInformationParameters : JSONModel

/** Branch id for the parent user (owner of the user) */
@property (nonatomic, strong) NSString *branch_id;
/** User id of the parent user */
@property (nonatomic, strong) NSString *user_id;
/** Phase to keep the user (1, 2, 3 or 4) */
@property (nonatomic, strong) NSString *phase;

@end
