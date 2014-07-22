//
//  UserSearch.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 POJO class for UserSearchParameters json structure based on API responses.
 */
@interface UserSearch : JSONModel


/** The parent branch_id of the user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** The parent branch_id of the user */
@property (nonatomic, strong) NSString <Optional> *broot;
/** The number of elements per page to slide data */
@property (nonatomic) int pagination;
/** The number of page to fecth */
@property (nonatomic) int page;

@end
