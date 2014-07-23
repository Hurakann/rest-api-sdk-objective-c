//  Catalog.h
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
 * POJO class for Catalog information json structure based on HOVER API request.
 */
@interface Catalog : JSONModel

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
