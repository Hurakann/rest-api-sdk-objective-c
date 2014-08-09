//  Group.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Group information json structure based on API request.
 */
@interface Group : JSONModel

/** Id of group*/
@property (nonatomic, strong) NSString <Optional> *groupId;
/** Name of group */
@property (nonatomic, strong) NSString <Optional> *name;
/** Status of group */
@property (nonatomic) BOOL status;

@end
