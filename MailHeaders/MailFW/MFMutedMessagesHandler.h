//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface MFMutedMessagesHandler : NSObject
{
}

+ (BOOL)archiveOrDeleteMutedMessages;
+ (void)setArchiveOrDeleteMutedMessages:(BOOL)arg1;
+ (void)handleMessages:(id)arg1 changeManager:(id)arg2;
+ (void)handleMessages:(id)arg1 store:(id)arg2;
+ (void)handleMutedMessages:(id)arg1 store:(id)arg2;

@end

