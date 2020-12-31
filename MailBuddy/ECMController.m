//
//  ECMController.m
//  ECM
//
//  Created by ujs on 10/22/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "ECMController.h"
#import <objc/objc-runtime.h>
#import "MVMailBundle.h"
#import "CodeInjector.h"
#import "Constants.h"
#import <Contacts/Contacts.h>

int LoggingLevel = 0;

@implementation ECMController
static NSUserDefaults* userDefaults;
static NSBundle *bundle = nil;
static NSMutableArray *contacts;

+ (void)initialize
{
    if(self != [ECMController class])
        return;
    
    Class mvMailBundleClass = NSClassFromString(@"MVMailBundle");
    if(!mvMailBundleClass)
        return;
    
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated"
        class_setSuperclass([self class], mvMailBundleClass);
    #pragma GCC diagnostic pop
    
    [self sharedInstance];
    userDefaults = [NSUserDefaults standardUserDefaults];
    contacts = [[NSMutableArray alloc] init];
    [self readContact];
//    CNContact* ct = [contacts objectAtIndex:10];
//    [ECMController showAlertWithTitle:@"" Message:[NSString stringWithFormat:@"%@", ct]];
//    [self initializeUserDefaults];
    [self backupLocaleDict];
    [[((MVMailBundle *)self) class] registerBundle];
}
+(void)readContact {
    if ([CNContactStore class]) {
        CNContactStore *addressBook = [[CNContactStore alloc] init];
        NSArray *keyToFetch = @[CNContactEmailAddressesKey, CNContactFamilyNameKey, CNContactGivenNameKey, CNContactPhoneNumbersKey, CNContactPostalAddressesKey];
        CNContactFetchRequest *fetchRequest = [[CNContactFetchRequest alloc] initWithKeysToFetch:keyToFetch];
        [addressBook enumerateContactsWithFetchRequest:fetchRequest error:nil usingBlock:^(CNContact * _Nonnull contact, BOOL * _Nonnull stop) {
            [contacts addObject:contact];
        }];
    }
}
+(NSString*)getNameFromEmail:(NSString*)email {
    NSString* name;
    for (CNContact *contact in contacts) {
        CNLabeledValue *emailValue = contact.emailAddresses.firstObject;
        if (emailValue != nil) {
            NSString *emailString = emailValue.value;
            if ([emailString isEqual:email]) {
                name = [NSString stringWithFormat:@"%@ %@", [contact givenName], [contact familyName]];
                break;
            }
        }
    }
//    [ECMController showAlertWithTitle:@"contact name" Message:name];
    return name;
}
+(void)backupLocaleDict {
        
    [ECMController.userDefaults setInteger:0 forKey:key_format_type];
    [ECMController.userDefaults setBool:YES forKey:key_auto_greet];
    
    NSMutableDictionary* dict = [NSMutableDictionary new];
    
    NSArray *localizations = [[ECMController bundle] localizations];
    for (NSString *loc in localizations) {
        [dict setValue:[ECMController localizedString:@"STRING_custom" localeIdentifier:loc] forKey:loc];
    }
    [userDefaults setObject:dict forKey:key_custom_text];
    dict = [dict init];
    for (NSString *loc in localizations) {
        [dict setValue:[ECMController localizedString:@"STRING_random" localeIdentifier:loc] forKey:loc];
    }
    [userDefaults setObject:dict forKey:key_random_text];
    dict = [dict init];
    for (NSString *loc in localizations) {
        [dict setValue:[ECMController localizedString:@"STRING_time1" localeIdentifier:loc] forKey:loc];
    }
    [userDefaults setObject:dict forKey:key_time_text1];
    dict = [dict init];
    for (NSString *loc in localizations) {
        [dict setValue:[ECMController localizedString:@"STRING_time2" localeIdentifier:loc] forKey:loc];
    }
    [userDefaults setObject:dict forKey:key_time_text2];
    dict = [dict init];
    for (NSString *loc in localizations) {
        [dict setValue:[ECMController localizedString:@"STRING_time3" localeIdentifier:loc] forKey:loc];
    }
    [userDefaults setObject:dict forKey:key_time_text3];
}
+(NSDictionary*)initLocaleDictWithValue:(NSString*)val {
    NSMutableDictionary* dict = [NSMutableDictionary new];
    
    NSArray *localizations = [[ECMController bundle] localizations];
    for (NSString *loc in localizations) {
        [dict setValue:@"" forKey:loc];
        if ([GET_DEFAULT(ECMLanguageCode) isEqualToString:loc]) {
            [dict setValue:val forKey:loc];
        }
    }
//    [ECMController showAlertWithTitle:@"" Message:[NSString stringWithFormat:@"%@", dict]];
    return dict;
}
+(void)updateLocaleDictWithKey:(NSString*)key Value:(NSString*)val {
    NSMutableDictionary* dict = [[userDefaults objectForKey:key] mutableCopy];
    [dict setValue:val forKey:GET_DEFAULT(ECMLanguageCode)];
//    [self showAlertWithTitle:@"" Message:[NSString stringWithFormat:@"%@", dict]];
    [userDefaults setObject:dict forKey:key];
}
+(void)initializeUserDefaults {
    if ([ECMController.userDefaults objectForKey:key_format_type] == nil) {
        [userDefaults setObject:@"Custom" forKey:key_format_type];
    }
    if ([userDefaults objectForKey:key_custom_text] == nil) {
        [userDefaults setObject:[self initLocaleDictWithValue:[ECMController localizedString:@"STRING_custom"]] forKey:key_custom_text];
    }
    if ([userDefaults objectForKey:key_random_text] == nil) {
        [userDefaults setObject:[self initLocaleDictWithValue:[ECMController localizedString:@"STRING_random"]] forKey:key_random_text];
    }
    if ([userDefaults objectForKey:key_time_text1] == nil) {
        [userDefaults setObject:[self initLocaleDictWithValue:[ECMController localizedString:@"STRING_time1"]] forKey:key_time_text1];
    }
    if ([userDefaults objectForKey:key_time_text2] == nil) {
        [userDefaults setObject:[self initLocaleDictWithValue:[ECMController localizedString:@"STRING_time2"]] forKey:key_time_text2];
    }
    if ([userDefaults objectForKey:key_time_text3] == nil) {
        [userDefaults setObject:[self initLocaleDictWithValue:[ECMController localizedString:@"STRING_time3"]] forKey:key_time_text3];
    }
}
//
// -----------------------------------------------------------------------------
+ (NSUserDefaults*) userDefaults { return [NSUserDefaults standardUserDefaults]; }

+ (instancetype)sharedInstance
{
    static dispatch_once_t onceToken;
    static ECMController *instance;
    dispatch_once(&onceToken, ^{
        instance = [[ECMController alloc] init];
    });
    
    return instance;
}
+ (NSString *) extractEmailAddress: (NSString *)address
{
    NSRange r = [address rangeOfString:@"<" options:NSBackwardsSearch];
    NSString *senderEmail = [address substringFromIndex:r.location + 1];
    r = [senderEmail rangeOfString:@">" options:NSBackwardsSearch];
    return [senderEmail substringToIndex:r.location];
}
+ (BOOL)isElCapitan {
    NSProcessInfo *info = [NSProcessInfo processInfo];
    if(![info respondsToSelector:@selector(isOperatingSystemAtLeastVersion:)])
        return NO;
    
    NSOperatingSystemVersion requiredVersion = {10,11,0};
    return [info isOperatingSystemAtLeastVersion:requiredVersion];
}
+ (void) showAlertWithTitle: (NSString *)title Message: (NSString *)msg
{
    NSAlert *alert = [NSAlert alertWithMessageText:title defaultButton:@"Ok" alternateButton:nil otherButton:nil informativeTextWithFormat:msg];
    [alert runModal];
}
//+(void)setLanguage:(NSString *)l
//{
//    NSLog(@"preferredLang: %@", l);
//    NSString *path = [[ NSBundle mainBundle ] pathForResource:l ofType:@"lproj" ];
//    bundle = [NSBundle bundleWithPath:path];
//}
+(void)setLanguage:(NSString*)language
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        object_setClass([NSBundle mainBundle],[ECMController class]);
    });
    objc_setAssociatedObject([NSBundle mainBundle], &bundle, language ? [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:language ofType:@"lproj"]] : nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
+(NSString*)localizedStringForKey:(NSString *)key value:(NSString *)value
{
    NSBundle* bundle1=objc_getAssociatedObject(self, &bundle);
    return bundle1 ? [bundle1 localizedStringForKey:key value:value table:nil] : [bundle localizedStringForKey:key value:value table:nil];
}
+(NSString *)get:(NSString *)key alter:(NSString *)alternate
{
    return [bundle localizedStringForKey:key value:alternate table:nil];
}

+ (NSLocale *)currentLocale
{
    static NSLocale *locale;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *identifier = [self localeIdentifier];
        locale = [[NSLocale alloc] initWithLocaleIdentifier:identifier];
    });
    return [NSLocale currentLocale];
}

+ (NSString *)localeIdentifier
{
    NSString *identifier = [[userDefaults objectForKey:@"AppleLanguages"] objectAtIndex:0];
    
    if ([identifier hasPrefix:@"en-US"] || [identifier hasPrefix:@"en-GB"]){
        // use as-is
        identifier = @"en";
    } else if ([identifier hasPrefix:@"en"])
        identifier = @"en"; // for issue #39 - considering all en-* into one umberlla
    else if ([identifier hasPrefix:@"zh-Hans"] || [identifier isEqualToString:@"zh_CN"])
        identifier = @"zh-Hans";
    else if ([identifier hasPrefix:@"zh-Hant"] || [identifier isEqualToString:@"zh_TW"])
        identifier = @"zh-Hant";
    else if ([identifier hasPrefix:@"no"] || [identifier hasPrefix:@"nb"])
        identifier = @"nb"; // for issue #52 - 'Norwegian Bokmål (nb, no)' locale support
    else if ([identifier hasPrefix:@"de"])
        identifier = @"de";
    else if ([identifier hasPrefix:@"es"])
        identifier = @"es";
    else if ([identifier hasPrefix:@"fr"])
        identifier = @"fr";
    else if ([identifier hasPrefix:@"it"])
        identifier = @"it";
    else if ([identifier hasPrefix:@"ja"])
        identifier = @"ja";
    else if ([identifier hasPrefix:@"ko"])
        identifier = @"ko";
    else if ([identifier hasPrefix:@"nl"])
        identifier = @"nl";
    else if ([identifier hasPrefix:@"pt-BR"]) {
        // use as-is
    } else if ([identifier hasPrefix:@"pt_PT"] || [identifier hasPrefix:@"pt-PT"]) {
        identifier = @"pt-PT";
    } else if ([identifier hasPrefix:@"pt"])
        identifier = @"pt";
    else if ([identifier hasPrefix:@"ru"])
        identifier = @"ru";
    else if ([identifier hasPrefix:@"sv"])
        identifier = @"sv";
    else if ([identifier hasPrefix:@"uk"])
        identifier = @"uk";
    
    return [identifier stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

// for issue #21 - https://github.com/jeevatkm/ReplyWithHeader/issues/21
+ (BOOL)isLocaleSupported
{
    NSString *locale = [self localeIdentifier];
    BOOL supported = [[[self bundle] localizations] containsObject:locale];
    
    return supported;
}

+ (BOOL)isSpecificLocale
{
    NSString *currentLocaleIdentifier = [self localeIdentifier];
    return ([currentLocaleIdentifier isEqualToString:@"ja"]
            || [currentLocaleIdentifier isEqualToString:@"zh-Hans"]
            || [currentLocaleIdentifier isEqualToString:@"zh-Hant"]);
}
+ (NSString *)localizedString:(NSString *)key
{
    NSBundle *mhBundle = [self bundle];
    NSString *localString = NSLocalizedStringFromTableInBundle(key, @"Localizable", mhBundle, nil);
    if(![localString isEqualToString:key])
        return localString;

    return [self localizedString:key localeIdentifier:@"Base"];
}

+ (NSString *)localizedString:(NSString *)key localeIdentifier:(NSString *)identifier
{
    NSString *filePath = [[self bundle] pathForResource:@"Localizable"
                                                       ofType:@"strings"
                                                  inDirectory:@""
                                              forLocalization:identifier];
    NSDictionary *stringDict = [NSDictionary dictionaryWithContentsOfFile:filePath];

    NSString *string = [stringDict objectForKey:key];

    if ( string == nil )
    {
        return [self localizedString:key localeIdentifier:@"en"];
    }

    return [stringDict objectForKey:key];
}
+ (NSBundle *)bundle
{
    static NSBundle *bundle;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bundle = [NSBundle bundleForClass:[ECMController class]];
    });
    return bundle;
}

+ (NSString *)bundleIdentifier
{
    return [[[self bundle] infoDictionary] objectForKey:ECMBundleIdentifier];
}


//
// -----------------------------------------------------------------------------
- (instancetype)init
{
    self = [super init];
    
    if (self) {
        [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector(initMenu)
        name:@"initMenu"
        object:nil];
        [self initMenu];

        [CodeInjector injectUsingMethodPrefix:@"MPP"];
        
    }
    
    return self;
}


- (void)openECM {
    NSInteger trial = [ECMController.userDefaults integerForKey:trial_days];
    if (trial == 0) {
        [[NSNotificationCenter defaultCenter]
        postNotificationName:@"initMenu"
        object:nil userInfo:nil];
        
        NSAlert *alert = [NSAlert alertWithMessageText:@"Warning" defaultButton:@"Ok" alternateButton:nil otherButton:nil informativeTextWithFormat:@"TrialDay is over."];
        [alert runModal];
        return;
    }
    [ECMController.userDefaults setInteger:trial-1 forKey:trial_days];
    _windowController = [[ECMWindowController alloc] initWithWindowNibName:@"ECMWindowController"];
//    [_windowController showWindow:self];
    [NSApp runModalForWindow:[_windowController window]];
}
- (void)openLicense {
    _l_windowController = [[LicenseWindowController alloc] initWithWindowNibName:@"LicenseWindowController"];
    [NSApp runModalForWindow:[_l_windowController window]];
    
}

- (void)initMenu {
    
    NSApplication *application = [NSApplication sharedApplication];
    NSMenu *theMenu = application.mainMenu;
    NSArray* itemArray = [theMenu itemArray];
    for (NSMenuItem* item in itemArray) {
        NSString* title = [item submenu].title;
        
        if ([title isEqualToString:@"MailBuddy"]) {
            [theMenu removeItem:item];
            break;
        }
    }
    NSMenuItem* subGroup = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
    [theMenu addItem:subGroup];
    
    NSMenu *subMenu = [[NSMenu alloc] initWithTitle:@"MailBuddy"];
    NSMenuItem *licenseItem = [[NSMenuItem alloc] initWithTitle:@"License" action:@selector(openLicense) keyEquivalent:@""];
    [licenseItem setTarget:self];
    [subMenu addItem:licenseItem];

    NSMenuItem *openItem = [[NSMenuItem alloc] initWithTitle:@"Open" action:@selector(openECM) keyEquivalent:@""];
    if ([ECMController.userDefaults integerForKey:trial_days] > 0) {
        [openItem setTarget:self];
    }
    [subMenu addItem:openItem];


    [theMenu setSubmenu:subMenu forItem:subGroup];
}
+ (NSString *) selectRandomStringFromArray:(NSArray *)array {
    NSUInteger myCount = [array count];
    if (myCount)
        return [array objectAtIndex:arc4random_uniform(myCount)];
    else
        return nil;
}
+ (BOOL) compareHour1:(NSString *)h1 Minute1:(NSString *)m1 Hour2:(NSString*)h2 Minute2:(NSString*)m2 {
    if (h1.intValue > h2.intValue) {
        return YES;
    } else if (h1.intValue == h2.intValue) {
        if (m1.intValue >= m2.intValue) {
            return YES;
        } else {
            return NO;
        }
    } else {
        return NO;
    }
}



@end
