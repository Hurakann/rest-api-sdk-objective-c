//
//  Profile.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "General.h"

/**
 * POJO class for Profile json structure based on API responses.
 */
@interface Profile : JSONModel

/** id for profile */
@property (nonatomic, strong) NSString <Optional> *profile_id;
/** id for profile */
@property (nonatomic, strong) NSString <Optional> *id;
/** Name for profile */
@property (nonatomic, strong) NSString <Optional> *name;
/** id for profile tree */
@property (nonatomic, strong) NSString <Optional> *tree_id;
/** Based on information */
@property (nonatomic, strong) General <Optional> *based_on;

@end
