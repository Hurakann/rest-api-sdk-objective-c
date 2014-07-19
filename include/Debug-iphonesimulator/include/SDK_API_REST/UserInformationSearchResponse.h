//
//  UserInformationSearchResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 11/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UserGetParameters.h"
#import "JSONModel.h"

@interface UserInformationSearchResponse : JSONModel

@property (nonatomic) int total_results;
@property (nonatomic) int pages;
@property (nonatomic, strong) NSArray <UserGetParameters, ConvertOnDemand, Optional> *users;

@end
