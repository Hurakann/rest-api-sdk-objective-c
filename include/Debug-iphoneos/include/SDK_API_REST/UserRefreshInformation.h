//
//  UserRefreshInformation.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for update user information and related data in json structure based on API responses.
 */
@interface UserRefreshInformation : JSONModel

/** Branch id for the parent user (owner of the user) */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** User id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;

@end
