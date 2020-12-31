//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "AssistantDelegate-Protocol.h"

@class Assistant, NSButton, NSEvent, NSString, NSView, NSWindow;

@interface AssistantManager : NSObject <AssistantDelegate>
{
    Assistant *_assistant;
    BOOL _userWantsToQuit;
    NSView *_assistantContainerView;
    NSButton *_backButton;
    NSButton *_forwardButton;
    NSButton *_cancelButton;
    NSWindow *_window;
    NSButton *_helpButton;
    NSEvent *_libraryUpgradeCompletedEvent;
    long long _type;
    AssistantManager *_me;
}

+ (BOOL)isImporting;
+ (BOOL)openAssistantOfType:(long long)arg1 modalForWindow:(id)arg2 userWantsToQuit:(char *)arg3;
+ (BOOL)openAssistantOfType:(long long)arg1 modalForWindow:(id)arg2;
@property(retain, nonatomic) AssistantManager *me; // @synthesize me=_me;
@property(nonatomic) BOOL userWantsToQuit; // @synthesize userWantsToQuit=_userWantsToQuit;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(retain, nonatomic) NSEvent *libraryUpgradeCompletedEvent; // @synthesize libraryUpgradeCompletedEvent=_libraryUpgradeCompletedEvent;
@property(nonatomic) __weak NSButton *helpButton; // @synthesize helpButton=_helpButton;
@property(retain, nonatomic) NSWindow *window; // @synthesize window=_window;
@property(nonatomic) __weak NSButton *cancelButton; // @synthesize cancelButton=_cancelButton;
@property(nonatomic) __weak NSButton *forwardButton; // @synthesize forwardButton=_forwardButton;
@property(nonatomic) __weak NSButton *backButton; // @synthesize backButton=_backButton;
@property(nonatomic) __weak NSView *assistantContainerView; // @synthesize assistantContainerView=_assistantContainerView;
- (void).cxx_destruct;
- (void)assistantDidFinish:(id)arg1;
- (void)_moveWindowToFront:(id)arg1;
- (void)_terminate;
- (void)_sheetWillBegin:(id)arg1;
- (void)_windowDidBecomeKey:(id)arg1;
- (void)_showInWindow:(id)arg1;
- (void)_start;
- (void)cancel:(id)arg1;
- (void)forward:(id)arg1;
- (void)back:(id)arg1;
- (void)dealloc;
- (id)_initWithType:(long long)arg1;
@property(retain, nonatomic) Assistant *assistant;
- (id)init;
- (id)_newAssistantOfType:(long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

