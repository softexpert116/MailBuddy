//
//  ECMWindowController.h
//  ECM
//
//  Created by ujs on 10/26/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECMWindowController : NSWindowController {
    __weak IBOutlet NSButton *btn_autoGreet;
  
    __weak IBOutlet NSTextField *label_settings;
    __weak IBOutlet NSTextField *label_format;
    __weak IBOutlet NSTextField *text_custom;
    __weak IBOutlet NSTextField *text_random;
    __weak IBOutlet NSTextField *label_separate;
    
    __weak IBOutlet NSTextField *label_language;
    __weak IBOutlet NSButton *btn_custom;
    __weak IBOutlet NSButton *btn_random;
    __weak IBOutlet NSButton *btn_time;
    __weak IBOutlet NSTextField *text_time;
    __weak IBOutlet NSTextField *text_preview;
    __weak IBOutlet NSButton *btn_edit;
    __weak IBOutlet NSTextField *label_changing;
    __weak IBOutlet NSTextField *label_font;
    
    __weak IBOutlet NSTextField *label_preview;
    
    __weak IBOutlet NSTextField *label_font_name_size;
    __weak IBOutlet NSPopUpButton *popup_lang;
    __weak IBOutlet NSButton *btn_apply;
    __weak IBOutlet NSButton *btn_close;
    __weak IBOutlet NSButton *btn_select_font_size;
    __weak IBOutlet NSTextField *label_trial;
}

@end

NS_ASSUME_NONNULL_END
