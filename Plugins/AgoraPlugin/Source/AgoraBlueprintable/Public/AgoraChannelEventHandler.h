#pragma once

#include "concurrent_queue.h"
#include <functional>

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#if (defined(__APPLE__) && TARGET_OS_IPHONE)
#include <Agora/iOS/Include/IAgoraRtcChannel.h>
#else
#include <Agora/IAgoraRtcChannel.h>
#endif

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UECompatibility.h"

class UAgoraChannel;

namespace agora {
namespace blueprints {
/**
Retrieves Agora callbacks.
*/
class ChannelEventHandler : public agora::rtc::IChannelEventHandler
{
public:

   ChannelEventHandler( UAgoraChannel* outer );
   ~ChannelEventHandler();

   /** All UAgoraChannel callbacks are called here. This method is used to syncronize Agora and UE threads.*/
   void OnTick();

   /** @ref UAgoraChannel::OnChannelWarningDelegate "OnChannelWarning"*/
   virtual void onChannelWarning( agora::rtc::IChannel *rtcChannel, int warn, const char* msg );

   /** @ref UAgoraChannel::OnChannelErrorDelegate "OnChannelError"*/
   virtual void onChannelError( agora::rtc::IChannel *rtcChannel, int err, const char* msg );

   /** @ref UAgoraChannel::OnJoinChannelSuccessDelegate "OnJoinChannelSuccess"*/
   virtual void onJoinChannelSuccess( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed );

   /** @ref UAgoraChannel::OnRejoinChannelSuccessDelegate "OnRejoinChannelSuccess"*/
   virtual void onRejoinChannelSuccess( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed );

   /** @ref UAgoraChannel::OnLeaveChannelDelegate "OnLeaveChannel"*/
   virtual void onLeaveChannel( agora::rtc::IChannel *rtcChannel, const agora::rtc::RtcStats& stats );

   /** @ref UAgoraChannel::OnClientRoleChangedDelegate "OnClientRoleChanged"*/
   virtual void onClientRoleChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::CLIENT_ROLE_TYPE oldRole, agora::rtc::CLIENT_ROLE_TYPE newRole );

   /** @ref UAgoraChannel::OnUserJoinedDelegate "OnUserJoined"*/
   virtual void onUserJoined( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed );

   /** @ref UAgoraChannel::OnUserOfflineDelegate "OnUserOffline"*/
   virtual void onUserOffline( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::USER_OFFLINE_REASON_TYPE reason );

   /** @ref UAgoraChannel::OnConnectionLostDelegate "OnConnectionLost"*/
   virtual void onConnectionLost( agora::rtc::IChannel *rtcChannel );

   /** @ref UAgoraChannel::OnRequestTokenDelegate "OnRequestToken"*/
   virtual void onRequestToken( agora::rtc::IChannel *rtcChannel );

   /** @ref UAgoraChannel::OnTokenPrivilegeWillExpireDelegate "OnTokenPrivilegeWillExpire"*/
   virtual void onTokenPrivilegeWillExpire( agora::rtc::IChannel *rtcChannel, const char* token );

   /** @ref UAgoraChannel::OnRtcStatsDelegate "OnRtcStats"*/
   virtual void onRtcStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RtcStats& stats );

   /** @ref UAgoraChannel::OnNetworkQualityDelegate "OnNetworkQuality"*/
   virtual void onNetworkQuality( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int txQuality, int rxQuality );

   /** @ref UAgoraChannel::OnRemoteVideoStatsDelegate "OnRemoteVideoStats"*/
   virtual void onRemoteVideoStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RemoteVideoStats& stats );

   /** @ref UAgoraChannel::OnRemoteAudioStatsDelegate "OnRemoteAudioStats"*/
   virtual void onRemoteAudioStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RemoteAudioStats& stats );

   /** @ref UAgoraChannel::OnRemoteAudioStateChangedDelegate "OnRemoteAudioStateChanged"*/
   virtual void onRemoteAudioStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::REMOTE_AUDIO_STATE state, agora::rtc::REMOTE_AUDIO_STATE_REASON reason, int elapsed );

   /** @ref UAgoraChannel::OnActiveSpeakerDelegate "OnActiveSpeaker"*/
   virtual void onActiveSpeaker( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid );

   /** @ref UAgoraChannel::OnVideoSizeChangedDelegate "OnVideoSizeChanged"*/
   virtual void onVideoSizeChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int width, int height, int rotation );

   /** @ref UAgoraChannel::OnRemoteVideoStateChangedDelegate "OnRemoteVideoStateChanged"*/
   virtual void onRemoteVideoStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::REMOTE_VIDEO_STATE state, agora::rtc::REMOTE_VIDEO_STATE_REASON reason, int elapsed );

   /** @ref UAgoraChannel::OnStreamMessageDelegate "OnStreamMessage"*/
   virtual void onStreamMessage( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int streamId, const char* data, size_t length );

   /** @ref UAgoraChannel::OnStreamMessageErrorDelegate "OnStreamMessageError"*/
   virtual void onStreamMessageError( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int streamId, int code, int missed, int cached );

   /** @ref UAgoraChannel::OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged"*/
   virtual void onChannelMediaRelayStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_STATE state, agora::rtc::CHANNEL_MEDIA_RELAY_ERROR code );

   /** @ref UAgoraChannel::OnChannelMediaRelayEventDelegate "OnChannelMediaRelayEvent"*/
   virtual void onChannelMediaRelayEvent( agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_EVENT code );

   /** @ref UAgoraChannel::OnRtmpStreamingStateChangedDelegate "OnRtmpStreamingStateChanged"*/
   virtual void onRtmpStreamingStateChanged( agora::rtc::IChannel *rtcChannel, const char *url, agora::rtc::RTMP_STREAM_PUBLISH_STATE state, agora::rtc::RTMP_STREAM_PUBLISH_ERROR errCode );

   /** @ref UAgoraChannel::OnTranscodingUpdatedDelegate "OnTranscodingUpdated"*/
   virtual void onTranscodingUpdated( agora::rtc::IChannel *rtcChannel );

   /** @ref UAgoraChannel::OnStreamInjectedStatusDelegate "OnStreamInjectedStatus"*/
   virtual void onStreamInjectedStatus( agora::rtc::IChannel *rtcChannel, const char* url, agora::rtc::uid_t uid, int status );

   /** @ref UAgoraChannel::OnLocalPublishFallbackToAudioOnlyDelegate "OnLocalPublishFallbackToAudioOnly"*/
   virtual void onLocalPublishFallbackToAudioOnly( agora::rtc::IChannel *rtcChannel, bool isFallbackOrRecover );

   /** @ref UAgoraChannel::OnRemoteSubscribeFallbackToAudioOnlyDelegate "OnRemoteSubscribeFallbackToAudioOnly"*/
   virtual void onRemoteSubscribeFallbackToAudioOnly( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, bool isFallbackOrRecover );

   /** @ref UAgoraChannel::OnConnectionStateChangedDelegate "OnConnectionStateChanged"*/
   virtual void onConnectionStateChanged( agora::rtc::IChannel *rtcChannel,
                                          agora::rtc::CONNECTION_STATE_TYPE state,
                                          agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason );

private:
   UAgoraChannel* m_eventHandler = nullptr;
   /** Events queue*/
   ConcurrentQueue<std::function<void()>> m_functionQueue;
};

}
}
