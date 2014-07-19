//  LoginRestoreParameters.h
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
 * POJO class for restore datas to login based on API responses.
 */
@interface LoginRestoreParameters : JSONModel

/** user's email */
@property (nonatomic, strong) NSString *userEmail;

@end
