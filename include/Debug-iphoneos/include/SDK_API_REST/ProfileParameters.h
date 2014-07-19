//
//  ProfileParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface ProfileParameters : JSONModel

/** User id for current user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** Name of service */
@property (nonatomic, strong) NSString <Optional> *name;
/** Based on id*/
@property (nonatomic, strong) NSString <Optional> *based_on_id;
/** Profile id*/
@property (nonatomic, strong) NSString <Optional> *profile_id;

@end
