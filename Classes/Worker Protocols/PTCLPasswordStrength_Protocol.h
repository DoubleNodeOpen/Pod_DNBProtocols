//
//  PTCLPasswordStrength_Protocol.h
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

typedef NS_ENUM(NSUInteger, WKRPasswordStrengthType)
{
    WKRPasswordStrengthTypeWeak,
    WKRPasswordStrengthTypeModerate,
    WKRPasswordStrengthTypeStrong
};

@protocol PTCLPasswordStrength_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLPasswordStrength_Protocol> _Nullable nextPasswordStrengthWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLPasswordStrength_Protocol>)nextWorker;

#pragma mark - Business Logic

- (WKRPasswordStrengthType)doCheckPasswordStrength:(nonnull NSString*)password;

@end
