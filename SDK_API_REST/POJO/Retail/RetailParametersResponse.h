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

@property (nonatomic,strong) NSString <Optional> *title;
@property (nonatomic,strong) NSString <Optional> *retail_ad_id;
@property (nonatomic,strong) NSString <Optional> *ad;

@end

