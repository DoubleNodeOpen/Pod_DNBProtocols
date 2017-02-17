//
//  PTCLValidation_Protocol.h
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

@protocol PTCLValidation_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLValidation_Protocol> _Nullable    nextValidationWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLValidation_Protocol>)nextValidationWorker;

- (BOOL)doValidateBirthday:(nonnull NSDate*)birthday error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateEmail:(nonnull NSString*)email error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateHandle:(nonnull NSString*)handle error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateName:(nonnull NSString*)name error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateNumber:(nonnull NSString*)number error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidatePassword:(nonnull NSString*)password error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidatePercentage:(nonnull NSString*)percentage error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateSearch:(nonnull NSString*)search error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateState:(nonnull NSString*)state error:(NSError*_Nullable*_Nullable)error;

@end
