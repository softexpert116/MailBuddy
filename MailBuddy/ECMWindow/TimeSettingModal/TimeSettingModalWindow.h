//
//  TimeSettingModalWindow.h
//  ECM
//
//  Created by ujs on 10/28/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface TimeSettingModalWindow : NSWindowController {
    
    __weak IBOutlet NSDatePicker *time11;
    __weak IBOutlet NSDatePicker *time12;
    __weak IBOutlet NSDatePicker *time21;
    __weak IBOutlet NSDatePicker *time22;
    __weak IBOutlet NSDatePicker *time31;
    __weak IBOutlet NSDatePicker *time32;
    __weak IBOutlet NSTextField *text1;
    __weak IBOutlet NSTextField *text2;
    __weak IBOutlet NSTextField *text3;
    __weak IBOutlet NSButton *btn_apply;
    __weak IBOutlet NSButton *btn_close;
}

@end

NS_ASSUME_NONNULL_END
