//
//  Branches.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "Parent.h"
#import "Profile.h"
#import "General.h"

/**
 * POJO class for Branches json structure based on API responses.
 */


@interface Branches : JSONModel

@property (nonatomic, strong) NSString <Optional> *color;
@property (nonatomic, strong) NSString <Optional> *tree_id;
@property (nonatomic, strong) NSString <Optional> *branch_id;
@property (nonatomic, strong) NSString <Optional> *behaviour_id;

@property (nonatomic, strong) Parent <Optional> *parent;
@property (nonatomic, strong) Profile <Optional> *profile;

@end

@protocol Branches;