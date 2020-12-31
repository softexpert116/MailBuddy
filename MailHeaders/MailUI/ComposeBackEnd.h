//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "AttachmentManagerDelegate-Protocol.h"
#import "ImageConverterDelegate-Protocol.h"
#import "MCActivityTarget-Protocol.h"

@class EditableWebMessageDocument, MCInvocationQueue, MCMessage, MCMessageBody, MCMessageHeaders, MFDeliveryAccount, MFMailAccount, MFMailbox, MFSignature, NSArray, NSError, NSFont, NSInputStream, NSLock, NSMutableArray, NSMutableData, NSMutableDictionary, NSMutableSet, NSNumber, NSOperationQueue, NSOutputStream, NSPort, NSString, NSUUID, NSUndoManager, NSUserActivity, SMIMEEncryptionState;
@protocol ComposeBackEndDelegate;

@interface ComposeBackEnd : NSObject <AttachmentManagerDelegate, ImageConverterDelegate, MCActivityTarget, NSStreamDelegate, NSUserActivityDelegate>
{
    NSArray *_originalMessages;
    NSMutableDictionary *_originalMessageHeaders;
    long long _type;
    unsigned long long _encodingHint;
    unsigned long long _imageArchiveSize;
    EditableWebMessageDocument *_document;
    NSMutableDictionary *_cleanHeaders;
    NSMutableDictionary *_extraRecipients;
    NSMutableDictionary *_directoriesByAttachment;
    NSLock *_smimeLock;
    NSMutableDictionary *_signingIdentities;
    NSMutableDictionary *_encryptionCertificates;
    NSMutableSet *_knownMessageIds;
    BOOL _hasChanges;
    BOOL _overrideRemoteAttachmentsPreference;
    NSMutableArray *_converters;
    NSMutableArray *_composeDataToStream;
    NSMutableData *_replyData;
    BOOL _shouldDownloadRemoteAttachments;
    BOOL _includeHeaders;
    BOOL _canSign;
    BOOL _canEncrypt;
    BOOL _signIfPossible;
    BOOL _encryptIfPossible;
    BOOL _isUndeliverable;
    BOOL _isDeliveringMessage;
    BOOL _willCloseEditor;
    BOOL _sendAttachmentsViaMailDrop;
    BOOL _saveThreadCancelFlag;
    BOOL _hadChangesBeforeSave;
    BOOL _contentsWasEditedByUser;
    BOOL _didAppendMessageToOutbox;
    BOOL _isEditing;
    BOOL _isSendFormatInitialized;
    BOOL _attachmentUploadFailed;
    id <ComposeBackEndDelegate> _delegate;
    NSNumber *_uniqueID;
    NSError *_invalidSigningIdentityError;
    NSString *_saveThreadMessageId;
    MFMailbox *_saveThreadMailbox;
    MCMessageBody *_originalMessageBody;
    NSUUID *_documentID;
    NSUndoManager *_undoManager;
    long long _composeMode;
    MCMessageBody *_initialMessageBody;
    NSArray *_generatedMessageBodies;
    NSUserActivity *_activity;
    NSOperationQueue *_smimeQueue;
    long long _windowsFriendliness;
    unsigned long long _composeDataOffset;
    NSOutputStream *_outputStream;
    NSInputStream *_inputStream;
    unsigned long long _replyBytesRead;
    unsigned long long _imagesToResize;
    NSPort *_resizePort;
    id <ComposeBackEndDelegate> _delegateScopeRetain;
    NSUUID *_placeholderMessageID;
    MCInvocationQueue *_saveQueue;
}

+ (id)keyPathsForValuesAffectingAccount;
+ (id)_workQueue;
+ (id)supportedMailboxTypes;
+ (void)initialize;
+ (id)mailDropUploadsLog;
+ (id)draftsLog;
@property(readonly, nonatomic) MCInvocationQueue *saveQueue; // @synthesize saveQueue=_saveQueue;
@property(retain, nonatomic) NSUUID *placeholderMessageID; // @synthesize placeholderMessageID=_placeholderMessageID;
@property(retain, nonatomic) id <ComposeBackEndDelegate> delegateScopeRetain; // @synthesize delegateScopeRetain=_delegateScopeRetain;
@property(nonatomic) BOOL attachmentUploadFailed; // @synthesize attachmentUploadFailed=_attachmentUploadFailed;
@property(nonatomic) unsigned long long imageArchiveSize; // @synthesize imageArchiveSize=_imageArchiveSize;
@property(readonly, nonatomic) NSPort *resizePort; // @synthesize resizePort=_resizePort;
@property unsigned long long imagesToResize; // @synthesize imagesToResize=_imagesToResize;
@property(nonatomic) unsigned long long replyBytesRead; // @synthesize replyBytesRead=_replyBytesRead;
@property __weak NSInputStream *inputStream; // @synthesize inputStream=_inputStream;
@property __weak NSOutputStream *outputStream; // @synthesize outputStream=_outputStream;
@property(nonatomic) unsigned long long composeDataOffset; // @synthesize composeDataOffset=_composeDataOffset;
@property(nonatomic) unsigned long long encodingHint; // @synthesize encodingHint=_encodingHint;
@property(nonatomic) BOOL isSendFormatInitialized; // @synthesize isSendFormatInitialized=_isSendFormatInitialized;
@property(nonatomic) BOOL isEditing; // @synthesize isEditing=_isEditing;
@property(nonatomic) long long windowsFriendliness; // @synthesize windowsFriendliness=_windowsFriendliness;
@property(nonatomic) BOOL didAppendMessageToOutbox; // @synthesize didAppendMessageToOutbox=_didAppendMessageToOutbox;
@property(readonly, nonatomic) NSOperationQueue *smimeQueue; // @synthesize smimeQueue=_smimeQueue;
@property(nonatomic) BOOL contentsWasEditedByUser; // @synthesize contentsWasEditedByUser=_contentsWasEditedByUser;
@property(nonatomic) BOOL hadChangesBeforeSave; // @synthesize hadChangesBeforeSave=_hadChangesBeforeSave;
@property BOOL saveThreadCancelFlag; // @synthesize saveThreadCancelFlag=_saveThreadCancelFlag;
@property(retain, nonatomic) NSUserActivity *activity; // @synthesize activity=_activity;
@property(nonatomic) BOOL sendAttachmentsViaMailDrop; // @synthesize sendAttachmentsViaMailDrop=_sendAttachmentsViaMailDrop;
@property(copy, nonatomic) NSArray *generatedMessageBodies; // @synthesize generatedMessageBodies=_generatedMessageBodies;
@property(retain, nonatomic) MCMessageBody *initialMessageBody; // @synthesize initialMessageBody=_initialMessageBody;
@property(nonatomic) long long composeMode; // @synthesize composeMode=_composeMode;
@property(retain, nonatomic) NSUndoManager *undoManager; // @synthesize undoManager=_undoManager;
@property(retain, nonatomic) NSUUID *documentID; // @synthesize documentID=_documentID;
@property(retain, nonatomic) EditableWebMessageDocument *document; // @synthesize document=_document;
@property(retain, nonatomic) MCMessageBody *originalMessageBody; // @synthesize originalMessageBody=_originalMessageBody;
@property(retain) MFMailbox *saveThreadMailbox; // @synthesize saveThreadMailbox=_saveThreadMailbox;
@property(copy) NSString *saveThreadMessageId; // @synthesize saveThreadMessageId=_saveThreadMessageId;
@property(nonatomic) BOOL willCloseEditor; // @synthesize willCloseEditor=_willCloseEditor;
@property(nonatomic) BOOL isDeliveringMessage; // @synthesize isDeliveringMessage=_isDeliveringMessage;
@property(nonatomic) BOOL isUndeliverable; // @synthesize isUndeliverable=_isUndeliverable;
@property(nonatomic) BOOL encryptIfPossible; // @synthesize encryptIfPossible=_encryptIfPossible;
@property(nonatomic) BOOL signIfPossible; // @synthesize signIfPossible=_signIfPossible;
@property(retain) NSError *invalidSigningIdentityError; // @synthesize invalidSigningIdentityError=_invalidSigningIdentityError;
@property BOOL canEncrypt; // @synthesize canEncrypt=_canEncrypt;
@property BOOL canSign; // @synthesize canSign=_canSign;
@property(nonatomic) BOOL includeHeaders; // @synthesize includeHeaders=_includeHeaders;
@property(retain, nonatomic) NSNumber *uniqueID; // @synthesize uniqueID=_uniqueID;
@property(nonatomic) __weak id <ComposeBackEndDelegate> delegate; // @synthesize delegate=_delegate;
- (id)_addAttachmentsForOriginalMessages;
- (void)stream:(id)arg1 handleEvent:(unsigned long long)arg2;
- (void)userActivity:(id)arg1 didReceiveInputStream:(id)arg2 outputStream:(id)arg3;
- (void)_markForOverwrite:(id)arg1;
- (void)_saveThreadSaveContentsUserInitiated:(BOOL)arg1 onlyIfHasSignificantContent:(BOOL)arg2;
- (void)_saveThreadRemoveLastSave;
- (void)_saveThreadSetMessageId:(id)arg1 mailbox:(id)arg2 overwrite:(id)arg3;
- (void)_saveThreadUpdateAccount:(id)arg1 mailbox:(id)arg2;
- (BOOL)_saveThreadShouldCancel;
@property(readonly, nonatomic) BOOL isSavingMessage;
@property(readonly, nonatomic) BOOL shouldReplaceAttachmentsWithPlaceholders;
- (long long)_convertSaveOrSendResultFromResultCodeT:(long long)arg1;
- (id)mailboxCreateIfNeeded:(BOOL)arg1;
- (id)_formattedAddressMatchingRawAddress:(id)arg1 inAccount:(id)arg2;
- (id)_firstValidReplyAddress;
- (id)_replyAddressBasedOnSelection;
- (id)replyAddressForMessage:(id)arg1;
- (void)_saveRecipients;
- (void)_setupDefaultRecipientsFirstTime:(BOOL)arg1;
- (void)_ccOrBccMyselfGivenOriginalMessage:(id)arg1 uniquedRecipientsTable:(id)arg2;
@property(readonly, nonatomic) BOOL containsAttachmentsThatCouldConfuseWindowsClients;
@property(readonly, nonatomic) BOOL containsAttachments;
- (BOOL)attachmentCanBeSentInline:(id)arg1;
- (id)_copyOfContentsForDraft:(BOOL)arg1 isOkayToForceRichText:(BOOL)arg2 isMailDropPlaceholderMessage:(BOOL)arg3;
- (id)_newOutgoingMessageUsingWriter:(id)arg1 contents:(id)arg2 headers:(id)arg3 isDraft:(BOOL)arg4;
@property(readonly, nonatomic) NSFont *userDefaultMessageFont;
@property(readonly, nonatomic) BOOL containsRichText;
@property(readonly, nonatomic) BOOL hasContents;
- (void)generateMessageBodies;
- (void)fetchAndCacheMessages;
- (void)_notifyDelegateMonitor:(id)arg1 alreadyDone:(char *)arg2;
- (void)finishPreparingContent;
- (void)updateSaveDestinationAccount:(id)arg1 mailbox:(id)arg2;
- (void)updateDocumentReference:(id)arg1;
- (void)_configureLastDraftInformationFromHeaders:(id)arg1 overwrite:(BOOL)arg2;
- (BOOL)_isValidSaveDestination:(id)arg1;
- (void)updateSMIMEStatus:(id)arg1;
@property(readonly, copy, nonatomic) SMIMEEncryptionState *encryptionState;
@property(readonly, copy, nonatomic) NSArray *recipientsThatHaveNoKeyForEncryption;
@property(readonly, copy, nonatomic) NSArray *allRecipients;
- (BOOL)isEditingMessage:(id)arg1;
- (void)removeLastDraft;
- (id)defaultMessageStore;
- (BOOL)saveMessageDueToUserAction:(BOOL)arg1 onlyIfHasSignificantContent:(BOOL)arg2;
- (BOOL)saveMessageDueToUserAction:(BOOL)arg1;
@property(readonly, copy, nonatomic) NSString *saveTaskName;
- (void)_backgroundSaveDidChangeMessageId:(id)arg1;
- (void)backgroundSaveEnded:(id)arg1;
- (void)_backgroundAppendEnded:(id)arg1;
- (void)_synchronouslyAppendMessageToOutboxWithContents:(id)arg1;
- (BOOL)_recipientsContainCellPhoneAddress:(id)arg1;
- (void)_resizeAttachmentElementsForAttachments:(id)arg1;
- (void)deliverMessageCompletionHandler:(id)arg1;
- (void)imageConverter:(id)arg1 didFinishConversionWithResultCode:(long long)arg2;
- (void)_beginResizeOfImageAttachment:(id)arg1;
- (id)_createImageAttachmentRecordWithZoneID:(id)arg1 images:(id)arg2 error:(id *)arg3;
- (id)_newAttachmentRecordWithZoneID:(id)arg1 URL:(id)arg2 filesize:(id)arg3 filename:(id)arg4 mimeType:(id)arg5;
- (id)_createAttachmentRecordWithZoneID:(id)arg1 data:(id)arg2 filename:(id)arg3 mimeType:(id)arg4 error:(id *)arg5;
- (void)_recordZoneIDInDatabase:(id)arg1 completionHandler:(id)arg2;
- (void)_revertAttachments:(id)arg1 andExecuteBlock:(id)arg2 withError:(id)arg3;
- (void)_uploadAttachments:(id)arg1 completionBlock:(id)arg2;
- (BOOL)isAddressHeaderKey:(id)arg1;
- (void)removeAddressForHeader:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)insertAddress:(id)arg1 forHeader:(id)arg2 atIndex:(unsigned long long)arg3;
- (void)setAddressList:(id)arg1 forHeader:(id)arg2;
- (id)addressListForHeader:(id)arg1;
- (void)_setStructuredList:(id)arg1 forHeader:(id)arg2;
- (id)_structuredListForHeader:(id)arg1;
- (void)addHeaders:(id)arg1;
@property(readonly, nonatomic) long long displayableMessagePriority;
- (void)setMessagePriority:(long long)arg1;
- (id)htmlStringForSignature:(id)arg1;
@property(retain, nonatomic) MFSignature *signature;
@property(readonly, copy, nonatomic) NSString *signatureId;
@property(readonly, nonatomic) BOOL okToAddSignatureAutomatically;
@property(readonly, copy, nonatomic) NSString *messageID;
@property(retain, nonatomic) NSString *subject;
- (void)_setCleanHeaders:(id)arg1;
- (id)cleanHeaders;
- (void)setDefaultSenderIfNeeded;
@property(retain, nonatomic) NSString *sender;
@property(readonly, nonatomic) MFDeliveryAccount *deliveryAccount;
@property(retain, nonatomic) MFMailAccount *account;
- (id)messageFuture;
- (id)_makeMessageWithContents:(id)arg1 isDraft:(BOOL)arg2 shouldSign:(BOOL)arg3 shouldEncrypt:(BOOL)arg4 shouldSkipSignature:(BOOL)arg5;
- (unsigned long long)_encodingHint;
@property(readonly, nonatomic) BOOL isAppleScriptMessage;
@property(readonly, nonatomic) BOOL defaultFormatIsRich;
- (void)_getForwardOrReplyPrefix:(id *)arg1 shouldIncludeHeaders:(char *)arg2 shouldReturnOriginalMessage:(char *)arg3 startOffRich:(char *)arg4 bePlainIfPossible:(char *)arg5 shouldStripAttributesOfOriginalMessage:(char *)arg6;
- (void)setTypeAndConfigureLoadingOfRemoteAttachments:(long long)arg1;
- (void)_configureLoadingOfRemoteAttachments;
- (void)_generateMessageBodiesFromOriginalMessages;
- (id)directoryForAttachment:(id)arg1;
@property(readonly, copy, nonatomic) NSArray *attachments;
- (void)setOriginalMessages:(id)arg1;
- (id)_knownMessageIds;
@property(readonly, nonatomic) MCMessageHeaders *originalMessageHeaders;
@property(retain, nonatomic) MCMessage *originalMessage;
@property(nonatomic) BOOL sendWindowsFriendlyAttachments;
- (void)setShouldDownloadRemoteAttachments:(BOOL)arg1;
@property(readonly, nonatomic) BOOL isRedirecting;
@property(nonatomic) long long type;
@property(nonatomic) BOOL hasChanges;
@property(readonly, copy) NSString *description;
@property(readonly, copy) NSString *debugDescription;
- (void)setStateFromBackEnd:(id)arg1;
- (void)_createUniqueID;
- (void)_initializeDocument;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy, nonatomic) NSString *displayName;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

