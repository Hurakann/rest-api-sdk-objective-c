//
//  Branches.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "Parent.h"
#import "Profile.h"
#import "General.h"

/**
 * POJO class for Branches json structure based on API responses.
 */
@interface Branches : JSONModel

/** color user, if parent user is blue otherwise black */
@property (nonatomic, strong) NSString <Optional> *color;
/** id of the tree where the user's session is located */
@property (nonatomic, strong) NSString <Optional> *tree_id;
/** branch id of the user's session */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** id of the behaviour of the user's session */
@property (nonatomic, strong) NSString <Optional> *behaviour_id;

/** Parent Object */
@property (nonatomic, strong) Parent <Optional> *parent;
/** Profile Object */
@property (nonatomic, strong) Profile <Optional> *profile;

@end

@protocol Branches ;