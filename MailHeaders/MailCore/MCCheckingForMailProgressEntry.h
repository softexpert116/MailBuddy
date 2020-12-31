//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <MailCore/MCProgressEntry.h>

@interface MCCheckingForMailProgressEntry : MCProgressEntry
{
    BOOL _foundNewUnreadMessageInInbox;
    BOOL _userInitiated;
    unsigned long long _foundMessages;
}

+ (id)keyPathsForValuesAffectingShouldDisplay;
+ (id)keyPathsForValuesAffectingStatusText;
+ (id)keyPathsForValuesAffectingProgressName;
@property(nonatomic) BOOL userInitiated; // @synthesize userInitiated=_userInitiated;
@property(nonatomic) BOOL foundNewUnreadMessageInInbox; // @synthesize foundNewUnreadMessageInInbox=_foundNewUnreadMessageInInbox;
@property(nonatomic) unsigned long long foundMessages; // @synthesize foundMessages=_foundMessages;
- (BOOL)shouldDisplay;
- (double)finishDelay;
- (void)refreshValues;
- (id)observedProgressKeypaths;
- (id)progressSlice;
- (BOOL)indeterminate;
- (id)statusText;
- (id)progressName;

@end

