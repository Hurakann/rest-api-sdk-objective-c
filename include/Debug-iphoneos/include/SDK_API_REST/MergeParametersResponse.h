//
//  MergeParametersResponse.h
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
 * POJO class for Merge Parameters Response information json structure based on HOVER API response.
 */
@interface MergeParametersResponse : JSONModel

/** id of the user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** full user name */
@property (nonatomic, strong) NSString <Optional> *name;
/** Merge parameter, can be main, merge or free */
@property (nonatomic, strong) NSString <Optional> *merge;

@end
