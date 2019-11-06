//
//  UtilsMacros.h
//  IRBaseKitDemo
//
//  Created by eyecloud on 2019/11/6.
//

#ifndef UtilsMacros_h
#define UtilsMacros_h

/** 屏幕尺寸相关 */
#define kScreenWidth       [UIScreen mainScreen].bounds.size.width
#define kScreenHeight      [UIScreen mainScreen].bounds.size.height
#define kScreenBounds      [UIScreen mainScreen].bounds
#define kStatusBarH       ((iPhoneX||iPhoneXR||iPhoneXS||iPhoneXMAX)?44.0f:20.0f)// 顶部安全距离
#define kNavH             ((iPhoneX||iPhoneXR||iPhoneXS||iPhoneXMAX)?88.0f:64.0f)// 导航栏高度
#define kTabbarH          ((iPhoneX||iPhoneXR||iPhoneXS||iPhoneXMAX)?83.0f:49.0f)// Tabbar高度
#define kSafeBottomH      ((KIPHONEXPLUST)?34:0)// 底部安全距离
#define KIPHONEXPLUST     kScreenHeight >= 812//有刘海屏的iphone手机

/** 手机型号相关 */
#define kIS_IPHONE          (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kIS_IPAD            (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define kIS_IPOD            ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])
#define iPhoneX             ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 812)

#define iPhoneXS            ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 812)

#define iPhoneXR            ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 896)

#define iPhoneXMAX          ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 896)

#define iPhone6             ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 667)

#define iPhone6Plus          ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 736)

#define iPhone5sORiPhone5    ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.height) == 568)

#define iPhone4              ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone && MAX([UIScreen mainScreen].bounds.size.height,[UIScreen mainScreen].bounds.size.width) == 480)

/** 系统相关 */
#define kSYSTEM_VERSION      [[[UIDevice currentDevice] systemVersion] floatValue]
#define kPathDocument        [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define kPathLibrary         [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
#define kPathCache           [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

/** UI相关 */
//Font
#define kFont(x)                [UIFont systemFontOfSize:x]
#define kBoldFont(x)            [UIFont boldSystemFontOfSize:x]
//Color
#define kHexColor(hexValue)     [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0f]
//Image
#define kImage(imageName)                        [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define kBundleImage(__FILENAME__,__EXTENSION__) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:__FILENAME__ ofType:__EXTENSION__]]
//Radius
#define LXViewBorderRadius(View, Radius, Width, UIColor)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

/** Function相关*/
#define kApplication         [UIApplication sharedApplication]
#define kAppDelegate         (AppDelegate*)[[UIApplication sharedApplication] delegate]
#define kKeyWindow           [UIApplication sharedApplication].keyWindow
#define kUserDefaults        [NSUserDefaults standardUserDefaults]
#define kNotificationCenter  [NSNotificationCenter defaultCenter]
#define KPostNotification(name,obj,info) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj userInfo:info]
#define kFormat(format,...)  [NSString stringWithFormat:format,##__VA_ARGS__]

//空值判断
#define kISNullString(str)          ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
#define kISNullArray(array)         (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 ||[array isEqual:[NSNull null]])
#define kISNullDict(dic)            (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0 || [dic isEqual:[NSNull null]])
#define kISNullObject(_object)      (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//safe
#define kSafeBlock(blockName,...) ({!blockName ? nil : blockName(__VA_ARGS__);})


/** 其他 */
#define WeakSelf(type)            __weak typeof(type) weak##type = type;
#define StrongSelf(type)          __strong typeof(type) type = weak##type;

#ifdef DEBUG
#define kLog(FORMAT, ...)       fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...)      nil
#endif

#endif /* UtilsMacros_h */
