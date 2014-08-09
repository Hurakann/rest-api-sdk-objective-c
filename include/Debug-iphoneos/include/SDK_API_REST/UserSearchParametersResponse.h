//
//  UserSearchParametersResponse.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import <Foundation/Foundation.h>
#import "UserGetParametersResponse.h"
#import "JSONModel.h"

/**
 POJO class for User Search Parameters Response information json structure based on API responses.
 */
@interface UserSearchParametersResponse : JSONModel

/** Number of total results */
@property (nonatomic) int total_results;
/** Number of pages to result */
@property (nonatomic) int pages;
/** Users match with yours search params */
@property (nonatomic, strong) NSArray <UserGetParametersResponse, ConvertOnDemand, Optional> *users;


@end
