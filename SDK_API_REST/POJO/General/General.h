//
//  General.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 03/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for ANY section that has an id and name propertys 
 * to json structure based on API responses.
 */
@interface General : JSONModel

/** id for something  */
@property (nonatomic, strong) NSString *id;
/** Name for somethig */
@property (nonatomic, strong) NSString *name;

@end
