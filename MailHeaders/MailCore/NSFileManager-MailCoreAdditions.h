//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSFileManager.h>

@interface NSFileManager (MailCoreAdditions)
- (id)fileModificationDateAtPath:(id)arg1 traverseLink:(BOOL)arg2;
- (long long)fileSizeAtPath:(id)arg1 traverseLink:(BOOL)arg2;
- (id)createUniqueDirectoryAtPath:(id)arg1 withIntermediateDirectories:(BOOL)arg2 attributes:(id)arg3 error:(id *)arg4;
@end

