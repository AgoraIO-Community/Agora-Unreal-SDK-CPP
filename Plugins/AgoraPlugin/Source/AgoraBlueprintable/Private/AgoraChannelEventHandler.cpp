#include "AgoraChannelEventHandler.h"
#include "AgoraBlueprintable.h"
#include "Agora.h"

namespace agora {
namespace blueprints {
ChannelEventHandler::ChannelEventHandler( UAgoraChannel* outer )
   : m_eventHandler( outer )
{
   if( !m_eventHandler )
   {
      UE_LOG( AgoraEngineLog, Error, TEXT( "ChannelEventHandler::ChannelEventHandler - Outer class is nullptr" ) );
   }
}

ChannelEventHandler::~ChannelEventHandler()
{
   m_functionQueue.clear();
   m_eventHandler = nullptr;
}

void ChannelEventHandler::OnTick()
{
   //todo: use "if" instead of "while"?
   while( !m_functionQueue.empty() )
   {
      std::function<void()> curFunction;
      if( m_functionQueue.tryPop( curFunction ) )
      {
         curFunction();
      }
   }
}
void ChannelEventHandler::onChannelError( agora::rtc::IChannel *rtcChannel, int Err, const char* msg )
{
   FString Msg( ANSI_TO_TCHAR( msg ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnChannelErrorDelegate.Broadcast( Err, Msg );
   } );
}

void ChannelEventHandler::onChannelWarning( agora::rtc::IChannel *rtcChannel, int Warn, const char* msg )
{
   FString Msg( ANSI_TO_TCHAR( msg ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnChannelWarningDelegate.Broadcast( Warn, Msg );
   } );
}

void ChannelEventHandler::onJoinChannelSuccess( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int Elapsed )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnJoinChannelSuccessDelegate.Broadcast( Uid, Elapsed );
   } );
}

void ChannelEventHandler::onRejoinChannelSuccess( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int Elapsed )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRejoinChannelSuccessDelegate.Broadcast( Uid, Elapsed );
   } );
}

void ChannelEventHandler::onLeaveChannel( agora::rtc::IChannel *rtcChannel, const agora::rtc::RtcStats& stats )
{
   FRtcStats Stats = FRtcStats( stats );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnLeaveChannelDelegate.Broadcast( Stats );
   } );
}

void ChannelEventHandler::onClientRoleChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::CLIENT_ROLE_TYPE OldRole, agora::rtc::CLIENT_ROLE_TYPE NewRole )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnClientRoleChangedDelegate.Broadcast( convert( OldRole ), convert( NewRole ) );
   } );
}

void ChannelEventHandler::onUserJoined( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int Elapsed )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnUserJoinedDelegate.Broadcast( Uid, Elapsed );
   } );
}

void ChannelEventHandler::onUserOffline( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, agora::rtc::USER_OFFLINE_REASON_TYPE Reason )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnUserOfflineDelegate.Broadcast( Uid, convert( Reason ) );
   } );
}

void ChannelEventHandler::onConnectionLost( agora::rtc::IChannel *rtcChannel )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnConnectionLostDelegate.Broadcast();
   } );
}

void ChannelEventHandler::onRequestToken( agora::rtc::IChannel *rtcChannel )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRequestTokenDelegate.Broadcast();
   } );
}

void ChannelEventHandler::onTokenPrivilegeWillExpire( agora::rtc::IChannel *rtcChannel, const char* token )
{
   FString Token( ANSI_TO_TCHAR( token ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnTokenPrivilegeWillExpireDelegate.Broadcast( Token );
   } );
}

void ChannelEventHandler::onRtcStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RtcStats& stats )
{
   FRtcStats Stats = FRtcStats( stats );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRtcStatsDelegate.Broadcast( Stats );
   } );
}

void ChannelEventHandler::onNetworkQuality( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int txQuality, int rxQuality )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnNetworkQualityDelegate.Broadcast( uid, txQuality, rxQuality );
   } );
}

void ChannelEventHandler::onRemoteVideoStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RemoteVideoStats& stats )
{
   FRemoteVideoStats Stats = convert( stats );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRemoteVideoStatsDelegate.Broadcast( Stats );
   } );
}

void ChannelEventHandler::onRemoteAudioStats( agora::rtc::IChannel *rtcChannel, const agora::rtc::RemoteAudioStats& stats )
{
   FRemoteAudioStats Stats = convert( stats );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRemoteAudioStatsDelegate.Broadcast( Stats );
   } );
}

void ChannelEventHandler::onRemoteAudioStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, agora::rtc::REMOTE_AUDIO_STATE State, agora::rtc::REMOTE_AUDIO_STATE_REASON Reason, int Elapsed )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRemoteAudioStateChangedDelegate.Broadcast( Uid, convert( State ), convert( Reason ), Elapsed );
   } );
}

void ChannelEventHandler::onActiveSpeaker( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnActiveSpeakerDelegate.Broadcast( Uid );
   } );
}

void ChannelEventHandler::onVideoSizeChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int Width, int Height, int Rotation )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnVideoSizeChangedDelegate.Broadcast( Uid, Width, Height, Rotation );
   } );
}

void ChannelEventHandler::onRemoteVideoStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, agora::rtc::REMOTE_VIDEO_STATE State, agora::rtc::REMOTE_VIDEO_STATE_REASON Reason, int Elapsed )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRemoteVideoStateChangedDelegate.Broadcast( Uid, convert( State ), convert( Reason ), Elapsed );
   } );
}

void ChannelEventHandler::onStreamMessage( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int StreamId, const char* data, size_t Length )
{
   FString Data( ANSI_TO_TCHAR( data ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnStreamMessageDelegate.Broadcast( Uid, StreamId, Data, Length );
   } );
}

void ChannelEventHandler::onStreamMessageError( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, int StreamId, int Code, int Missed, int Cached )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnStreamMessageErrorDelegate.Broadcast( Uid, StreamId, Code, Missed, Cached );
   } );
}

void ChannelEventHandler::onChannelMediaRelayStateChanged( agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_STATE State, agora::rtc::CHANNEL_MEDIA_RELAY_ERROR Code )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnChannelMediaRelayStateChangedDelegate.Broadcast( convert( State ), convert( Code ) );
   } );
}

void ChannelEventHandler::onChannelMediaRelayEvent( agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_EVENT Code )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnChannelMediaRelayEventDelegate.Broadcast( convert( Code ) );
   } );
}

void ChannelEventHandler::onRtmpStreamingStateChanged( agora::rtc::IChannel *rtcChannel, const char *url, agora::rtc::RTMP_STREAM_PUBLISH_STATE State, agora::rtc::RTMP_STREAM_PUBLISH_ERROR ErrCode )
{
   FString Url( ANSI_TO_TCHAR( url ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRtmpStreamingStateChangedDelegate.Broadcast( Url, convert( State ), convert( ErrCode ) );
   } );
}

void ChannelEventHandler::onTranscodingUpdated( agora::rtc::IChannel *rtcChannel )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnTranscodingUpdatedDelegate.Broadcast();
   } );
}

void ChannelEventHandler::onStreamInjectedStatus( agora::rtc::IChannel *rtcChannel, const char* url, agora::rtc::uid_t Uid, int Status )
{
   FString Url( ANSI_TO_TCHAR( url ) );
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnStreamInjectedStatusDelegate.Broadcast( Url, Uid, Status );
   } );
}

void ChannelEventHandler::onLocalPublishFallbackToAudioOnly( agora::rtc::IChannel *rtcChannel, bool IsFallbackOrRecover )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnLocalPublishFallbackToAudioOnlyDelegate.Broadcast( IsFallbackOrRecover );
   } );
}

void ChannelEventHandler::onRemoteSubscribeFallbackToAudioOnly( agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t Uid, bool IsFallbackOrRecover )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnRemoteSubscribeFallbackToAudioOnlyDelegate.Broadcast( Uid, IsFallbackOrRecover );
   } );
}

void ChannelEventHandler::onConnectionStateChanged( agora::rtc::IChannel *rtcChannel,
                                                    agora::rtc::CONNECTION_STATE_TYPE State,
                                                    agora::rtc::CONNECTION_CHANGED_REASON_TYPE Reason )
{
   m_functionQueue.push( [=]()
   {
      if( m_eventHandler )
         m_eventHandler->OnConnectionStateChangedDelegate.Broadcast( convert( State ), convert( Reason ) );
   } );
}
}
}