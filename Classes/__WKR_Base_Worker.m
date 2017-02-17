//
//  __WKR_Base_Worker.m
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

#import "__WKR_Base_Worker.h"

@interface WKR_Base_Worker ()
{
    NSMutableArray<NSString*> * _options;
}

@end

@implementation WKR_Base_Worker

@synthesize nextBaseWorker;

#define ERROR_DOMAIN_CLASS      [NSString stringWithFormat:@"com.doublenodeopen.dncprotocols.%@", NSStringFromClass([self class])]
#define ERROR_UNKNOWN           1001
#define ERROR_NOT_FOUND         1002
#define ERROR_BAD_PARAMETER     1003
#define ERROR_BAD_RESPONSE      1004
#define ERROR_SERVER_ERROR      1005

+ (instancetype _Nonnull)worker   {   return [self worker:nil]; }

+ (instancetype _Nonnull)worker:(nullable id<PTCLBase_Protocol>)nextBaseWorker
{
    return [self.alloc initWithWorker:nextBaseWorker];
}

- (nonnull instancetype)init
{
    self = [super init];
    if (self)
    {
        _options    = NSMutableArray.array;
        
        self->nextBaseWorker = nil;
        
        [self configure];
    }
    
    return self;
}

- (nonnull instancetype)initWithWorker:(nullable id<PTCLBase_Protocol>)nextBaseWorker_
{
    self = [super init];
    if (self)
    {
        _options    = NSMutableArray.array;
        
        self->nextBaseWorker = nextBaseWorker_;
        
        [self configure];
    }
    
    return self;
}

#pragma mark - Configuration

- (void)configure
{
    // Worker Dependency Injection
}

#pragma mark - Common Methods

- (BOOL)isOptionEnabled:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        return [_options containsObject:option];
    }
}

- (void)enableOption:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        if (![self isOptionEnabled:option])
        {
            [_options addObject:option];
        }
    }
    
    if (self.nextBaseWorker)
    {
        [self.nextBaseWorker enableOption:option];
    }
}

- (void)disableOption:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        if ([self isOptionEnabled:option])
        {
            [_options removeObject:option];
        }
    }
    
    if (self.nextBaseWorker)
    {
        [self.nextBaseWorker disableOption:option];
    }
}

@end
