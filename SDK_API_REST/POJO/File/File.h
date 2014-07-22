//
//  File.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for File information json structure based on API responses.
 */
@interface File : JSONModel

/** Identifier to file */
@property (nonatomic, strong) NSString <Optional> *file_id;
/** Key to file */
@property (nonatomic, strong) NSString <Optional> *file_key;
/** Type of file (IFE, CURP, RFC)*/
@property (nonatomic, strong) NSString <Optional> *file_type;

@end

@protocol FileProtocol;