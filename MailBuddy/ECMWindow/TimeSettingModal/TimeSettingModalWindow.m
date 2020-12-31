//
//  TimeSettingModalWindow.m
//  ECM
//
//  Created by ujs on 10/28/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "TimeSettingModalWindow.h"
#import "Constants.h"
#import "ECMController.h"

@interface TimeSettingModalWindow ()

@end

@implementation TimeSettingModalWindow
- (void)awakeFromNib
{
    [super awakeFromNib];
    [self.window center];
    [self window].backgroundColor = [NSColor colorWithRed:236.0f/255 green:100.0f/255 blue:19.0f/255 alpha:1.0f];
}
- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    [[self window] setTitle:[ECMController localizedString:@"STRING_time_setting" localeIdentifier:GET_DEFAULT(ECMLanguageCode)]];
    [btn_apply setTitle:[ECMController localizedString:@"STRING_apply" localeIdentifier:GET_DEFAULT(ECMLanguageCode)]];
    [btn_close setTitle:[ECMController localizedString:@"STRING_close" localeIdentifier:GET_DEFAULT(ECMLanguageCode)]];

    [time11 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time12 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time21 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time22 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time31 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time32 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    
    if ([ECMController.userDefaults objectForKey:key_time_text1] != nil) {
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text1];
        [text1 setStringValue:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val11] != nil) {
        [time11 setDateValue:[ECMController.userDefaults objectForKey:key_time_val11]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val12] != nil) {
        [time12 setDateValue:[ECMController.userDefaults objectForKey:key_time_val12]];
    }
    
    if ([ECMController.userDefaults objectForKey:key_time_text2] != nil) {
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text2];
        [text2 setStringValue:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val21] != nil) {
        [time21 setDateValue:[ECMController.userDefaults objectForKey:key_time_val21]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val22] != nil) {
        [time22 setDateValue:[ECMController.userDefaults objectForKey:key_time_val22]];
    }

    if ([ECMController.userDefaults objectForKey:key_time_text3] != nil) {
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text3];
        [text3 setStringValue:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val31] != nil) {
        [time31 setDateValue:[ECMController.userDefaults objectForKey:key_time_val31]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val32] != nil) {
        [time32 setDateValue:[ECMController.userDefaults objectForKey:key_time_val32]];
    }
}
- (IBAction)clickApply:(id)sender {
    [ECMController updateLocaleDictWithKey:key_time_text1 Value:text1.stringValue];
    [ECMController.userDefaults setValue:[time11 dateValue] forKey:key_time_val11];
    [ECMController.userDefaults setValue:[time12 dateValue] forKey:key_time_val12];
    
    [ECMController updateLocaleDictWithKey:key_time_text2 Value:text2.stringValue];
    [ECMController.userDefaults setValue:[time21 dateValue] forKey:key_time_val21];
    [ECMController.userDefaults setValue:[time22 dateValue] forKey:key_time_val22];

    [ECMController updateLocaleDictWithKey:key_time_text3 Value:text3.stringValue];
    [ECMController.userDefaults setValue:[time31 dateValue] forKey:key_time_val31];
    [ECMController.userDefaults setValue:[time32 dateValue] forKey:key_time_val32];
//    [[self window] close];
    [ECMController showAlertWithTitle:@"Success" Message:@"Successfully applied!"];
    [self clickCancel:nil];

}
- (IBAction)clickCancel:(id)sender {
    [[self window] close];
}


- (void)windowWillClose:(NSNotification *)notification
{
    [NSApp stopModal];
}

@end
