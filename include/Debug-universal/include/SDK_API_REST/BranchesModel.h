//
//  BranchesModel.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 13/08/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@protocol BranchesModel
@end

@interface BranchesModel : JSONModel

/** color user, if parent user is blue otherwise black */
@property (nonatomic, strong) NSString <Optional> *color;
/** id of the tree where the user's session is located */
@property (nonatomic, strong) NSString <Optional> *tree_id;
/** branch id of the user's session */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** id of the behaviour of the user's session */
@property (nonatomic, strong) NSString <Optional> *behaviour_id;

@end

