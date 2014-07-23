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

@property (nonatomic, retain) NSURL *proxyURL;
@property (nonatomic, retain) NSURL *socketURL;
@property (assign) NSNumber *timeOutInterval;
@property (assign) NSNumber *filetimeOutInterval;

+ (SharedData *)instance;
- (void)resetModel;


@end
