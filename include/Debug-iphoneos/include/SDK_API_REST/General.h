//
//  General.h
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
 * POJO class for ANY section that has an id and name propertys to json structure based on API responses.
 */
@interface General : JSONModel

/** id for something  */
@property (nonatomic, strong) NSString <Optional> *id;
/** Name for somethig */
@property (nonatomic, strong) NSString <Optional> *name;

@end
