
#include "AgoraRtcChannel.h"

#include <utility>

namespace agora {
namespace rtc {
namespace ue4 {

AgoraRtcChannel::AgoraRtcChannel( const AgoraRtcChannel& other )
   : m_rtcChannel( other.m_rtcChannel )
{}

AgoraRtcChannel::AgoraRtcChannel( AgoraRtcChannel&& other ) noexcept
   : m_rtcChannel( std::exchange( other.m_rtcChannel, nullptr ) )
{}

AgoraRtcChannel& AgoraRtcChannel::operator=( const AgoraRtcChannel& other )
{
   return *this = AgoraRtcChannel( other );
}
AgoraRtcChannel& AgoraRtcChannel::operator=( AgoraRtcChannel&& other ) noexcept
{
   std::swap( m_rtcChannel, other.m_rtcChannel );
   return *this;
}

AgoraRtcChannel::AgoraRtcChannel( agora::rtc::IChannel* rtcChannel )
   : m_rtcChannel( rtcChannel )
{}

AgoraRtcChannel::~AgoraRtcChannel()
{
   release();
}

AgoraRtcChannel* AgoraRtcChannel::createAgoraRtcChannel( agora::rtc::IChannel *channel )
{
   agora::rtc::IChannel* agoraChannel = channel;
   if( !agoraChannel )
   {
      return nullptr;
   }
   return new AgoraRtcChannel( agoraChannel );
}

int AgoraRtcChannel::setChannelEventHandler( agora::rtc::IChannelEventHandler *channelEh )
{
   return m_rtcChannel->setChannelEventHandler( channelEh );
}

int AgoraRtcChannel::joinChannel( const char* token,
                                  const char* info,
                                  agora::rtc::uid_t uid,
                                  const agora::rtc::ChannelMediaOptions& options )
{
   return m_rtcChannel->joinChannel( token, info, uid, options );
}

int AgoraRtcChannel::joinChannelWithUserAccount( const char* token,
                                                 const char* userAccount,
                                                 const agora::rtc::ChannelMediaOptions& options )
{
   return m_rtcChannel->joinChannelWithUserAccount( token, userAccount, options );
}

int AgoraRtcChannel::leaveChannel()
{
   return m_rtcChannel->leaveChannel();
}

int AgoraRtcChannel::publish()
{
   return m_rtcChannel->publish();
}

int AgoraRtcChannel::unpublish()
{
   return m_rtcChannel->unpublish();
}

const char* AgoraRtcChannel::channelId()
{
   return m_rtcChannel->channelId();
}

int AgoraRtcChannel::getCallId( agora::util::AString& callId )
{
   return m_rtcChannel->getCallId( callId );
}

int AgoraRtcChannel::renewToken( const char* token )
{
   return m_rtcChannel->renewToken( token );
}

int AgoraRtcChannel::setEncryptionSecret( const char* secret )
{
   return m_rtcChannel->setEncryptionSecret( secret );
}

int AgoraRtcChannel::setEncryptionMode( const char* encryptionMode )
{
   return m_rtcChannel->setEncryptionMode( encryptionMode );
}

int AgoraRtcChannel::registerPacketObserver( agora::rtc::IPacketObserver* observer )
{
   return m_rtcChannel->registerPacketObserver( observer );
}

int AgoraRtcChannel::registerMediaMetadataObserver( agora::rtc::IMetadataObserver *observer, agora::rtc::IMetadataObserver::METADATA_TYPE type )
{
   return m_rtcChannel->registerMediaMetadataObserver( observer, type );
}

int AgoraRtcChannel::setClientRole( agora::rtc::CLIENT_ROLE_TYPE role )
{
   return m_rtcChannel->setClientRole( role );
}

int AgoraRtcChannel::setRemoteUserPriority( agora::rtc::uid_t uid, agora::rtc::PRIORITY_TYPE userPriority )
{
   return m_rtcChannel->setRemoteUserPriority( uid, userPriority );
}

int AgoraRtcChannel::setRemoteVoicePosition( agora::rtc::uid_t uid, double pan, double gain )
{
   return m_rtcChannel->setRemoteVoicePosition( uid, pan, gain );
}

int AgoraRtcChannel::setRemoteRenderMode( agora::rtc::uid_t userId, agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode )
{
   return m_rtcChannel->setRemoteRenderMode( userId, renderMode, mirrorMode );
}

int AgoraRtcChannel::setDefaultMuteAllRemoteAudioStreams( bool mute )
{
   return m_rtcChannel->setDefaultMuteAllRemoteAudioStreams( mute );
}

int AgoraRtcChannel::setDefaultMuteAllRemoteVideoStreams( bool mute )
{
   return m_rtcChannel->setDefaultMuteAllRemoteVideoStreams( mute );
}

int AgoraRtcChannel::muteAllRemoteAudioStreams( bool mute )
{
   return m_rtcChannel->muteAllRemoteAudioStreams( mute );
}

int AgoraRtcChannel::adjustUserPlaybackSignalVolume( agora::rtc::uid_t userId, int volume )
{
   return m_rtcChannel->adjustUserPlaybackSignalVolume( userId, volume );
}

int AgoraRtcChannel::muteRemoteAudioStream( agora::rtc::uid_t userId, bool mute )
{
   return m_rtcChannel->muteRemoteAudioStream( userId, mute );
}

int AgoraRtcChannel::muteAllRemoteVideoStreams( bool mute )
{
   return m_rtcChannel->muteAllRemoteVideoStreams( mute );
}

int AgoraRtcChannel::muteRemoteVideoStream( agora::rtc::uid_t userId, bool mute )
{
   return m_rtcChannel->muteRemoteVideoStream( userId, mute );
}

int AgoraRtcChannel::setRemoteVideoStreamType( agora::rtc::uid_t userId, agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType )
{
   return m_rtcChannel->setRemoteVideoStreamType( userId, streamType );
}

int AgoraRtcChannel::setRemoteDefaultVideoStreamType( agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType )
{
   return m_rtcChannel->setRemoteDefaultVideoStreamType( streamType );
}

int AgoraRtcChannel::createDataStream( int* streamId, bool reliable, bool ordered )
{
   return m_rtcChannel->createDataStream( streamId, reliable, ordered );
}

int AgoraRtcChannel::sendStreamMessage( int streamId, const char* data, size_t length )
{
   return m_rtcChannel->sendStreamMessage( streamId, data, length );
}

int AgoraRtcChannel::addPublishStreamUrl( const char *url, bool transcodingEnabled )
{
   return m_rtcChannel->addPublishStreamUrl( url, transcodingEnabled );
}

int AgoraRtcChannel::removePublishStreamUrl( const char *url )
{
   return m_rtcChannel->removePublishStreamUrl( url );
}

int AgoraRtcChannel::setLiveTranscoding( const agora::rtc::LiveTranscoding &transcoding )
{
   return m_rtcChannel->setLiveTranscoding( transcoding );
}

int AgoraRtcChannel::addInjectStreamUrl( const char* url, const agora::rtc::InjectStreamConfig& config )
{
   return m_rtcChannel->addInjectStreamUrl( url, config );
}

int AgoraRtcChannel::removeInjectStreamUrl( const char* url )
{
   return m_rtcChannel->removeInjectStreamUrl( url );
}

int AgoraRtcChannel::startChannelMediaRelay( const agora::rtc::ChannelMediaRelayConfiguration &configuration )
{
   return m_rtcChannel->startChannelMediaRelay( configuration );
}

int AgoraRtcChannel::updateChannelMediaRelay( const agora::rtc::ChannelMediaRelayConfiguration &configuration )
{
   return m_rtcChannel->updateChannelMediaRelay( configuration );
}

int AgoraRtcChannel::stopChannelMediaRelay()
{
   return m_rtcChannel->stopChannelMediaRelay();
}

agora::rtc::CONNECTION_STATE_TYPE AgoraRtcChannel::getConnectionState()
{
   return m_rtcChannel->getConnectionState();
}

int AgoraRtcChannel::release()
{
   return m_rtcChannel->release();
}


}
}
}