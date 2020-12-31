//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "NSAnimationDelegate-Protocol.h"

@class NSLayoutConstraint, NSString, NSView, NSViewController;

@interface ActivityViewController : NSObject <NSAnimationDelegate>
{
    NSView *_contentView;
    NSViewController *_progressViewController;
    NSLayoutConstraint *_activityViewHeightConstraint;
}

@property(retain, nonatomic) NSLayoutConstraint *activityViewHeightConstraint; // @synthesize activityViewHeightConstraint=_activityViewHeightConstraint;
@property(retain, nonatomic) NSViewController *progressViewController; // @synthesize progressViewController=_progressViewController;
@property(retain, nonatomic) NSView *contentView; // @synthesize contentView=_contentView;
- (void).cxx_destruct;
- (void)_setVisible:(BOOL)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)dealloc;
- (void)awakeFromNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
