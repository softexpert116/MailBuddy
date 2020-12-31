//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "RichMessageCellBase.h"

@class CNAvatarViewController, MessageStatusStackView, NSAttributedString, NSColor, NSImageView, NSLayoutConstraint, NSMutableArray, NSTextField, ThreadDisclosureTextField, ToCCIndicator;

@interface RichMessageCellView : RichMessageCellBase
{
    NSColor *_textColor;
    CNAvatarViewController *_avatarViewController;
    unsigned long long _numberOfSnippetLines;
    BOOL _showToCc;
    BOOL _showMailbox;
    BOOL _showSize;
    NSTextField *_senderView;
    NSTextField *_subjectView;
    NSTextField *_snippetView;
    NSTextField *_dateView;
    NSLayoutConstraint *_avatarWidthConstraint;
    ToCCIndicator *_toCcIndicator;
    NSLayoutConstraint *_toCcHeightConstraint;
    NSLayoutConstraint *_toCcSenderAlignment;
    NSLayoutConstraint *_toCcSubjectAlignment;
    NSLayoutConstraint *_toCcSubjectSpacing;
    ThreadDisclosureTextField *_threadDisclosureControl;
    NSLayoutConstraint *_threadMargin;
    NSLayoutConstraint *_threadDatePadding;
    NSLayoutConstraint *_threadSubjectPadding;
    NSLayoutConstraint *_threadSnippetPadding;
    NSLayoutConstraint *_threadSizeVerticalPadding;
    NSLayoutConstraint *_threadSizeHorizontalPadding;
    NSImageView *_unreadView;
    NSImageView *_vipView;
    NSImageView *_flagStatusView;
    NSImageView *_attachmentView;
    NSImageView *_statusView;
    NSImageView *_mutedView;
    NSLayoutConstraint *_statusAlignment;
    NSLayoutConstraint *_statusSenderPadding;
    NSLayoutConstraint *_statusDatePadding;
    NSLayoutConstraint *_statusSenderHeight;
    MessageStatusStackView *_statusStack;
    NSTextField *_mailboxView;
    NSLayoutConstraint *_subjectMailboxPadding;
    NSLayoutConstraint *_subjectMailboxAlignment;
    NSLayoutConstraint *_mailboxDateAlignment;
    NSLayoutConstraint *_mailboxThreadPadding;
    NSLayoutConstraint *_mailboxSizePadding;
    NSTextField *_sizeView;
    NSLayoutConstraint *_sizeDateAlignment;
    NSLayoutConstraint *_subjectSizeAlignment;
    NSLayoutConstraint *_subjectSizeHorizontalPadding;
    NSMutableArray *_flagViews;
}

+ (double)photoDimensionForPhotoSize:(long long)arg1;
+ (id)keyPathsForValuesAffectingThreadCount;
+ (id)keyPathsForValuesAffectingIsOpen;
+ (id)keyPathsForValuesAffectingSnippetString;
@property(readonly, nonatomic) NSMutableArray *flagViews; // @synthesize flagViews=_flagViews;
@property(retain, nonatomic) NSLayoutConstraint *subjectSizeHorizontalPadding; // @synthesize subjectSizeHorizontalPadding=_subjectSizeHorizontalPadding;
@property(retain, nonatomic) NSLayoutConstraint *subjectSizeAlignment; // @synthesize subjectSizeAlignment=_subjectSizeAlignment;
@property(retain, nonatomic) NSLayoutConstraint *sizeDateAlignment; // @synthesize sizeDateAlignment=_sizeDateAlignment;
@property(retain, nonatomic) NSTextField *sizeView; // @synthesize sizeView=_sizeView;
@property(retain, nonatomic) NSLayoutConstraint *mailboxSizePadding; // @synthesize mailboxSizePadding=_mailboxSizePadding;
@property(retain, nonatomic) NSLayoutConstraint *mailboxThreadPadding; // @synthesize mailboxThreadPadding=_mailboxThreadPadding;
@property(retain, nonatomic) NSLayoutConstraint *mailboxDateAlignment; // @synthesize mailboxDateAlignment=_mailboxDateAlignment;
@property(retain, nonatomic) NSLayoutConstraint *subjectMailboxAlignment; // @synthesize subjectMailboxAlignment=_subjectMailboxAlignment;
@property(retain, nonatomic) NSLayoutConstraint *subjectMailboxPadding; // @synthesize subjectMailboxPadding=_subjectMailboxPadding;
@property(retain, nonatomic) NSTextField *mailboxView; // @synthesize mailboxView=_mailboxView;
@property(retain, nonatomic) MessageStatusStackView *statusStack; // @synthesize statusStack=_statusStack;
@property(retain, nonatomic) NSLayoutConstraint *statusSenderHeight; // @synthesize statusSenderHeight=_statusSenderHeight;
@property(retain, nonatomic) NSLayoutConstraint *statusDatePadding; // @synthesize statusDatePadding=_statusDatePadding;
@property(retain, nonatomic) NSLayoutConstraint *statusSenderPadding; // @synthesize statusSenderPadding=_statusSenderPadding;
@property(retain, nonatomic) NSLayoutConstraint *statusAlignment; // @synthesize statusAlignment=_statusAlignment;
@property(retain, nonatomic) NSImageView *mutedView; // @synthesize mutedView=_mutedView;
@property(retain, nonatomic) NSImageView *statusView; // @synthesize statusView=_statusView;
@property(retain, nonatomic) NSImageView *attachmentView; // @synthesize attachmentView=_attachmentView;
@property(retain, nonatomic) NSImageView *flagStatusView; // @synthesize flagStatusView=_flagStatusView;
@property(retain, nonatomic) NSImageView *vipView; // @synthesize vipView=_vipView;
@property(retain, nonatomic) NSImageView *unreadView; // @synthesize unreadView=_unreadView;
@property(retain, nonatomic) NSLayoutConstraint *threadSizeHorizontalPadding; // @synthesize threadSizeHorizontalPadding=_threadSizeHorizontalPadding;
@property(retain, nonatomic) NSLayoutConstraint *threadSizeVerticalPadding; // @synthesize threadSizeVerticalPadding=_threadSizeVerticalPadding;
@property(retain, nonatomic) NSLayoutConstraint *threadSnippetPadding; // @synthesize threadSnippetPadding=_threadSnippetPadding;
@property(retain, nonatomic) NSLayoutConstraint *threadSubjectPadding; // @synthesize threadSubjectPadding=_threadSubjectPadding;
@property(retain, nonatomic) NSLayoutConstraint *threadDatePadding; // @synthesize threadDatePadding=_threadDatePadding;
@property(retain, nonatomic) NSLayoutConstraint *threadMargin; // @synthesize threadMargin=_threadMargin;
@property(retain, nonatomic) ThreadDisclosureTextField *threadDisclosureControl; // @synthesize threadDisclosureControl=_threadDisclosureControl;
@property(retain, nonatomic) NSLayoutConstraint *toCcSubjectSpacing; // @synthesize toCcSubjectSpacing=_toCcSubjectSpacing;
@property(retain, nonatomic) NSLayoutConstraint *toCcSubjectAlignment; // @synthesize toCcSubjectAlignment=_toCcSubjectAlignment;
@property(retain, nonatomic) NSLayoutConstraint *toCcSenderAlignment; // @synthesize toCcSenderAlignment=_toCcSenderAlignment;
@property(retain, nonatomic) NSLayoutConstraint *toCcHeightConstraint; // @synthesize toCcHeightConstraint=_toCcHeightConstraint;
@property(retain, nonatomic) ToCCIndicator *toCcIndicator; // @synthesize toCcIndicator=_toCcIndicator;
@property(retain, nonatomic) NSLayoutConstraint *avatarWidthConstraint; // @synthesize avatarWidthConstraint=_avatarWidthConstraint;
@property(nonatomic) __weak NSTextField *dateView; // @synthesize dateView=_dateView;
@property(nonatomic) __weak NSTextField *snippetView; // @synthesize snippetView=_snippetView;
@property(nonatomic) __weak NSTextField *subjectView; // @synthesize subjectView=_subjectView;
@property(nonatomic) __weak NSTextField *senderView; // @synthesize senderView=_senderView;
- (void).cxx_destruct;
- (void)setThreadDisclosureTarget:(id)arg1;
- (void)setThreadDisclosureAction:(SEL)arg1;
- (void)_updateFlagViewsWithImages:(id)arg1;
- (id)_anchorViewForNewFlag:(double *)arg1;
- (void)_updateAvatarViewWithContacts:(id)arg1;
- (void)_updateToCCIndicatorWithString:(id)arg1;
- (void)_updateThreadControlWithThreadCount:(unsigned long long)arg1;
- (void)_updateSizeLabel;
- (void)_updateMailboxLabel;
- (void)_updateReplyButtonWithImage:(id)arg1;
- (void)_updateAttachmentViewWithImage:(id)arg1;
- (void)_updateMutedIndicatorWithImage:(id)arg1;
- (void)_updateVIPIndicatorWithImage:(id)arg1;
- (void)_updateUnreadIndicatorWithImage:(id)arg1;
- (void)_updateStatusViewWithImage:(id)arg1;
- (void)prepareForReuse;
- (void)viewWillMoveToWindow:(id)arg1;
- (BOOL)acceptsFirstResponder;
- (BOOL)canBecomeKeyView;
@property(nonatomic) unsigned long long numberOfSnippetLines;
- (void)setBackgroundStyle:(long long)arg1;
- (void)setObjectValue:(id)arg1;
@property(readonly, nonatomic) unsigned long long threadCount;
@property(readonly, nonatomic) BOOL isOpen;
@property(readonly, nonatomic) NSAttributedString *snippetString;
- (id)snippetStringAttributes;
- (double)defaultRowHeight;
@property(readonly, nonatomic) CNAvatarViewController *avatarViewController;
- (void)setShowSize:(BOOL)arg1;
- (BOOL)showSize;
- (void)setShowMailbox:(BOOL)arg1;
- (BOOL)showMailbox;
- (void)setShowToCc:(BOOL)arg1;
- (BOOL)showToCc;
- (BOOL)isHighlighted;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)dealloc;
- (void)awakeFromNib;
- (void)_richTableCellViewCommonInit;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)updateFontsUsingBold:(BOOL)arg1;

@end

