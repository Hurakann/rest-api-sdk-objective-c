//  HoverBox.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, eder.nocelo@hovanetworks.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "JSONModel.h"

/**
 * POJO class for Hover Box information json structure based on HOVER API request.
 */
@interface HoverBox : JSONModel

/** Hover Box id*/
@property (nonatomic, strong) NSString <Optional> *hoverbox;
/** flush */
@property (assign) BOOL flush;
/** Branch id to current user*/
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** Branch id to current user */
@property (nonatomic, strong) NSString <Optional> *branch_user;


@end
