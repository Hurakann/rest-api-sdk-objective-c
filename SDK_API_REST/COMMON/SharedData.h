//  SharedData.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>

@interface SharedData : NSObject

@property (nonatomic, retain) NSString *branch_id;
@property (nonatomic, retain) NSString *user_id;
@property (nonatomic, retain) NSString *api_version;
@property (nonatomic, retain) NSString *port;
@property (nonatomic, retain) NSURL *proxyURL;

@property (nonatomic, assign) int timeOutInterval;
@property (nonatomic, assign) int filetimeOutInterval;

+ (SharedData *)instance;
- (void)resetModel;


@end
