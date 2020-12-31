//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "MailTableViewDelegate-Protocol.h"
#import "MessageListContentControllerDelegate-Protocol.h"
#import "NSPasteboardItemDataProvider-Protocol.h"
#import "NSServicesMenuRequestor-Protocol.h"
#import "NSTableViewDataSource-Protocol.h"
#import "SelectionOwner-Protocol.h"

@class ConversationPrefetcher, MCMessage, MFGlobalBodyFetchContext, MFMessageThread, MailTableView, MessageListContentController, MessageSelection, NSArray, NSCache, NSDictionary, NSFont, NSMapTable, NSMutableArray, NSMutableSet, NSNumber, NSPredicate, NSSet, NSString, NSTableColumn, TableViewScrollState;
@protocol MCMessageDataSource, SortTitleSetter, TableViewManagerDelegate;

@interface TableViewManager : NSObject <MessageListContentControllerDelegate, NSPasteboardItemDataProvider, NSServicesMenuRequestor, MailTableViewDelegate, NSTableViewDataSource, SelectionOwner>
{
    MessageListContentController *_messageListContentController;
    NSMutableArray *_rawSelection;
    NSFont *_font;
    NSMutableSet *_selectedConversationIDs;
    id _snippetLock;
    NSMutableSet *_messagesBeingFetched;
    unsigned long long _lastRequestedRow;
    NSMapTable *_messageProxyObjects;
    BOOL _isFocused;
    BOOL _sortColumnOrderAscending;
    BOOL _mailboxSortColumnOrderAscending;
    BOOL _isInThreadedMode;
    BOOL _awaitingInitialScrollPosition;
    BOOL _scrollFoundSelectionIntoView;
    BOOL _awaitingInitialSelection;
    BOOL _clearSelectionOnUpdate;
    BOOL _threadOpeningIsInProgress;
    BOOL _threadClosingIsInProgress;
    BOOL _dontUpdateTrackingRects;
    BOOL _useBoldFontForUnreadMessages;
    BOOL _clearingSearch;
    BOOL _animatingRowSelection;
    BOOL _keepSelectionWhenTogglingThread;
    unsigned char _suspendChangesToScrollingAndSelection;
    BOOL _isColumnLayoutMessageList;
    BOOL _highlightClosedThreads;
    BOOL _showSize;
    BOOL _showDateTime;
    BOOL _showToCc;
    BOOL _showContactPhotos;
    BOOL _animatingThreadOpening;
    BOOL _animatingThreadClosing;
    BOOL _selectingMessagesForTransfer;
    BOOL _didAwake;
    BOOL _beganAnimationGrouping;
    MailTableView *_tableView;
    id <TableViewManagerDelegate> _delegate;
    NSArray *_tableColumns;
    NSMapTable *_storeStateTable;
    NSSet *_mouseTrackers;
    NSDictionary *_messageIDsToSelectWhenOpened;
    NSArray *_threadIDsToOpenWhenOpened;
    long long _sortColumnOrder;
    long long _mailboxSortColumnOrder;
    long long _initialScrollType;
    TableViewScrollState *_savedScrollState;
    NSDictionary *_initialMailboxViewingState;
    NSFont *_boldFont;
    long long _searchTarget;
    long long _searchField;
    id <SortTitleSetter> _sortTitleSetter;
    NSCache *_snippetsForMessage;
    ConversationPrefetcher *_conversationPrefetcher;
    NSArray *_expandedSelection;
    NSArray *_expandedSelectionForTransfer;
    long long _colorHighlightLeftEdge;
    long long _colorHighlightWidth;
    MFMessageThread *_threadBeingClosed;
    MFMessageThread *_threadBeingOpened;
    long long _numberOfSelectedRowsBeforeTogglingThread;
    unsigned long long _numberOfSnippetLines;
    NSTableColumn *_richTableColumn;
    long long _previouslyViewedMessageRow;
    long long _currentViewedMessageRow;
    long long _nextMessageDirection;
    MFGlobalBodyFetchContext *_bodyFetchContext;
    NSArray *_messageListItemsFromMouseDown;
    NSArray *_draggedMessageListItems;
    NSNumber *_sortViewHeight;
    NSNumber *_topHitsHeaderViewHeight;
    double _rowHeightMessage;
    double _rowHeightMessageInThreadedMode;
    double _rowHeightMessageColumnLayout;
    struct _NSRange _messageRangeFromMouseDown;
}

+ (id)keyPathsForValuesAffectingFilterPredicate;
+ (id)specialImageForMessageCount:(unsigned long long)arg1 offset:(struct CGPoint *)arg2;
+ (BOOL)isColumnValid:(long long)arg1;
+ (void)initialize;
+ (id)log;
@property(nonatomic) double rowHeightMessageColumnLayout; // @synthesize rowHeightMessageColumnLayout=_rowHeightMessageColumnLayout;
@property(nonatomic) double rowHeightMessageInThreadedMode; // @synthesize rowHeightMessageInThreadedMode=_rowHeightMessageInThreadedMode;
@property(nonatomic) double rowHeightMessage; // @synthesize rowHeightMessage=_rowHeightMessage;
@property(retain, nonatomic) NSNumber *topHitsHeaderViewHeight; // @synthesize topHitsHeaderViewHeight=_topHitsHeaderViewHeight;
@property(retain, nonatomic) NSNumber *sortViewHeight; // @synthesize sortViewHeight=_sortViewHeight;
@property(copy, nonatomic) NSArray *draggedMessageListItems; // @synthesize draggedMessageListItems=_draggedMessageListItems;
@property(copy, nonatomic) NSArray *messageListItemsFromMouseDown; // @synthesize messageListItemsFromMouseDown=_messageListItemsFromMouseDown;
@property(nonatomic) BOOL beganAnimationGrouping; // @synthesize beganAnimationGrouping=_beganAnimationGrouping;
@property(readonly, nonatomic) MFGlobalBodyFetchContext *bodyFetchContext; // @synthesize bodyFetchContext=_bodyFetchContext;
@property(nonatomic) long long nextMessageDirection; // @synthesize nextMessageDirection=_nextMessageDirection;
@property(nonatomic) long long currentViewedMessageRow; // @synthesize currentViewedMessageRow=_currentViewedMessageRow;
@property(nonatomic) long long previouslyViewedMessageRow; // @synthesize previouslyViewedMessageRow=_previouslyViewedMessageRow;
@property(retain, nonatomic) NSTableColumn *richTableColumn; // @synthesize richTableColumn=_richTableColumn;
@property(nonatomic) unsigned long long numberOfSnippetLines; // @synthesize numberOfSnippetLines=_numberOfSnippetLines;
@property(nonatomic) BOOL didAwake; // @synthesize didAwake=_didAwake;
@property(nonatomic) long long numberOfSelectedRowsBeforeTogglingThread; // @synthesize numberOfSelectedRowsBeforeTogglingThread=_numberOfSelectedRowsBeforeTogglingThread;
@property(nonatomic) __weak MFMessageThread *threadBeingOpened; // @synthesize threadBeingOpened=_threadBeingOpened;
@property(nonatomic) __weak MFMessageThread *threadBeingClosed; // @synthesize threadBeingClosed=_threadBeingClosed;
@property(nonatomic) long long colorHighlightWidth; // @synthesize colorHighlightWidth=_colorHighlightWidth;
@property(nonatomic) long long colorHighlightLeftEdge; // @synthesize colorHighlightLeftEdge=_colorHighlightLeftEdge;
@property(nonatomic) struct _NSRange messageRangeFromMouseDown; // @synthesize messageRangeFromMouseDown=_messageRangeFromMouseDown;
@property(copy, nonatomic) NSArray *expandedSelectionForTransfer; // @synthesize expandedSelectionForTransfer=_expandedSelectionForTransfer;
@property(copy, nonatomic) NSArray *expandedSelection; // @synthesize expandedSelection=_expandedSelection;
@property(retain, nonatomic) ConversationPrefetcher *conversationPrefetcher; // @synthesize conversationPrefetcher=_conversationPrefetcher;
@property(readonly, nonatomic) NSCache *snippetsForMessage; // @synthesize snippetsForMessage=_snippetsForMessage;
@property(nonatomic) BOOL selectingMessagesForTransfer; // @synthesize selectingMessagesForTransfer=_selectingMessagesForTransfer;
@property(readonly, nonatomic) BOOL animatingThreadClosing; // @synthesize animatingThreadClosing=_animatingThreadClosing;
@property(readonly, nonatomic) BOOL animatingThreadOpening; // @synthesize animatingThreadOpening=_animatingThreadOpening;
@property(nonatomic) BOOL showContactPhotos; // @synthesize showContactPhotos=_showContactPhotos;
@property(nonatomic) BOOL showToCc; // @synthesize showToCc=_showToCc;
@property(nonatomic) BOOL showDateTime; // @synthesize showDateTime=_showDateTime;
@property(nonatomic) BOOL showSize; // @synthesize showSize=_showSize;
@property(nonatomic) BOOL highlightClosedThreads; // @synthesize highlightClosedThreads=_highlightClosedThreads;
@property(nonatomic) BOOL isColumnLayoutMessageList; // @synthesize isColumnLayoutMessageList=_isColumnLayoutMessageList;
@property(nonatomic) __weak id <SortTitleSetter> sortTitleSetter; // @synthesize sortTitleSetter=_sortTitleSetter;
@property(nonatomic) long long searchField; // @synthesize searchField=_searchField;
@property(nonatomic) long long searchTarget; // @synthesize searchTarget=_searchTarget;
@property(retain, nonatomic) NSFont *boldFont; // @synthesize boldFont=_boldFont;
@property(nonatomic) unsigned char suspendChangesToScrollingAndSelection; // @synthesize suspendChangesToScrollingAndSelection=_suspendChangesToScrollingAndSelection;
@property(nonatomic) BOOL keepSelectionWhenTogglingThread; // @synthesize keepSelectionWhenTogglingThread=_keepSelectionWhenTogglingThread;
@property(nonatomic) BOOL animatingRowSelection; // @synthesize animatingRowSelection=_animatingRowSelection;
@property(nonatomic) BOOL clearingSearch; // @synthesize clearingSearch=_clearingSearch;
@property(nonatomic) BOOL useBoldFontForUnreadMessages; // @synthesize useBoldFontForUnreadMessages=_useBoldFontForUnreadMessages;
@property(nonatomic) BOOL dontUpdateTrackingRects; // @synthesize dontUpdateTrackingRects=_dontUpdateTrackingRects;
@property(nonatomic) BOOL threadClosingIsInProgress; // @synthesize threadClosingIsInProgress=_threadClosingIsInProgress;
@property(nonatomic) BOOL threadOpeningIsInProgress; // @synthesize threadOpeningIsInProgress=_threadOpeningIsInProgress;
@property(nonatomic) BOOL clearSelectionOnUpdate; // @synthesize clearSelectionOnUpdate=_clearSelectionOnUpdate;
@property(nonatomic) BOOL awaitingInitialSelection; // @synthesize awaitingInitialSelection=_awaitingInitialSelection;
@property(copy, nonatomic) NSDictionary *initialMailboxViewingState; // @synthesize initialMailboxViewingState=_initialMailboxViewingState;
@property(retain, nonatomic) TableViewScrollState *savedScrollState; // @synthesize savedScrollState=_savedScrollState;
@property(nonatomic) BOOL scrollFoundSelectionIntoView; // @synthesize scrollFoundSelectionIntoView=_scrollFoundSelectionIntoView;
@property(nonatomic) long long initialScrollType; // @synthesize initialScrollType=_initialScrollType;
@property(nonatomic) BOOL awaitingInitialScrollPosition; // @synthesize awaitingInitialScrollPosition=_awaitingInitialScrollPosition;
@property(nonatomic) long long mailboxSortColumnOrder; // @synthesize mailboxSortColumnOrder=_mailboxSortColumnOrder;
@property(nonatomic) long long sortColumnOrder; // @synthesize sortColumnOrder=_sortColumnOrder;
@property(nonatomic) BOOL isInThreadedMode; // @synthesize isInThreadedMode=_isInThreadedMode;
@property(nonatomic) BOOL mailboxSortColumnOrderAscending; // @synthesize mailboxSortColumnOrderAscending=_mailboxSortColumnOrderAscending;
@property(nonatomic) BOOL sortColumnOrderAscending; // @synthesize sortColumnOrderAscending=_sortColumnOrderAscending;
@property(nonatomic) BOOL isFocused; // @synthesize isFocused=_isFocused;
@property(copy, nonatomic) NSArray *threadIDsToOpenWhenOpened; // @synthesize threadIDsToOpenWhenOpened=_threadIDsToOpenWhenOpened;
@property(copy, nonatomic) NSDictionary *messageIDsToSelectWhenOpened; // @synthesize messageIDsToSelectWhenOpened=_messageIDsToSelectWhenOpened;
@property(copy, nonatomic) NSSet *mouseTrackers; // @synthesize mouseTrackers=_mouseTrackers;
@property(retain, nonatomic) NSMapTable *storeStateTable; // @synthesize storeStateTable=_storeStateTable;
@property(copy, nonatomic) NSArray *tableColumns; // @synthesize tableColumns=_tableColumns;
@property(nonatomic) __weak id <TableViewManagerDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) MailTableView *tableView; // @synthesize tableView=_tableView;
- (void).cxx_destruct;
- (id)_messageThreadForRow:(long long)arg1;
- (id)_messageForRow:(long long)arg1;
- (id)_messageListItemForRow:(long long)arg1;
- (void)recordMessageSelectionDuringSearch;
@property(retain, nonatomic) NSPredicate *filterPredicate;
- (void)setIsSortedAscending:(BOOL)arg1;
@property(readonly, nonatomic) BOOL isSortedAscending;
- (void)setSortColumn:(long long)arg1 ascending:(BOOL)arg2;
- (id)sortByStringForColumn:(long long)arg1;
@property(readonly, nonatomic) long long sortColumn;
- (BOOL)isSortedByDateReceived;
- (void)searchForSuggestions:(id)arg1 in:(long long)arg2 withOptions:(long long)arg3 fromSuggestionsSearchField:(id)arg4 filterPredicate:(id)arg5;
- (void)_updateInitialViewingState;
- (void)clearSearch;
- (void)_updateSearchDelegate;
- (void)_animateRowSelection:(id)arg1 byExtendingSelection:(BOOL)arg2;
- (long long)countOfTableViewRowsForMessageListContentController:(id)arg1;
- (BOOL)messageListContentController:(id)arg1 canIncludeItemsOfType:(long long)arg2;
- (void)messageListContentControllerDidChangeSort:(id)arg1;
- (void)messageListContentControllerDidUpdateConversations:(id)arg1;
- (void)messageListContentControllerDidFinishLoading:(id)arg1;
- (void)messageListContentControllerDidProcessUpdates:(id)arg1;
- (void)messageListContentController:(id)arg1 refreshedObjects:(id)arg2;
- (void)messageListContentController:(id)arg1 foundPinnedIndex:(long long)arg2 withOffset:(double)arg3;
- (void)messageListContentController:(id)arg1 foundSelectionIndexes:(id)arg2 shouldAnimate:(BOOL)arg3;
- (void)messageListContentControllerNeedsReload:(id)arg1;
- (void)messageListContentController:(id)arg1 didApplyChanges:(id)arg2;
- (void)messageListContentController:(id)arg1 willApplyChanges:(id)arg2;
- (void)messageListContentControllerWillProcessUpdates:(id)arg1;
- (void)reloadMailboxes:(id)arg1 messageFilterPredicate:(id)arg2;
- (void)setMailboxes:(id)arg1 messageFilterPredicate:(id)arg2 isSettingUpUI:(BOOL)arg3;
- (void)_restoreScrollState:(id)arg1;
- (id)_currentScrollStatePreferringSelection:(BOOL)arg1;
- (BOOL)_debugThreadAnimation;
- (id)messageToSelectIfEntireSelectionRemoved:(id)arg1;
- (void)_recordSelectionHistoryForRow:(long long)arg1;
- (void)_resetNextMessageTracking;
- (BOOL)_goUpInsteadOfDown;
- (long long)_indexOfFirstNonDeletedNonSelectedMessage:(long long)arg1 withinRowRange:(struct _NSRange)arg2 goUp:(BOOL)arg3;
@property(retain, nonatomic) MessageListContentController *messageListContentController;
- (id)accessibilityRowHeaderUIElementsForMailTableView:(id)arg1;
- (id)accessibilityUILinkedViewsForMailTableView:(id)arg1;
- (id)mailTableView:(id)arg1 dragImageForRowsWithIndexes:(id)arg2 event:(id)arg3 dragImageOffset:(struct CGPoint *)arg4;
- (BOOL)tableView:(id)arg1 writeRowsWithIndexes:(id)arg2 toPasteboard:(id)arg3;
- (void)mailTableView:(id)arg1 didMouseDown:(id)arg2;
- (void)mailTableView:(id)arg1 willMouseDown:(id)arg2;
- (void)mailTableViewDragWillEnd:(id)arg1 operation:(unsigned long long)arg2;
- (void)transfer:(id)arg1 didCompleteWithError:(id)arg2;
- (id)messagesToTransferIsMove:(BOOL)arg1;
- (id)_filterAndExpandMessagesForTransfer:(id)arg1;
- (void)archiveMessages:(id)arg1 allowUndo:(BOOL)arg2 withAnimationOptions:(unsigned long long)arg3;
- (BOOL)shouldDeleteMessagesGivenCurrentState:(id)arg1;
- (void)undeleteMessagesAllowingUndo:(BOOL)arg1;
- (void)deleteMessages:(id)arg1 allowMoveToTrash:(BOOL)arg2 allowUndo:(BOOL)arg3 selectingNextMessage:(BOOL)arg4 withAnimationOptions:(unsigned long long)arg5;
- (void)_redeleteMessages:(id)arg1 messagesToSelect:(id)arg2;
- (void)undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2;
- (void)_undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2 unreadMessages:(id)arg3;
- (id)_undoActionNameForMessageCount:(unsigned long long)arg1;
- (BOOL)mailTableView:(id)arg1 doCommandBySelector:(SEL)arg2;
@property(readonly, nonatomic) id <MCMessageDataSource> messageStore;
@property(readonly, nonatomic) MCMessage *currentDisplayedMessage;
- (id)parentThreadForChildMessage:(id)arg1;
@property(readonly, nonatomic) MCMessage *messageThatUserIsProbablyReading;
- (void)selectMessage:(id)arg1 options:(unsigned long long)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)selectMessages:(id)arg1;
- (struct CGRect)_tableViewVisibleRectWithoutUnderscroll;
- (void)_selectMessages:(id)arg1 scrollIfNeeded:(BOOL)arg2 options:(unsigned long long)arg3 completionBlock:(CDUnknownBlockType)arg4;
- (id)actionMessagesForOperation:(long long)arg1;
@property(readonly, copy, nonatomic) NSArray *selection;
- (id)selectionExpandingThreadsAndHiddenCopies:(BOOL)arg1;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)arg1;
- (void)deleteKeyPressed;
- (long long)_photoSizeForNumberOfSnippetLines:(unsigned long long)arg1;
- (void)_snippetsUpdated:(id)arg1;
- (void)_updateRowsWithNewSnippets:(id)arg1;
- (void)_updateSnippetsForMessage:(id)arg1 ignoreExpected:(BOOL)arg2;
- (void)resetSnippetCache;
- (id)_messagesNeedingSnippetsAroundRow:(unsigned long long)arg1 refreshProxies:(BOOL)arg2;
- (void)_performSnippetFetching;
- (void)_cacheSnippetsAroundRow:(unsigned long long)arg1 refreshProxies:(BOOL)arg2;
- (id)_snippetFetchQueue;
- (id)_snippetForMessage:(id)arg1;
- (void)pasteboard:(id)arg1 item:(id)arg2 provideDataForType:(id)arg3;
- (BOOL)writeSelectionToPasteboard:(id)arg1 types:(id)arg2;
- (id)mailTableView:(id)arg1 validRequestorForSendType:(id)arg2 returnType:(id)arg3;
- (void)_doubleClickedMessage:(id)arg1;
- (id)tableView:(id)arg1 dataCellForTableColumn:(id)arg2 row:(long long)arg3;
- (void)_resetObjectValueForCellView:(id)arg1;
- (BOOL)_shouldShowMailboxNames;
- (void)_prepareCell:(id)arg1 withMessage:(id)arg2;
- (id)_prepareProxyForMessage:(id)arg1 selected:(BOOL)arg2 createIfNeeded:(BOOL)arg3 cacheSnippet:(char *)arg4;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (struct _NSRange)_visibleRowRange;
- (id)_cellStyleForItem:(id)arg1;
- (id)tableView:(id)arg1 rowViewForRow:(long long)arg2;
- (id)_archiveActionColor;
- (id)_deleteActionForMessageCount:(unsigned long long)arg1;
- (id)_unreadActionIsRead:(BOOL)arg1 isChild:(BOOL)arg2;
- (id)tableView:(id)arg1 rowActionsForRow:(long long)arg2 edge:(long long)arg3;
- (void)tableView:(id)arg1 didRemoveRowView:(id)arg2 forRow:(long long)arg3;
- (void)tableView:(id)arg1 didAddRowView:(id)arg2 forRow:(long long)arg3;
- (void)_setupRowView:(id)arg1 atIndex:(long long)arg2;
- (void)_setupRowView:(id)arg1 messageListItem:(id)arg2 atIndex:(long long)arg3;
- (void)_setupRowViewAtRow:(long long)arg1 fetchingSnippet:(BOOL)arg2;
- (id)_proxyForMessage:(id)arg1 createIfNeeded:(BOOL)arg2 showRecipient:(BOOL)arg3;
- (id)_proxyForMessage:(id)arg1 createIfNeeded:(BOOL)arg2;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (BOOL)tableView:(id)arg1 shouldTypeSelectForEvent:(id)arg2 withCurrentSearchString:(id)arg3;
- (id)_messageSelectionColor;
- (long long)numberOfRowsInTableView:(id)arg1;
@property(readonly, copy, nonatomic) NSString *selectionStateLog;
- (void)mailTableViewDidResignFirstResponder:(id)arg1;
- (void)mailTableViewDidBecomeFirstResponder:(id)arg1;
- (void)_redisplayRowsAboveSelected;
- (void)_handleSelectionChangeFromNotification:(BOOL)arg1;
- (void)tableViewSelectionDidChange:(id)arg1;
- (id)_normalizedSelection:(id)arg1;
- (id)tableView:(id)arg1 selectionIndexesForProposedSelection:(id)arg2;
- (void)_selectOrDeselectMembersOfThread:(id)arg1 atIndex:(long long)arg2 select:(BOOL)arg3;
- (void)_updateViewingPaneToSelection;
- (id)_messageSelectionWithDataForPrinting:(BOOL)arg1;
@property(readonly, nonatomic) MessageSelection *messageSelectionForPrinting;
@property(readonly, nonatomic) MessageSelection *messageSelection;
- (id)_openThreadIdentifiers;
- (void)_rawSelectionIdentifiersForThreads:(id *)arg1 identifiersForMessages:(id *)arg2;
- (id)_mailboxViewingStatePreferringSelection:(BOOL)arg1;
- (void)removeAllRawSelection;
- (void)addRawSelectionObject:(id)arg1;
- (void)replaceObjectInRawSelectionAtIndex:(unsigned long long)arg1 withObject:(id)arg2;
- (void)removeObjectFromRawSelectionAtIndex:(unsigned long long)arg1;
- (id)objectInRawSelectionAtIndex:(unsigned long long)arg1;
@property(readonly, nonatomic) unsigned long long countOfRawSelection;
@property(retain, nonatomic) NSArray *rawSelection;
- (void)_updateSelectedThreadList;
- (void)_reloadDisplayWhenMessageCategoriesHaveChanged;
- (void)_reloadDisplayOnlyForMessagesInSet:(id)arg1 highlightOnly:(BOOL)arg2;
- (BOOL)_isMessageInSelectedThread:(id)arg1;
- (long long)mailTableView:(id)arg1 shouldScrollRowToVisible:(long long)arg2;
- (void)scrollRowToVisible:(long long)arg1 position:(long long)arg2;
@property(readonly, nonatomic) BOOL isSelectionVisible;
- (void)showSelectionAndCenter:(BOOL)arg1;
- (void)selectFirstReplyToMessage;
- (void)selectParentOfMessage;
- (void)selectPreviousMessage:(BOOL)arg1;
- (void)selectNextMessage:(BOOL)arg1;
@property(readonly, nonatomic) BOOL nextMessageIsBelow;
- (BOOL)openSelectedThread;
- (void)stepOutOfSelectedThread;
- (void)stepIntoSelectedThread;
- (void)selectNextMessageMovingUpward:(BOOL)arg1;
- (void)selectNextMessageMovingDownward:(BOOL)arg1;
- (unsigned long long)_modifierFlagsForKeyboardNavigation;
- (BOOL)selectionIsExactlyOneOpenThread;
@property(readonly, nonatomic) BOOL canSelectNextReplyToParent;
@property(readonly, nonatomic) BOOL canSelectFirstReplyToMessage;
@property(readonly, nonatomic) BOOL canSelectParentOfMessage;
- (long long)_indexOfMessageNearest:(long long)arg1 numberOfRows:(long long)arg2 downward:(BOOL)arg3;
- (void)toggleThread:(id)arg1 ignoreModifierKeys:(BOOL)arg2;
- (void)toggleThread:(id)arg1;
- (void)unhideMessages:(id)arg1;
- (BOOL)hideMessages:(id)arg1 selectingNextMessage:(BOOL)arg2 withAnimationOptions:(unsigned long long)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (void)closeAllThreads;
- (void)openAllThreads;
- (void)closeThread:(id)arg1 row:(long long)arg2 selectThread:(BOOL)arg3;
- (void)openThread:(id)arg1 row:(long long)arg2;
- (void)invalidateSelectionCache:(id)arg1;
- (void)toggleThreadedMode;
@property(retain, nonatomic) NSFont *font;
- (void)_updateTableViewRowHeight;
- (BOOL)tableView:(id)arg1 isGroupRow:(long long)arg2;
- (double)tableView:(id)arg1 heightOfRow:(long long)arg2;
- (void)_calculateRowHeights;
- (void)makeMessageListFirstResponder;
- (void)selectAllMessagesAndMakeFirstResponder;
- (BOOL)shouldSortAscendingByDefaultForColumn:(long long)arg1;
- (void)_updateSortTitle;
- (void)_threadColorPreferenceChanged:(id)arg1;
- (void)_snippetLinePreferenceChanged:(id)arg1;
- (void)_refreshMessageListLayout;
- (void)_viewerPreferencesChanged:(id)arg1;
@property(readonly, nonatomic) BOOL canSelectPreviousMessage;
@property(readonly, nonatomic) BOOL canSelectNextMessage;
- (void)readAttributesFromViewingOptions:(id)arg1;
- (void)writeAttributesToViewingOptions:(id)arg1;
- (void)_conversationsUpdated:(id)arg1;
- (void)_messageMarkedForOverwrite:(id)arg1;
- (void)prepareForWindowClose;
- (void)dealloc;
- (void)richReplyButtonClicked:(id)arg1;
- (void)prepareContentInRange:(struct _NSRange)arg1;
- (double)floatingHeaderHeight:(id)arg1;
- (void)userDidScrollInTableView:(id)arg1;
- (id)tableViewGetDefaultMenu:(id)arg1;
- (void)_unregisterTableViewNibs;
- (void)_registerTableViewNibs;
- (void)awakeFromNib;
@property(readonly, nonatomic) BOOL showSnippets;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

