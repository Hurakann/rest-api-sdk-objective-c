//
//  SharedData.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 25/06/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SharedData : NSObject

@property (nonatomic, retain) NSURL *proxyURL;
@property (nonatomic, retain) NSURL *socketURL;
@property (assign) NSNumber *timeOutInterval;
@property (assign) NSNumber *filetimeOutInterval;

+ (SharedData *)instance;
- (void)resetModel;


@end
