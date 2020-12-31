//
//  LicenseWindowController.h
//  ECM
//
//  Created by ujs on 12/11/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface LicenseWindowController : NSWindowController
@property (weak) IBOutlet NSTextField *edit_email;
@property (weak) IBOutlet NSTextField *edit_num1;
@property (weak) IBOutlet NSTextField *edit_num2;
@property (weak) IBOutlet NSTextField *edit_num3;
@property (weak) IBOutlet NSTextField *edit_num4;
@property (weak) IBOutlet NSButton *btn_validate;
@property (weak) IBOutlet NSButton *btn_trial;
@property (weak) IBOutlet NSButton *btn_serial;
@property (weak) IBOutlet NSTextField *label_error;
@end

NS_ASSUME_NONNULL_END
