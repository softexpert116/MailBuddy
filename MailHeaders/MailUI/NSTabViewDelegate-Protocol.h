//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class NSTabView, NSTabViewItem;

@protocol NSTabViewDelegate <NSObject>

@optional
- (void)tabViewDidChangeNumberOfTabViewItems:(NSTabView *)arg1;
- (void)tabView:(NSTabView *)arg1 didSelectTabViewItem:(NSTabViewItem *)arg2;
- (void)tabView:(NSTabView *)arg1 willSelectTabViewItem:(NSTabViewItem *)arg2;
- (BOOL)tabView:(NSTabView *)arg1 shouldSelectTabViewItem:(NSTabViewItem *)arg2;
@end

