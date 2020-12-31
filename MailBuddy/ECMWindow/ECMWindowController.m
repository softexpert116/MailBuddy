//
//  ECMWindowController.m
//  ECM
//
//  Created by ujs on 10/26/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "ECMWindowController.h"
#import "ECMController.h"
#import "TimeSettingModalWindow.h"
#import "Constants.h"

@interface ECMWindowController () <NSComboBoxDataSource,NSComboBoxDelegate>

@end

@implementation ECMWindowController
NSString* formatStr;
NSInteger formatType = -1;
NSDate *time11, *time12, *time21, *time22, *time31, *time32;
//NSString *t_text1 = @"", *t_text2 = @"", *t_text3 = @"";
NSArray* languages;
NSString *localeIdentifier;

- (void)windowDidLoad {
    [super windowDidLoad];
    NSInteger trial = [ECMController.userDefaults integerForKey:trial_days];
    [label_trial setStringValue:[NSString stringWithFormat:@"Left Trial: %ld", (long)trial]];
    
    [label_font_name_size
    setStringValue:[NSString stringWithFormat:@"%@ %@",
                    GET_DEFAULT_VALUE(ECMHeaderFontName),
                    GET_DEFAULT_VALUE(ECMHeaderFontSize)]];
    
    //------------- Locale start ----------------------------------------
    NSArray *localizations = [[ECMController bundle] localizations];
    NSString *supportedLocales = @"";
    [[popup_lang menu] removeAllItems];
    for (NSString *lang in localizations)
    {
        if ([lang isEqual: @"Base"]) {
            continue;
        }
        
        NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:lang];
        NSString *name = [locale displayNameForKey:NSLocaleIdentifier value:lang];
        supportedLocales = [supportedLocales stringByAppendingString:name];
        supportedLocales = [supportedLocales stringByAppendingString:@" "];
        
        NSMenuItem *item = [[NSMenuItem alloc] init];
        [item setRepresentedObject:lang];
        [item setTitle:name];
        
        [[popup_lang menu] addItem:item];
    }
    
    localeIdentifier = GET_DEFAULT(ECMLanguageCode);
    if (!localeIdentifier)
    {
        localeIdentifier = [ECMController localeIdentifier];
    }
    
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:localeIdentifier];
    NSString *name = [locale displayNameForKey:NSLocaleIdentifier value:localeIdentifier];
    
    [popup_lang selectItemWithTitle:name];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(languagePopUpSelectionChanged:)
                                                 name:NSMenuDidSendActionNotification
                                               object:[popup_lang menu]];
    
    // fix for #26 https://github.com/jeevatkm/ReplyWithHeader/issues/26
    if ( ![ECMController isLocaleSupported] ) {
        
        [popup_lang setEnabled:NO];
        
    }
    [self updateControls];
    
    // ------------------------------ Locale End --------------------------------
    
    if ([ECMController.userDefaults boolForKey:key_auto_greet] == YES) {
        [btn_autoGreet setState:NSControlStateValueOn];
    } else {
        [btn_autoGreet setState:NSControlStateValueOff];
    }
    [btn_custom setState:NSControlStateValueOff];
    [btn_random setState:NSControlStateValueOff];
    [btn_time setState:NSControlStateValueOff];
    
    if ([ECMController.userDefaults objectForKey:key_format_type] != nil) {
        formatType = [ECMController.userDefaults integerForKey:key_format_type];
        if (formatType == 0) {
            [btn_custom setState:NSControlStateValueOn];
            
        } else if (formatType == 1) {
            [btn_random setState:NSControlStateValueOn];
            
        } else if (formatType == 2) {
            [btn_time setState:NSControlStateValueOn];
            
        }
    }
    
    [self updateValues];
}
- (void)updateControls {
    [[self window] setTitle:[ECMController localizedString:@"STRING_email_content_manipulation" localeIdentifier:localeIdentifier]];
    [label_settings setStringValue:[ECMController localizedString:@"STRING_settings" localeIdentifier:localeIdentifier]];
    [btn_autoGreet setTitle:[ECMController localizedString:@"STRING_auto_greets" localeIdentifier:localeIdentifier]];
    [btn_custom setTitle:[ECMController localizedString:@"STRING_l_custom" localeIdentifier:localeIdentifier]];
    [btn_random setTitle:[ECMController localizedString:@"STRING_l_random" localeIdentifier:localeIdentifier]];
    [label_separate setStringValue:[ECMController localizedString:@"STRING_separate_keywords_by_single_coma" localeIdentifier:localeIdentifier]];
    [btn_time setTitle:[ECMController localizedString:@"STRING_time" localeIdentifier:localeIdentifier]];
    [btn_edit setTitle:[ECMController localizedString:@"STRING_edit" localeIdentifier:localeIdentifier]];
    [label_changing setStringValue:[ECMController localizedString:@"STRING_changing_language_will_reset_time_greetings" localeIdentifier:localeIdentifier]];
    [label_preview setStringValue:[ECMController localizedString:@"STRING_preview" localeIdentifier:localeIdentifier]];
    [label_language setStringValue:[ECMController localizedString:@"STRING_language" localeIdentifier:localeIdentifier]];
    [label_font setStringValue:[ECMController localizedString:@"STRING_font" localeIdentifier:localeIdentifier]];
    [btn_select_font_size setTitle:[ECMController localizedString:@"STRING_select_font_size" localeIdentifier:localeIdentifier]];

    
    [btn_apply setTitle:[ECMController localizedString:@"STRING_apply" localeIdentifier:localeIdentifier]];
    [btn_close setTitle:[ECMController localizedString:@"STRING_close" localeIdentifier:localeIdentifier]];
}
- (void)languagePopUpSelectionChanged:(NSNotification *)notification {
    NSMenuItem *selectedItem = [popup_lang selectedItem];
    SET_USER_DEFAULT([selectedItem representedObject], ECMLanguageCode);
    localeIdentifier = GET_DEFAULT(ECMLanguageCode);
    [self updateControls];
    [self updateValues];
}
- (void)changeFont:(id)sender {
    NSFont *oldFont = label_font_name_size.font;
    NSFont *font = [sender convertFont:oldFont];
    NSString *fontSize = [NSString stringWithFormat: @"%.0f", font.pointSize];
    
    NSString *fontDescription = [NSString stringWithFormat: @"%@ %.0f", font.fontName, font.pointSize];
    SET_USER_DEFAULT(font.fontName, ECMHeaderFontName);
    SET_USER_DEFAULT(fontSize, ECMHeaderFontSize);
    
    [label_font_name_size setStringValue:fontDescription];
    [text_preview setFont:font];
}
- (IBAction)selectFont:(id)sender {
    NSString *font = GET_DEFAULT_VALUE(ECMHeaderFontName);
    NSString *fontSize = GET_DEFAULT_VALUE(ECMHeaderFontSize);
    
    [[NSFontPanel sharedFontPanel] setDelegate:self];
    [[NSFontPanel sharedFontPanel] setEnabled:YES];
    [[NSFontPanel sharedFontPanel] makeKeyAndOrderFront:self];
    
    [[NSFontPanel sharedFontPanel]
     setPanelFont:[NSFont fontWithName:font size:[fontSize floatValue]] isMultiple:NO];
}

- (void)updateValues {
    if ([ECMController.userDefaults objectForKey:key_custom_text] != nil) {
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_custom_text];
        [text_custom setStringValue:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    if ([ECMController.userDefaults objectForKey:key_random_text] != nil) {
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_random_text];
        [text_random setStringValue:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    
    NSString* time = @"";
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH:mm"];

    if ([ECMController.userDefaults objectForKey:key_time_val11] != nil) {
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val11];
        time11 = date;
        time = [formatter stringFromDate:date];
    }
    if ([ECMController.userDefaults objectForKey:key_time_val12] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val12];
        time12 = date;
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
    }
    if ([ECMController.userDefaults objectForKey:key_time_text1] != nil) {
        time = [time stringByAppendingString:@" "];
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text1];
        time = [time stringByAppendingString:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }

    if ([ECMController.userDefaults objectForKey:key_time_val21] != nil) {
        time = [time stringByAppendingString:@"\n"];
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val21];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time21 = date;
    }
    if ([ECMController.userDefaults objectForKey:key_time_val22] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val22];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time22 = date;
    }
    if ([ECMController.userDefaults objectForKey:key_time_text2] != nil) {
        time = [time stringByAppendingString:@" "];
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text2];
        time = [time stringByAppendingString:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }

    if ([ECMController.userDefaults objectForKey:key_time_val31] != nil) {
        time = [time stringByAppendingString:@"\n"];
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val31];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time31 = date;
    }
    if ([ECMController.userDefaults objectForKey:key_time_val32] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:key_time_val32];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time32 = date;
    }
    if ([ECMController.userDefaults objectForKey:key_time_text3] != nil) {
        time = [time stringByAppendingString:@" "];
        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text3];
        time = [time stringByAppendingString:[dict valueForKey:GET_DEFAULT(ECMLanguageCode)]];
    }
    
    [text_time setStringValue:time];
    [self refreshPreview];
}
-(void)refreshPreview {
    if (btn_autoGreet.state == NSControlStateValueOn) {
        NSString* preview = @"";
        if (formatType == 0) {
            preview = text_custom.stringValue;
        } else if (formatType == 1) {
            if (text_random.stringValue.length > 0) {
                NSArray *stringArray = [text_random.stringValue componentsSeparatedByString: @","];
                preview = [ECMController selectRandomStringFromArray:stringArray];
            }
        } else if (formatType == 2) {
            if (time11 != nil) {
                NSDateFormatter *formatter_H = [[NSDateFormatter alloc] init];
                [formatter_H setDateFormat:@"HH"];
                NSDateFormatter *formatter_m = [[NSDateFormatter alloc] init];
                [formatter_m setDateFormat:@"mm"];
                NSDate* curDate = [NSDate date];
                NSString *string_H = [formatter_H stringFromDate:curDate];
                NSString *string_m = [formatter_m stringFromDate:curDate];
                
                if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time11] Minute2:[formatter_H stringFromDate:time11]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time12] Minute2:[formatter_H stringFromDate:time12]]) {
                    NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text1];
                    preview = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                } else if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time21] Minute2:[formatter_H stringFromDate:time21]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time22] Minute2:[formatter_H stringFromDate:time22]]) {
                    NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text2];
                    preview = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                } else if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time31] Minute2:[formatter_H stringFromDate:time31]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time32] Minute2:[formatter_H stringFromDate:time32]]) {
                    NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text3];
                    preview = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                }
            }
        }
        
        [text_preview setStringValue:preview];
        NSString *font = GET_DEFAULT_VALUE(ECMHeaderFontName);
        NSString *fontSize = GET_DEFAULT_VALUE(ECMHeaderFontSize);
        NSFont* nsFont = [NSFont fontWithName:font size:[fontSize floatValue]];
        [text_preview setFont:nsFont];
    } else {
        [text_preview setStringValue:@""];
    }
}
- (IBAction)clickApply:(id)sender {
    if (btn_autoGreet.state == NSControlStateValueOn) {
        [ECMController.userDefaults setBool:YES forKey:key_auto_greet];
    } else {
        [ECMController.userDefaults setBool:NO forKey:key_auto_greet];
    }
    
    if (formatType == 0) {
        [ECMController updateLocaleDictWithKey:key_custom_text Value:text_custom.stringValue];
    } else if (formatType == 1) {
        [ECMController updateLocaleDictWithKey:key_random_text Value:text_random.stringValue];
    }
    [ECMController.userDefaults setInteger:formatType forKey:key_format_type];
    [ECMController showAlertWithTitle:@"Success" Message:@"Successfully applied!"];

}
- (IBAction)clickAutoGreet:(id)sender {
    [self refreshPreview];
}
- (IBAction)clickClose:(id)sender {
    [[self window] close];
}
- (IBAction)selectFormat:(NSButton *)sender {
    formatType = sender.tag;
    [self refreshPreview];
}
- (IBAction)openTimeSetting:(NSButton *)sender {
    TimeSettingModalWindow* windowController = [[TimeSettingModalWindow alloc] initWithWindowNibName:@"TimeSettingModalWindow"];
    [NSApp runModalForWindow:[windowController window]];
    [self updateValues];
}
- (void)windowWillClose:(NSNotification *)notification
{
    [NSApp stopModal];
}

-(NSInteger)numberOfItemsInComboBox:(NSComboBox *)aComboBox{
    return languages.count;
}

-(id)comboBox:(NSComboBox *)aComboBox objectValueForItemAtIndex:(NSInteger)loc{
    
    return [languages objectAtIndex:loc];
}
-(void)awakeFromNib {
    [self window].backgroundColor = [NSColor colorWithRed:236.0f/255 green:100.0f/255 blue:19.0f/255 alpha:1.0f];
}

@end
