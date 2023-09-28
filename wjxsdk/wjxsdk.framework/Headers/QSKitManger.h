//
//  QSKitManger.h
//  QSKit_Example
//
//  Created by redyangred on 2023/9/22.
//  Copyright © 2023 liuyang272219971@qq.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger { //横屏模式
    RegionLandOne, //屏幕的比例50%
    RegionLandTwo, //屏幕的比例80%
} RegionLandValue;


typedef enum : NSUInteger { //竖屏模式
    RegionVertOne, //屏幕的比例60%
    RegionVertTwo, //屏幕的比例40%
    RegionVertThree, //屏幕的比例80%
}RegionVertValue;

@interface QSKitManger : NSObject


+ (id)sharedInstance;

/**
 rootViewController : 当前控制器
 url: 传入需要问卷的网站地址
 */
- (void)startQuestion:(UIViewController *)currentController urlPath:(NSString *)url;


/**
 RegionLandValue 更换横屏大小模式
 横屏默认弹窗的宽度：50%
 注意：如果想改变弹窗区域，必须在‘startQuestion’之前调用此方法
 */
- (void)changeRegionSizeLand:(RegionLandValue)landValue;

/**
 RegionVertValue 更换竖屏大小模式
 默认弹窗高度：60%
 注意：如果想改变弹窗区域，必须在‘startQuestion’之前调用此方法
 */
- (void)changeRegionSizeVer:(RegionVertValue)vertValue;


/**
 注意：必须在需要使用此功能的控制器的viewdidload方法调用此方法 ‘成对出现’
 */
- (void)addObserverObjc;

/**
 注意：必须在使用过addObserverObjc的控制器的dealloc方法调用此方法 ‘成对出现’
 
 */
- (void)removeObserverObjc;


@end

NS_ASSUME_NONNULL_END
