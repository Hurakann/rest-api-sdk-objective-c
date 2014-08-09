//  File.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.


#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for File information json structure based on API request.
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