//
//  __PTCLBase_Protocol.h
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

#import <UIKit/UIKit.h>

@protocol PTCLBase_Protocol <NSObject>

@property (strong, nonatomic)   id<PTCLBase_Protocol> _Nullable nextBaseWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLBase_Protocol>)nextBaseWorker;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithWorker:(nullable id<PTCLBase_Protocol>)nextBaseWorker;

- (void)configure;

- (void)enableOption:(nonnull NSString*)option;
- (void)disableOption:(nonnull NSString*)option;

@end
