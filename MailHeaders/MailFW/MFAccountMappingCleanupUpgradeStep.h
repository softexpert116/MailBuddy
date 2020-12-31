//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFRemoveMessagesUpgradeStep.h>

@interface MFAccountMappingCleanupUpgradeStep : MFRemoveMessagesUpgradeStep
{
}

+ (BOOL)recalculateAllConversations;
+ (BOOL)needToPerformFromMinorVersion:(unsigned long long)arg1 initialLastWriteMinorVersion:(unsigned long long)arg2;
+ (unsigned long long)targetVersion;
- (void)_recalculateMessageCountsForPOPMailbox:(id)arg1;
- (BOOL)_addRecipientsForLibraryID:(long long)arg1 recipients:(id)arg2 recipientType:(BOOL)arg3 position:(int)arg4 cache:(id)arg5;
- (BOOL)_addRecipientsForLibraryIDFromMessage:(id)arg1 libraryID:(long long)arg2 cache:(id)arg3;
- (long long)_rowIDForAddressText:(id)arg1 cache:(id)arg2;
- (long long)_rowIDForSubject:(id)arg1 cache:(id)arg2;
- (id)_referencesAsEncodedMessageIDStringFromMessageHeaders:(id)arg1;
- (id)_insertMessages:(id)arg1 withMailbox:(id)arg2 error:(id *)arg3;
- (BOOL)_rebuildPOPMailbox:(id)arg1;
- (void)_rebuildPOPAccounts:(id)arg1;
- (void)_deleteMailboxesFromDatabase:(id)arg1;
- (id)_popAccountsNeedingRebuild:(id)arg1;
- (id)_fetchOrphanedMailboxIDs:(id *)arg1;
- (void)runWithRowIDsNeedingConversationRecalculation:(id)arg1;
- (id)initWithDatabaseConnection:(id)arg1 accounts:(id)arg2;

@end

