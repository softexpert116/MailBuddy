//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFEWSRequestOperation.h>

@class EWSDuration, EWSEmailAddress, EWSReplyBodyType, MFEWSSetUserOofSettingsResponseOperation;

@interface MFEWSSetUserOofSettingsRequestOperation : MFEWSRequestOperation
{
    long long _oofState;
    EWSReplyBodyType *_internalReply;
    EWSReplyBodyType *_externalReply;
    EWSDuration *_duration;
    EWSEmailAddress *_emailAddress;
    long long _externalAudienceType;
}

@property(readonly, nonatomic) long long externalAudienceType; // @synthesize externalAudienceType=_externalAudienceType;
@property(readonly, nonatomic) EWSEmailAddress *emailAddress; // @synthesize emailAddress=_emailAddress;
@property(readonly, nonatomic) EWSDuration *duration; // @synthesize duration=_duration;
@property(readonly, nonatomic) EWSReplyBodyType *externalReply; // @synthesize externalReply=_externalReply;
@property(readonly, nonatomic) EWSReplyBodyType *internalReply; // @synthesize internalReply=_internalReply;
@property(readonly, nonatomic) long long oofState; // @synthesize oofState=_oofState;
- (void).cxx_destruct;
- (id)prepareRequest;
- (id)newResponseOperationWithGateway:(id)arg1 errorHandler:(id)arg2;
@property(retain, nonatomic) MFEWSSetUserOofSettingsResponseOperation *responseOperation;
- (id)initWithGateway:(id)arg1 errorHandler:(id)arg2;
- (id)initWithEmailAddress:(id)arg1 oofState:(long long)arg2 internalReply:(id)arg3 externalReply:(id)arg4 startTime:(id)arg5 endTime:(id)arg6 externalAudienceType:(long long)arg7 gateway:(id)arg8 errorHandler:(id)arg9;

@end
