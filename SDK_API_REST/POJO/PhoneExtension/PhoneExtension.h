//
//  PhoneExtension.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for PhoneExtension to json structure based on API responses.
 */
@interface PhoneExtension : JSONModel

/** Secret password */
@property (nonatomic, strong) NSString <Optional> *pass;
/** IP direction to r5 */
@property (nonatomic, strong) NSString <Optional> *r5;
/** IP direction to freeswitch */
@property (nonatomic, strong) NSString <Optional> *freeswitch;
/** Name extension */
@property (nonatomic, strong) NSString <Optional> *extension;

@end
