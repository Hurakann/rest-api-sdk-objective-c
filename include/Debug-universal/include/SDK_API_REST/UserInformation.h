//
//  UserInformation.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 26/06/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface UserInformation : JSONModel

@property (nonatomic, strong) NSString *branchId;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *lastname;
@property (nonatomic, strong) NSString *lastname2;
@property (nonatomic, strong) NSString *gender;
@property (nonatomic, strong) NSString *birthday;
@property (nonatomic, strong) NSString *phase;
@property (nonatomic, strong) NSString *coloruser;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, strong) NSString *profileId;
@property (nonatomic, strong) NSString *userId;

@end
