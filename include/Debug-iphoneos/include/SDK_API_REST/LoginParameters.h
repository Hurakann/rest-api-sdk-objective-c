//  LoginParameters.h
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
 * POJO class for login json structure based on API responses.
 */
@interface LoginParameters : JSONModel

/** UserName of user to try login */
@property (nonatomic, strong) NSString *user;
/** Password of user to try login */
@property (nonatomic, strong) NSString *password;


@end
