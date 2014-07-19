//
//  GroupParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface GroupParameters : JSONModel

/** Id of group*/
@property (nonatomic, strong) NSString <Optional> *groupId;
/** Name of group */
@property (nonatomic, strong) NSString <Optional> *name;
/** Status of group */
@property (assign) BOOL status;

@end
