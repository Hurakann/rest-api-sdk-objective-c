//
//  Parent.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Parent json structure based on API responses.
 */
@interface Parent : JSONModel

@property (nonatomic, strong) NSString <Optional> *name;
@property (nonatomic, strong) NSString <Optional> *user_d;
@property (nonatomic, strong) NSString <Optional> *branch_d;
@property (nonatomic, strong) NSString <Optional> *coloruser;

@end
