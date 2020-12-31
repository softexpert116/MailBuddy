//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import "ComposeBackEndDelegate-Protocol.h"
#import "LoadingOverlayModalDelegate-Protocol.h"
#import "MCActivityTarget-Protocol.h"
#import "PopoutAnimationContentProvider-Protocol.h"
#import "ReportBugWindowControllerDelegate-Protocol.h"
#import "TerminationHandler-Protocol.h"

@class ComposeBackEnd, ComposeStatusView, DeliveryFailure, EFFuture, EditableWebMessageDocument, EditingWebMessageController, FindBarContainer, HeadersEditor, LoadingOverlay, MCAttachment, NSArray, NSButton, NSDictionary, NSOperation, NSOperationQueue, NSStackView, NSString, NSTextFinder, NSTouchBar, NSView, ReportBugWindowController, WebArchive, WebViewEditor, _ControllerTitleTransformer;
@protocol ComposeContext, ComposeViewControllerDelegate;

@interface ComposeViewController : NSViewController <LoadingOverlayModalDelegate, ReportBugWindowControllerDelegate, NSTouchBarDelegate, ComposeBackEndDelegate, MCActivityTarget, NSTextFinderClient, NSSharingServiceDelegate, NSUserInterfaceValidations, PopoutAnimationContentProvider, TerminationHandler>
{
    ComposeBackEnd *_backEnd;
    BOOL _showsConfirmSendingTouchBar;
    NSTouchBar *_standardTouchBar;
    NSTouchBar *_confirmSendingTouchBar;
    id _confirmSendingTouchBarEventMonitor;
    BOOL _shouldSaveWhenClosing;
    BOOL _hasIncludedAttachmentsFromOriginal;
    BOOL _isShareKitOriginated;
    BOOL _isFinishedLoading;
    BOOL _sendWhenFinishLoading;
    BOOL _wantsToClose;
    BOOL _userSavedMessage;
    BOOL _isAutoSaving;
    BOOL _hasUserMadeChanges;
    BOOL _isBeingPreparedForSending;
    BOOL _userKnowsSaveFailed;
    BOOL _shouldIncludeEditingHistoryInDiagnostics;
    BOOL _shouldUseObfuscationWhenSavingEditingHistory;
    id <ComposeViewControllerDelegate> _delegate;
    WebViewEditor *_webViewEditor;
    HeadersEditor *_headersEditor;
    long long _messageType;
    LoadingOverlay *_loadingOverlay;
    NSStackView *_contentStack;
    NSString *_URLShareUUID;
    WebArchive *_pageWebArchive;
    WebArchive *_readerWebArchive;
    MCAttachment *_PDFAttachment;
    ComposeStatusView *_composeStatusView;
    NSView *_clippingView;
    unsigned long long _textLengthForLastEstimatedMessageSize;
    NSOperationQueue *_operationQueue;
    NSView *_statusRow;
    NSDictionary *_toolbarItems;
    NSOperation *_savedFinishLoadingEditorOperation;
    _ControllerTitleTransformer *_titleTransformer;
    DeliveryFailure *_deliveryFailure;
    NSArray *_unapprovedRecipients;
    NSButton *_includeExcludeAttachmentsButton;
    ReportBugWindowController *_reportBugWindowController;
    EditingWebMessageController *_webMessageController;
    NSDictionary *_settings;
    FindBarContainer *_findBarContainer;
    NSTextFinder *_textFinder;
}

+ (void)_setMessageStatus:(id)arg1 onMessageID:(id)arg2;
+ (id)documentWebPreferencesIdentifierForRichText:(BOOL)arg1;
+ (id)allocWithZone:(struct _NSZone *)arg1;
@property(retain, nonatomic) NSTextFinder *textFinder; // @synthesize textFinder=_textFinder;
@property(nonatomic) __weak FindBarContainer *findBarContainer; // @synthesize findBarContainer=_findBarContainer;
@property(copy, nonatomic) NSDictionary *settings; // @synthesize settings=_settings;
@property(retain, nonatomic) EditingWebMessageController *webMessageController; // @synthesize webMessageController=_webMessageController;
@property(nonatomic) BOOL shouldUseObfuscationWhenSavingEditingHistory; // @synthesize shouldUseObfuscationWhenSavingEditingHistory=_shouldUseObfuscationWhenSavingEditingHistory;
@property(nonatomic) BOOL shouldIncludeEditingHistoryInDiagnostics; // @synthesize shouldIncludeEditingHistoryInDiagnostics=_shouldIncludeEditingHistoryInDiagnostics;
@property(retain, nonatomic) ReportBugWindowController *reportBugWindowController; // @synthesize reportBugWindowController=_reportBugWindowController;
@property(retain, nonatomic) NSButton *includeExcludeAttachmentsButton; // @synthesize includeExcludeAttachmentsButton=_includeExcludeAttachmentsButton;
@property(nonatomic) BOOL userKnowsSaveFailed; // @synthesize userKnowsSaveFailed=_userKnowsSaveFailed;
@property(nonatomic) BOOL isBeingPreparedForSending; // @synthesize isBeingPreparedForSending=_isBeingPreparedForSending;
@property(nonatomic) BOOL hasUserMadeChanges; // @synthesize hasUserMadeChanges=_hasUserMadeChanges;
@property(nonatomic) BOOL isAutoSaving; // @synthesize isAutoSaving=_isAutoSaving;
@property(nonatomic) BOOL userSavedMessage; // @synthesize userSavedMessage=_userSavedMessage;
@property(nonatomic) BOOL wantsToClose; // @synthesize wantsToClose=_wantsToClose;
@property(copy, nonatomic) NSArray *unapprovedRecipients; // @synthesize unapprovedRecipients=_unapprovedRecipients;
@property(nonatomic) BOOL sendWhenFinishLoading; // @synthesize sendWhenFinishLoading=_sendWhenFinishLoading;
@property(retain, nonatomic) DeliveryFailure *deliveryFailure; // @synthesize deliveryFailure=_deliveryFailure;
@property(readonly, nonatomic) _ControllerTitleTransformer *titleTransformer; // @synthesize titleTransformer=_titleTransformer;
@property(nonatomic) __weak NSOperation *savedFinishLoadingEditorOperation; // @synthesize savedFinishLoadingEditorOperation=_savedFinishLoadingEditorOperation;
@property(copy, nonatomic) NSDictionary *toolbarItems; // @synthesize toolbarItems=_toolbarItems;
@property(nonatomic) __weak NSView *statusRow; // @synthesize statusRow=_statusRow;
@property(retain, nonatomic) NSOperationQueue *operationQueue; // @synthesize operationQueue=_operationQueue;
@property(nonatomic) unsigned long long textLengthForLastEstimatedMessageSize; // @synthesize textLengthForLastEstimatedMessageSize=_textLengthForLastEstimatedMessageSize;
@property(retain, nonatomic) NSView *clippingView; // @synthesize clippingView=_clippingView;
@property(retain, nonatomic) ComposeStatusView *composeStatusView; // @synthesize composeStatusView=_composeStatusView;
@property(nonatomic) BOOL isFinishedLoading; // @synthesize isFinishedLoading=_isFinishedLoading;
@property(retain, nonatomic) MCAttachment *PDFAttachment; // @synthesize PDFAttachment=_PDFAttachment;
@property(retain, nonatomic) WebArchive *readerWebArchive; // @synthesize readerWebArchive=_readerWebArchive;
@property(retain, nonatomic) WebArchive *pageWebArchive; // @synthesize pageWebArchive=_pageWebArchive;
@property(retain, nonatomic) NSString *URLShareUUID; // @synthesize URLShareUUID=_URLShareUUID;
@property(nonatomic) BOOL isShareKitOriginated; // @synthesize isShareKitOriginated=_isShareKitOriginated;
@property(nonatomic) __weak NSStackView *contentStack; // @synthesize contentStack=_contentStack;
@property(retain, nonatomic) LoadingOverlay *loadingOverlay; // @synthesize loadingOverlay=_loadingOverlay;
@property(nonatomic) long long messageType; // @synthesize messageType=_messageType;
@property(nonatomic) BOOL hasIncludedAttachmentsFromOriginal; // @synthesize hasIncludedAttachmentsFromOriginal=_hasIncludedAttachmentsFromOriginal;
@property(retain, nonatomic) HeadersEditor *headersEditor; // @synthesize headersEditor=_headersEditor;
@property(nonatomic) BOOL shouldSaveWhenClosing; // @synthesize shouldSaveWhenClosing=_shouldSaveWhenClosing;
@property(retain, nonatomic) WebViewEditor *webViewEditor; // @synthesize webViewEditor=_webViewEditor;
@property(nonatomic) __weak id <ComposeViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) Class backEndClass;
- (void)nowWouldBeAGoodTimeToTerminate:(id)arg1;
- (id)dictionaryRepresentation;
- (id)_bodySnapshot;
- (struct CGRect)_composeFrame;
- (struct CGRect)_headerFrame;
- (id)getContentGeometryData;
- (void)getSnapshotParts:(id)arg1;
- (void)replyAllMessage:(id)arg1;
- (void)replyMessage:(id)arg1;
- (void)changeReplyMode:(id)arg1;
- (void)reportBug:(id)arg1;
- (void)_openNewCompositionRadar;
- (void)closeWindowForController:(id)arg1;
- (void)controller:(id)arg1 runSysdiagnoseWithObfuscation:(BOOL)arg2;
- (void)controller:(id)arg1 saveOnlyEditingWithObfuscation:(BOOL)arg2;
- (void)_restoreOriginalAttachments:(id)arg1;
- (void)insertOriginalAttachments:(id)arg1;
@property(readonly, getter=isEditable) BOOL editable;
- (void)performTextFinderAction:(id)arg1;
- (void)_ensureTextFinder;
- (void)forceClose;
- (void)show;
- (void)_addAttachmentsFromShareKit;
- (BOOL)_isReplyingFromShareKitWithFileAttachments;
- (id)_messageBodyFromShareDictionary:(id)arg1;
- (void)_showURLPicker;
- (void)_setupDefaultURLState;
- (BOOL)_needsURLPicker;
- (void)_showURLPickerIfNeeded;
- (void)_validateURLPicker;
- (void)_insertUserHTMLDivs;
- (void)_getUserHTMLForEditing;
- (void)_addBaseURLToDocumentIfNeeded;
- (id)_newOriginalSharingSourceURLHTMLString;
- (void)_changeSharedURLToDisplayType:(long long)arg1;
- (void)refreshShareContentsForDisplayType:(long long)arg1;
- (void)URLPickerPopupChanged:(id)arg1;
- (void)insertEmoji:(id)arg1;
- (void)setMessagePriority:(id)arg1;
- (void)useInspectorBar:(id)arg1;
- (void)_registerSelectionRestorationWithUndoManager:(id)arg1;
- (void)toggleRich:(id)arg1;
- (void)makePlainText:(id)arg1;
- (void)makeRichText:(id)arg1;
- (void)_generateMessageBodiesToAppendForMessages:(id)arg1;
- (void)_appendMessages:(id)arg1 withMessageBodies:(id)arg2;
- (void)_removeAllFormatting;
- (void)appendMessageArray:(id)arg1;
- (void)appendMessages:(id)arg1;
- (void)updateUIAfterAppleScriptModification:(id)arg1;
- (void)toggleCheckGrammarWithSpelling:(id)arg1;
- (void)changeSpellCheckingBehavior:(id)arg1;
- (void)_printAsExportJob:(BOOL)arg1;
- (void)exportAsPDF:(id)arg1;
- (void)showPrintPanel:(id)arg1;
- (void)setInitialFirstResponder;
- (void)viewWillClose;
- (BOOL)canSave;
@property(readonly, nonatomic) BOOL hasChanges;
- (void)saveDocument:(id)arg1;
- (void)saveMessageToDrafts:(id)arg1;
- (void)_setUserSavedMessageAndPostNotification:(BOOL)arg1;
- (void)canClose:(id)arg1;
- (void)_saveMessageDueToUserAction:(BOOL)arg1;
- (void)autoSave;
- (void)setInsertionPointAtEnd;
- (void)activityHandoffFailed;
@property(nonatomic) BOOL shouldCloseWindowWhenAnimationCompletes;
@property(readonly, nonatomic) EFFuture *estimatedMessageSize;
- (void)backEndHandedMessageToDevice:(id)arg1;
- (void)backEndDidCancelMessageDeliveryForAttachmentError:(id)arg1;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForError:(id)arg2;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForEncryptionError:(id)arg2;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForMissingCertificatesForRecipients:(id)arg2;
- (BOOL)backEnd:(id)arg1 shouldDeliverMessage:(id)arg2;
- (BOOL)backEnd:(id)arg1 shouldSaveMessage:(id)arg2;
- (void)_prependBRToBody;
- (void)backEndDidLoadInitialContent:(id)arg1 mayUseDarkAppearance:(BOOL)arg2;
- (void)loadingOverlayDidEnd:(id)arg1 returnCode:(long long)arg2;
- (id)_composeView;
- (void)backEnd:(id)arg1 didBeginBackgroundLoadActivity:(id)arg2;
- (void)backEndDidSaveMessage:(id)arg1 result:(long long)arg2;
- (void)_setMessageStatusOnOriginalMessage;
- (void)backEndDidAppendMessageToOutbox:(id)arg1 result:(long long)arg2;
- (void)backEndDidChange:(id)arg1;
- (void)backEnd:(id)arg1 willCreateMessageWithHeaders:(id)arg2;
- (void)_showMailDropAlert:(id)arg1 forAttachmentCount:(unsigned long long)arg2;
@property(readonly, nonatomic) EFFuture *canSendViaMailDrop;
- (void)encryptionStatusDidChange;
- (id)_newEncryptionVerificationAlert;
- (id)_newShouldDeliverMessageWithoutEncryptionAlertWithMessage:(id)arg1;
- (id)_newFailedToCreateMessageAlert;
- (id)_newSaveFailureAlert;
- (id)_newAppendToOutboxFailedAlert;
- (id)_newCannotSaveToOutboxAlert;
- (id)_newShouldSaveAlert;
- (id)_newAlertForMalformedAddress:(id)arg1;
- (id)_newNoRecipientsAlert;
- (id)_newEmptyMessageAlert;
- (id)_newPendingAttachmentAlert;
- (BOOL)_isFullyLoaded;
- (void)sendMessageAfterChecking:(id)arg1;
- (void)reportDeliveryFailure:(id)arg1;
- (void)send:(id)arg1;
@property(readonly, nonatomic) BOOL sendButtonShouldBeEnabled;
- (BOOL)validateMenuItem:(id)arg1;
- (id)_firstSelectedAttachmentView;
- (id)sharingService:(id)arg1 sourceWindowForShareItems:(id)arg2 sharingContentScope:(long long *)arg3;
- (id)sharingService:(id)arg1 transitionImageForShareItem:(id)arg2 contentRect:(struct CGRect *)arg3;
- (struct CGRect)sharingService:(id)arg1 sourceFrameOnScreenForShareItem:(id)arg2;
- (void)_replaceSelectionWithMarkupString:(id)arg1;
- (void)sharingService:(id)arg1 didShareItems:(id)arg2;
- (void)_updateIncudeExcludeAttachmentsButtonImage;
- (id)touchBar:(id)arg1 makeItemForIdentifier:(id)arg2;
- (void)_validateTouchBarItems;
- (void)_confirmSending:(id)arg1;
- (void)_hideConfirmSendingTouchBar:(id)arg1;
- (void)_showConfirmSendingTouchBar:(id)arg1;
- (id)_confirmSendingTouchBar;
- (id)_standardTouchBar;
- (id)makeTouchBar;
- (void)editVisibleHeaders:(id)arg1;
- (BOOL)validateToolbarItem:(id)arg1;
- (void)updateSendButtonStateInToolbar;
- (void)editSignatures:(id)arg1;
- (void)changeSignature:(id)arg1;
- (BOOL)_currentBodyAppearanceIsDark;
- (void)toggleLightBackgrounds:(id)arg1;
- (void)_setComposeViewDrawsBackground:(BOOL)arg1;
- (id)shareItemsForSelection;
- (void)invokeExtensionService:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (id)messageBodyFromSettings:(id)arg1;
- (void)prepareContent;
- (void)_setupGrammarChecking;
- (void)_setupSpellChecking;
- (id)missingCertificatesMessageForRecipients:(id)arg1 uponDelivery:(BOOL)arg2;
- (void)continueLoadingInitialContent:(id)arg1;
- (void)_updateComposeWebViewPreferencesForRichText:(BOOL)arg1;
- (void)_finishLoadingEditor;
- (void)_loadHTMLStringIntoWebView:(id)arg1 baseURL:(id)arg2;
- (void)_loadHTMLDataIntoWebView:(id)arg1;
- (void)_loadInitialDocumentIntoWebView;
- (id)_finishLoadingEditorOperation;
- (id)_loadInitialDocumentOperation;
- (id)_prepareContentOperation;
- (BOOL)_loadContent;
- (void)_hideImageStatus;
- (void)messageSizeDidChange:(id)arg1;
- (void)_saveImageSizeToDefaults;
- (void)imageSizePopupChanged:(id)arg1;
- (id)_maxImageSizeAsString;
@property(readonly, nonatomic) BOOL hasPendingAttachmentReads;
- (void)_setImageSizePopupToSize:(id)arg1;
- (void)_showImageStatus;
- (void)_updateImageSizePopup;
- (unsigned long long)_attachmentsContainConvertibleImage:(id)arg1 convertibles:(id)arg2;
- (BOOL)_convertImageAttachments:(id)arg1;
- (id)mailAttachmentsAdded:(id)arg1;
- (void)_attachmentDidFinishReading;
- (void)mailAttachmentsDeleted;
- (void)_mailAttachmentsDeleted;
@property(readonly, nonatomic) unsigned long long encryptionOverhead;
- (unsigned long long)_signatureOverhead;
- (id)_textLengthEstimate;
- (BOOL)_isConvertingImages;
- (void)webViewDidChange:(id)arg1;
- (void)updateAttachmentStatus;
- (void)attachFilesAtEnd:(id)arg1;
- (void)alwaysAttachFilesAtEnd:(id)arg1;
- (void)_setSendWindowsFriendlyAttachments:(BOOL)arg1;
- (void)sendWindowsFriendlyAttachments:(id)arg1;
- (void)insertFile:(id)arg1;
@property(readonly, nonatomic) EditableWebMessageDocument *webMessageDocument;
- (void)_hideStatusBar;
- (void)_showStatusBar;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (long long)type;
@property(retain, nonatomic) ComposeBackEnd *backEnd;
- (void)_diagnosticsNotificationReceived:(id)arg1;
- (void)viewDidDisappear;
- (void)_updateViewAppearance;
- (void)_setUpWebMessageController;
- (void)viewDidLoad;
- (void)loadWithContext:(id)arg1;
- (void)showWithContext:(id)arg1;
@property(retain) id <ComposeContext> representedObject;
- (void)dealloc;
- (void)_composeViewControllerCommonInit;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initWithCoder:(id)arg1;

// Remaining properties
@property(readonly) BOOL allowsMultipleSelection;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly, copy, nonatomic) NSString *displayName;
@property(readonly) struct _NSRange firstSelectedRange;
@property(readonly) NSUInteger hash;
@property(readonly, getter=isSelectable) BOOL selectable;
@property(copy) NSArray *selectedRanges;
@property(readonly) NSString *string;
@property(readonly) Class superclass;
@property(readonly, copy) NSArray *visibleCharacterRanges;

@end

