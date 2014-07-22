//
//  HoverBox.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 22/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

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
