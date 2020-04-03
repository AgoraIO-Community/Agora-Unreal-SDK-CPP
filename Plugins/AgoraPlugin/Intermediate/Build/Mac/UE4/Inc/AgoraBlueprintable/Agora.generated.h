// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
struct FAgoraUserInfo;
struct FAudioVolumeInfo;
struct FRemoteAudioStats;
struct FLocalAudioStats;
struct FRemoteVideoStats;
struct FLocalVideoStats;
struct FRtcStats;
struct FLastmileProbeResult;
struct FMediaDevice;
struct FRectangle;
struct FScreenCaptureParameters;
struct FChannelMediaRelayConfiguration;
struct FInjectStreamConfig;
struct FBeautyOptions;
struct FWatermarkOptions;
struct FLiveTranscoding;
struct FLastmileProbeConfig;
struct FVideoCanvas;
struct FCameraCapturerConfiguration;
struct FVideoEncoderConfiguration;
enum class EResult : uint8;
class UPlainData;
#ifdef AGORABLUEPRINTABLE_Agora_generated_h
#error "Agora.generated.h already included, missing '#pragma once' in Agora.h"
#endif
#define AGORABLUEPRINTABLE_Agora_generated_h

#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3463_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteFrameReceived_Parms \
{ \
	int64 UserId; \
	UTexture2D* Frame; \
}; \
static inline void FRemoteFrameReceived_DelegateWrapper(const FMulticastScriptDelegate& RemoteFrameReceived, int64 UserId, UTexture2D* Frame) \
{ \
	_Script_AgoraBlueprintable_eventRemoteFrameReceived_Parms Parms; \
	Parms.UserId=UserId; \
	Parms.Frame=Frame; \
	RemoteFrameReceived.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3462_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalFrameReceived_Parms \
{ \
	UTexture2D* Frame; \
}; \
static inline void FLocalFrameReceived_DelegateWrapper(const FMulticastScriptDelegate& LocalFrameReceived, UTexture2D* Frame) \
{ \
	_Script_AgoraBlueprintable_eventLocalFrameReceived_Parms Parms; \
	Parms.Frame=Frame; \
	LocalFrameReceived.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_109_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserInfoUpdated_Parms \
{ \
	int64 Uid; \
	FAgoraUserInfo Info; \
}; \
static inline void FUserInfoUpdated_DelegateWrapper(const FMulticastScriptDelegate& UserInfoUpdated, int64 Uid, FAgoraUserInfo Info) \
{ \
	_Script_AgoraBlueprintable_eventUserInfoUpdated_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Info=Info; \
	UserInfoUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_108_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalUserRegistered_Parms \
{ \
	int64 Uid; \
	FString UserAccount; \
}; \
static inline void FLocalUserRegistered_DelegateWrapper(const FMulticastScriptDelegate& LocalUserRegistered, int64 Uid, const FString& UserAccount) \
{ \
	_Script_AgoraBlueprintable_eventLocalUserRegistered_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.UserAccount=UserAccount; \
	LocalUserRegistered.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_107_DELEGATE \
struct _Script_AgoraBlueprintable_eventNetworkTypeChanged_Parms \
{ \
	TEnumAsByte<ENETWORK_TYPE> Type; \
}; \
static inline void FNetworkTypeChanged_DelegateWrapper(const FMulticastScriptDelegate& NetworkTypeChanged, ENETWORK_TYPE Type) \
{ \
	_Script_AgoraBlueprintable_eventNetworkTypeChanged_Parms Parms; \
	Parms.Type=Type; \
	NetworkTypeChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_106_DELEGATE \
struct _Script_AgoraBlueprintable_eventConnectionStateChanged_Parms \
{ \
	TEnumAsByte<ECONNECTION_STATE_TYPE> State; \
	TEnumAsByte<ECONNECTION_CHANGED_REASON_TYPE> Reason; \
}; \
static inline void FConnectionStateChanged_DelegateWrapper(const FMulticastScriptDelegate& ConnectionStateChanged, ECONNECTION_STATE_TYPE State, ECONNECTION_CHANGED_REASON_TYPE Reason) \
{ \
	_Script_AgoraBlueprintable_eventConnectionStateChanged_Parms Parms; \
	Parms.State=State; \
	Parms.Reason=Reason; \
	ConnectionStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_105_DELEGATE \
struct _Script_AgoraBlueprintable_eventMicrophoneEnabled_Parms \
{ \
	bool Enabled; \
}; \
static inline void FMicrophoneEnabled_DelegateWrapper(const FMulticastScriptDelegate& MicrophoneEnabled, bool Enabled) \
{ \
	_Script_AgoraBlueprintable_eventMicrophoneEnabled_Parms Parms; \
	Parms.Enabled=Enabled ? true : false; \
	MicrophoneEnabled.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_104_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteVideoTransportStats_Parms \
{ \
	int64 Uid; \
	int32 Delay; \
	int32 Lost; \
	int32 RxKBitRate; \
}; \
static inline void FRemoteVideoTransportStats_DelegateWrapper(const FMulticastScriptDelegate& RemoteVideoTransportStats, int64 Uid, int32 Delay, int32 Lost, int32 RxKBitRate) \
{ \
	_Script_AgoraBlueprintable_eventRemoteVideoTransportStats_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Delay=Delay; \
	Parms.Lost=Lost; \
	Parms.RxKBitRate=RxKBitRate; \
	RemoteVideoTransportStats.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_103_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteAudioTransportStats_Parms \
{ \
	int64 Uid; \
	int32 Delay; \
	int32 Lost; \
	int32 RxKBitRate; \
}; \
static inline void FRemoteAudioTransportStats_DelegateWrapper(const FMulticastScriptDelegate& RemoteAudioTransportStats, int64 Uid, int32 Delay, int32 Lost, int32 RxKBitRate) \
{ \
	_Script_AgoraBlueprintable_eventRemoteAudioTransportStats_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Delay=Delay; \
	Parms.Lost=Lost; \
	Parms.RxKBitRate=RxKBitRate; \
	RemoteAudioTransportStats.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_102_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteSubscribeFallbackToAudioOnly_Parms \
{ \
	int64 Uid; \
	bool IsFallbackOrRecover; \
}; \
static inline void FRemoteSubscribeFallbackToAudioOnly_DelegateWrapper(const FMulticastScriptDelegate& RemoteSubscribeFallbackToAudioOnly, int64 Uid, bool IsFallbackOrRecover) \
{ \
	_Script_AgoraBlueprintable_eventRemoteSubscribeFallbackToAudioOnly_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.IsFallbackOrRecover=IsFallbackOrRecover ? true : false; \
	RemoteSubscribeFallbackToAudioOnly.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_101_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalPublishFallbackToAudioOnly_Parms \
{ \
	bool IsFallbackOrRecover; \
}; \
static inline void FLocalPublishFallbackToAudioOnly_DelegateWrapper(const FMulticastScriptDelegate& LocalPublishFallbackToAudioOnly, bool IsFallbackOrRecover) \
{ \
	_Script_AgoraBlueprintable_eventLocalPublishFallbackToAudioOnly_Parms Parms; \
	Parms.IsFallbackOrRecover=IsFallbackOrRecover ? true : false; \
	LocalPublishFallbackToAudioOnly.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_100_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioRouteChanged_Parms \
{ \
	TEnumAsByte<EAUDIO_ROUTE_TYPE> Routing; \
}; \
static inline void FAudioRouteChanged_DelegateWrapper(const FMulticastScriptDelegate& AudioRouteChanged, EAUDIO_ROUTE_TYPE Routing) \
{ \
	_Script_AgoraBlueprintable_eventAudioRouteChanged_Parms Parms; \
	Parms.Routing=Routing; \
	AudioRouteChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_99_DELEGATE \
struct _Script_AgoraBlueprintable_eventStreamInjectedStatus_Parms \
{ \
	FString Url; \
	int64 Uid; \
	int32 Status; \
}; \
static inline void FStreamInjectedStatus_DelegateWrapper(const FMulticastScriptDelegate& StreamInjectedStatus, const FString& Url, int64 Uid, int32 Status) \
{ \
	_Script_AgoraBlueprintable_eventStreamInjectedStatus_Parms Parms; \
	Parms.Url=Url; \
	Parms.Uid=Uid; \
	Parms.Status=Status; \
	StreamInjectedStatus.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_98_DELEGATE \
static inline void FTranscodingUpdated_DelegateWrapper(const FMulticastScriptDelegate& TranscodingUpdated) \
{ \
	TranscodingUpdated.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_97_DELEGATE \
struct _Script_AgoraBlueprintable_eventStreamUnpublished_Parms \
{ \
	FString Url; \
}; \
static inline void FStreamUnpublished_DelegateWrapper(const FMulticastScriptDelegate& StreamUnpublished, const FString& Url) \
{ \
	_Script_AgoraBlueprintable_eventStreamUnpublished_Parms Parms; \
	Parms.Url=Url; \
	StreamUnpublished.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_96_DELEGATE \
struct _Script_AgoraBlueprintable_eventStreamPublished_Parms \
{ \
	FString Url; \
	int32 Error; \
}; \
static inline void FStreamPublished_DelegateWrapper(const FMulticastScriptDelegate& StreamPublished, const FString& Url, int32 Error) \
{ \
	_Script_AgoraBlueprintable_eventStreamPublished_Parms Parms; \
	Parms.Url=Url; \
	Parms.Error=Error; \
	StreamPublished.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_95_DELEGATE \
struct _Script_AgoraBlueprintable_eventRtmpStreamingStateChanged_Parms \
{ \
	FString Url; \
	TEnumAsByte<ERTMP_STREAM_PUBLISH_STATE> State; \
	TEnumAsByte<ERTMP_STREAM_PUBLISH_ERROR> ErrCode; \
}; \
static inline void FRtmpStreamingStateChanged_DelegateWrapper(const FMulticastScriptDelegate& RtmpStreamingStateChanged, const FString& Url, ERTMP_STREAM_PUBLISH_STATE State, ERTMP_STREAM_PUBLISH_ERROR ErrCode) \
{ \
	_Script_AgoraBlueprintable_eventRtmpStreamingStateChanged_Parms Parms; \
	Parms.Url=Url; \
	Parms.State=State; \
	Parms.ErrCode=ErrCode; \
	RtmpStreamingStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_94_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstRemoteAudioFrame_Parms \
{ \
	int64 Uid; \
	int32 Elapsed; \
}; \
static inline void FFirstRemoteAudioFrame_DelegateWrapper(const FMulticastScriptDelegate& FirstRemoteAudioFrame, int64 Uid, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstRemoteAudioFrame_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Elapsed=Elapsed; \
	FirstRemoteAudioFrame.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_93_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstLocalAudioFrame_Parms \
{ \
	int32 Elapsed; \
}; \
static inline void FFirstLocalAudioFrame_DelegateWrapper(const FMulticastScriptDelegate& FirstLocalAudioFrame, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstLocalAudioFrame_Parms Parms; \
	Parms.Elapsed=Elapsed; \
	FirstLocalAudioFrame.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_92_DELEGATE \
struct _Script_AgoraBlueprintable_eventChannelMediaRelayEvent_Parms \
{ \
	TEnumAsByte<ECHANNEL_MEDIA_RELAY_EVENT> Code; \
}; \
static inline void FChannelMediaRelayEvent_DelegateWrapper(const FMulticastScriptDelegate& ChannelMediaRelayEvent, ECHANNEL_MEDIA_RELAY_EVENT Code) \
{ \
	_Script_AgoraBlueprintable_eventChannelMediaRelayEvent_Parms Parms; \
	Parms.Code=Code; \
	ChannelMediaRelayEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_91_DELEGATE \
struct _Script_AgoraBlueprintable_eventChannelMediaRelayStateChanged_Parms \
{ \
	TEnumAsByte<ECHANNEL_MEDIA_RELAY_STATE> State; \
	TEnumAsByte<ECHANNEL_MEDIA_RELAY_ERROR> Code; \
}; \
static inline void FChannelMediaRelayStateChanged_DelegateWrapper(const FMulticastScriptDelegate& ChannelMediaRelayStateChanged, ECHANNEL_MEDIA_RELAY_STATE State, ECHANNEL_MEDIA_RELAY_ERROR Code) \
{ \
	_Script_AgoraBlueprintable_eventChannelMediaRelayStateChanged_Parms Parms; \
	Parms.State=State; \
	Parms.Code=Code; \
	ChannelMediaRelayStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_90_DELEGATE \
static inline void FMediaEngineStartCallSuccess_DelegateWrapper(const FMulticastScriptDelegate& MediaEngineStartCallSuccess) \
{ \
	MediaEngineStartCallSuccess.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_89_DELEGATE \
static inline void FMediaEngineLoadSuccess_DelegateWrapper(const FMulticastScriptDelegate& MediaEngineLoadSuccess) \
{ \
	MediaEngineLoadSuccess.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_88_DELEGATE \
struct _Script_AgoraBlueprintable_eventStreamMessageError_Parms \
{ \
	int64 Uid; \
	int32 StreamId; \
	int32 Code; \
	int32 Missed; \
	int32 Cached; \
}; \
static inline void FStreamMessageError_DelegateWrapper(const FMulticastScriptDelegate& StreamMessageError, int64 Uid, int32 StreamId, int32 Code, int32 Missed, int32 Cached) \
{ \
	_Script_AgoraBlueprintable_eventStreamMessageError_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.StreamId=StreamId; \
	Parms.Code=Code; \
	Parms.Missed=Missed; \
	Parms.Cached=Cached; \
	StreamMessageError.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_87_DELEGATE \
struct _Script_AgoraBlueprintable_eventStreamMessage_Parms \
{ \
	int64 Uid; \
	int32 StreamId; \
	FString Data; \
	int64 Length; \
}; \
static inline void FStreamMessage_DelegateWrapper(const FMulticastScriptDelegate& StreamMessage, int64 Uid, int32 StreamId, const FString& Data, int64 Length) \
{ \
	_Script_AgoraBlueprintable_eventStreamMessage_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.StreamId=StreamId; \
	Parms.Data=Data; \
	Parms.Length=Length; \
	StreamMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_86_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserEnableLocalVideo_Parms \
{ \
	int64 Uid; \
	bool Enabled; \
}; \
static inline void FUserEnableLocalVideo_DelegateWrapper(const FMulticastScriptDelegate& UserEnableLocalVideo, int64 Uid, bool Enabled) \
{ \
	_Script_AgoraBlueprintable_eventUserEnableLocalVideo_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Enabled=Enabled ? true : false; \
	UserEnableLocalVideo.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_85_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteVideoStateChanged_Parms \
{ \
	int64 Uid; \
	TEnumAsByte<EREMOTE_VIDEO_STATE> State; \
	TEnumAsByte<EREMOTE_VIDEO_STATE_REASON> Reason; \
	int32 Elapsed; \
}; \
static inline void FRemoteVideoStateChanged_DelegateWrapper(const FMulticastScriptDelegate& RemoteVideoStateChanged, int64 Uid, EREMOTE_VIDEO_STATE State, EREMOTE_VIDEO_STATE_REASON Reason, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventRemoteVideoStateChanged_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.State=State; \
	Parms.Reason=Reason; \
	Parms.Elapsed=Elapsed; \
	RemoteVideoStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_84_DELEGATE \
struct _Script_AgoraBlueprintable_eventVideoSizeChanged_Parms \
{ \
	int64 Uid; \
	int32 Width; \
	int32 Height; \
	int32 Rotation; \
}; \
static inline void FVideoSizeChanged_DelegateWrapper(const FMulticastScriptDelegate& VideoSizeChanged, int64 Uid, int32 Width, int32 Height, int32 Rotation) \
{ \
	_Script_AgoraBlueprintable_eventVideoSizeChanged_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	Parms.Rotation=Rotation; \
	VideoSizeChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_83_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalVideoStateChanged_Parms \
{ \
	TEnumAsByte<ELOCAL_VIDEO_STREAM_STATE> LocalVideoState; \
	TEnumAsByte<ELOCAL_VIDEO_STREAM_ERROR> Error; \
}; \
static inline void FLocalVideoStateChanged_DelegateWrapper(const FMulticastScriptDelegate& LocalVideoStateChanged, ELOCAL_VIDEO_STREAM_STATE LocalVideoState, ELOCAL_VIDEO_STREAM_ERROR Error) \
{ \
	_Script_AgoraBlueprintable_eventLocalVideoStateChanged_Parms Parms; \
	Parms.LocalVideoState=LocalVideoState; \
	Parms.Error=Error; \
	LocalVideoStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_82_DELEGATE \
struct _Script_AgoraBlueprintable_eventVideoDeviceStateChanged_Parms \
{ \
	FString DeviceId; \
	int32 DeviceType; \
	int32 DeviceState; \
}; \
static inline void FVideoDeviceStateChanged_DelegateWrapper(const FMulticastScriptDelegate& VideoDeviceStateChanged, const FString& DeviceId, int32 DeviceType, int32 DeviceState) \
{ \
	_Script_AgoraBlueprintable_eventVideoDeviceStateChanged_Parms Parms; \
	Parms.DeviceId=DeviceId; \
	Parms.DeviceType=DeviceType; \
	Parms.DeviceState=DeviceState; \
	VideoDeviceStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_81_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstRemoteAudioDecoded_Parms \
{ \
	int64 Uid; \
	int32 Elapsed; \
}; \
static inline void FFirstRemoteAudioDecoded_DelegateWrapper(const FMulticastScriptDelegate& FirstRemoteAudioDecoded, int64 Uid, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstRemoteAudioDecoded_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Elapsed=Elapsed; \
	FirstRemoteAudioDecoded.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_80_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioEffectFinished_Parms \
{ \
	int32 SoundId; \
}; \
static inline void FAudioEffectFinished_DelegateWrapper(const FMulticastScriptDelegate& AudioEffectFinished, int32 SoundId) \
{ \
	_Script_AgoraBlueprintable_eventAudioEffectFinished_Parms Parms; \
	Parms.SoundId=SoundId; \
	AudioEffectFinished.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_79_DELEGATE \
static inline void FRemoteAudioMixingEnd_DelegateWrapper(const FMulticastScriptDelegate& RemoteAudioMixingEnd) \
{ \
	RemoteAudioMixingEnd.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_78_DELEGATE \
static inline void FRemoteAudioMixingBegin_DelegateWrapper(const FMulticastScriptDelegate& RemoteAudioMixingBegin) \
{ \
	RemoteAudioMixingBegin.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_77_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioMixingStateChanged_Parms \
{ \
	TEnumAsByte<EAUDIO_MIXING_STATE_TYPE> State; \
	TEnumAsByte<EAUDIO_MIXING_ERROR_TYPE> ErrorCode; \
}; \
static inline void FAudioMixingStateChanged_DelegateWrapper(const FMulticastScriptDelegate& AudioMixingStateChanged, EAUDIO_MIXING_STATE_TYPE State, EAUDIO_MIXING_ERROR_TYPE ErrorCode) \
{ \
	_Script_AgoraBlueprintable_eventAudioMixingStateChanged_Parms Parms; \
	Parms.State=State; \
	Parms.ErrorCode=ErrorCode; \
	AudioMixingStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_76_DELEGATE \
static inline void FAudioMixingFinished_DelegateWrapper(const FMulticastScriptDelegate& AudioMixingFinished) \
{ \
	AudioMixingFinished.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_75_DELEGATE \
struct _Script_AgoraBlueprintable_eventCameraExposureAreaChanged_Parms \
{ \
	int32 X; \
	int32 Y; \
	int32 Width; \
	int32 Height; \
}; \
static inline void FCameraExposureAreaChanged_DelegateWrapper(const FMulticastScriptDelegate& CameraExposureAreaChanged, int32 X, int32 Y, int32 Width, int32 Height) \
{ \
	_Script_AgoraBlueprintable_eventCameraExposureAreaChanged_Parms Parms; \
	Parms.X=X; \
	Parms.Y=Y; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	CameraExposureAreaChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_74_DELEGATE \
struct _Script_AgoraBlueprintable_eventCameraFocusAreaChanged_Parms \
{ \
	int32 X; \
	int32 Y; \
	int32 Width; \
	int32 Height; \
}; \
static inline void FCameraFocusAreaChanged_DelegateWrapper(const FMulticastScriptDelegate& CameraFocusAreaChanged, int32 X, int32 Y, int32 Width, int32 Height) \
{ \
	_Script_AgoraBlueprintable_eventCameraFocusAreaChanged_Parms Parms; \
	Parms.X=X; \
	Parms.Y=Y; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	CameraFocusAreaChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_73_DELEGATE \
static inline void FCameraReady_DelegateWrapper(const FMulticastScriptDelegate& CameraReady) \
{ \
	CameraReady.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_72_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioDeviceVolumeChanged_Parms \
{ \
	TEnumAsByte<EMEDIA_DEVICE_TYPE> DeviceType; \
	int32 Volume; \
	bool Muted; \
}; \
static inline void FAudioDeviceVolumeChanged_DelegateWrapper(const FMulticastScriptDelegate& AudioDeviceVolumeChanged, EMEDIA_DEVICE_TYPE DeviceType, int32 Volume, bool Muted) \
{ \
	_Script_AgoraBlueprintable_eventAudioDeviceVolumeChanged_Parms Parms; \
	Parms.DeviceType=DeviceType; \
	Parms.Volume=Volume; \
	Parms.Muted=Muted ? true : false; \
	AudioDeviceVolumeChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_71_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioDeviceStateChanged_Parms \
{ \
	FString DeviceId; \
	int32 DeviceType; \
	int32 DeviceState; \
}; \
static inline void FAudioDeviceStateChanged_DelegateWrapper(const FMulticastScriptDelegate& AudioDeviceStateChanged, const FString& DeviceId, int32 DeviceType, int32 DeviceState) \
{ \
	_Script_AgoraBlueprintable_eventAudioDeviceStateChanged_Parms Parms; \
	Parms.DeviceId=DeviceId; \
	Parms.DeviceType=DeviceType; \
	Parms.DeviceState=DeviceState; \
	AudioDeviceStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_70_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserEnableVideo_Parms \
{ \
	int64 Uid; \
	bool Enabled; \
}; \
static inline void FUserEnableVideo_DelegateWrapper(const FMulticastScriptDelegate& UserEnableVideo, int64 Uid, bool Enabled) \
{ \
	_Script_AgoraBlueprintable_eventUserEnableVideo_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Enabled=Enabled ? true : false; \
	UserEnableVideo.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_69_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserMuteVideo_Parms \
{ \
	int64 Uid; \
	bool Muted; \
}; \
static inline void FUserMuteVideo_DelegateWrapper(const FMulticastScriptDelegate& UserMuteVideo, int64 Uid, bool Muted) \
{ \
	_Script_AgoraBlueprintable_eventUserMuteVideo_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Muted=Muted ? true : false; \
	UserMuteVideo.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_68_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserMuteAudio_Parms \
{ \
	int64 Uid; \
	bool Muted; \
}; \
static inline void FUserMuteAudio_DelegateWrapper(const FMulticastScriptDelegate& UserMuteAudio, int64 Uid, bool Muted) \
{ \
	_Script_AgoraBlueprintable_eventUserMuteAudio_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Muted=Muted ? true : false; \
	UserMuteAudio.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_67_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstRemoteVideoFrame_Parms \
{ \
	int64 Uid; \
	int32 Width; \
	int32 Height; \
	int32 Elapsed; \
}; \
static inline void FFirstRemoteVideoFrame_DelegateWrapper(const FMulticastScriptDelegate& FirstRemoteVideoFrame, int64 Uid, int32 Width, int32 Height, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstRemoteVideoFrame_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	Parms.Elapsed=Elapsed; \
	FirstRemoteVideoFrame.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_66_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstRemoteVideoDecoded_Parms \
{ \
	int64 Uid; \
	int32 Width; \
	int32 Height; \
	int32 Elapsed; \
}; \
static inline void FFirstRemoteVideoDecoded_DelegateWrapper(const FMulticastScriptDelegate& FirstRemoteVideoDecoded, int64 Uid, int32 Width, int32 Height, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstRemoteVideoDecoded_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	Parms.Elapsed=Elapsed; \
	FirstRemoteVideoDecoded.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_65_DELEGATE \
struct _Script_AgoraBlueprintable_eventFirstLocalVideoFrame_Parms \
{ \
	int32 Width; \
	int32 Height; \
	int32 Elapsed; \
}; \
static inline void FFirstLocalVideoFrame_DelegateWrapper(const FMulticastScriptDelegate& FirstLocalVideoFrame, int32 Width, int32 Height, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventFirstLocalVideoFrame_Parms Parms; \
	Parms.Width=Width; \
	Parms.Height=Height; \
	Parms.Elapsed=Elapsed; \
	FirstLocalVideoFrame.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_64_DELEGATE \
static inline void FVideoStopped_DelegateWrapper(const FMulticastScriptDelegate& VideoStopped) \
{ \
	VideoStopped.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_63_DELEGATE \
struct _Script_AgoraBlueprintable_eventActiveSpeaker_Parms \
{ \
	int64 Uid; \
}; \
static inline void FActiveSpeaker_DelegateWrapper(const FMulticastScriptDelegate& ActiveSpeaker, int64 Uid) \
{ \
	_Script_AgoraBlueprintable_eventActiveSpeaker_Parms Parms; \
	Parms.Uid=Uid; \
	ActiveSpeaker.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_62_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioVolumeIndication_Parms \
{ \
	TArray<FAudioVolumeInfo> speakers; \
	int32 totalVolume; \
}; \
static inline void FAudioVolumeIndication_DelegateWrapper(const FMulticastScriptDelegate& AudioVolumeIndication, TArray<FAudioVolumeInfo> const& speakers, int32 totalVolume) \
{ \
	_Script_AgoraBlueprintable_eventAudioVolumeIndication_Parms Parms; \
	Parms.speakers=speakers; \
	Parms.totalVolume=totalVolume; \
	AudioVolumeIndication.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_61_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteAudioStateChanged_Parms \
{ \
	int64 Uid; \
	TEnumAsByte<EREMOTE_AUDIO_STATE> State; \
	TEnumAsByte<EREMOTE_AUDIO_STATE_REASON> Reason; \
	int32 Elapsed; \
}; \
static inline void FRemoteAudioStateChanged_DelegateWrapper(const FMulticastScriptDelegate& RemoteAudioStateChanged, int64 Uid, EREMOTE_AUDIO_STATE State, EREMOTE_AUDIO_STATE_REASON Reason, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventRemoteAudioStateChanged_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.State=State; \
	Parms.Reason=Reason; \
	Parms.Elapsed=Elapsed; \
	RemoteAudioStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_60_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalAudioStateChanged_Parms \
{ \
	TEnumAsByte<ELOCAL_AUDIO_STREAM_STATE> State; \
	TEnumAsByte<ELOCAL_AUDIO_STREAM_ERROR> Error; \
}; \
static inline void FLocalAudioStateChanged_DelegateWrapper(const FMulticastScriptDelegate& LocalAudioStateChanged, ELOCAL_AUDIO_STREAM_STATE State, ELOCAL_AUDIO_STREAM_ERROR Error) \
{ \
	_Script_AgoraBlueprintable_eventLocalAudioStateChanged_Parms Parms; \
	Parms.State=State; \
	Parms.Error=Error; \
	LocalAudioStateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_59_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteAudioStatsDelegate_Parms \
{ \
	FRemoteAudioStats Stats; \
}; \
static inline void FRemoteAudioStatsDelegate_DelegateWrapper(const FMulticastScriptDelegate& RemoteAudioStatsDelegate, FRemoteAudioStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventRemoteAudioStatsDelegate_Parms Parms; \
	Parms.Stats=Stats; \
	RemoteAudioStatsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_58_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalAudioStatsDelegate_Parms \
{ \
	FLocalAudioStats Stats; \
}; \
static inline void FLocalAudioStatsDelegate_DelegateWrapper(const FMulticastScriptDelegate& LocalAudioStatsDelegate, FLocalAudioStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventLocalAudioStatsDelegate_Parms Parms; \
	Parms.Stats=Stats; \
	LocalAudioStatsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_57_DELEGATE \
struct _Script_AgoraBlueprintable_eventRemoteVideoStatsDelegate_Parms \
{ \
	FRemoteVideoStats Stats; \
}; \
static inline void FRemoteVideoStatsDelegate_DelegateWrapper(const FMulticastScriptDelegate& RemoteVideoStatsDelegate, FRemoteVideoStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventRemoteVideoStatsDelegate_Parms Parms; \
	Parms.Stats=Stats; \
	RemoteVideoStatsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_56_DELEGATE \
struct _Script_AgoraBlueprintable_eventLocalVideoStatsDelegate_Parms \
{ \
	FLocalVideoStats Stats; \
}; \
static inline void FLocalVideoStatsDelegate_DelegateWrapper(const FMulticastScriptDelegate& LocalVideoStatsDelegate, FLocalVideoStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventLocalVideoStatsDelegate_Parms Parms; \
	Parms.Stats=Stats; \
	LocalVideoStatsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_55_DELEGATE \
struct _Script_AgoraBlueprintable_eventNetworkQuality_Parms \
{ \
	int64 Uid; \
	int32 TxQuality; \
	int32 RxQuality; \
}; \
static inline void FNetworkQuality_DelegateWrapper(const FMulticastScriptDelegate& NetworkQuality, int64 Uid, int32 TxQuality, int32 RxQuality) \
{ \
	_Script_AgoraBlueprintable_eventNetworkQuality_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.TxQuality=TxQuality; \
	Parms.RxQuality=RxQuality; \
	NetworkQuality.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_54_DELEGATE \
struct _Script_AgoraBlueprintable_eventRtcStatsDelegate_Parms \
{ \
	FRtcStats Stats; \
}; \
static inline void FRtcStatsDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcStatsDelegate, FRtcStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventRtcStatsDelegate_Parms Parms; \
	Parms.Stats=Stats; \
	RtcStatsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_53_DELEGATE \
struct _Script_AgoraBlueprintable_eventAudioQuality_Parms \
{ \
	int64 Uid; \
	int32 Quality; \
	int32 Delay; \
	int32 Lost; \
}; \
static inline void FAudioQuality_DelegateWrapper(const FMulticastScriptDelegate& AudioQuality, int64 Uid, int32 Quality, int32 Delay, int32 Lost) \
{ \
	_Script_AgoraBlueprintable_eventAudioQuality_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Quality=Quality; \
	Parms.Delay=Delay; \
	Parms.Lost=Lost; \
	AudioQuality.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_52_DELEGATE \
struct _Script_AgoraBlueprintable_eventTokenPrivilegeWillExpire_Parms \
{ \
	FString Token; \
}; \
static inline void FTokenPrivilegeWillExpire_DelegateWrapper(const FMulticastScriptDelegate& TokenPrivilegeWillExpire, const FString& Token) \
{ \
	_Script_AgoraBlueprintable_eventTokenPrivilegeWillExpire_Parms Parms; \
	Parms.Token=Token; \
	TokenPrivilegeWillExpire.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_51_DELEGATE \
static inline void FRequestToken_DelegateWrapper(const FMulticastScriptDelegate& RequestToken) \
{ \
	RequestToken.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_50_DELEGATE \
struct _Script_AgoraBlueprintable_eventApiCallExecuted_Parms \
{ \
	int32 Err; \
	FString Api; \
	FString Result; \
}; \
static inline void FApiCallExecuted_DelegateWrapper(const FMulticastScriptDelegate& ApiCallExecuted, int32 Err, const FString& Api, const FString& Result) \
{ \
	_Script_AgoraBlueprintable_eventApiCallExecuted_Parms Parms; \
	Parms.Err=Err; \
	Parms.Api=Api; \
	Parms.Result=Result; \
	ApiCallExecuted.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_49_DELEGATE \
static inline void FConnectionBanned_DelegateWrapper(const FMulticastScriptDelegate& ConnectionBanned) \
{ \
	ConnectionBanned.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_48_DELEGATE \
static inline void FConnectionLost_DelegateWrapper(const FMulticastScriptDelegate& ConnectionLost) \
{ \
	ConnectionLost.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_47_DELEGATE \
static inline void FConnectionInterrupted_DelegateWrapper(const FMulticastScriptDelegate& ConnectionInterrupted) \
{ \
	ConnectionInterrupted.ProcessMulticastDelegate<UObject>(NULL); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_46_DELEGATE \
struct _Script_AgoraBlueprintable_eventLastmileProbeResultDelegate_Parms \
{ \
	FLastmileProbeResult Result; \
}; \
static inline void FLastmileProbeResultDelegate_DelegateWrapper(const FMulticastScriptDelegate& LastmileProbeResultDelegate, FLastmileProbeResult const& Result) \
{ \
	_Script_AgoraBlueprintable_eventLastmileProbeResultDelegate_Parms Parms; \
	Parms.Result=Result; \
	LastmileProbeResultDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_45_DELEGATE \
struct _Script_AgoraBlueprintable_eventLastmileQuality_Parms \
{ \
	int32 Quality; \
}; \
static inline void FLastmileQuality_DelegateWrapper(const FMulticastScriptDelegate& LastmileQuality, int32 Quality) \
{ \
	_Script_AgoraBlueprintable_eventLastmileQuality_Parms Parms; \
	Parms.Quality=Quality; \
	LastmileQuality.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_44_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserOffline_Parms \
{ \
	int64 Uid; \
	TEnumAsByte<EUSER_OFFLINE_REASON_TYPE> Reason; \
}; \
static inline void FUserOffline_DelegateWrapper(const FMulticastScriptDelegate& UserOffline, int64 Uid, EUSER_OFFLINE_REASON_TYPE Reason) \
{ \
	_Script_AgoraBlueprintable_eventUserOffline_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Reason=Reason; \
	UserOffline.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_43_DELEGATE \
struct _Script_AgoraBlueprintable_eventUserJoined_Parms \
{ \
	int64 Uid; \
	int32 Elapsed; \
}; \
static inline void FUserJoined_DelegateWrapper(const FMulticastScriptDelegate& UserJoined, int64 Uid, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventUserJoined_Parms Parms; \
	Parms.Uid=Uid; \
	Parms.Elapsed=Elapsed; \
	UserJoined.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_42_DELEGATE \
struct _Script_AgoraBlueprintable_eventClientRoleChanged_Parms \
{ \
	TEnumAsByte<ECLIENT_ROLE_TYPE> OldRole; \
	TEnumAsByte<ECLIENT_ROLE_TYPE> NewRole; \
}; \
static inline void FClientRoleChanged_DelegateWrapper(const FMulticastScriptDelegate& ClientRoleChanged, ECLIENT_ROLE_TYPE OldRole, ECLIENT_ROLE_TYPE NewRole) \
{ \
	_Script_AgoraBlueprintable_eventClientRoleChanged_Parms Parms; \
	Parms.OldRole=OldRole; \
	Parms.NewRole=NewRole; \
	ClientRoleChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_41_DELEGATE \
struct _Script_AgoraBlueprintable_eventLeaveChannel_Parms \
{ \
	FRtcStats Stats; \
}; \
static inline void FLeaveChannel_DelegateWrapper(const FMulticastScriptDelegate& LeaveChannel, FRtcStats const& Stats) \
{ \
	_Script_AgoraBlueprintable_eventLeaveChannel_Parms Parms; \
	Parms.Stats=Stats; \
	LeaveChannel.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_40_DELEGATE \
struct _Script_AgoraBlueprintable_eventRejoinChannelSuccess_Parms \
{ \
	FString Channel; \
	int64 Uid; \
	int32 Elapsed; \
}; \
static inline void FRejoinChannelSuccess_DelegateWrapper(const FMulticastScriptDelegate& RejoinChannelSuccess, const FString& Channel, int64 Uid, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventRejoinChannelSuccess_Parms Parms; \
	Parms.Channel=Channel; \
	Parms.Uid=Uid; \
	Parms.Elapsed=Elapsed; \
	RejoinChannelSuccess.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_39_DELEGATE \
struct _Script_AgoraBlueprintable_eventJoinChannelSuccess_Parms \
{ \
	FString Channel; \
	int64 Uid; \
	int32 Elapsed; \
}; \
static inline void FJoinChannelSuccess_DelegateWrapper(const FMulticastScriptDelegate& JoinChannelSuccess, const FString& Channel, int64 Uid, int32 Elapsed) \
{ \
	_Script_AgoraBlueprintable_eventJoinChannelSuccess_Parms Parms; \
	Parms.Channel=Channel; \
	Parms.Uid=Uid; \
	Parms.Elapsed=Elapsed; \
	JoinChannelSuccess.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_38_DELEGATE \
struct _Script_AgoraBlueprintable_eventError_Parms \
{ \
	int32 Err; \
	FString Msg; \
}; \
static inline void FError_DelegateWrapper(const FMulticastScriptDelegate& Error, int32 Err, const FString& Msg) \
{ \
	_Script_AgoraBlueprintable_eventError_Parms Parms; \
	Parms.Err=Err; \
	Parms.Msg=Msg; \
	Error.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_37_DELEGATE \
struct _Script_AgoraBlueprintable_eventWarning_Parms \
{ \
	int32 ErrorCode; \
	FString ErrorMessage; \
}; \
static inline void FWarning_DelegateWrapper(const FMulticastScriptDelegate& Warning, int32 ErrorCode, const FString& ErrorMessage) \
{ \
	_Script_AgoraBlueprintable_eventWarning_Parms Parms; \
	Parms.ErrorCode=ErrorCode; \
	Parms.ErrorMessage=ErrorMessage; \
	Warning.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnumerateVideoRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateVideoRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVideoRecordingDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentVideoRecordingDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentVideoRecordingDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVideoRecordingDevice(Z_Param_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetVideoRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioDeviceLoopbackTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioDeviceLoopbackTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioDeviceLoopbackTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndicationInterval); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioDeviceLoopbackTest(Z_Param_IndicationInterval); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioPlaybackDeviceTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioPlaybackDeviceTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioPlaybackDeviceTest) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_TestAudioFilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioPlaybackDeviceTest(Z_Param_TestAudioFilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioRecordingDeviceTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioRecordingDeviceTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioRecordingDeviceTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndicationInterval); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioRecordingDeviceTest(Z_Param_IndicationInterval); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioPlaybackDeviceVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioPlaybackDeviceVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioRecordingDeviceVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioRecordingDeviceVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDeviceVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioPlaybackDeviceVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDeviceVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioRecordingDeviceVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioPlaybackDeviceMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioPlaybackDeviceMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioRecordingDeviceMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioRecordingDeviceMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAudioPlaybackDeviceMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsAudioPlaybackDeviceMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAudioRecordingDeviceMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsAudioRecordingDeviceMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetApplicationVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetApplicationVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetApplicationVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetApplicationVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetApplicationMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetApplicationMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsApplicationMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsApplicationMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnumerateAudioPlaybackDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateAudioPlaybackDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnumerateAudioRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateAudioRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioPlaybackDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioRecordingDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAudioPlaybackDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentAudioPlaybackDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAudioRecordingDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentAudioRecordingDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentAudioPlaybackDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentAudioPlaybackDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentAudioRecordingDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentAudioRecordingDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetAudioPlaybackDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetAudioRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopScreenCapture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopScreenCapture(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateScreenCaptureRegion) \
	{ \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateScreenCaptureRegion(Z_Param_Out_RegionRect); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateScreenCaptureParameters) \
	{ \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateScreenCaptureParameters(Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetScreenCaptureContentHint) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ContentHint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetScreenCaptureContentHint(EVIDEO_CONTENT_HINT(Z_Param_ContentHint)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartScreenCaptureByScreenRect) \
	{ \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_ScreenRect); \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartScreenCaptureByScreenRect(Z_Param_Out_ScreenRect,Z_Param_Out_RegionRect,Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartScreenCaptureByDisplayId) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_DisplayId); \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartScreenCaptureByDisplayId(Z_Param_DisplayId,Z_Param_Out_RegionRect,Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioSessionOperationRestriction) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Restriction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioSessionOperationRestriction(EAUDIO_SESSION_OPERATION_RESTRICTION(Z_Param_Restriction)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSpeakerphoneEnabled) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsSpeakerphoneEnabled(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInEarMonitoringVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetInEarMonitoringVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableSpeakerphone) \
	{ \
		P_GET_UBOOL(Z_Param_SpeakerOn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEnableSpeakerphone(Z_Param_SpeakerOn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultAudioRouteToSpeakerphone) \
	{ \
		P_GET_UBOOL(Z_Param_DefaultToSpeaker); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultAudioRouteToSpeakerphone(Z_Param_DefaultToSpeaker); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchCamera) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Direction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SwitchCamera(ECAMERA_DIRECTION(Z_Param_Direction)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCallId) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_CallId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCallId(Z_Param_Out_CallId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChannelMediaRelay) \
	{ \
		P_GET_STRUCT_REF(FChannelMediaRelayConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateChannelMediaRelay(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartChannelMediaRelay) \
	{ \
		P_GET_STRUCT_REF(FChannelMediaRelayConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartChannelMediaRelay(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInjectStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_STRUCT_REF(FInjectStreamConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddInjectStreamUrl(Z_Param_Url,Z_Param_Out_Config); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBeautyEffectOptions) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_STRUCT(FBeautyOptions,Z_Param_Options); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetBeautyEffectOptions(Z_Param_Enabled,Z_Param_Options); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddVideoWatermark) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_WatermarkUrl); \
		P_GET_STRUCT_REF(FWatermarkOptions,Z_Param_Out_Options); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddVideoWatermark(Z_Param_WatermarkUrl,Z_Param_Out_Options); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLiveTranscoding) \
	{ \
		P_GET_STRUCT_REF(FLiveTranscoding,Z_Param_Out_Transcoding); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLiveTranscoding(Z_Param_Out_Transcoding); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateDataStream) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Id); \
		P_GET_UBOOL(Z_Param_Reliable); \
		P_GET_UBOOL(Z_Param_Ordered); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->CreateDataStream(Z_Param_Out_Id,Z_Param_Reliable,Z_Param_Ordered); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartLastmileProbeTest) \
	{ \
		P_GET_STRUCT_REF(FLastmileProbeConfig,Z_Param_Out_ProbeConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartLastmileProbeTest(Z_Param_Out_ProbeConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioMixingPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioMixingPosition(Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetupRemoteVideo) \
	{ \
		P_GET_STRUCT_REF(FVideoCanvas,Z_Param_Out_Canvas); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetupRemoteVideo(Z_Param_Out_Canvas); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetupLocalVideo) \
	{ \
		P_GET_STRUCT_REF(FVideoCanvas,Z_Param_Out_Canvas); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetupLocalVideo(Z_Param_Out_Canvas); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserInfoByUid) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_STRUCT_REF(FAgoraUserInfo,Z_Param_Out_UserInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetUserInfoByUid(Z_Param_UserId,Z_Param_Out_UserInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserInfoByUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_GET_STRUCT_REF(FAgoraUserInfo,Z_Param_Out_UserInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetUserInfoByUserAccount(Z_Param_UserAccount,Z_Param_Out_UserInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetConnectionState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TEnumAsByte<ECONNECTION_STATE_TYPE>*)Z_Param__Result=P_THIS->GetConnectionState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioRecording) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Quality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioRecording(Z_Param_FilePath,Z_Param_SampleRate,EAUDIO_RECORDING_QUALITY_TYPE(Z_Param_Quality)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteSubscribeFallbackOption) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Option); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteSubscribeFallbackOption(ESTREAM_FALLBACK_OPTIONS(Z_Param_Option)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalPublishFallbackOption) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Option); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalPublishFallbackOption(ESTREAM_FALLBACK_OPTIONS(Z_Param_Option)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlaybackAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_PlaybackSampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UseMode); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetPlaybackAudioFrameParameters(Z_Param_PlaybackSampleRate,Z_Param_Channel,ERAW_AUDIO_FRAME_OP_MODE_TYPE(Z_Param_UseMode),Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRecordingAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_RecordingSampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UseMode); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRecordingAudioFrameParameters(Z_Param_RecordingSampleRate,Z_Param_Channel,ERAW_AUDIO_FRAME_OP_MODE_TYPE(Z_Param_UseMode),Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVideoMirrorMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_MirrorMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVideoMirrorMode(EVIDEO_MIRROR_MODE_TYPE(Z_Param_MirrorMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteRenderMode) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_RenderMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteRenderMode(Z_Param_UserId,ERENDER_MODE_TYPE(Z_Param_RenderMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalRenderMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_RenderMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalRenderMode(ERENDER_MODE_TYPE(Z_Param_RenderMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceReverbPreset) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ReverbPreset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceReverbPreset(EAUDIO_REVERB_PRESET(Z_Param_ReverbPreset)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceChanger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoiceChanger); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceChanger(EVOICE_CHANGER_PRESET(Z_Param_VoiceChanger)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceReverb) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ReverbKey); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceReverb(EAUDIO_REVERB_TYPE(Z_Param_ReverbKey),Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceEqualization) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_BandFrequency); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BandGain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceEqualization(EAUDIO_EQUALIZATION_BAND_FREQUENCY(Z_Param_BandFrequency),Z_Param_BandGain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteDefaultVideoStreamType) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_StreamType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteDefaultVideoStreamType(EREMOTE_VIDEO_STREAM_TYPE(Z_Param_StreamType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteVideoStreamType) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_StreamType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteVideoStreamType(Z_Param_UserId,EREMOTE_VIDEO_STREAM_TYPE(Z_Param_StreamType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioProfile) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Profile); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Scenario); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioProfile(EAUDIO_PROFILE_TYPE(Z_Param_Profile),EAUDIO_SCENARIO_TYPE(Z_Param_Scenario)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteUserPriority) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UserPriority); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteUserPriority(Z_Param_UserId,EPRIORITY_TYPE(Z_Param_UserPriority)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetClientRole) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Role); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetClientRole(ECLIENT_ROLE_TYPE(Z_Param_Role)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCameraCapturerConfiguration) \
	{ \
		P_GET_STRUCT_REF(FCameraCapturerConfiguration,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCameraCapturerConfiguration(Z_Param_Out_Config); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteVoicePosition) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pan); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Gain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteVoicePosition(Z_Param_UserId,Z_Param_Pan,Z_Param_Gain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteRemoteVideoStream) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteRemoteVideoStream(Z_Param_UserId,Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteRemoteAudioStream) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteRemoteAudioStream(Z_Param_UserId,Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveInjectStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemoveInjectStreamUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemovePublishStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemovePublishStreamUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPublishStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_UBOOL(Z_Param_TranscodingEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddPublishStreamUrl(Z_Param_Url,Z_Param_TranscodingEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendStreamMessage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_StreamId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SendStreamMessage(Z_Param_StreamId,Z_Param_Data,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetErrorDescription) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Code); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetErrorDescription(Z_Param_Code); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execComplain) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Description); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Complain(Z_Param_CallId,Z_Param_Description); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRate) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Rating); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Description); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Rate(Z_Param_CallId,Z_Param_Rating,Z_Param_Description); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFile(Z_Param_FilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LoopCount); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pan); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Gain); \
		P_GET_UBOOL(Z_Param_Publish); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PlayEffect(Z_Param_SoundId,Z_Param_FilePath,Z_Param_LoopCount,Z_Param_Pitch,Z_Param_Pan,Z_Param_Gain,Z_Param_Publish); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPreloadEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PreloadEffect(Z_Param_SoundId,Z_Param_FilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioMixing) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_UBOOL(Z_Param_Loopback); \
		P_GET_UBOOL(Z_Param_Replace); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Cycle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioMixing(Z_Param_FilePath,Z_Param_Loopback,Z_Param_Replace,Z_Param_Cycle); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinChannelWithUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->JoinChannelWithUserAccount(Z_Param_Token,Z_Param_ChannelId,Z_Param_UserAccount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegisterLocalUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_AppId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RegisterLocalUserAccount(Z_Param_AppId,Z_Param_UserAccount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRenewToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RenewToken(Z_Param_Token); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SwitchChannel(Z_Param_Token,Z_Param_ChannelId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustPlaybackSignalVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustPlaybackSignalVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustRecordingSignalVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustRecordingSignalVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMixedAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetMixedAudioFrameParameters(Z_Param_SampleRate,Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetExternalAudioSink) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetExternalAudioSink(Z_Param_Enabled,Z_Param_SampleRate,Z_Param_Channels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetExternalAudioSource) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetExternalAudioSource(Z_Param_Enabled,Z_Param_SampleRate,Z_Param_Channels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableAudioVolumeIndication) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Interval); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Smooth); \
		P_GET_UBOOL(Z_Param_ReportVad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableAudioVolumeIndication(Z_Param_Interval,Z_Param_Smooth,Z_Param_ReportVad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFileSize) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_FileSizeInKBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFileSize(Z_Param_FileSizeInKBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFilter) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_Filter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFilter(Z_Param_Filter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoicePitch) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoicePitch(Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnloadEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UnloadEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolumeOfEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetVolumeOfEffect(Z_Param_SoundId,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEffectsVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEffectsVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingPublishVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingPublishVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingPlayoutVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingPlayoutVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableWebSdkInteroperability) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableWebSdkInteroperability(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableDualStreamMode) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableDualStreamMode(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableSoundPositionIndication) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableSoundPositionIndication(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultMuteAllRemoteVideoStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultMuteAllRemoteVideoStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteAllRemoteVideoStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteAllRemoteVideoStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLocalVideo) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLocalVideo(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultMuteAllRemoteAudioStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultMuteAllRemoteAudioStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteAllRemoteAudioStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteAllRemoteAudioStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLocalAudio) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLocalAudio(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopChannelMediaRelay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopChannelMediaRelay(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearVideoWatermarks) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ClearVideoWatermarks(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopLastmileProbeTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopLastmileProbeTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableLastmileTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableLastmileTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLastmileTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLastmileTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEffectsVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetEffectsVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingCurrentPosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingCurrentPosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingDuration) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingDuration(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingPublishVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingPublishVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingPlayoutVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingPlayoutVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioRecording) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioRecording(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopEchoTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopEchoTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartEchoTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IntervalInSeconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartEchoTest(Z_Param_IntervalInSeconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVideoEncoderConfiguration) \
	{ \
		P_GET_STRUCT_REF(FVideoEncoderConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetVideoEncoderConfiguration(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChannelProfile) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Profile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetChannelProfile(ECHANNEL_PROFILE_TYPE(Z_Param_Profile)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEncryptionSecret) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Secret); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEncryptionSecret(Z_Param_Secret); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEncryptionMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_EncryptionMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEncryptionMode(EENCRYPTION_MODE(Z_Param_EncryptionMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteLocalVideoStream) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteLocalVideoStream(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteLocalAudioStream) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteLocalAudioStream(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableAudio) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableAudio(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableAudio) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableAudio(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableVideo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableVideo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableVideo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableVideo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopPreview) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopPreview(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartPreview) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartPreview(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLeaveChannel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->LeaveChannel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OptionalInfo); \
		P_GET_PROPERTY(UInt64Property,Z_Param_OptionalUserId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->JoinChannel(Z_Param_ChannelId,Z_Param_Token,Z_Param_OptionalInfo,Z_Param_OptionalUserId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_GET_ENUM_REF(EResult,Z_Param_Out_Result); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AppId); \
		P_GET_OBJECT(UPlainData,Z_Param_OptionalContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Initialize((EResult&)(Z_Param_Out_Result),Z_Param_AppId,Z_Param_OptionalContext); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnumerateVideoRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateVideoRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVideoRecordingDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentVideoRecordingDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentVideoRecordingDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDevice) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetVideoRecordingDevice(Z_Param_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVideoRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetVideoRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioDeviceLoopbackTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioDeviceLoopbackTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioDeviceLoopbackTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndicationInterval); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioDeviceLoopbackTest(Z_Param_IndicationInterval); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioPlaybackDeviceTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioPlaybackDeviceTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioPlaybackDeviceTest) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_TestAudioFilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioPlaybackDeviceTest(Z_Param_TestAudioFilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioRecordingDeviceTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioRecordingDeviceTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioRecordingDeviceTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndicationInterval); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioRecordingDeviceTest(Z_Param_IndicationInterval); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioPlaybackDeviceVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioPlaybackDeviceVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioRecordingDeviceVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioRecordingDeviceVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDeviceVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioPlaybackDeviceVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDeviceVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioRecordingDeviceVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioPlaybackDeviceMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioPlaybackDeviceMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioRecordingDeviceMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioRecordingDeviceMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAudioPlaybackDeviceMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsAudioPlaybackDeviceMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAudioRecordingDeviceMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsAudioRecordingDeviceMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetApplicationVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetApplicationVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetApplicationVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetApplicationVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetApplicationMuted) \
	{ \
		P_GET_UBOOL(Z_Param_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetApplicationMuted(Z_Param_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsApplicationMuted) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Muted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->IsApplicationMuted(Z_Param_Out_Muted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnumerateAudioPlaybackDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateAudioPlaybackDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnumerateAudioRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnumerateAudioRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioPlaybackDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDeviceCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioRecordingDeviceCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAudioPlaybackDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentAudioPlaybackDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentAudioRecordingDevice) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Index); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceName); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCurrentAudioRecordingDevice(Z_Param_Out_Index,Z_Param_Out_DeviceName,Z_Param_Out_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentAudioPlaybackDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentAudioPlaybackDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCurrentAudioRecordingDevice) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_DeviceId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCurrentAudioRecordingDevice(Z_Param_DeviceId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioPlaybackDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetAudioPlaybackDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioRecordingDevices) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FMediaDevice>*)Z_Param__Result=P_THIS->GetAudioRecordingDevices(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopScreenCapture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopScreenCapture(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateScreenCaptureRegion) \
	{ \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateScreenCaptureRegion(Z_Param_Out_RegionRect); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateScreenCaptureParameters) \
	{ \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateScreenCaptureParameters(Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetScreenCaptureContentHint) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ContentHint); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetScreenCaptureContentHint(EVIDEO_CONTENT_HINT(Z_Param_ContentHint)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartScreenCaptureByScreenRect) \
	{ \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_ScreenRect); \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartScreenCaptureByScreenRect(Z_Param_Out_ScreenRect,Z_Param_Out_RegionRect,Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartScreenCaptureByDisplayId) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_DisplayId); \
		P_GET_STRUCT_REF(FRectangle,Z_Param_Out_RegionRect); \
		P_GET_STRUCT_REF(FScreenCaptureParameters,Z_Param_Out_CaptureParams); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartScreenCaptureByDisplayId(Z_Param_DisplayId,Z_Param_Out_RegionRect,Z_Param_Out_CaptureParams); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioSessionOperationRestriction) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Restriction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioSessionOperationRestriction(EAUDIO_SESSION_OPERATION_RESTRICTION(Z_Param_Restriction)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSpeakerphoneEnabled) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsSpeakerphoneEnabled(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInEarMonitoringVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetInEarMonitoringVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEnableSpeakerphone) \
	{ \
		P_GET_UBOOL(Z_Param_SpeakerOn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEnableSpeakerphone(Z_Param_SpeakerOn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultAudioRouteToSpeakerphone) \
	{ \
		P_GET_UBOOL(Z_Param_DefaultToSpeaker); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultAudioRouteToSpeakerphone(Z_Param_DefaultToSpeaker); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchCamera) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Direction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SwitchCamera(ECAMERA_DIRECTION(Z_Param_Direction)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCallId) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_CallId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetCallId(Z_Param_Out_CallId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateChannelMediaRelay) \
	{ \
		P_GET_STRUCT_REF(FChannelMediaRelayConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UpdateChannelMediaRelay(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartChannelMediaRelay) \
	{ \
		P_GET_STRUCT_REF(FChannelMediaRelayConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartChannelMediaRelay(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInjectStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_STRUCT_REF(FInjectStreamConfig,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddInjectStreamUrl(Z_Param_Url,Z_Param_Out_Config); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBeautyEffectOptions) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_STRUCT(FBeautyOptions,Z_Param_Options); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetBeautyEffectOptions(Z_Param_Enabled,Z_Param_Options); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddVideoWatermark) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_WatermarkUrl); \
		P_GET_STRUCT_REF(FWatermarkOptions,Z_Param_Out_Options); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddVideoWatermark(Z_Param_WatermarkUrl,Z_Param_Out_Options); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLiveTranscoding) \
	{ \
		P_GET_STRUCT_REF(FLiveTranscoding,Z_Param_Out_Transcoding); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLiveTranscoding(Z_Param_Out_Transcoding); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateDataStream) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Id); \
		P_GET_UBOOL(Z_Param_Reliable); \
		P_GET_UBOOL(Z_Param_Ordered); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->CreateDataStream(Z_Param_Out_Id,Z_Param_Reliable,Z_Param_Ordered); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartLastmileProbeTest) \
	{ \
		P_GET_STRUCT_REF(FLastmileProbeConfig,Z_Param_Out_ProbeConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartLastmileProbeTest(Z_Param_Out_ProbeConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioMixingPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Pos); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioMixingPosition(Z_Param_Pos); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetupRemoteVideo) \
	{ \
		P_GET_STRUCT_REF(FVideoCanvas,Z_Param_Out_Canvas); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetupRemoteVideo(Z_Param_Out_Canvas); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetupLocalVideo) \
	{ \
		P_GET_STRUCT_REF(FVideoCanvas,Z_Param_Out_Canvas); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetupLocalVideo(Z_Param_Out_Canvas); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserInfoByUid) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_STRUCT_REF(FAgoraUserInfo,Z_Param_Out_UserInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetUserInfoByUid(Z_Param_UserId,Z_Param_Out_UserInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserInfoByUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_GET_STRUCT_REF(FAgoraUserInfo,Z_Param_Out_UserInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetUserInfoByUserAccount(Z_Param_UserAccount,Z_Param_Out_UserInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetConnectionState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TEnumAsByte<ECONNECTION_STATE_TYPE>*)Z_Param__Result=P_THIS->GetConnectionState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioRecording) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Quality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioRecording(Z_Param_FilePath,Z_Param_SampleRate,EAUDIO_RECORDING_QUALITY_TYPE(Z_Param_Quality)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteSubscribeFallbackOption) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Option); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteSubscribeFallbackOption(ESTREAM_FALLBACK_OPTIONS(Z_Param_Option)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalPublishFallbackOption) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Option); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalPublishFallbackOption(ESTREAM_FALLBACK_OPTIONS(Z_Param_Option)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlaybackAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_PlaybackSampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UseMode); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetPlaybackAudioFrameParameters(Z_Param_PlaybackSampleRate,Z_Param_Channel,ERAW_AUDIO_FRAME_OP_MODE_TYPE(Z_Param_UseMode),Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRecordingAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_RecordingSampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UseMode); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRecordingAudioFrameParameters(Z_Param_RecordingSampleRate,Z_Param_Channel,ERAW_AUDIO_FRAME_OP_MODE_TYPE(Z_Param_UseMode),Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVideoMirrorMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_MirrorMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVideoMirrorMode(EVIDEO_MIRROR_MODE_TYPE(Z_Param_MirrorMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteRenderMode) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_RenderMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteRenderMode(Z_Param_UserId,ERENDER_MODE_TYPE(Z_Param_RenderMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalRenderMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_RenderMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalRenderMode(ERENDER_MODE_TYPE(Z_Param_RenderMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceReverbPreset) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ReverbPreset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceReverbPreset(EAUDIO_REVERB_PRESET(Z_Param_ReverbPreset)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceChanger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_VoiceChanger); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceChanger(EVOICE_CHANGER_PRESET(Z_Param_VoiceChanger)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceReverb) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_ReverbKey); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceReverb(EAUDIO_REVERB_TYPE(Z_Param_ReverbKey),Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoiceEqualization) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_BandFrequency); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BandGain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoiceEqualization(EAUDIO_EQUALIZATION_BAND_FREQUENCY(Z_Param_BandFrequency),Z_Param_BandGain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteDefaultVideoStreamType) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_StreamType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteDefaultVideoStreamType(EREMOTE_VIDEO_STREAM_TYPE(Z_Param_StreamType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteVideoStreamType) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_StreamType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteVideoStreamType(Z_Param_UserId,EREMOTE_VIDEO_STREAM_TYPE(Z_Param_StreamType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAudioProfile) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Profile); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Scenario); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetAudioProfile(EAUDIO_PROFILE_TYPE(Z_Param_Profile),EAUDIO_SCENARIO_TYPE(Z_Param_Scenario)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteUserPriority) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_UserPriority); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteUserPriority(Z_Param_UserId,EPRIORITY_TYPE(Z_Param_UserPriority)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetClientRole) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Role); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetClientRole(ECLIENT_ROLE_TYPE(Z_Param_Role)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCameraCapturerConfiguration) \
	{ \
		P_GET_STRUCT_REF(FCameraCapturerConfiguration,Z_Param_Out_Config); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetCameraCapturerConfiguration(Z_Param_Out_Config); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRemoteVoicePosition) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pan); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Gain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetRemoteVoicePosition(Z_Param_UserId,Z_Param_Pan,Z_Param_Gain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteRemoteVideoStream) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteRemoteVideoStream(Z_Param_UserId,Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteRemoteAudioStream) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_UserId); \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteRemoteAudioStream(Z_Param_UserId,Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveInjectStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemoveInjectStreamUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemovePublishStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemovePublishStreamUrl(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPublishStreamUrl) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_UBOOL(Z_Param_TranscodingEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AddPublishStreamUrl(Z_Param_Url,Z_Param_TranscodingEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendStreamMessage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_StreamId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SendStreamMessage(Z_Param_StreamId,Z_Param_Data,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetErrorDescription) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Code); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetErrorDescription(Z_Param_Code); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execComplain) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Description); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Complain(Z_Param_CallId,Z_Param_Description); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRate) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Rating); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Description); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Rate(Z_Param_CallId,Z_Param_Rating,Z_Param_Description); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFile(Z_Param_FilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LoopCount); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pan); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Gain); \
		P_GET_UBOOL(Z_Param_Publish); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PlayEffect(Z_Param_SoundId,Z_Param_FilePath,Z_Param_LoopCount,Z_Param_Pitch,Z_Param_Pan,Z_Param_Gain,Z_Param_Publish); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPreloadEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PreloadEffect(Z_Param_SoundId,Z_Param_FilePath); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAudioMixing) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilePath); \
		P_GET_UBOOL(Z_Param_Loopback); \
		P_GET_UBOOL(Z_Param_Replace); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Cycle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartAudioMixing(Z_Param_FilePath,Z_Param_Loopback,Z_Param_Replace,Z_Param_Cycle); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinChannelWithUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->JoinChannelWithUserAccount(Z_Param_Token,Z_Param_ChannelId,Z_Param_UserAccount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegisterLocalUserAccount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_AppId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserAccount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RegisterLocalUserAccount(Z_Param_AppId,Z_Param_UserAccount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRenewToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RenewToken(Z_Param_Token); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SwitchChannel(Z_Param_Token,Z_Param_ChannelId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustPlaybackSignalVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustPlaybackSignalVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustRecordingSignalVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustRecordingSignalVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMixedAudioFrameParameters) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SamplesPerCall); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetMixedAudioFrameParameters(Z_Param_SampleRate,Z_Param_SamplesPerCall); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetExternalAudioSink) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetExternalAudioSink(Z_Param_Enabled,Z_Param_SampleRate,Z_Param_Channels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetExternalAudioSource) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_SampleRate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetExternalAudioSource(Z_Param_Enabled,Z_Param_SampleRate,Z_Param_Channels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableAudioVolumeIndication) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Interval); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Smooth); \
		P_GET_UBOOL(Z_Param_ReportVad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableAudioVolumeIndication(Z_Param_Interval,Z_Param_Smooth,Z_Param_ReportVad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFileSize) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_FileSizeInKBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFileSize(Z_Param_FileSizeInKBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLogFilter) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_Filter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLogFilter(Z_Param_Filter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLocalVoicePitch) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetLocalVoicePitch(Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnloadEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->UnloadEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopEffect(Z_Param_SoundId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVolumeOfEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_SoundId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetVolumeOfEffect(Z_Param_SoundId,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEffectsVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEffectsVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingPublishVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingPublishVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingPlayoutVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingPlayoutVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustAudioMixingVolume) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->AdjustAudioMixingVolume(Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableWebSdkInteroperability) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableWebSdkInteroperability(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableDualStreamMode) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableDualStreamMode(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableSoundPositionIndication) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableSoundPositionIndication(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultMuteAllRemoteVideoStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultMuteAllRemoteVideoStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteAllRemoteVideoStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteAllRemoteVideoStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLocalVideo) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLocalVideo(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDefaultMuteAllRemoteAudioStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetDefaultMuteAllRemoteAudioStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteAllRemoteAudioStreams) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteAllRemoteAudioStreams(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLocalAudio) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLocalAudio(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopChannelMediaRelay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopChannelMediaRelay(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearVideoWatermarks) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ClearVideoWatermarks(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopLastmileProbeTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopLastmileProbeTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableLastmileTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableLastmileTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLastmileTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableLastmileTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAllEffects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAllEffects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetEffectsVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetEffectsVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingCurrentPosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingCurrentPosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingDuration) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingDuration(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingPublishVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingPublishVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAudioMixingPlayoutVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetAudioMixingPlayoutVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResumeAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ResumeAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPauseAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->PauseAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioMixing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioMixing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAudioRecording) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopAudioRecording(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopEchoTest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopEchoTest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartEchoTest) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_IntervalInSeconds); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartEchoTest(Z_Param_IntervalInSeconds); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVideoEncoderConfiguration) \
	{ \
		P_GET_STRUCT_REF(FVideoEncoderConfiguration,Z_Param_Out_Configuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetVideoEncoderConfiguration(Z_Param_Out_Configuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetChannelProfile) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Profile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetChannelProfile(ECHANNEL_PROFILE_TYPE(Z_Param_Profile)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEncryptionSecret) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Secret); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEncryptionSecret(Z_Param_Secret); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEncryptionMode) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_EncryptionMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->SetEncryptionMode(EENCRYPTION_MODE(Z_Param_EncryptionMode)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteLocalVideoStream) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteLocalVideoStream(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMuteLocalAudioStream) \
	{ \
		P_GET_UBOOL(Z_Param_Mute); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->MuteLocalAudioStream(Z_Param_Mute); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableAudio) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableAudio(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableAudio) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableAudio(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableVideo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->DisableVideo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableVideo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->EnableVideo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopPreview) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StopPreview(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartPreview) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->StartPreview(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLeaveChannel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->LeaveChannel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ChannelId); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OptionalInfo); \
		P_GET_PROPERTY(UInt64Property,Z_Param_OptionalUserId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->JoinChannel(Z_Param_ChannelId,Z_Param_Token,Z_Param_OptionalInfo,Z_Param_OptionalUserId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_GET_ENUM_REF(EResult,Z_Param_Out_Result); \
		P_GET_PROPERTY(UStrProperty,Z_Param_AppId); \
		P_GET_OBJECT(UPlainData,Z_Param_OptionalContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Initialize((EResult&)(Z_Param_Out_Result),Z_Param_AppId,Z_Param_OptionalContext); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUIAgora(); \
	friend struct Z_Construct_UClass_UIAgora_Statics; \
public: \
	DECLARE_CLASS(UIAgora, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UIAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_INCLASS \
private: \
	static void StaticRegisterNativesUIAgora(); \
	friend struct Z_Construct_UClass_UIAgora_Statics; \
public: \
	DECLARE_CLASS(UIAgora, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UIAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UIAgora(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIAgora) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UIAgora); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIAgora); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UIAgora(UIAgora&&); \
	NO_API UIAgora(const UIAgora&); \
public:


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UIAgora(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UIAgora(UIAgora&&); \
	NO_API UIAgora(const UIAgora&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UIAgora); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIAgora); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_PRIVATE_PROPERTY_OFFSET
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_124_PROLOG
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_RPC_WRAPPERS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_INCLASS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_RPC_WRAPPERS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_INCLASS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_127_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AGORABLUEPRINTABLE_API UClass* StaticClass<class UIAgora>();

#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnUserOffline) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_userId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_reason); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnUserOffline(Z_Param_userId,EUSER_OFFLINE_REASON_TYPE(Z_Param_reason)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnLeaveChannel) \
	{ \
		P_GET_STRUCT_REF(FRtcStats,Z_Param_Out_Stats); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnLeaveChannel(Z_Param_Out_Stats); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnUserOffline) \
	{ \
		P_GET_PROPERTY(UInt64Property,Z_Param_userId); \
		P_GET_PROPERTY(UByteProperty,Z_Param_reason); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnUserOffline(Z_Param_userId,EUSER_OFFLINE_REASON_TYPE(Z_Param_reason)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnLeaveChannel) \
	{ \
		P_GET_STRUCT_REF(FRtcStats,Z_Param_Out_Stats); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnLeaveChannel(Z_Param_Out_Stats); \
		P_NATIVE_END; \
	}


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAgora(); \
	friend struct Z_Construct_UClass_UAgora_Statics; \
public: \
	DECLARE_CLASS(UAgora, UIAgora, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_INCLASS \
private: \
	static void StaticRegisterNativesUAgora(); \
	friend struct Z_Construct_UClass_UAgora_Statics; \
public: \
	DECLARE_CLASS(UAgora, UIAgora, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AgoraBlueprintable"), NO_API) \
	DECLARE_SERIALIZER(UAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAgora(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAgora) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAgora); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgora); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAgora(UAgora&&); \
	NO_API UAgora(const UAgora&); \
public:


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAgora(UAgora&&); \
	NO_API UAgora(const UAgora&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAgora); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAgora); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAgora)


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_PRIVATE_PROPERTY_OFFSET
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3470_PROLOG
#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_RPC_WRAPPERS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_INCLASS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_PRIVATE_PROPERTY_OFFSET \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_RPC_WRAPPERS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_INCLASS_NO_PURE_DECLS \
	AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h_3473_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AGORABLUEPRINTABLE_API UClass* StaticClass<class UAgora>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AgoraSDKTest_Plugins_AgoraPlugin_Source_AgoraBlueprintable_Public_Agora_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
