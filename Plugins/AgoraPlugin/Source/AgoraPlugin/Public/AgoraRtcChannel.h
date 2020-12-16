#pragma once
#include "CoreMinimal.h"
#include "AgoraRtcEngine.h"
#include <memory>

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

namespace agora {
namespace rtc {
namespace ue4 {

/**
* Wrapper around agora::rtc::IRtcChannel
*/
class AGORAPLUGIN_API AgoraRtcChannel
{
public:
   AgoraRtcChannel() = delete;
   AgoraRtcChannel( const AgoraRtcChannel& other );
   AgoraRtcChannel( AgoraRtcChannel&& other ) noexcept;
   AgoraRtcChannel& operator=( const AgoraRtcChannel& other );
   AgoraRtcChannel& operator=( AgoraRtcChannel&& other ) noexcept;
   ~AgoraRtcChannel();

public:

   /** Creates the \ref IChannel object and returns the pointer.
   @return   \arg Success: Pointer to the \ref IChannel object.
             \arg Failure: nullptr.
   */
   static AgoraRtcChannel* createAgoraRtcChannel( agora::rtc::IChannel *channel );

   /** Sets the channel event handler.

     After setting the channel event handler, you can listen for channel events and receive the statistics of the corresponding `AgoraRtcChannel` object.

     @param channelEh The event handler of the `AgoraRtcChannel` object. For details, see IChannelEventHandler.

     @return
     - 0: Success.
     - < 0: Failure.
     */
   int setChannelEventHandler( agora::rtc::IChannelEventHandler *channelEh );

   /** Joins the channel with a user ID.

    This method differs from the `joinChannel` method in the `AgoraRtcEngine` class in the following aspects:

    | AgoraRtcChannel::joinChannel                                                                                                                        | AgoraRtcEngine::joinChannel                                                                                    |
    |-----------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
    | Does not contain the `channelId` parameter, because `channelId` is specified when creating the `AgoraRtcChannel` object.                            | Contains the `channelId` parameter, which specifies the channel to join.                                       |
    | Contains the `options` parameter, which decides whether to subscribe to all streams before joining the channel.                                     | Does not contain the `options` parameter. By default, users subscribe to all streams when joining the channel. |
    | Users can join multiple channels simultaneously by creating multiple `AgoraRtcChannel` objects and calling the `joinChannel` method of each object. | Users can join only one channel.                                                                               |
    | By default, the SDK does not publish any stream after the user joins the channel. You need to call the publish method to do that.                   | By default, the SDK publishes streams once the user joins the channel.                                         |

    @note
    - If you are already in a channel, you cannot rejoin it with the same `uid`.
    - We recommend using different UIDs for different channels.
    - If you want to join the same channel from different devices, ensure that the UIDs in all devices are different.
    - Ensure that the app ID you use to generate the token is the same with the app ID used when creating the `AgoraRtcChannel` object.

    @param token The token for authentication:
    - In situations not requiring high security: You can use the temporary token generated at Console. For details, see [Get a temporary token](https://docs.agora.io/en/Agora%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-temporary-token).
    - In situations requiring high security: Set it as the token generated at your server. For details, see [Generate a token](https://docs.agora.io/en/Agora%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-token).
    @param info (Optional) Additional information about the channel. This parameter can be set as null. Other users in the channel do not receive this information.
    @param uid The user ID. A 32-bit unsigned integer with a value ranging from 1 to (232-1). This parameter must be unique. If `uid` is not assigned (or set as `0`), the SDK assigns a `uid` and reports it in the \ref onJoinChannelSuccess callback. The app must maintain this user ID.
    @param options The channel media options: \ref ChannelMediaOptions

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (-2)
       - #ERR_NOT_READY (-3)
       - #ERR_REFUSED (-5)
    */
   int joinChannel( const char* token,
                    const char* info,
                    agora::rtc::uid_t uid,
                    const agora::rtc::ChannelMediaOptions& options );

   /** Joins the channel with a user account.

    After the user successfully joins the channel, the SDK triggers the following callbacks:

    - The local client: \ref onLocalUserRegistered and \ref onJoinChannelSuccess.
    - The remote client: \ref onUserJoined and \ref onUserInfoUpdated , if the user joining the channel is in the Communication profile, or is a BROADCASTER in the Live Broadcast profile.

    @note To ensure smooth communication, use the same parameter type to identify the user. For example, if a user joins the channel with a user ID, then ensure all the other users use the user ID too. The same applies to the user account.
    If a user joins the channel with the Agora Web SDK, ensure that the uid of the user is set to the same parameter type.

    @param token The token generated at your server:
    - For low-security requirements: You can use the temporary token generated at Console. For details, see [Get a temporary toke](https://docs.agora.io/en/Voice/token?platform=All%20Platforms#get-a-temporary-token).
    - For high-security requirements: Set it as the token generated at your server. For details, see [Get a token](https://docs.agora.io/en/Voice/token?platform=All%20Platforms#get-a-token).
    @param userAccount The user account. The maximum length of this parameter is 255 bytes. Ensure that you set this parameter and do not set it as null. Supported character scopes are:
    - All lowercase English letters: a to z.
    - All uppercase English letters: A to Z.
    - All numeric characters: 0 to 9.
    - The space character.
    - Punctuation characters and other symbols, including: "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ",".
    @param options The channel media options: \ref ChannelMediaOptions.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (-2)
       - #ERR_NOT_READY (-3)
       - #ERR_REFUSED (-5)
    */
   int joinChannelWithUserAccount( const char* token,
                                   const char* userAccount,
                                   const agora::rtc::ChannelMediaOptions& options );

   /** Allows a user to leave a channel, such as hanging up or exiting a call.

    After joining a channel, the user must call the *leaveChannel* method to end the call before joining another channel.

    This method returns 0 if the user leaves the channel and releases all resources related to the call.

    This method call is asynchronous, and the user has not left the channel when the method call returns. Once the user leaves the channel, the SDK triggers the \ref onLeaveChannel callback.

    A successful \ref leaveChannel method call triggers the following callbacks:
    - The local client: \ref onLeaveChannel 
    - The remote client: \ref onUserOffline , if the user leaving the channel is in the Communication channel, or is a BROADCASTER in the Live Broadcast profile.

    @note
    - If you call the \ref release method immediately after the *leaveChannel* method, the *leaveChannel* process interrupts, and the \ref onLeaveChannel callback is not triggered.
    - If you call the *leaveChannel* method during a CDN live streaming, the SDK triggers the \ref removePublishStreamUrl method.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int leaveChannel();

   /** Publishes the local stream to the channel.

    You must keep the following restrictions in mind when calling this method. Otherwise, the SDK returns the #ERR_REFUSED (5):
    - This method publishes one stream only to the channel corresponding to the current `IChannel` object.
    - In a Live Broadcast channel, only a broadcaster can call this method. To switch the client role, call \ref setClientRole of the current `AgoraRtcChannel` object.
    - You can publish a stream to only one channel at a time. For details on joining multiple channels, see the advanced guide *Join Multiple Channels*.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_REFUSED (5): The method call is refused.
    */
   int publish();

   /** Stops publishing a stream to the channel.

    If you call this method in a channel where you are not publishing streams, the SDK returns #ERR_REFUSED (5).

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_REFUSED (5): The method call is refused.
    */
   int unpublish();

   /** Gets the channel ID of the current `AgoraRtcChannel` object.

    @return
    - The channel ID of the current `AgoraRtcChannel` object, if the method call succeeds.
    - The empty string "", if the method call fails.
    */
   const char *channelId();

   /** Retrieves the current call ID.

    When a user joins a channel on a client, a `callId` is generated to identify the call from the client.
    Feedback methods, such as \ref AgoraRtcEngine::rate "rate" and \ref AgoraRtcEngine::complain "complain", must be called after the call ends to submit feedback to the SDK.

    The `rate` and `complain` methods require the `callId` parameter retrieved from the `getCallId` method during a call. `callId` is passed as an argument into the `rate` and `complain` methods after the call ends.

    @param callId The current call ID.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int getCallId( agora::util::AString& callId );

   /** Gets a new token when the current token expires after a period of time.

    The `token` expires after a period of time once the token schema is enabled when:

    - The SDK triggers the \ref onTokenPrivilegeWillExpire callback, or
    - The \ref onConnectionStateChanged reports CONNECTION_CHANGED_TOKEN_EXPIRED(9).

    The application should call this method to get the new `token`. Failure to do so will result in the SDK disconnecting from the server.

    @param token Pointer to the new token.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   int renewToken( const char* token );

   /** Enables built-in encryption with an encryption password before users join a channel.

    All users in a channel must use the same encryption password. The encryption password is automatically cleared once a user leaves the channel.

    If an encryption password is not specified, the encryption functionality will be disabled.

    @note
    - Do not use this method for CDN live streaming.
    - For optimal transmission, ensure that the encrypted data size does not exceed the original data size + 16 bytes. 16 bytes is the maximum padding size for AES encryption.

    @param secret Pointer to the encryption password.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setEncryptionSecret( const char* secret );

   /** Sets the built-in encryption mode.

    The Agora SDK supports built-in encryption, which is set to the `aes-128-xts` mode by default. Call this method to use other encryption modes.

    All users in the same channel must use the same encryption mode and password.

    Refer to the information related to the AES encryption algorithm on the differences between the encryption modes.

    @note Call the \ref setEncryptionSecret method to enable the built-in encryption function before calling this method.

    @param encryptionMode The set encryption mode:
    - "aes-128-xts": (Default) 128-bit AES encryption, XTS mode.
    - "aes-128-ecb": 128-bit AES encryption, ECB mode.
    - "aes-256-xts": 256-bit AES encryption, XTS mode.
    - "": When encryptionMode is set as NULL, the encryption mode is set as "aes-128-xts" by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setEncryptionMode( const char* encryptionMode );

   /** Registers a packet observer.

    The Agora SDK allows your application to register a packet observer to receive callbacks for voice or video packet transmission.

    @note
    - The size of the packet sent to the network after processing should not exceed 1200 bytes, otherwise, the packet may fail to be sent.
    - Ensure that both receivers and senders call this method, otherwise, you may meet undefined behaviors such as no voice and black screen.
    - When you use CDN live streaming, recording or storage functions, Agora doesn't recommend calling this method.

    @param observer The registered packet observer. See \ref IPacketObserver.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int registerPacketObserver( agora::rtc::IPacketObserver* observer );

   /** Registers the metadata observer.

    Registers the metadata observer. You need to implement the IMetadataObserver class and specify the metadata type in this method. A successful call of this method triggers the \ref IMetadataObserver::getMaxMetadataSize "getMaxMetadataSize" callback.
    This method enables you to add synchronized metadata in the video stream for more diversified live broadcast interactions, such as sending shopping links, digital coupons, and online quizzes.

    @note
    - Call this method before the joinChannel method.
    - This method applies to the Live-broadcast channel profile.

    @param observer The IMetadataObserver class. See the definition of \ref IMetadataObserver for details.
    @param type See \ref IMetadataObserver::METADATA_TYPE "METADATA_TYPE". The SDK supports VIDEO_METADATA (0) only for now.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int registerMediaMetadataObserver( agora::rtc::IMetadataObserver *observer, agora::rtc::IMetadataObserver::METADATA_TYPE type );

   /** Sets the role of the user, such as a host or an audience (default), before joining a channel in a live broadcast.

    This method can be used to switch the user role in a live broadcast after the user joins a channel.

    In the Live Broadcast profile, when a user switches user roles after joining a channel, a successful \ref setClientRole method call triggers the following callbacks:
    - The local client: \ref onClientRoleChanged 
    - The remote client: \ref onUserJoined or \ref onUserOffline (BECOME_AUDIENCE)

    @note
    This method applies only to the Live-broadcast profile.

    @param role Sets the role of the user. See #CLIENT_ROLE_TYPE.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setClientRole( agora::rtc::CLIENT_ROLE_TYPE role );

   /** Prioritizes a remote user's stream.

    Use this method with the \ref AgoraRtcEngine::setRemoteSubscribeFallbackOption "setRemoteSubscribeFallbackOption" method.
    If the fallback function is enabled for a subscribed stream, the SDK ensures the high-priority user gets the best possible stream quality.

    @note The Agora SDK supports setting `serPriority` as high for one user only.

    @param  uid  The ID of the remote user.
    @param  userPriority Sets the priority of the remote user. See #PRIORITY_TYPE.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setRemoteUserPriority( agora::rtc::uid_t uid, agora::rtc::PRIORITY_TYPE userPriority );

   /** Sets the sound position and gain of a remote user.

    When the local user calls this method to set the sound position of a remote user, the sound difference between the left and right channels allows the
    local user to track the real-time position of the remote user, creating a real sense of space. This method applies to massively multiplayer online games,
    such as Battle Royale games.

    @note
    - For this method to work, enable stereo panning for remote users by calling the \ref AgoraRtcEngine::enableSoundPositionIndication "enableSoundPositionIndication" method before joining a channel.
    - This method requires hardware support. For the best sound positioning, we recommend using a stereo speaker.

    @param uid The ID of the remote user.
    @param pan The sound position of the remote user. The value ranges from -1.0 to 1.0:
    - 0.0: the remote sound comes from the front.
    - -1.0: the remote sound comes from the left.
    - 1.0: the remote sound comes from the right.
    @param gain Gain of the remote user. The value ranges from 0.0 to 100.0. The default value is 100.0 (the original gain of the remote user).
    The smaller the value, the less the gain.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setRemoteVoicePosition( agora::rtc::uid_t uid, double pan, double gain );

   /** Updates the display mode of the video view of a remote user.

    After initializing the video view of a remote user, you can call this method to update its rendering and mirror modes.
    This method affects only the video view that the local user sees.

    @note
    - Call this method after calling the \ref AgoraRtcEngine::setupRemoteVideo "setupRemoteVideo" method to initialize the remote video view.
    - During a call, you can call this method as many times as necessary to update the display mode of the video view of a remote user.

    @param userId The ID of the remote user.
    @param renderMode The rendering mode of the remote video view. See #RENDER_MODE_TYPE.
    @param mirrorMode
    - The mirror mode of the remote video view. See #VIDEO_MIRROR_MODE_TYPE.
    - **Note**: The SDK disables the mirror mode by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setRemoteRenderMode( agora::rtc::uid_t userId, agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode );

   /** Sets whether to receive all remote audio streams by default.

    You can call this method either before or after joining a channel. If you call `setDefaultMuteAllRemoteAudioStreams (true)` after joining a channel, the remote audio streams of all subsequent users are not received.

    @note If you want to resume receiving the audio stream, call \ref muteRemoteAudioStream "muteRemoteAudioStream (false)",
    and specify the ID of the remote user whose audio stream you want to receive.
    To receive the audio streams of multiple remote users, call `muteRemoteAudioStream (false)` as many times.
    Calling `setDefaultMuteAllRemoteAudioStreams (false)` resumes receiving the audio streams of subsequent users only.

    @param mute Sets whether to receive/stop receiving all remote users' audio streams by default:
    - true:  Stops receiving all remote users' audio streams by default.
    - false: (Default) Receives all remote users' audio streams by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setDefaultMuteAllRemoteAudioStreams( bool mute );

   /** Sets whether to receive all remote video streams by default.

    You can call this method either before or after joining a channel. If you call `setDefaultMuteAllRemoteVideoStreams (true)` after joining a channel, 
    the remote video streams of all subsequent users are not received.

    @note If you want to resume receiving the video stream, call \ref muteRemoteVideoStream "muteRemoteVideoStream (false)", 
    and specify the ID of the remote user whose video stream you want to receive.
    To receive the video streams of multiple remote users, call `muteRemoteVideoStream (false)` as many times. Calling `setDefaultMuteAllRemoteVideoStreams (false)` resumes
    receiving the video streams of subsequent users only.

    @param mute Sets whether to receive/stop receiving all remote users' video streams by default:
    - true: Stop receiving all remote users' video streams by default.
    - false: (Default) Receive all remote users' video streams by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setDefaultMuteAllRemoteVideoStreams( bool mute );

   /** Stops/Resumes receiving all remote users' audio streams.

    @param mute Sets whether to receive/stop receiving all remote users' audio streams.
    - true: Stops receiving all remote users' audio streams.
    - false: (Default) Receives all remote users' audio streams.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int muteAllRemoteAudioStreams( bool mute );

   /** Adjust the playback volume of the specified remote user.

    After joining a channel, call \ref AgoraRtcEngine::adjustPlaybackSignalVolume "adjustPlaybackSignalVolume" to adjust the playback volume of different remote users,
    or adjust multiple times for one remote user.

    @note
    - Call this method after joining a channel.
    - This method adjusts the playback volume, which is the mixed volume for the specified remote user.
    - This method can only adjust the playback volume of one specified remote user at a time. If you want to adjust the playback volume of several remote users,
    call the method multiple times, once for each remote user.

    @param userId The user ID, which should be the same as the `uid` of \ref joinChannel
    @param volume The playback volume of the voice. The value ranges from 0 to 100:
    - 0: Mute.
    - 100: Original volume.

    @return
    - 0: Success.
   - < 0: Failure.
    */
   int adjustUserPlaybackSignalVolume( agora::rtc::uid_t userId, int volume );

   /** Stops/Resumes receiving a specified remote user's audio stream.

   @note If you called the \ref muteAllRemoteAudioStreams method and set `mute` as `true` to stop
    receiving all remote users' audio streams, call the `muteAllRemoteAudioStreams` method and set `mute` as `false` before calling this method.
    The `muteAllRemoteAudioStreams` method sets all remote audio streams, while the `muteRemoteAudioStream` method sets a specified remote audio stream.

   @param userId The user ID of the specified remote user sending the audio.
   @param mute Sets whether to receive/stop receiving a specified remote user's audio stream:
   - true: Stops receiving the specified remote user's audio stream.
   - false: (Default) Receives the specified remote user's audio stream.

   @return
   - 0: Success.
   - < 0: Failure.

   */
   int muteRemoteAudioStream( agora::rtc::uid_t userId, bool mute );

   /** Stops/Resumes receiving all video stream from a specified remote user.

    @param  mute Sets whether to receive/stop receiving all remote users' video streams:
    - true: Stop receiving all remote users' video streams.
    - false: (Default) Receive all remote users' video streams.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int muteAllRemoteVideoStreams( bool mute );

   /** Stops/Resumes receiving the video stream from a specified remote user.

    @note If you called the \ref muteAllRemoteVideoStreams method and
    set `mute` as `true` to stop receiving all remote video streams, call the `muteAllRemoteVideoStreams` method and
    set `mute` as `false` before calling this method.

    @param userId The user ID of the specified remote user.
    @param mute Sets whether to stop/resume receiving the video stream from a specified remote user:
    - true: Stop receiving the specified remote user's video stream.
    - false: (Default) Receive the specified remote user's video stream.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int muteRemoteVideoStream( agora::rtc::uid_t userId, bool mute );

   /** Sets the stream type of the remote video.

    Under limited network conditions, if the publisher has not disabled the dual-stream mode using
    \ref AgoraRtcEngine::enableDualStreamMode "enableDualStreamMode" (false),
    the receiver can choose to receive either the high-quality video stream (the high resolution, and high bitrate video stream) or
    the low-video stream (the low resolution, and low bitrate video stream).

    By default, users receive the high-quality video stream. Call this method if you want to switch to the low-video stream.
    This method allows the app to adjust the corresponding video stream type based on the size of the video window to
    reduce the bandwidth and resources.

    The aspect ratio of the low-video stream is the same as the high-quality video stream. Once the resolution of the high-quality video
    stream is set, the system automatically sets the resolution, frame rate, and bitrate of the low-video stream.

    The method result returns in the \ref onApiCallExecuted callback.

    @param userId The ID of the remote user sending the video stream.
    @param streamType  Sets the video-stream type. See #REMOTE_VIDEO_STREAM_TYPE.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setRemoteVideoStreamType( agora::rtc::uid_t userId, agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType );

   /** Sets the default stream type of remote videos.

    Under limited network conditions, if the publisher has not disabled the dual-stream mode using
    \ref AgoraRtcEngine::enableDualStreamMode "enableDualStreamMode" (false),
    the receiver can choose to receive either the high-quality video stream (the high resolution, and high bitrate video stream) or
    the low-video stream (the low resolution, and low bitrate video stream).

    By default, users receive the high-quality video stream. Call this method if you want to switch to the low-video stream.
    This method allows the app to adjust the corresponding video stream type based on the size of the video window to
    reduce the bandwidth and resources. The aspect ratio of the low-video stream is the same as the high-quality video stream.
    Once the resolution of the high-quality video stream is set, the system automatically sets the resolution, frame rate, and bitrate of the low-video stream.

    The method result returns in the \ref onApiCallExecuted callback.

    @param streamType Sets the default video-stream type. See #REMOTE_VIDEO_STREAM_TYPE.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setRemoteDefaultVideoStreamType( agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType );

   /** Creates a data stream.

    Each user can create up to five data streams during the lifecycle of the AgoraRtcChannel.

    @note Set both the `reliable` and `ordered` parameters to `true` or `false`. Do not set one as `true` and the other as `false`.

    @param streamId The ID of the created data stream.
    @param reliable Sets whether or not the recipients are guaranteed to receive the data stream from the sender within five seconds:
    - true: The recipients receive the data stream from the sender within five seconds. If the recipient does not receive the data stream within five seconds,
    an error is reported to the application.
    - false: There is no guarantee that the recipients receive the data stream within five seconds and no error message is reported for
    any delay or missing data stream.
    @param ordered Sets whether or not the recipients receive the data stream in the sent order:
    - true: The recipients receive the data stream in the sent order.
    - false: The recipients do not receive the data stream in the sent order.

    @return
    - Returns 0: Success.
    - < 0: Failure.
    */
   int createDataStream( int* streamId, bool reliable, bool ordered );

   /** Sends data stream messages to all users in a channel.

    The SDK has the following restrictions on this method:
    - Up to 30 packets can be sent per second in a channel with each packet having a maximum size of 1 kB.
    - Each client can send up to 6 kB of data per second.
    - Each user can have up to five data streams simultaneously.

    A successful \ref sendStreamMessage method call triggers
    the \ref onStreamMessage callback on the remote client, from which the remote user gets the stream message.

    A failed \ref sendStreamMessage method call triggers
    the \ref onStreamMessageError callback on the remote client.

    @note
    - This method applies only to the Communication profile or to the hosts in the Live-broadcast profile. If an audience in the Live-broadcast profile calls this method, the audience may be switched to a host.
    - Ensure that you have created the data stream using \ref createDataStream before calling this method.

    @param streamId  The ID of the sent data stream, returned in the \ref createDataStream method.
    @param data The sent data.
    @param length The length of the sent data.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int sendStreamMessage( int streamId, const char* data, size_t length );

   /** Publishes the local stream to a specified CDN live RTMP address.  (CDN live only.)

    The SDK returns the result of this method call in the \ref onStreamPublished callback.

    The \ref addPublishStreamUrl method call triggers the \ref onRtmpStreamingStateChanged callback
    on the local client to report the state of adding a local stream to the CDN.

    @note
    - Ensure that the user joins the channel before calling this method.
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
    - This method adds only one stream RTMP URL address each time it is called.

    @param  url The CDN streaming URL in the RTMP format. The maximum length of this parameter is 1024 bytes. The RTMP URL address must not contain special characters, such as Chinese language characters.
    @param  transcodingEnabled Sets whether transcoding is enabled/disabled:
    - true: Enable transcoding. To [transcode](https://docs.agora.io/en/Agora%20Platform/terms?platform=All%20Platforms#transcoding) the audio or video streams when publishing them to CDN live, often used for combining the audio and video streams of multiple hosts in CDN live. If you set this parameter as `true`, ensure that you call the \ref setLiveTranscoding method before this method.
    - false: Disable transcoding.

    @return
    - 0: Success.
    - < 0: Failure.
         - #ERR_INVALID_ARGUMENT (2): The RTMP URL address is NULL or has a string length of 0.
         - #ERR_NOT_INITIALIZED (7): You have not initialized `AgoraRtcChannel` when publishing the stream.
    */
   int addPublishStreamUrl( const char *url, bool transcodingEnabled );

   /** Removes an RTMP stream from the CDN.

    This method removes the RTMP URL address (added by the \ref addPublishStreamUrl method) from a CDN live stream.

    The SDK returns the result of this method call in the \ref onStreamUnpublished callback.

    The \ref removePublishStreamUrl method call triggers
    the \ref onRtmpStreamingStateChanged callback on the local client to report the state of removing an RTMP stream from the CDN.

    @note
    - This method removes only one RTMP URL address each time it is called.
    - The RTMP URL address must not contain special characters, such as Chinese language characters.

    @param url The RTMP URL address to be removed. The maximum length of this parameter is 1024 bytes.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int removePublishStreamUrl( const char *url );

   /** Sets the video layout and audio settings for CDN live. (CDN live only.)

    The SDK triggers the \ref onTranscodingUpdated callback when you
    call the `setLiveTranscoding` method to update the transcoding setting.

    @note
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*..
    - If you call the `setLiveTranscoding` method to set the transcoding setting for the first time, the SDK does not trigger the `onTranscodingUpdated` callback.

    @param transcoding Sets the CDN live audio/video transcoding settings. See LiveTranscoding.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int setLiveTranscoding( const agora::rtc::LiveTranscoding &transcoding );

   /** Adds a voice or video stream URL address to a live broadcast.

   The \ref onStreamPublished callback returns the inject status.
   If this method call is successful, the server pulls the voice or video stream and injects it into a live channel.
   This is applicable to scenarios where all audience members in the channel can watch a live show and interact with each other.

    The \ref addInjectStreamUrl method call triggers the following callbacks:
   - The local client:
     - \ref onStreamInjectedStatus , with the state of the injecting the online stream.
     - \ref onUserJoined (uid: 666), if the method call is successful and the online media stream is injected into the channel.
   - The remote client:
     - \ref onUserJoined (uid: 666), if the method call is successful and the online media stream is injected into the channel.

    @note
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
    - This method applies to the Native SDK v2.4.1 and later.
    - This method applies to the Live-Broadcast profile only.
    - You can inject only one media stream into the channel at the same time.

    @param url The URL address to be added to the ongoing live broadcast. Valid protocols are RTMP, HLS, and HTTP-FLV.
    - Supported audio codec type: AAC.
    - Supported video codec type: H264 (AVC).
    @param config The InjectStreamConfig object that contains the configuration of the added voice or video stream.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (2): The injected URL does not exist. Call this method again to inject the stream and ensure that the URL is valid.
       - #ERR_NOT_READY (3): The user is not in the channel.
       - #ERR_NOT_SUPPORTED (4): The channel profile is not live broadcast. Call the \ref AgoraRtcEngine::setChannelProfile "setChannelProfile" method and set the channel profile to live broadcast before calling this method.
       - #ERR_NOT_INITIALIZED (7): The SDK is not initialized. Ensure that the AgoraRtcChannel object is initialized before calling this method.
    */
   int addInjectStreamUrl( const char* url, const agora::rtc::InjectStreamConfig& config );

   /** Removes the voice or video stream URL address from a live broadcast.

    This method removes the URL address (added by the \ref addInjectStreamUrl method) from the live broadcast.

    @note If this method is called successfully, the SDK triggers the \ref onUserOffline callback and returns a stream uid of 666.

    @param url Pointer to the URL address of the added stream to be removed.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   int removeInjectStreamUrl( const char* url );

   /** Starts to relay media streams across channels.
    *
     After a successful method call, the SDK triggers the \ref onChannelMediaRelayStateChanged
     and \ref onChannelMediaRelayEvent callbacks, and these callbacks return the state and events of the media stream relay.
    - If the \ref onChannelMediaRelayStateChanged callback returns #RELAY_STATE_RUNNING (2) and #RELAY_OK (0), and the \ref onChannelMediaRelayEvent callback 
    returns #RELAY_EVENT_PACKET_SENT_TO_DEST_CHANNEL (4), the broadcaster starts sending data to the destination channel.
     - If the \ref onChannelMediaRelayStateChanged callback returns #RELAY_STATE_FAILURE (3), an exception occurs during the media stream relay.
    
     @note
     - Call this method after the \ref joinChannel method.
     - This method takes effect only when you are a broadcaster in a Live-broadcast channel.
     - After a successful method call, if you want to call this method again, ensure that you call the \ref stopChannelMediaRelay method to quit the current relay.
     - Contact sales-us@agora.io before implementing this function.
     - We do not support string user accounts in this API.
    
     @param configuration The configuration of the media stream relay:
     ChannelMediaRelayConfiguration.
    
     @return
     - 0: Success.
     - < 0: Failure.
    */
   int startChannelMediaRelay( const agora::rtc::ChannelMediaRelayConfiguration &configuration );

   /** Updates the channels for media stream relay.
    
     After a successful \ref startChannelMediaRelay method call, if you want to relay the media stream to more channels, or leave the current relay channel, 
     you can call the \ref updateChannelMediaRelay method.
    
     After a successful method call, the SDK triggers the \ref onChannelMediaRelayEvent callback with the #RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL (7) state code.
    
     @note
     Call this method after the \ref startChannelMediaRelay method to update the destination channel.
    
     @param configuration The media stream relay configuration: \ref ChannelMediaRelayConfiguration.
    
     @return
     - 0: Success.
     - < 0: Failure.
    */
   int updateChannelMediaRelay( const agora::rtc::ChannelMediaRelayConfiguration &configuration );

   /** Stops the media stream relay.
    
     Once the relay stops, the broadcaster quits all the destination channels.
    
     After a successful method call, the SDK triggers the \ref onChannelMediaRelayStateChanged callback. If the callback returns #RELAY_STATE_IDLE (0) and #RELAY_OK (0),
     the broadcaster successfully stops the relay.
    
     @note
     If the method call fails, the SDK triggers the \ref onChannelMediaRelayStateChanged callback with the #RELAY_ERROR_SERVER_NO_RESPONSE (2) or
     #RELAY_ERROR_SERVER_CONNECTION_LOST (8) state code. You can leave the channel by calling the \ref leaveChannel method, and the media stream relay automatically stops.
    
     @return
     - 0: Success.
     - < 0: Failure.
    */
   int stopChannelMediaRelay();

   /** Gets the current connection state of the SDK.

    @return #CONNECTION_STATE_TYPE.
    */
   agora::rtc::CONNECTION_STATE_TYPE getConnectionState();

private:
   int release();

private:
   AgoraRtcChannel( agora::rtc::IChannel* rtcChannel );

private:
   agora::rtc::IChannel* m_rtcChannel = nullptr;
};

}
}
}
