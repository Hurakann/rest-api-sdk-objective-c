//
//  RetailParametersResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 30/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface RetailParametersResponse : JSONModel

@property (nonatomic,strong) NSString <Optional> *ad;
@property (nonatomic,strong) NSString <Optional> *retail_ad_id;

@end

@protocol RetailParametersResponse;
