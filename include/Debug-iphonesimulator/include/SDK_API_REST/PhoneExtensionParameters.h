//
//  PhoneExtensionParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for PhoneExtension to json structure based on API responses.
 */
@interface PhoneExtensionParameters : JSONModel

/** Secret password */
@property (nonatomic, strong) NSString *pass;
/** IP direction to r5 */
@property (nonatomic, strong) NSString *r5;
/** IP direction to freeswitch */
@property (nonatomic, strong) NSString *freeswitch;
/** Name extension */
@property (nonatomic, strong) NSString *extension;

@end
