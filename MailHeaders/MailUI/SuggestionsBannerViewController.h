//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import "SGSuggestionPresenterDelegate-Protocol.h"

@class ConversationMember, NSLayoutConstraint, NSString;

@interface SuggestionsBannerViewController : NSViewController <SGSuggestionPresenterDelegate>
{
    BOOL _isSingleton;
    NSLayoutConstraint *_verticalBannerConstraint;
    NSLayoutConstraint *_leadingBannerConstraint;
    NSLayoutConstraint *_trailingBannerConstraint;
}

+ (id)_suggestionsService;
+ (id)suggestionsServiceLog;
@property(retain, nonatomic) NSLayoutConstraint *trailingBannerConstraint; // @synthesize trailingBannerConstraint=_trailingBannerConstraint;
@property(retain, nonatomic) NSLayoutConstraint *leadingBannerConstraint; // @synthesize leadingBannerConstraint=_leadingBannerConstraint;
@property(retain, nonatomic) NSLayoutConstraint *verticalBannerConstraint; // @synthesize verticalBannerConstraint=_verticalBannerConstraint;
@property(nonatomic) BOOL isSingleton; // @synthesize isSingleton=_isSingleton;
- (void).cxx_destruct;
- (void)suggestionPresenterWantsToShowBanner:(id)arg1;
- (void)suggestionPresenterWantsToHideBanner:(id)arg1;
- (void)_updateViewAppearance;
- (void)_updateConstraints;
- (void)updateViewConstraints;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
@property(retain, nonatomic) ConversationMember *representedObject;
- (void)viewDidLoad;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

