//
//  CatalogsParameters.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@interface CatalogsParameters : JSONModel

/** Name of object*/
@property (nonatomic, strong) NSString <Optional> *name;
/** Identifier for state, when catalog is of states */
@property (nonatomic, strong) NSString <Optional> *estate_id;
/** Identifier for country, when catalog is of countries */
@property (nonatomic, strong) NSString <Optional> *country_id;
/** Identifier for town, when catalog is of towns */
@property (nonatomic, strong) NSString <Optional> *town_id;
/** Type of site, when catalog is of towns */
@property (nonatomic, strong) NSString <Optional> *type_site;

@end

