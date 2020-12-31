//
//  TextMessageDisplay+ECMController.m
//  ECM
//
//  Created by ujs on 10/31/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "TextMessageDisplay+ECMController.h"
#import "TextMessageDisplay.h"
#import "ECMController.h"
//#import <UIKit/UIKit.h>

@implementation TextMessageDisplay_ECMController

- (void)MPPAwakeFromNib {
    
    [self MPPAwakeFromNib];
    [ECMController showAlertWithTitle:@"" Message:@"content"];
//    TextMessageDisplay *messageDisplay = (TextMessageDisplay *)self;
//    messageDisplay.message
}

@end
