//  PhaseEditedParameters.h
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
 * POJO class for PhaseEditedParameters json structure based on API request.
 */
@interface PhaseEditedParameters : JSONModel

/** Branch id of user was edit*/
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Name of user was edit*/
@property (nonatomic, strong) NSString <Optional> *name;

@end
