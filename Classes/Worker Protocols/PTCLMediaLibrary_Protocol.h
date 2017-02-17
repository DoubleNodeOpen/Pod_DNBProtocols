//
//  PTCLMediaLibrary_Protocol.h
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

typedef void(^PTCLMediaLibraryBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidNSArrayNSError)(NSArray* _Nullable assets, NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidUIImageNSDictionary)(UIImage* _Nullable image, NSDictionary* _Nullable info);

@protocol PTCLMediaLibrary_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMediaLibrary_Protocol> _Nullable    nextMediaLibraryWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMediaLibrary_Protocol>)nextMediaLibraryWorker;

+ (CGSize)PTCLMediaLibraryMaximumSize;

- (BOOL)doCheckAuthorization;
- (void)doRequestAuthorizationWithCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSError)completionBlock;

- (void)doLoadImagesWithCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;

- (void)doLoadImage:(nonnull id)asset
               size:(CGSize)size
    completionBlock:(nullable PTCLMediaLibraryBlockVoidUIImageNSDictionary)completionBlock;

@end
