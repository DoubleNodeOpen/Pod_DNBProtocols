//
//  PTCLCache_Protocol.h
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

typedef void(^PTCLCacheBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLCacheBlockVoidIDNSError)(id _Nullable object, NSError* _Nullable error);

@protocol PTCLCache_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLCache_Protocol> _Nullable  nextCacheWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLCache_Protocol>)nextCacheWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)cacheId
                withBlock:(nullable PTCLCacheBlockVoidIDNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)cacheId
                  withBlock:(nullable PTCLCacheBlockVoidNSError)block;

- (void)doSaveObject:(nonnull id)object
               forId:(nonnull NSString*)cacheId
           withBlock:(nullable PTCLCacheBlockVoidNSError)block;

@end
