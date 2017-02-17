//
//  PTCLSocialAuthenticate_Session.h
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

#import <UIKit/UIKit.h>

#import "PTCLSocialAuthenticate_User.h"

@interface PTCLSocialAuthenticate_Session : NSObject

+ (nonnull instancetype)session;

@property (copy, nonatomic)   NSString* _Nullable       userId;
@property (copy, nonatomic)   NSString* _Nullable       username;
@property (copy, nonatomic)   NSString* _Nullable       password;
@property (copy, nonatomic)   NSDictionary* _Nullable   authData;

@property (copy, nonatomic)   PTCLSocialAuthenticate_User* _Nullable    user;

@end