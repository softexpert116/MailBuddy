//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDictionary, NSUserDefaults;

@interface MFLegacyAccountStorage : NSObject
{
    NSDictionary *_accountsPlistContents;
    NSUserDefaults *_mailUserDefaults;
}

+ (id)legacyUIDForAccount:(id)arg1;
+ (id)smtpIdentifierWithHostname:(id)arg1 username:(id)arg2;
@property(readonly, nonatomic) NSUserDefaults *mailUserDefaults; // @synthesize mailUserDefaults=_mailUserDefaults;
@property(copy, nonatomic) NSDictionary *accountsPlistContents; // @synthesize accountsPlistContents=_accountsPlistContents;
- (void).cxx_destruct;
- (id)legacyTildeAbbreviatedAccountDirectoryPathForAccount:(id)arg1;
- (id)legacyAccountInfoForAccount:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (id)stringForKey:(id)arg1;
- (id)arrayForKey:(id)arg1;
- (id)objectForKey:(id)arg1;
- (id)init;

@end

