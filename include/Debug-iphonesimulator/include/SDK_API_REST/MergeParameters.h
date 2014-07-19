//
//  MergeParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Merge properties to json structure based on API responses.
 */
@interface MergeParameters : JSONModel

/** Branch id */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Main user id */
@property (nonatomic, strong) NSString <Optional> *main_user_id;
/** Users id to merge */
@property (nonatomic, strong) NSArray <Optional> *users_id;
/** The new main user of the merge group */
@property (nonatomic, strong, getter = theNewMainUser) NSString <Optional> *new_main_user_id;



@end
