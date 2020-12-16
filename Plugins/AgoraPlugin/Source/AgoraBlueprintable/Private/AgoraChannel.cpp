
#include "AgoraChannel.h"
#include "Agora.h"
#include "AgoraBlueprintable.h"
#include "AgoraRtcChannel.h"

#include <string>

using namespace agora::rtc::ue4;
using namespace agora::media::ue4;

int UAgoraChannel::Initialize( agora::rtc::ue4::AgoraRtcChannel* Channel )
{
   rtcChannel = TSharedPtr< AgoraRtcChannel >( Channel );
   if( !rtcChannel )
   {
      UE_LOG( AgoraEngineLog, Error, TEXT( "UAgoraChannel::Initialize - failed to create Agora Rtc Channel" ) );
      return -1;
   }

   channelEventHandler = TSharedPtr<agora::blueprints::ChannelEventHandler>( new agora::blueprints::ChannelEventHandler( this ) );
   if( !channelEventHandler )
   {
      UE_LOG( AgoraEngineLog, Error, TEXT( "UAgoraChannel::Initialize - failed to create ChannelEventHandler" ) );
      return -1;
   }

   if( rtcChannel->setChannelEventHandler( channelEventHandler.Get() ) < 0 )
   {
      UE_LOG( AgoraEngineLog, Error, TEXT( "UAgoraChannel::Initialize - failed to set ChannelEventHandler" ) );
      return -1;
   }

   return 0;
}

void UAgoraChannel::BeginDestroy()
{
   Super::BeginDestroy();
}

int UAgoraChannel::JoinChannel( const FString& token,
                                const FString& info,
                                int64 uid,
                                const FChannelMediaOptions& options )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->joinChannel( TCHAR_TO_ANSI( *token ), TCHAR_TO_ANSI( *info ), uid, convert( options ) );
}

int UAgoraChannel::JoinChannelWithUserAccount( const FString& token,
                                               const FString& userAccount,
                                               const FChannelMediaOptions& options )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->joinChannelWithUserAccount( TCHAR_TO_ANSI( *token ), TCHAR_TO_ANSI( *userAccount ), convert( options ) );
}

int UAgoraChannel::LeaveChannel()
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->leaveChannel();
}

int UAgoraChannel::Publish()
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->publish();
}

int UAgoraChannel::Unpublish()
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->unpublish();
}

const FString UAgoraChannel::ChannelId()
{
   FString rez = "";
   if( !rtcChannel )
      return rez;
   rez = ANSI_TO_TCHAR( rtcChannel->channelId() );
   return rez;
}

int UAgoraChannel::SetRemoteVoicePosition( int64 uid, float pan, float gain )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setRemoteVoicePosition( uid, pan, gain );
}

int UAgoraChannel::SetDefaultMuteAllRemoteAudioStreams( bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setDefaultMuteAllRemoteAudioStreams( mute );
}

int UAgoraChannel::SetDefaultMuteAllRemoteVideoStreams( bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setDefaultMuteAllRemoteVideoStreams( mute );
}

int UAgoraChannel::MuteAllRemoteAudioStreams( bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->muteAllRemoteAudioStreams( mute );
}

int UAgoraChannel::AdjustUserPlaybackSignalVolume( int64 userId, int volume )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->adjustUserPlaybackSignalVolume( userId, volume );
}

int UAgoraChannel::MuteRemoteAudioStream( int64 userId, bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->muteRemoteAudioStream( userId, mute );
}

int UAgoraChannel::MuteAllRemoteVideoStreams( bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->muteAllRemoteVideoStreams( mute );
}

int UAgoraChannel::MuteRemoteVideoStream( int64 userId, bool mute )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->muteRemoteVideoStream( userId, mute );
}

int UAgoraChannel::StopChannelMediaRelay()
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->stopChannelMediaRelay();
}

void UAgoraChannel::Tick( float DeltaTime )
{
   if( channelEventHandler )
      channelEventHandler->OnTick();
}

int UAgoraChannel::GetCallId( FString& callId )
{
   if( !rtcChannel )
      return -1;

   agora::util::AString str;
   int ret = rtcChannel->getCallId( str );

   if( str )
   {
      callId = ANSI_TO_TCHAR( str->c_str() );
   }

   return ret;
}

int UAgoraChannel::RenewToken( const FString& token )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->renewToken( TCHAR_TO_ANSI( *token ) );
}

int UAgoraChannel::SetEncryptionSecret( const FString& secret )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setEncryptionSecret( TCHAR_TO_ANSI( *secret ) );
}

int UAgoraChannel::SetEncryptionMode( EENCRYPTION_MODE encryptionMode )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setEncryptionMode( convert( encryptionMode ) );
}

int UAgoraChannel::SendStreamMessage( int streamId, const FString& data, int64 length )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->sendStreamMessage( streamId, TCHAR_TO_ANSI( *data ), length );
}

int UAgoraChannel::AddPublishStreamUrl( const FString& url, bool transcodingEnabled )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->addPublishStreamUrl( TCHAR_TO_ANSI( *url ), transcodingEnabled );
}

int UAgoraChannel::RemovePublishStreamUrl( const FString& url )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->removePublishStreamUrl( TCHAR_TO_ANSI( *url ) );
}

int UAgoraChannel::RemoveInjectStreamUrl( const FString& url )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->removeInjectStreamUrl( TCHAR_TO_ANSI( *url ) );
}

int UAgoraChannel::CreateDataStream( int& streamId, bool reliable, bool ordered )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->createDataStream( &streamId, reliable, ordered );
}

int UAgoraChannel::SetLiveTranscoding( const FLiveTranscoding &transcoding )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setLiveTranscoding( transcoding.convert( users, watermark, backgroundImage ) );
}

int UAgoraChannel::AddInjectStreamUrl( const FString& url, const FInjectStreamConfig& config )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->addInjectStreamUrl( TCHAR_TO_ANSI( *url ), convert( config ) );
}

int UAgoraChannel::StartChannelMediaRelay( const FChannelMediaRelayConfiguration &configuration )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->startChannelMediaRelay( configuration.convert( srcInfo, destInfos ) );
}

int UAgoraChannel::UpdateChannelMediaRelay( const FChannelMediaRelayConfiguration &configuration )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->updateChannelMediaRelay( configuration.convert( srcInfo, destInfos ) );
}

int UAgoraChannel::SetClientRole( ECLIENT_ROLE_TYPE role )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setClientRole( convert( role ) );
}

int UAgoraChannel::SetRemoteUserPriority( int64 uid, EPRIORITY_TYPE userPriority )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setRemoteUserPriority( uid, convert( userPriority ) );
}

int UAgoraChannel::SetRemoteRenderMode( int64 userId, ERENDER_MODE_TYPE renderMode, EVIDEO_MIRROR_MODE_TYPE mirrorMode )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setRemoteRenderMode( userId, convert( renderMode ), convert( mirrorMode ) );
}

int UAgoraChannel::SetRemoteVideoStreamType( int64 userId, EREMOTE_VIDEO_STREAM_TYPE streamType )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setRemoteVideoStreamType( userId, convert( streamType ) );
}

int UAgoraChannel::SetRemoteDefaultVideoStreamType( EREMOTE_VIDEO_STREAM_TYPE streamType )
{
   if( !rtcChannel )
      return -1;
   return rtcChannel->setRemoteDefaultVideoStreamType( convert( streamType ) );
}

ECONNECTION_STATE_TYPE UAgoraChannel::GetConnectionState()
{
   if( !rtcChannel )
      return CONNECTION_STATE_FAILED;
   return convert( rtcChannel->getConnectionState() );
}


