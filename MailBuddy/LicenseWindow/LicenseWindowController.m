//
//  LicenseWindowController.m
//  ECM
//
//  Created by ujs on 12/11/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "LicenseWindowController.h"
#import "ECMController.h"
#import "MBProgressHUD.h"
#import "Constants.h"

@interface LicenseWindowController ()

@end

@implementation LicenseWindowController
int license_type = 0;
NSString* email, *num1, *num2, *num3, *num4, *license;

- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    if (![ECMController.userDefaults objectForKey:is_trial]) {
        [_btn_trial setEnabled:YES];
        [_btn_trial setState:NSControlStateValueOn];
        license_type = 0;
    } else {
        [_btn_trial setEnabled:NO];
        [_btn_serial setState:NSControlStateValueOn];
        license_type = 1;
    }
}
- (IBAction)clickValidate:(id)sender {
    if (license_type == 0) {
        if (![ECMController.userDefaults objectForKey:is_trial]) {
            [ECMController.userDefaults setInteger:5 forKey:trial_days];
            [ECMController.userDefaults setObject:@"trial" forKey:is_trial];
        }

        NSInteger trial = [ECMController.userDefaults integerForKey:trial_days];

        [_label_error setTextColor:NSColor.greenColor];
        [_label_error setStringValue:[NSString stringWithFormat:@"Trial Days: %ld", (long)trial]];
    } else {
        email = _edit_email.stringValue;
        num1 = _edit_num1.stringValue;
        num2 = _edit_num2.stringValue;
        num3 = _edit_num3.stringValue;
        num4 = _edit_num4.stringValue;
        if (![self validateEmailWithString:email]) {
            [ECMController showAlertWithTitle:@"Warning" Message:@"Invalid email address!"];
            return;
        }
        if (num1.length*num2.length*num3.length*num4.length == 0) {
            [ECMController showAlertWithTitle:@"Warning" Message:@"Please fill in your serial number!"];
            return;
        }
        license = [NSString stringWithFormat:@"%@-%@-%@-%@", num1, num2, num3, num4];
        
        [self checkLicenseRequestWithEmail:email License:license];
    }

}
- (IBAction)chooseType:(NSButton*)sender {
    license_type = (int)sender.tag;
}
- (BOOL)validateEmailWithString:(NSString*)email
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:email];
}
-(void)checkLicenseRequestWithEmail:(NSString*)email License:(NSString*)license {
    NSMutableURLRequest *theRequest=[NSMutableURLRequest requestWithURL:[NSURL URLWithString:[@"https://my.mail-buddy.de/CustomerMaster/Add_Customer_Master" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]]
                                                            cachePolicy:NSURLRequestReloadIgnoringLocalCacheData
                                                        timeoutInterval:15.0];
    //do post request for parameter passing
    [theRequest setHTTPMethod:@"POST"];

    //set the content type to JSON
    [theRequest setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"Content-Type"];

    NSString *post = [NSString stringWithFormat:@"flag=flag&ID=0&Email=%@&LicenseKey=%@&LicenseStatus=&LicenseType=License&DeviceID=%@", email, license, @"123456"];
    NSData *postData = [post dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    [theRequest setHTTPBody:postData];
//    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:theRequest delegate:self];
    NSURLConnection *connection = [[NSURLConnection alloc] initWithRequest:theRequest delegate:self startImmediately:NO];
    [connection scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [connection start];
    
    [MBProgressHUD showHUDAddedTo:self.window.contentView animated:YES];
    
}
- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse *)response
{
    NSLog(@"Did Receive Response %@", response);
}
- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data
{
    [MBProgressHUD hideHUDForView:self.window.contentView animated:YES];
    //NSLog(@"Did Receive Data %@", data);
    id jsonData = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
//    [ECMController showAlertWithTitle:@"" Message:[NSString stringWithFormat:@"%@", jsonData]];
    NSString* msg = [jsonData objectForKey:@"msg"];
    NSInteger ID = [[jsonData objectForKey:@"ID"] intValue];
    NSInteger TrialDays = [[jsonData objectForKey:@"TrialDays"] intValue];
    if (ID == 0) {
        [_label_error setTextColor:NSColor.orangeColor];
        [_label_error setStringValue:[NSString stringWithFormat:@"Error: %@", msg]];
    } else {
        [_label_error setTextColor:NSColor.greenColor];
        [_label_error setStringValue:[NSString stringWithFormat:@"Success: %@\nTrial Days: %ld", msg, (long)TrialDays]];
        [ECMController.userDefaults setInteger:TrialDays forKey:trial_days];
    }
    
}
- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error
{
    [MBProgressHUD hideHUDForView:self.window.contentView animated:YES];
    NSLog(@"Did Fail");
    [ECMController showAlertWithTitle:@"" Message:error.description];
}
- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{
    NSLog(@"Did Finish");
    // Do something with responseData
}
- (void)windowWillClose:(NSNotification *)notification
{
    [NSApp stopModal];
    [[NSNotificationCenter defaultCenter]
    postNotificationName:@"initMenu"
    object:nil userInfo:nil];
}
-(void)awakeFromNib {
    [self window].backgroundColor = [NSColor colorWithRed:236.0f/255 green:100.0f/255 blue:19.0f/255 alpha:1.0f];
}
@end
