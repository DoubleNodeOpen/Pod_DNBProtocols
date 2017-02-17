//
//  PTCLAnalytics_Protocol.h
//  DoubleNodeOpen Base
//
//  Created by Darren Ehlers on 2017/02/17.
//  Copyright © 2017 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#pragma once

#import "__PTCLBase_Protocol.h"

#define NS_PRETTY_FUNCTION  [NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__]

@protocol PTCLAnalytics_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLAnalytics_Protocol> _Nullable    nextAnalyticsWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLAnalytics_Protocol>)nextAnalyticsWorker;

#pragma mark - Business Logic / Single Item CRUD

#pragma mark - Identify

- (void)doIdentify:(NSString*_Nonnull)userId;
- (void)doIdentify:(NSString*_Nonnull)userId traits:(NSDictionary*_Nonnull)traits;
- (void)doIdentify:(NSString*_Nonnull)userId traits:(NSDictionary*_Nonnull)traits options:(NSDictionary*_Nonnull)options;

#pragma mark - Track

- (void)doTrack:(NSString*_Nonnull)event;
- (void)doTrack:(NSString*_Nonnull)event properties:(NSDictionary*_Nonnull)properties;
- (void)doTrack:(NSString*_Nonnull)event properties:(NSDictionary*_Nonnull)properties options:(NSDictionary*_Nonnull)options;

#pragma mark - Screen

- (void)doScreen:(NSString*_Nonnull)screenTitle;
- (void)doScreen:(NSString*_Nonnull)screenTitle properties:(NSDictionary*_Nonnull)properties;
- (void)doScreen:(NSString*_Nonnull)screenTitle properties:(NSDictionary*_Nonnull)properties options:(NSDictionary*_Nonnull)options;

#pragma mark - Group

- (void)doGroup:(NSString*_Nonnull)groupId;
- (void)doGroup:(NSString*_Nonnull)groupId traits:(NSDictionary*_Nonnull)traits;
- (void)doGroup:(NSString*_Nonnull)groupId traits:(NSDictionary*_Nonnull)traits options:(NSDictionary*_Nonnull)options;

@end
