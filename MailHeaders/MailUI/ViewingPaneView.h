//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSView.h>

@class NSHashTable;

@interface ViewingPaneView : NSView
{
    NSHashTable *_topAlignedSubviews;
    NSHashTable *_managedConstraints;
    NSView *_contentView;
    BOOL _isVertical;
}

+ (BOOL)automaticallyNotifiesObserversOfContentView;
@property(nonatomic) BOOL isVertical; // @synthesize isVertical=_isVertical;
- (void).cxx_destruct;
- (void)viewDidMoveToWindow;
- (void)updateConstraints;
- (void)setContentView:(id)arg1 titlebarAligned:(BOOL)arg2;
@property(readonly, nonatomic) NSView *contentView;
- (void)_viewingPaneViewCommonInit;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

