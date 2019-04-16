//
//  YZJAppModuleManager.h
//  AFNetworking
//
//  Created by hour on 2019/2/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YZJLanguageType) {
    YZJLanguageTypeChinese  = 1,
    YZJLanguageTypeEnglish  = 2
};

@interface YZJBaseAppModule : NSObject

- (void)moduleInit;

// todo
- (void)moduleDestory;

- (void)userLogin:(NSDictionary<NSString *, id> *)dict;
- (void)userLogout;

- (void)languageChanged:(YZJLanguageType)type;

/// system callback
//- (void)applicationDidFinishLaunch:(UIApplication *)application;
//- (void)applicationWillResignActive:(UIApplication *)application;
//- (void)applicationDidEnterBackground:(UIApplication *)application;
//- (void)applicationWillEnterForeground:(UIApplication *)application;
//- (void)applicationDidBecomeActive:(UIApplication *)application;
//- (void)applicationWillTerminate:(UIApplication *)application;


/// router 处理
- (NSArray<NSString *> *)supportUrl;
- (void)executeRouterUrl:(NSString *)url params:(NSDictionary *)dict vc:(UIViewController *)vc;

/// root vc
- (nonnull NSArray<NSString *> *)rootIdentifiers;
- (UIViewController *)rootVCWithIdentifier:(nonnull NSString *)identifier;
/**
 使用示例：
 通过这种方式 一个 module 可以设置多个 tabar 的 vc
 - (nonnull NSArray<NSString *> *)rootIdentifiers {
     return @[
             @"mail",
             @"workbench"
            ];
 }

 - (UIViewController *)rootVCWithIdentifier:(nonnull NSString *)identifier {
     if ([identifier isEqualToString:@"mail"]) {
        return [[UIViewController alloc] init];
     } else if ([identifier isEqualToString:@"workbench"]) {
        return [[UIViewController alloc] init];
     }
 
     return nil;
 }
 
 
 */



@end

@interface YZJAppModuleManager : NSObject

+ (instancetype)sharedInstance;


@end

NS_ASSUME_NONNULL_END
