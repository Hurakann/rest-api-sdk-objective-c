//
//  UserSearchParametersResponse.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 21/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UserGetParameters.h"
#import "JSONModel.h"

@interface UserSearchParametersResponse : JSONModel

/** Number of total results */
@property (nonatomic) int total_results;
/** Number of pages to result */
@property (nonatomic) int pages;
/** Users match with yours search params */
@property (nonatomic, strong) NSArray <UserGetParameters, ConvertOnDemand, Optional> *users;


@end
