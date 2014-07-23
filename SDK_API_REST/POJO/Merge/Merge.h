//
//  Merge.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Merge information json structure based on HOVER API request.
 */
@interface Merge : JSONModel

/** branch id of the main user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** id of the main user in the merge */
@property (nonatomic, strong) NSString <Optional> *main_user_id;
/** +1 array with the id of the users to join */
@property (nonatomic, strong) NSArray <Optional> *users_id;
/** The new main user of the merge group */
@property (nonatomic, strong, getter = theNewMainUser) NSString <Optional> *new_main_user_id;


@end
