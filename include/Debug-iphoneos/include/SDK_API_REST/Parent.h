//
//  Parent.h
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
 * POJO class for Parent json structure based on API responses.
 */
@interface Parent : JSONModel

/** name of the parent user */
@property (nonatomic, strong) NSString <Optional> *name;
/** id of the parent user */
@property (nonatomic, strong) NSString <Optional> *user_id;
/** branch id of the parent user */
@property (nonatomic, strong) NSString <Optional> *branch_id;
/** color user, this case blue. */
@property (nonatomic, strong) NSString <Optional> *coloruser;

@end
