//  LoginResetParameters.h
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
 * POJO class for Login reset parameters information json structure based on HOVER API request.
 */
@interface LoginResetParameters : JSONModel

/** user's email */
@property (nonatomic, strong) NSString <Optional> *email;
/** security code */
@property (nonatomic, strong) NSString <Optional> *code;
/** new password to user account */
@property (nonatomic, strong) NSString <Optional> *nPassword;

@end
