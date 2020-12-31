//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "AccountStatusDataSourceDelegate-Protocol.h"
#import "MCConnectionLogging-Protocol.h"
#import "MailTableViewDelegate-Protocol.h"

@class AccountStatusDataSource, MailTableView, NSButton, NSDrawer, NSMutableString, NSString, NSTextView, NSView, NSWindow;

@interface ConnectionDoctor : NSObject <AccountStatusDataSourceDelegate, MailTableViewDelegate, MCConnectionLogging>
{
    NSMutableString *_detailBuffer;
    NSWindow *_window;
    MailTableView *_tableView;
    NSButton *_checkStatusButton;
    NSDrawer *_detailDrawer;
    NSButton *_detailButton;
    NSView *_detailView;
    NSTextView *_detailTextView;
    AccountStatusDataSource *_deliveryASDS;
}

+ (id)sharedInstance;
+ (id)allocWithZone:(struct _NSZone *)arg1;
@property(retain, nonatomic) AccountStatusDataSource *deliveryASDS; // @synthesize deliveryASDS=_deliveryASDS;
@property(nonatomic) __weak NSTextView *detailTextView; // @synthesize detailTextView=_detailTextView;
@property(retain, nonatomic) NSView *detailView; // @synthesize detailView=_detailView;
@property(nonatomic) __weak NSButton *detailButton; // @synthesize detailButton=_detailButton;
@property(retain, nonatomic) NSDrawer *detailDrawer; // @synthesize detailDrawer=_detailDrawer;
@property(nonatomic) __weak NSButton *checkStatusButton; // @synthesize checkStatusButton=_checkStatusButton;
@property(nonatomic) __weak MailTableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) NSWindow *window; // @synthesize window=_window;
- (void).cxx_destruct;
- (void)flushLog;
- (void)logBytes:(void *)arg1 length:(unsigned long long)arg2;
- (void)logData:(id)arg1 range:(struct _NSRange)arg2;
- (void)logData:(id)arg1;
- (void)logString:(id)arg1;
- (void)_flushLog;
- (void)toggleDetail:(id)arg1;
- (void)showLogs:(id)arg1;
- (void)_logDebuggingInformationDidChange:(BOOL)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)windowWillClose:(id)arg1;
- (void)checkAccounts:(id)arg1;
- (void)_didRefreshStatusForAllAccounts:(id)arg1;
- (void)_willRefreshStatusForAllAccounts:(id)arg1;
- (void)show;
- (void)dealloc;
- (void)awakeFromNib;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

