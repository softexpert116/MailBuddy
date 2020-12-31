//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSButton.h>

#import "NSMenuDelegate-Protocol.h"

@class NSMenu, NSString;
@protocol ClippedItemsIndicatorDelegate;

@interface ClippedItemsIndicator : NSButton <NSMenuDelegate>
{
    NSMenu *_menu;
    id <ClippedItemsIndicatorDelegate> _delegate;
}

@property(nonatomic) __weak id <ClippedItemsIndicatorDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSMenu *menu; // @synthesize menu=_menu;
- (void).cxx_destruct;
- (void)menuDidClose:(id)arg1;
- (void)_popUpMenu;
- (void)mouseDown:(id)arg1;
- (void)_clippedItemsIndicatorCommonInit;
- (id)init;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

