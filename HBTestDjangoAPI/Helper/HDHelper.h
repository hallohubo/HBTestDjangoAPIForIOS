//
//  HDUtility.h
//  SNVideo
//
//  Created by Hu Dennis on 14-8-6.
//  Copyright (c) 2014年 evideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MessageUI/MFMessageComposeViewController.h>
#import <MessageUI/MessageUI.h>
//#import "CCLocationManager.h"
#import "MBProgressHUD.h"

@interface HDHelper : NSObject<MFMailComposeViewControllerDelegate, MFMessageComposeViewControllerDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate, UIAlertViewDelegate, UIActionSheetDelegate, CAAnimationDelegate>

@property (nonatomic, copy) void(^sendMailFinished)(MFMailComposeViewController *controller);
@property (nonatomic, copy) void(^sendMessageFinished)(MFMessageComposeViewController *controller);
//@property (nonatomic, copy) void(^cameraTakePictureFinished)(HDError *error, UIImage *image_);

+ (HDHelper *)instance;

+ (NSString *)uuid;

- (UIViewController *)mailController:(NSArray *)recipients title:(NSString *)title content:(NSString *)content image:(UIImage *)image block:(void (^)(MFMailComposeViewController *controller))block;

- (UIViewController *)messageController:(NSString *)bodyOfMessage recipients:(NSArray *)recipients block:(void (^)(MFMessageComposeViewController *controller))block;

+ (NSDictionary *)getConectedWIFI;

+ (void)makingCall:(NSString *)phone;
/**
 跳出提示，1秒后自动消失
 @param     sMsg  提示语句

*/
+ (void)mbSay:(NSString *)sMsg;

+ (void)mbSay:(NSString *)sMsg delay:(CGFloat)seconed;

/**
 跳出成功提示，
 @param     s  提示语句
 @return    MBProgressHUD对象

*/
+ (MBProgressHUD *)sayAfterSuccess:(NSString *)s;
/**
 跳出失败提示，
 @param     s  提示语句
 @return    MBProgressHUD对象
 
*/
+ (MBProgressHUD *)sayAfterFail:(NSString *)s;
/**
 跳出成功，用户手动关闭
 @param     sMsg  提示语句

*/
+ (void)say:(NSString *)sMsg;
+ (void)say:(NSString *)sMsg title:(NSString *)title;

+ (NSString *)UnixTime;
+ (NSString *)md5: (NSString *) inPutText;
+ (void)rotateView:(UIView *)view angle:(float)angle;
+ (void)setShadow:(UIView *)view;

/** NSString验证合法性 **/
+ (BOOL)isValidateEmail:(NSString *)email;
+ (BOOL)isValidateMobile:(NSString *)mobile;
+ (BOOL)isValidateCarNo:(NSString *)carNo;
+ (BOOL)isValideteIdentityCard:(NSString *)IDCardNumber;
+ (BOOL)isValidatePassword:(NSString *)sPwd;
+ (BOOL)isValidateAccount:(NSString *)s;      //合法的不含特殊字符的字符串，通常用户账户，用户名等的验证

/** 动画 **/
+ (void)showView:(UIView *)view centerAtPoint:(CGPoint)pos duration:(CGFloat)waitDuration;
+ (void)hideView:(UIView *)view duration:(CGFloat)waitDuration;
+ (void)view:(UIView *)view appearAt:(CGPoint)location withDalay:(CGFloat)delay duration:(CGFloat)duration;
+ (void)showPullDown:(UIView *)view appearAt:(CGPoint)center withDalay:(CGFloat)delay duration:(CGFloat)duration;//未完不可用
- (void)hidePullUp:(UIView *)view appearAt:(CGRect)bounds duration:(CGFloat)duration finished:(void (^)(void))block;
@property (nonatomic, copy) void (^hidePullUpAnimationFinished)(void);

/*相机*/
+ (BOOL) isCameraAvailable;
+ (BOOL) isRearCameraAvailable;
+ (BOOL) isFrontCameraAvailable;

//计算uitextview的contentsize的height
+ (CGFloat)heightOfUITextView:(UITextView *)textView;

/**
 @brief 添加文件夹，使其不会出现在iCloud自动备份中
 */
+ (BOOL)addSkipBackupAttributeToItemAtPath:(NSString *)filePathString;

+ (void)setNormalDisplayModleForTheView:(UIView *)v;

+ (void)addDashedBorderWithTheMotherView:(UIView *)view color:(UIColor *)color;
+ (void)removeDashedBorder:(UIView *)view;

//获取当前日期（年－月－日）
+ (NSString *)getCurrentDate;

/**
 定时，12分钟，（刷新界面用）
 @param str 标志位，如果朋友圈用@“blog”
 @return 是否到更新的时间了
 */
+ (BOOL)isTimeToRefresh:(NSString *)str;

/**
 定时，超过hour小时，返回yes
 @param str 事件标志标志位，如果朋友圈用@“blog”
 @return 是否到时间了
 */
+ (BOOL)hasPassedHours:(CGFloat)hour flag:(NSString *)str;


+ (NSString*)getMD5WithData:(NSData *)data;

+ (void)changeColor:(UIButton *)btn;

//url字符串中具有特殊功能的特殊字符的字符串，或者中文字符,作为参数传递时，需要用encode处理一下
+(NSString*)encodeString:(NSString*)uncodeString;
+(NSString*)decodeString:(NSString*)decodeString;
@end




