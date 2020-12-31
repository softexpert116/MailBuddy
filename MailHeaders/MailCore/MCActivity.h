//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSProgress;
@protocol MCActivityDelegate;

@interface MCActivity : NSObject
{
    BOOL _isFinished;
    id <MCActivityDelegate> _delegate;
    NSProgress *_progress;
    long long _qualityOfService;
}

@property(nonatomic) long long qualityOfService; // @synthesize qualityOfService=_qualityOfService;
@property(nonatomic) BOOL isFinished; // @synthesize isFinished=_isFinished;
@property(retain, nonatomic) NSProgress *progress; // @synthesize progress=_progress;
@property(nonatomic) __weak id <MCActivityDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)cancel;
- (void)end;
- (void)resume;
- (void)suspend;
- (void)begin;
- (void)dealloc;
- (id)init;

@end

