//
//  FileParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 10/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
/**
 * POJO class for File information json structure based on API responses.
 */
@protocol FileProtocol @end

@interface FileParameters : JSONModel

/** Identifier to file */
@property (nonatomic, strong) NSString <Optional> *fileId;
/** Key to file */
@property (nonatomic, strong) NSString <Optional> *fileKey;
/** Type of file (IFE, CURP, RFC)*/
@property (nonatomic, strong) NSString <Optional> *fileType;

@end
