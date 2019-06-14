//
//  HDGlobleInfo.m
//  HDStudio
//
//  Created by Hu Dennis on 14/12/12.
//  Copyright (c) 2014年 Hu Dennis. All rights reserved.
//

#import "HDGlobal.h"

static HDGlobal *pData = NULL;
@implementation HDGlobal

+ (HDGlobal *)instance{
    @synchronized(self){
        if (pData == NULL){
            pData = [[HDGlobal alloc] init];
        }
    }
    return pData;
}

#pragma mark - determine current user's login status

+ (BOOL)isLogin
{
    NSString * userID = [self getUserID];
    if(userID != nil && userID.length > 0){
        return YES;
    }else{
        return NO;
    }
}

#pragma mark - 获取当前用户ID
+ (NSString *)getUserID
{
    HDLoginUserModel *model = [HDLoginUserModel readFromLocal];
    NSString * value = model.MID;
    if(value != nil){
        return value;
    }else{
        return @"";
    }
}


- (void)reset{
    pData = NULL;
}


#pragma mark - UITabBarControllerDelegate

- (BOOL)tabBarController:(UITabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController{
    tabBarController.navigationController.navigationBarHidden = YES;
    return YES;
}

- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController{
    NSUInteger select = tabBarController.selectedIndex;
    NSLog(@"selectTabbarAtTabIndex = %d", (int)select);
    tabBarController.navigationController.navigationBarHidden = YES;
    [[NSNotificationCenter defaultCenter] postNotificationName:HDNOTI_DID_TAP_TABBAR_INDEX object:nil userInfo:@{@"index": @(select)}];

}


@end
