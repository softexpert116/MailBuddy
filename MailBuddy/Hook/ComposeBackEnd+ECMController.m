//
//  ComposeBackEnd+ECMController.m
//  MailReceipt
//
//  Created by Gyorvari Gabor on 2016. 09. 17..
//  Copyright © 2016. Gyorvari Gabor. All rights reserved.
//

#import "ComposeBackEnd+ECMController.h"
#import "MCMutableMessageHeaders.h"
#import "ComposeBackEnd.h"
//#import "NSObject+LPDynamicIvars.h"
#import "ECMController.h"

@implementation ComposeBackEnd_ECMController

- (id)MPP_newOutgoingMessageUsingWriter:(id)writer contents:(id)contents headers:(id)headers isDraft:(BOOL)isDraft {
    
    ComposeBackEnd *backEnd = (ComposeBackEnd *)self;

    NSString *senderEmail = [ECMController extractEmailAddress:backEnd.sender];
    
    [ECMController showAlertWithTitle:@"" Message:senderEmail];
//    if ([[backEnd getIvar:@"readReceipt"] boolValue]) {
//        [headers setHeader:senderEmail forKey:@"Disposition-Notification-To"];
//    }
//
//    if ([[backEnd getIvar:@"deliveryReceipt"] boolValue]) {
//        [headers setHeader:senderEmail forKey:@"Return-Receipt-To"];
//    }

    return [self MPP_newOutgoingMessageUsingWriter:writer contents:contents headers:headers isDraft:isDraft];
}
- (void)MPPAwakeFromNib {
    [ECMController showAlertWithTitle:@"" Message:@"sdf"];
    [self MPPAwakeFromNib];
    
    
}
@end
