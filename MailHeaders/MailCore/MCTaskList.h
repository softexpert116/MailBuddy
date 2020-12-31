//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSDictionary;
@protocol MCTaskListDelegate;

@interface MCTaskList : NSObject
{
    id <MCTaskListDelegate> _delegate;
    NSArray *_sortingKeys;
    NSDictionary *_listsByKey;
    NSDictionary *_comparatorsByKey;
}

+ (CDUnknownBlockType)_newComparatorForKey:(id)arg1;
@property(readonly, copy, nonatomic) NSDictionary *comparatorsByKey; // @synthesize comparatorsByKey=_comparatorsByKey;
@property(readonly, copy, nonatomic) NSDictionary *listsByKey; // @synthesize listsByKey=_listsByKey;
@property(readonly, copy, nonatomic) NSArray *sortingKeys; // @synthesize sortingKeys=_sortingKeys;
@property(nonatomic) __weak id <MCTaskListDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)_insertTask:(id)arg1 intoListWithKey:(id)arg2;
- (void)_extractTask:(id)arg1 fromListWithKey:(id)arg2;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)enumerateTasksForKey:(id)arg1 usingBlock:(CDUnknownBlockType)arg2;
- (id)copyOfListForKey:(id)arg1;
- (id)highestPriorityTaskForKey:(id)arg1;
@property(readonly, nonatomic) unsigned long long taskCount;
- (void)removeTask:(id)arg1;
- (void)addTask:(id)arg1;
- (void)dealloc;
- (id)description;
- (id)init;
- (id)initWithSortingKeys:(id)arg1;

@end

