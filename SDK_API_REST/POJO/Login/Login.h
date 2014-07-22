//
//  Login.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface Login : JSONModel

/** UserName of user to try login */
@property (nonatomic, strong) NSString *user;
/** Password of user to try login */
@property (nonatomic, strong) NSString *password;

@end
