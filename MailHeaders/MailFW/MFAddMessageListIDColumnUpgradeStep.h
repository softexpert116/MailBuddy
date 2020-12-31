//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFLibraryUpgradeStep.h>

@class NSArray, NSDictionary, NSProgress;

@interface MFAddMessageListIDColumnUpgradeStep : MFLibraryUpgradeStep
{
    NSArray *_accounts;
    NSDictionary *_mailboxPathsByMailboxURL;
    NSProgress *_messageProgress;
}

+ (unsigned long long)targetVersion;
@property(retain, nonatomic) NSProgress *messageProgress; // @synthesize messageProgress=_messageProgress;
@property(retain, nonatomic) NSDictionary *mailboxPathsByMailboxURL; // @synthesize mailboxPathsByMailboxURL=_mailboxPathsByMailboxURL;
@property(readonly, copy, nonatomic) NSArray *accounts; // @synthesize accounts=_accounts;
- (void).cxx_destruct;
- (id)_listIDHashForMessageLibraryID:(long long)arg1 mailboxURL:(id)arg2;
- (void)_gatherListIDsSinceDate:(id)arg1;
- (void)runWithRowIDsNeedingConversationRecalculation:(id)arg1;
- (id)initWithDatabaseConnection:(id)arg1;
- (id)initWithDatabaseConnection:(id)arg1 accounts:(id)arg2;

@end
