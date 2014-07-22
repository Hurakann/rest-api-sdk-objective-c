//
//  LoginResponseParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 09/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "Branches.h"

@interface LoginResponseParameters : JSONModel

/** User id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** Name for the user */
@property (nonatomic, strong) NSString <Optional> *name;
/** Lastname for the user */
@property (nonatomic, strong) NSString <Optional> *lastname;
/** Lastname2 for the user */
@property (nonatomic, strong) NSString <Optional> *lastname2;
/** Language short description for the user (es, en, so on....) */
@property (nonatomic, strong) NSString <Optional> *language;
/** Branches for the user */
@property (nonatomic, strong) NSArray  <Branches, ConvertOnDemand, Optional>* branches;

@end


