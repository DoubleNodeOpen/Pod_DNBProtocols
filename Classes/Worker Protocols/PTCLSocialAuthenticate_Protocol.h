//
//  PTCLSocialAuthenticate_Protocol.h
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

#import "PTCLSocialAuthenticate_Session.h"
#import "PTCLSocialAuthenticate_User.h"

#define NS_PRETTY_FUNCTION  [NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__]

typedef void(^PTCLSocialAuthenticateBlockVoidSessionNSError)(PTCLSocialAuthenticate_Session* _Nullable session, NSError* _Nullable error);
typedef void(^PTCLSocialAuthenticateBlockVoidUserNSError)(PTCLSocialAuthenticate_User* _Nullable user, NSError* _Nullable error);

@protocol PTCLSocialAuthenticate_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLSocialAuthenticate_Protocol> _Nullable   nextSocialAuthenticateWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLSocialAuthenticate_Protocol>)nextSocialAuthenticateWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doAuthenticateWithCompletion:(PTCLSocialAuthenticateBlockVoidSessionNSError _Nullable)completion;

- (void)doRetrieveUser:(nullable NSString*)userId
           withSession:(nullable PTCLSocialAuthenticate_Session*)session
        withCompletion:(nullable PTCLSocialAuthenticateBlockVoidUserNSError)completion;

@end
