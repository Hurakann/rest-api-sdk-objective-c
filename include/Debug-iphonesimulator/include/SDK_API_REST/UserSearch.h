//
//  UserSearch.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 POJO class for UserSearch information json structure based on API request.
 */
@interface UserSearch : JSONModel


/** The parent branch_id of the user */
@property (nonatomic, strong) NSString *branch_id;
/** The parent branch_id of the user */
@property (nonatomic, strong) NSString *broot;
/** The number of elements per page to slide data */
@property (nonatomic) int pagination;
/** The number of page to fecth */
@property (nonatomic) int page;

@end
