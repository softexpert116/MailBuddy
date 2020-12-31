//
//  ECMController.h
//  ECM
//
//  Created by ujs on 10/22/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <Cocoa/Cocoa.h>
#import "ECMWindowController.h"
#import "LicenseWindowController.h"

NS_ASSUME_NONNULL_BEGIN

@interface ECMController : NSObject
@property (strong, nonatomic) ECMWindowController *windowController;
@property (strong, nonatomic) LicenseWindowController *l_windowController;
+(void)backupLocaleDict;
+(NSDictionary*)initLocaleDictWithValue:(NSString*)val;
+(void)updateLocaleDictWithKey:(NSString*)key Value:(NSString*)val;
+(void)initializeUserDefaults;
+ (NSUserDefaults *) userDefaults;
+ (NSBundle *) bundle;
+ (NSMutableArray *)contacts;
+ (NSString *)bundleIdentifier;
+ (void) showAlertWithTitle: (NSString *)title Message: (NSString *)msg;
+ (NSLocale *)currentLocale;
+ (NSString *)localeIdentifier;
+ (BOOL)isLocaleSupported;
+ (BOOL)isSpecificLocale;
+(void)readContact;
+(NSString*)getNameFromEmail:(NSString*)email;

+ (NSString *)localizedString:(NSString *)key;
+ (NSString *)localizedString:(NSString *)key localeIdentifier:(NSString *)identifier;
+(void)setLanguage:(NSString *)language;
+(NSString*)localizedStringForKey:(NSString *)key value:(NSString *)value;
+(NSString *)get:(NSString *)key alter:(NSString *)alternate;
+ (BOOL)isElCapitan;
+ (NSString *) extractEmailAddress:(NSString *)address;
+ (NSString *) selectRandomStringFromArray:(NSArray *)array;
+ (BOOL) compareHour1:(NSString *)h1 Minute1:(NSString *)m1 Hour2:(NSString*)h2 Minute2:(NSString*)m2;
@end


NS_ASSUME_NONNULL_END
