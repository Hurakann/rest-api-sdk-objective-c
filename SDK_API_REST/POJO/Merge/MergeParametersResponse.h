//
//  MergeParametersResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface MergeParametersResponse : JSONModel

@property (nonatomic, strong) NSString <Optional> *user_id;
@property (nonatomic, strong) NSString <Optional> *name;
@property (nonatomic, strong) NSString <Optional> *merge;


@end