//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoCall.h"

#include "AgoraVideoDeviceManager.h"
#include "AgoraAudioDeviceManager.h"

#include "MediaShaders.h"

#include "VideoFrameObserver.h"

#include "AudioInOutDeviceManager.h"


//=============== RtcEngineEventHandler ==================

namespace agora
{
namespace rtc
{
namespace ue4
{

class RtcEngineEventHandler : public agora::rtc::IRtcEngineEventHandler
{
   void onJoinChannelSuccess( const char* channel, agora::rtc::uid_t uid, int elapsed ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onJoinChannelSuccess. channel: %s, uid: %d" ), channel, uid );
   }

   void onConnectionStateChanged( agora::rtc::CONNECTION_STATE_TYPE state, agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onConnectionStateChanged. state: %d, reason: %d" ), state, reason );
   }

   void onUserJoined( agora::rtc::uid_t uid, int elapsed ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onUserJoined. uid: %d, elapsed: %d" ), uid, elapsed );
   }

   void onRejoinChannelSuccess( const char* channel, agora::rtc::uid_t uid, int elapsed ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onRejoinChannelSuccess. channel: %s, uid: %d" ), channel, uid );
   }

   void onWarning( int warn, const char* msg ) override
   {
      //UE_LOG(LogTemp, Warning, TEXT("onWarning. warn: %d, msg: %s"), warn, msg );
      UE_LOG( LogTemp, Warning, TEXT( "onWarning. warn: %d" ), warn );
   }

   void onError( int err, const char* msg ) override
   {
      //UE_LOG(LogTemp, Warning, TEXT("onError. err: %d, msg: %s"), err, msg);
      UE_LOG( LogTemp, Warning, TEXT( "onError. err: %d" ), err );
   }

   void onRtcStats( const agora::rtc::RtcStats& stats ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onRtcStats. stats.duration: %d" ), stats.duration );
   }

   void onAudioVolumeIndication( const agora::rtc::AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onAudioVolumeIndication. totalVolume: %d" ), totalVolume );
      ( void ) speakers;
      ( void ) speakerNumber;
      ( void ) totalVolume;
   }
};

//============== PacketObserver ===================

class PacketObserver : public agora::rtc::IPacketObserver
{
public:
   bool onSendAudioPacket( Packet& packet ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onSendAudioPacket. packet.size: %d" ), packet.size );
      return true;
   }

   bool onSendVideoPacket( Packet& packet ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onSendVideoPacket. packet.size: %d" ), packet.size );
      return true;
   }

   bool onReceiveAudioPacket( Packet& packet ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onReceiveAudioPacket. packet.size: %d" ), packet.size );
      return true;
   }

   bool onReceiveVideoPacket( Packet& packet ) override
   {
      UE_LOG( LogTemp, Warning, TEXT( "onReceiveVideoPacket. packet.size: %d" ), packet.size );
      return true;
   }
};

}
}
}

//================== VideoCall =====================

VideoCall::VideoCall()
{
   InitAgora();
}

VideoCall::~VideoCall()
{
   StopCall();
}

void VideoCall::InitAgora()
{
   RtcEnginePtr = TSharedPtr<agora::rtc::ue4::AgoraRtcEngine>( agora::rtc::ue4::AgoraRtcEngine::createAgoraRtcEngine() );

   static agora::rtc::RtcEngineContext ctx;
   ctx.appId = "aab8b8f5a8cd4469a63042fcfafe7063";
   ctx.eventHandler = new agora::rtc::ue4::RtcEngineEventHandler();

   int ret = RtcEnginePtr->initialize( ctx );
   if( ret < 0 )
   {
      UE_LOG( LogTemp, Warning, TEXT( "RtcEngine initialize ret: %d" ), ret );
   }
   MediaEnginePtr = TSharedPtr<agora::media::ue4::AgoraMediaEngine>( agora::media::ue4::AgoraMediaEngine::Create( RtcEnginePtr.Get() ) );
}

FString VideoCall::GetVersion() const
{
   if( !RtcEnginePtr )
   {
      return "";
   }
   int build = 0;
   const char* version = RtcEnginePtr->getVersion( &build );
   return FString( ANSI_TO_TCHAR( version ) );
}

void VideoCall::SetResolution( int Width, int Height, agora::rtc::FRAME_RATE FrameRate )
{
   if( !RtcEnginePtr )
   {
      return;
   }
   agora::rtc::VideoEncoderConfiguration conf;
   conf.dimensions = agora::rtc::VideoDimensions( Width, Height );
   conf.frameRate = FrameRate;
   int nRet = RtcEnginePtr->setVideoEncoderConfiguration( conf );
   if( nRet < 0 )
   {
      UE_LOG( LogTemp, Warning, TEXT( "setVideoEncoderConfiguration : %d" ), nRet )
   }
}

void VideoCall::RegisterOnLocalFrameCallback(
   std::function<void( std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t )> OnFrameCallback )
{
   OnLocalFrameCallback = std::move( OnFrameCallback );
}

void VideoCall::RegisterOnRemoteFrameCallback(
   std::function<void( std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t )> OnFrameCallback )
{
   OnRemoteFrameCallback = std::move( OnFrameCallback );
}

void VideoCall::StartCall(
   const FString& ChannelName,
   const FString& EncryptionKey,
   const FString& EncryptionType )
{
   if( !RtcEnginePtr )
   {
      return;
   }
   if( MediaEnginePtr )
   {
      if( !VideoFrameObserverPtr )
      {
         VideoFrameObserverPtr = MakeUnique<VideoFrameObserver>();

         std::function<void( std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t )> OnCaptureVideoFrameCallback
            = [this]( std::uint8_t* buffer, std::uint32_t width, std::uint32_t height, std::uint32_t size )
         {
            if( OnLocalFrameCallback )
            {
               OnLocalFrameCallback( buffer, width, height, size );
            }
            else
            {
               UE_LOG( LogTemp, Warning, TEXT( "VideoCall OnLocalFrameCallback isn't set" ) );
            }
         };
         VideoFrameObserverPtr->setOnCaptureVideoFrameCallback( std::move( OnCaptureVideoFrameCallback ) );

         std::function<void( std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t )> OnRenderVideoFrameCallback
            = [this]( std::uint8_t* buffer, std::uint32_t width, std::uint32_t height, std::uint32_t size )
         {
            if( OnRemoteFrameCallback )
            {
               OnRemoteFrameCallback( buffer, width, height, size );
            }
            else
            {
               UE_LOG( LogTemp, Warning, TEXT( "VideoCall OnRemoteFrameCallback isn't set" ) );
            }
         };
         VideoFrameObserverPtr->setOnRenderVideoFrameCallback( std::move( OnRenderVideoFrameCallback ) );
      }

      MediaEnginePtr->registerVideoFrameObserver( VideoFrameObserverPtr.Get() );
   }

   int nRet = RtcEnginePtr->enableVideo();
   if( nRet < 0 )
   {
      UE_LOG( LogTemp, Warning, TEXT( "enableVideo : %d" ), nRet )
   }

   if( !EncryptionType.IsEmpty() && !EncryptionKey.IsEmpty() )
   {
      if( EncryptionType == "aes-256" )
      {
         RtcEnginePtr->setEncryptionMode( "aes-256-xts" );
      }
      else
      {
         RtcEnginePtr->setEncryptionMode( "aes-128-xts" );
      }

      nRet = RtcEnginePtr->setEncryptionSecret( TCHAR_TO_ANSI( *EncryptionKey ) );
      if( nRet < 0 )
      {
         UE_LOG( LogTemp, Warning, TEXT( "setEncryptionSecret : %d" ), nRet )
      }
   }

   nRet = RtcEnginePtr->setChannelProfile( agora::rtc::CHANNEL_PROFILE_COMMUNICATION );
   if( nRet < 0 )
   {
      UE_LOG( LogTemp, Warning, TEXT( "setChannelProfile : %d" ), nRet )
   }
   //"demoChannel1";
   std::uint32_t nUID = 0;
   nRet = RtcEnginePtr->joinChannel( NULL, TCHAR_TO_ANSI( *ChannelName ), NULL, nUID );
   if( nRet < 0 )
   {
      UE_LOG( LogTemp, Warning, TEXT( "joinChannel ret: %d" ), nRet );
   }
}

void VideoCall::StopCall()
{
   if( MediaEnginePtr )
   {
      MediaEnginePtr->registerVideoFrameObserver( nullptr );
   }

   if( !RtcEnginePtr )
   {
      return;
   }
   auto ConnectionState = RtcEnginePtr->getConnectionState();
   if( agora::rtc::CONNECTION_STATE_DISCONNECTED != ConnectionState )
   {
      int nRet = RtcEnginePtr->leaveChannel();
      if( nRet < 0 )
      {
         UE_LOG( LogTemp, Warning, TEXT( "leaveChannel ret: %d" ), nRet );
      }
   }
}

bool VideoCall::MuteLocalAudio( bool bMuted )
{
   if( !RtcEnginePtr )
   {
      return false;
   }
   int ret = RtcEnginePtr->muteLocalAudioStream( bMuted );
   if( ret == 0 )
      bLocalAudioMuted = bMuted;

   return ret == 0 ? true : false;
}

bool VideoCall::IsLocalAudioMuted()
{
   return bLocalAudioMuted;
}

bool VideoCall::MuteLocalVideo( bool bMuted )
{
   if( !RtcEnginePtr )
   {
      return false;
   }
   int ret = RtcEnginePtr->muteLocalVideoStream( bMuted );
   if( ret == 0 )
      bLocalVideoMuted = bMuted;

   return ret == 0 ? true : false;
}

bool VideoCall::IsLocalVideoMuted()
{
   return bLocalVideoMuted;
}

bool VideoCall::EnableVideo( bool bEnable )
{
   if( !RtcEnginePtr )
   {
      return false;
   }
   int nRet = 0;
   if( bEnable )
      nRet = RtcEnginePtr->enableVideo();
   else
      nRet = RtcEnginePtr->disableVideo();
   return nRet == 0 ? true : false;
}

TUniquePtr<CameraManager> VideoCall::GetCameraManager()
{
   return CameraManager::Create( RtcEnginePtr, MediaEnginePtr );
}

TUniquePtr<AudioInOutDeviceManager> VideoCall::GetAudioDeviceManager()
{
   return AudioInOutDeviceManager::Create( RtcEnginePtr );
}

bool VideoCall::EnableEchoTest( bool bEnable )
{
   if( !RtcEnginePtr )
   {
      return false;
   }
   int nRet = 0;
   if( bEnable )
      nRet = RtcEnginePtr->startEchoTest( 10 );
   else
      nRet = RtcEnginePtr->stopEchoTest();

   return nRet == 0 ? true : false;
}