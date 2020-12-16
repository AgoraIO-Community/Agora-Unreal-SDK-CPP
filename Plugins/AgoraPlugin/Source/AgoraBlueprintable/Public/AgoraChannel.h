#pragma once

#include "UECompatibility.h"
#include "AgoraChannelEventHandler.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tickable.h"
#include "Agora.h"
#include "AgoraChannel.generated.h"


namespace agora {
namespace rtc {
namespace ue4 {
class AgoraRtcChannel;
}
}
}

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FChannelWarning, int, Warn, const FString&, Msg );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FChannelError, int, Err, const FString&, Msg );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FJoinChannelSuccessDelegate, int64, Uid, int, Elapsed );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FRejoinChannelSuccessDelegate, int64, Uid, int, Elapsed );


/**
Allows to create channels in blueprints.

This class includes ChannelEventHandler callbacks and rtcChannel fuctions.

@note Methods agora::rtc::IChannel::registerPacketObserver and agora::rtc::IChannel::registerMediaMetadataObserver
 are not implemented in this class. If you need these functions in blueprints simply inherit from this class and add
 IPacketObserver and/or IMetadataObserver classes and required methods in child class.
 */
UCLASS( Blueprintable )
class AGORABLUEPRINTABLE_API UAgoraChannel : public UObject, public FTickableGameObject
{
   GENERATED_BODY()

public:

   friend class UIAgora;

   void BeginDestroy();

   ~UAgoraChannel() = default;

   /** Reports the warning code of `UAgoraChannel`.

   @param Warn The warning code: #WARN_CODE_TYPE
   @param Msg The warning message.

   */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FChannelWarning  OnChannelWarningDelegate;

   /** Reports the error code of `UAgoraChannel`.

     @param Err The error code: #ERROR_CODE_TYPE
     @param Msg The error message.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FChannelError OnChannelErrorDelegate;

   /** Occurs when a user joins a channel.

    This callback notifies the application that a user joins a specified channel.

    @param Uid The user ID. If the `uid` is not specified in the \ref JoinChannel method, the server automatically assigns a `uid`.
    @param Elapsed Time elapsed (ms) from the local user calling \ref JoinChannel until this callback is triggered.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FJoinChannelSuccessDelegate   OnJoinChannelSuccessDelegate;

   /** Occurs when a user rejoins the channel after being disconnected due to network problems.

     @param Uid The user ID.
     @param Elapsed Time elapsed (ms) from the local user starting to reconnect until this callback is triggered.

     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRejoinChannelSuccessDelegate  OnRejoinChannelSuccessDelegate;

   /** Occurs when a user leaves the channel.

    This callback notifies the application that a user leaves the channel when the application calls the \ref LeaveChannel method.

    The application retrieves information, such as the call duration and statistics.

    @param Stats The call statistics: RtcStats.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FLeaveChannel OnLeaveChannelDelegate;

   /** Occurs when the user role switches in a live broadcast. For example, from a host to an audience or vice versa.

     This callback notifies the application of a user role switch when the application calls the \ref SetClientRole  method.

     The SDK triggers this callback when the local user switches the user role by calling the \ref SetClientRole method after joining the channel.


     @param OldRole Role that the user switches from: #ECLIENT_ROLE_TYPE.
     @param NewRole Role that the user switches to: #ECLIENT_ROLE_TYPE.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FClientRoleChanged OnClientRoleChangedDelegate;

   /** Occurs when a remote user (Communication)/ host (Live Broadcast) joins the channel.

     - Communication profile: This callback notifies the application that another user joins the channel. If other users are already in the channel, the SDK also reports to the application on the existing users.
     - Live-broadcast profile: This callback notifies the application that the host joins the channel. If other hosts are already in the channel, the SDK also reports to the application on the existing hosts. We recommend limiting the number of hosts to 17.

     The SDK triggers this callback under one of the following circumstances:
     - A remote user/host joins the channel by calling the \ref JoinChannel method.
     - A remote user switches the user role to the host by calling the \ref SetClientRole method after joining the channel.
     - A remote user/host rejoins the channel after a network interruption.
     - The host injects an online media stream into the channel by calling the \ref AddInjectStreamUrl method.

     @note In the Live-broadcast profile:
     - The host receives this callback when another host joins the channel.
     - The audience in the channel receives this callback when a new host joins the channel.
     - When a web application joins the channel, the SDK triggers this callback as long as the web application publishes streams.


     @param Uid User ID of the user or host joining the channel.
     @param Elapsed Time delay (ms) from the local user calling the \ref JoinChannel method until the SDK triggers this callback.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FUserJoined OnUserJoinedDelegate;

   /** Occurs when a remote user (Communication)/host (Live Broadcast) leaves the channel.

    Reasons why the user is offline:

    - Leave the channel: When the user/host leaves the channel, the user/host sends a goodbye message. When the message is received, the SDK assumes that the user/host leaves the channel.
    - Drop offline: When no data packet of the user or host is received for a certain period of time, the SDK assumes that the user/host drops offline. Unreliable network connections may lead to false detections, so we recommend using the Agora RTM SDK for more reliable offline detection.


    @param Uid User ID of the user leaving the channel or going offline.
    @param Reason Reason why the user is offline: #EUSER_OFFLINE_REASON_TYPE.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FUserOffline  OnUserOfflineDelegate;

   /** Occurs when the SDK cannot reconnect to Agora's edge server 10 seconds after its connection to the server is interrupted.

    The SDK triggers this callback when it cannot connect to the server 10 seconds after calling the \ref JoinChannel method, whether or not it is in the channel.

    This callback is different from \ref UIAgora::OnConnectionInterruptedDelegate "OnConnectionInterruptedDelegate":

    - The SDK triggers the `onConnectionInterrupted` callback when it loses connection with the server for more than four seconds after it successfully joins the channel.
    - The SDK triggers the `onConnectionLost` callback when it loses connection with the server for more than 10 seconds, whether or not it joins the channel.

    If the SDK fails to rejoin the channel 20 minutes after being disconnected from Agora's edge server, the SDK stops rejoining the channel.


    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FConnectionLost  OnConnectionLostDelegate;

   /** Occurs when the token expires.

     After a token is specified by calling the \ref JoinChannel method, if the SDK losses connection with the Agora server due to network issues, the token may expire after a certain period of time and a new token may be required to reconnect to the server.

     This callback notifies the app to generate a new token and call `JoinChannel` to rejoin the channel with the new token.

     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRequestToken  OnRequestTokenDelegate;

   /** Occurs when the token expires in 30 seconds.

     The user becomes offline if the token used in the \ref JoinChannel method expires. The SDK triggers this callback 30 seconds before the token expires to remind the application to get a new token. Upon receiving this callback, generate a new token on the server and call the \ref RenewToken method to pass the new token to the SDK.

     @param token Token that expires in 30 seconds.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FTokenPrivilegeWillExpire  OnTokenPrivilegeWillExpireDelegate;

   /** Reports the statistics of the current call.

     The SDK triggers this callback once every two seconds after the user joins the channel.


     @param stats Statistics of the RtcEngine: RtcStats.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRtcStatsDelegate  OnRtcStatsDelegate;

   /** Reports the last mile network quality of each user in the channel once every two seconds.

    Last mile refers to the connection between the local device and Agora's edge server. This callback reports once every two seconds the last mile network conditions of each user in the channel. If a channel includes multiple users, the SDK triggers this callback as many times.

    @param Uid User ID. The network quality of the user with this @p uid is reported. If @p uid is 0, the local network quality is reported.
    @param TxQuality Uplink transmission quality rating of the user in terms of the transmission bitrate, packet loss rate, average RTT (Round-Trip Time), and jitter of the uplink network. @p TxQuality is a quality rating helping you understand how well the current uplink network conditions can support the selected VideoEncoderConfiguration. For example, a 1000 Kbps uplink network may be adequate for video frames with a resolution of 640 * 480 and a frame rate of 15 fps in the Live-broadcast profile, but may be inadequate for resolutions higher than 1280 * 720. See #QUALITY_TYPE.
    @param RxQuality Downlink network quality rating of the user in terms of the packet loss rate, average RTT, and jitter of the downlink network. See #QUALITY_TYPE.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FNetworkQuality   OnNetworkQualityDelegate;

   /** Reports the statistics of the video stream from each remote user/host.

      The SDK triggers this callback once every two seconds for each remote user/host. If a channel includes multiple remote users, the SDK triggers this callback as many times.

      @param Stats Statistics of the remote video stream. See FRemoteVideoStats.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRemoteVideoStatsDelegate  OnRemoteVideoStatsDelegate;

   /** Reports the statistics of the audio stream from each remote user/host.

     This callback replaces the \ref UIAgora::OnAudioQualityDelegate "OnAudioQuality" callback.

     The SDK triggers this callback once every two seconds for each remote user/host. If a channel includes multiple remote users, the SDK triggers this callback as many times.

     @param Stats The statistics of the received remote audio streams. See \ref FRemoteAudioStats.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRemoteAudioStatsDelegate  OnRemoteAudioStatsDelegate;

   /** Occurs when the remote audio state changes.

      This callback indicates the state change of the remote audio stream.
      @note This callback does not work properly when the number of users (in the Communication profile) or broadcasters (in the Live-broadcast profile) in the channel exceeds 17.


      @param Uid ID of the remote user whose audio state changes.
      @param State State of the remote audio. See #EREMOTE_AUDIO_STATE.
      @param Reason The reason of the remote audio state change.
      See #EREMOTE_AUDIO_STATE_REASON.
      @param elapsed Time elapsed (ms) from the local user calling the
      \ref JoinChannel method until the SDK
      triggers this callback.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRemoteAudioStateChanged  OnRemoteAudioStateChangedDelegate;

   /** Reports which user is the loudest speaker.

    If the user enables the audio volume indication by calling the \ref UIAgora::EnableAudioVolumeIndication(int, int, bool) "EnableAudioVolumeIndication" method, this callback returns the @p Uid of the active speaker detected by the audio volume detection module of the SDK.

    @note
    - To receive this callback, you need to call the \ref UIAgora::EnableAudioVolumeIndication(int, int, bool) "EnableAudioVolumeIndication" method.
    - This callback returns the user ID of the user with the highest voice volume during a period of time, instead of at the moment.


    @param Uid User ID of the active speaker. A `uid` of 0 represents the local user.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FActiveSpeaker OnActiveSpeakerDelegate;

   /** Occurs when the video size or rotation of a specified user changes.


    @param Uid User ID of the remote user or local user (0) whose video size or rotation changes.
    @param Width New width (pixels) of the video.
    @param Height New height (pixels) of the video.
    @param Rotation New rotation of the video [0 to 360).
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FVideoSizeChanged  OnVideoSizeChangedDelegate;

   /** Occurs when the remote video state changes.

    @note This callback does not work properly when the number of users (in the Communication profile) or broadcasters (in the Live-broadcast profile) in the channel exceeds 17.

    @param Uid ID of the remote user whose video state changes.
    @param State State of the remote video. See #EREMOTE_VIDEO_STATE.
    @param Reason The reason of the remote video state change. See
    #EREMOTE_VIDEO_STATE_REASON.
    @param elapsed Time elapsed (ms) from the local user calling the
    \ref JoinChannel method until the
    SDK triggers this callback.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRemoteVideoStateChanged OnRemoteVideoStateChangedDelegate;

   /** Occurs when the local user receives the data stream from the remote user within five seconds.

   The SDK triggers this callback when the local user receives the stream message that the remote user sends by calling the \ref SendStreamMessage method.

   @param Uid User ID of the remote user sending the message.
   @param StreamId Stream ID.
   @param Data The data received by the local user.
   @param Length Length of the data in bytes.
  */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FStreamMessage OnStreamMessageDelegate;

   /** Occurs when the local user does not receive the data stream from the remote user within five seconds.

     The SDK triggers this callback when the local user fails to receive the stream message that the remote user sends by calling the \ref SendStreamMessage method.

     @param Uid User ID of the remote user sending the message.
     @param StreamId Stream ID.
     @param Code Error code: #ERROR_CODE_TYPE.
     @param Missed Number of lost messages.
     @param Cached Number of incoming cached messages when the data stream is interrupted.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FStreamMessageError OnStreamMessageErrorDelegate;

   /** Occurs when the state of the media stream relay changes.
     *
     * The SDK returns the state of the current media relay with any error
     * message.
     *
     * @param State The state code in #ECHANNEL_MEDIA_RELAY_STATE.
     * @param Code The error code in #ECHANNEL_MEDIA_RELAY_ERROR.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FChannelMediaRelayStateChanged OnChannelMediaRelayStateChangedDelegate;

   /** Reports events during the media stream relay.
     *
     * @param Code The event code in #ECHANNEL_MEDIA_RELAY_EVENT.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FChannelMediaRelayEvent  OnChannelMediaRelayEventDelegate;

   /**
     Occurs when the state of the RTMP streaming changes.

     The SDK triggers this callback to report the result of the local user calling the \ref AddPublishStreamUrl  or \ref RemovePublishStreamUrl method.

     This callback indicates the state of the RTMP streaming. When exceptions occur, you can troubleshoot issues by referring to the detailed error descriptions in the *ErrCode* parameter.

     @param Url The RTMP URL address.
     @param State The RTMP streaming state. See: #ERTMP_STREAM_PUBLISH_STATE.
     @param ErrCode The detailed error information for streaming. See: #ERTMP_STREAM_PUBLISH_ERROR.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRtmpStreamingStateChanged OnRtmpStreamingStateChangedDelegate;

   /** Occurs when the publisher's transcoding is updated.

    When the `FLiveTranscoding` class in the \ref SetLiveTranscoding method updates, the SDK triggers the `OnTranscodingUpdated` callback to report the update information to the local host.

    @note If you call the `SetLiveTranscoding` method to set the LiveTranscoding class for the first time, the SDK does not trigger the `OnTranscodingUpdated` callback.

    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FTranscodingUpdated  OnTranscodingUpdatedDelegate;

   /** Occurs when a voice or video stream URL address is added to a live broadcast.

     @param Url The URL address of the externally injected stream.
     @param Uid User ID.
     @param Status State of the externally injected stream: #INJECT_STREAM_STATUS.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FStreamInjectedStatus OnStreamInjectedStatusDelegate;

   /** Occurs when the published media stream falls back to an audio-only stream due to poor network conditions or switches back to the video after the network conditions improve.

    If you call \ref UIAgora::SetLocalPublishFallbackOption and set *option* as #STREAM_FALLBACK_OPTION_AUDIO_ONLY, the SDK triggers this callback when the published stream falls back to audio-only mode due to poor uplink conditions, or when the audio stream switches back to the video after the uplink network condition improves.

    @param IsFallbackOrRecover Whether the published stream falls back to audio-only or switches back to the video:
    - true: The published stream falls back to audio-only due to poor network conditions.
    - false: The published stream switches back to the video after the network conditions improve.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FLocalPublishFallbackToAudioOnly OnLocalPublishFallbackToAudioOnlyDelegate;

   /** Occurs when the remote media stream falls back to audio-only stream
     * due to poor network conditions or switches back to the video stream
     * after the network conditions improve.
     *
     * If you call
     * \ref UIAgora::SetRemoteSubscribeFallbackOption
     * "SetRemoteSubscribeFallbackOption" and set
     * @p Option as #STREAM_FALLBACK_OPTION_AUDIO_ONLY, the SDK triggers this
     * callback when the remote media stream falls back to audio-only mode due
     * to poor uplink conditions, or when the remote media stream switches
     * back to the video after the uplink network condition improves.
     *
     * @note Once the remote media stream switches to the low stream due to
     * poor network conditions, you can monitor the stream switch between a
     * high and low stream in the RemoteVideoStats callback.
     * @param Uid ID of the remote user sending the stream.
     * @param IsFallbackOrRecover Whether the remotely subscribed media stream
     * falls back to audio-only or switches back to the video:
     * - true: The remotely subscribed media stream falls back to audio-only
     * due to poor network conditions.
     * - false: The remotely subscribed media stream switches back to the
     * video stream after the network conditions improved.
     */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FRemoteSubscribeFallbackToAudioOnly OnRemoteSubscribeFallbackToAudioOnlyDelegate;

   /** Occurs when the connection state between the SDK and the server changes.

    @param State See #ECONNECTION_STATE_TYPE.
    @param Reason See #ECONNECTION_CHANGED_REASON_TYPE.
    */
   UPROPERTY( BlueprintAssignable, Category = "Agora|Channel|Callbacks" )
      FConnectionStateChanged OnConnectionStateChangedDelegate;

   /** Joins the channel with a user ID.

    This method differs from the `joinChannel` method in the `UAgora` class in the following aspects:

    | JoinChannel                                                                                                                                       | UIAgora::JoinChannel                                                                                           |
    |---------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
    | Does not contain the `ChannelId` parameter, because `ChannelId` is specified when creating the `UAgoraChannel` object.                            | Contains the `ChannelId` parameter, which specifies the channel to join.                                      |
    | Contains the `Options` parameter, which decides whether to subscribe to all streams before joining the channel.                                   | Does not contain the `Options` parameter. By default, users subscribe to all streams when joining the channel.|
    | Users can join multiple channels simultaneously by creating multiple `UAgoraChannel` objects and calling the `JoinChannel` method of each object. | Users can join only one channel.                                                                              |
    | By default, the SDK does not publish any stream after the user joins the channel. You need to call the publish method to do that.                 | By default, the SDK publishes streams once the user joins the channel.                                        |

    @note
    - If you are already in a channel, you cannot rejoin it with the same `Uid`.
    - We recommend using different UIDs for different channels.
    - If you want to join the same channel from different devices, ensure that the UIDs in all devices are different.
    - Ensure that the app ID you use to generate the token is the same with the app ID used when creating the `UAgoraChannel` object.

    @param Token The token for authentication:
    - In situations not requiring high security: You can use the temporary token generated at Console. For details, see [Get a temporary token](https://docs.agora.io/en/Agora%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-temporary-token).
    - In situations requiring high security: Set it as the token generated at your server. For details, see [Generate a token](https://docs.agora.io/en/Agora%20Platform/token?platfor%20*%20m=All%20Platforms#get-a-token).
    @param Info (Optional) Additional information about the channel. This parameter can be set as null. Other users in the channel do not receive this information.
    @param Uid The user ID. A 32-bit unsigned integer with a value ranging from 1 to (232-1). This parameter must be unique. If `Uid` is not assigned (or set as `0`), the SDK assigns a `Uid` and reports it in the \ref OnJoinChannelSuccessDelegate "OnJoinChannelSuccess" callback. The app must maintain this user ID.
    @param Options The channel media options: \ref FChannelMediaOptions

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (-2)
       - #ERR_NOT_READY (-3)
       - #ERR_REFUSED (-5)
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int JoinChannel( const FString& Token,
                       const FString& Info,
                       int64 Uid,
                       const FChannelMediaOptions& Options );

   /** Joins the channel with a user account.

    After the user successfully joins the channel, the SDK triggers the following callbacks:

    - The local client: \ref UIAgora::OnLocalUserRegisteredDelegate "OnLocalUserRegistered" and \ref OnJoinChannelSuccessDelegate "OnJoinChannelSuccess" .
    - The remote client: \ref OnUserJoinedDelegate "OnUserJoined" and \ref UIAgora::OnUserInfoUpdatedDelegate "OnUserInfoUpdated" , if the user joining the channel is in the Communication profile, or is a BROADCASTER in the Live Broadcast profile.

    @note To ensure smooth communication, use the same parameter type to identify the user. For example, if a user joins the channel with a user ID, then ensure all the other users use the user ID too. The same applies to the user account.
    If a user joins the channel with the Agora Web SDK, ensure that the uid of the user is set to the same parameter type.

    @param Token The token generated at your server:
    - For low-security requirements: You can use the temporary token generated at Console. For details, see [Get a temporary toke](https://docs.agora.io/en/Voice/token?platform=All%20Platforms#get-a-temporary-token).
    - For high-security requirements: Set it as the token generated at your server. For details, see [Get a token](https://docs.agora.io/en/Voice/token?platform=All%20Platforms#get-a-token).
    @param UserAccount The user account. The maximum length of this parameter is 255 bytes. Ensure that you set this parameter and do not set it as null. Supported character scopes are:
    - All lowercase English letters: a to z.
    - All uppercase English letters: A to Z.
    - All numeric characters: 0 to 9.
    - The space character.
    - Punctuation characters and other symbols, including: "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ",".
    @param Options The channel media options: \ref FChannelMediaOptions.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (-2)
       - #ERR_NOT_READY (-3)
       - #ERR_REFUSED (-5)
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int JoinChannelWithUserAccount( const FString& Token,
                                      const FString& UserAccount,
                                      const FChannelMediaOptions& Options );

   /** Allows a user to leave a channel, such as hanging up or exiting a call.

    After joining a channel, the user must call the *LeaveChannel* method to end the call before joining another channel.

    This method returns 0 if the user leaves the channel and releases all resources related to the call.

    This method call is asynchronous, and the user has not left the channel when the method call returns. Once the user leaves the channel, the SDK triggers the \ref OnLeaveChannelDelegate "OnLeaveChannel" callback.

    A successful \ref LeaveChannel method call triggers the following callbacks:
    - The local client: \ref OnLeaveChannelDelegate "OnLeaveChannel"
    - The remote client: \ref OnUserOfflineDelegate "OnUserOffline" , if the user leaving the channel is in the Communication channel, or is a BROADCASTER in the Live Broadcast profile.

    @note
    - If you call the \ref agora::rtc::ue4::AgoraRtcChannel::release method immediately after the *LeaveChannel* method, the *LeaveChannel* process interrupts, and the \ref OnLeaveChannelDelegate "OnLeaveChannel" callback is not triggered.
    - If you call the *LeaveChannel* method during a CDN live streaming, the SDK triggers the \ref RemovePublishStreamUrl "RemovePublishStreamUrl" method.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int LeaveChannel();

   /** Publishes the local stream to the channel.

    You must keep the following restrictions in mind when calling this method. Otherwise, the SDK returns the #ERR_REFUSED (5):
    - This method publishes one stream only to the channel corresponding to the current `UAgoraChannel` object.
    - In a Live Broadcast channel, only a broadcaster can call this method. To switch the client role, call \ref SetClientRole of the current `UAgoraChannel` object.
    - You can publish a stream to only one channel at a time. For details on joining multiple channels, see the advanced guide *Join Multiple Channels*.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_REFUSED (5): The method call is refused.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int Publish();

   /** Stops publishing a stream to the channel.

    If you call this method in a channel where you are not publishing streams, the SDK returns #ERR_REFUSED (5).

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_REFUSED (5): The method call is refused.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int Unpublish();

   /** Gets the channel ID of the current `UAgoraChannel` object.

    @return
    - The channel ID of the current `UAgoraChannel` object, if the method call succeeds.
    - The empty string "", if the method call fails.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      const FString ChannelId();

   /** Retrieves the current call ID.

    When a user joins a channel on a client, a `CallId` is generated to identify the call from the client.
    Feedback methods, such as \ref UIAgora::Rate "Rate" and \ref UIAgora::Complain "Complain", must be called after the call ends to submit feedback to the SDK.

    The `Rate` and `Complain` methods require the `CallId` parameter retrieved from the `GetCallId` method during a call. `CallId` is passed as an argument into the `Rate` and `Complain` methods after the call ends.

    @param CallId The current call ID.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int GetCallId( FString& CallId );

   /** Gets a new token when the current token expires after a period of time.

    The `Token` expires after a period of time once the token schema is enabled when:

    - The SDK triggers the \ref OnTokenPrivilegeWillExpireDelegate "OnTokenPrivilegeWillExpire" callback, or
    - The \ref OnConnectionStateChangedDelegate "OnConnectionStateChanged" reports CONNECTION_CHANGED_TOKEN_EXPIRED(9).

    The application should call this method to get the new `Token`. Failure to do so will result in the SDK disconnecting from the server.

    @param Token Pointer to the new token.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int RenewToken( const FString& Token );

   /** Enables built-in encryption with an encryption password before users join a channel.

    All users in a channel must use the same encryption password. The encryption password is automatically cleared once a user leaves the channel.

    If an encryption password is not specified, the encryption functionality will be disabled.

    @note
    - Do not use this method for CDN live streaming.
    - For optimal transmission, ensure that the encrypted data size does not exceed the original data size + 16 bytes. 16 bytes is the maximum padding size for AES encryption.

    @param Secret Pointer to the encryption password.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetEncryptionSecret( const FString& Secret );

   /** Sets the built-in encryption mode.

    The Agora SDK supports built-in encryption, which is set to the `aes-128-xts` mode by default. Call this method to use other encryption modes.

    All users in the same channel must use the same encryption mode and password.

    Refer to the information related to the AES encryption algorithm on the differences between the encryption modes.

    @note Call the \ref SetEncryptionSecret method to enable the built-in encryption function before calling this method.

    @param EncryptionMode The set encryption mode:
    - "aes-128-xts": (Default) 128-bit AES encryption, XTS mode.
    - "aes-128-ecb": 128-bit AES encryption, ECB mode.
    - "aes-256-xts": 256-bit AES encryption, XTS mode.
    - "": When encryptionMode is set as NULL, the encryption mode is set as "aes-128-xts" by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetEncryptionMode( EENCRYPTION_MODE EncryptionMode );

   /** Sets the role of the user, such as a host or an audience (default), before joining a channel in a live broadcast.

    This method can be used to switch the user role in a live broadcast after the user joins a channel.

    In the Live Broadcast profile, when a user switches user roles after joining a channel, a successful \ref SetClientRole method call triggers the following callbacks:
    - The local client: \ref OnClientRoleChangedDelegate "OnClientRoleChanged"
    - The remote client: \ref OnUserJoinedDelegate "OnUserJoined" or \ref OnUserOfflineDelegate "OnUserOffline" (BECOME_AUDIENCE)

    @note
    This method applies only to the Live-broadcast profile.

    @param Role Sets the role of the user. See #ECLIENT_ROLE_TYPE.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetClientRole( ECLIENT_ROLE_TYPE Role );

   /** Prioritizes a remote user's stream.

    Use this method with the \ref UIAgora::SetRemoteSubscribeFallbackOption "SetRemoteSubscribeFallbackOption" method.
    If the fallback function is enabled for a subscribed stream, the SDK ensures the high-priority user gets the best possible stream quality.

    @note The Agora SDK supports setting `SerPriority` as high for one user only.

    @param  Uid  The ID of the remote user.
    @param  UserPriority Sets the priority of the remote user. See #EPRIORITY_TYPE.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetRemoteUserPriority( int64 Uid, EPRIORITY_TYPE UserPriority );

   /** Sets the sound position and gain of a remote user.

    When the local user calls this method to set the sound position of a remote user, the sound difference between the left and right channels allows the
    local user to track the real-time position of the remote user, creating a real sense of space. This method applies to massively multiplayer online games,
    such as Battle Royale games.

    @note
    - For this method to work, enable stereo panning for remote users by calling the \ref UIAgora::EnableSoundPositionIndication "EnableSoundPositionIndication" method before joining a channel.
    - This method requires hardware support. For the best sound positioning, we recommend using a stereo speaker.

    @param Uid The ID of the remote user.
    @param Pan The sound position of the remote user. The value ranges from -1.0 to 1.0:
    - 0.0: the remote sound comes from the front.
    - -1.0: the remote sound comes from the left.
    - 1.0: the remote sound comes from the right.
    @param Gain Gain of the remote user. The value ranges from 0.0 to 100.0. The default value is 100.0 (the original gain of the remote user).
    The smaller the value, the less the gain.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetRemoteVoicePosition( int64 Uid, float Pan, float Gain );

   /** Updates the display mode of the video view of a remote user.

    After initializing the video view of a remote user, you can call this method to update its rendering and mirror modes.
    This method affects only the video view that the local user sees.

    @note
    - Call this method after calling the \ref UIAgora::SetupRemoteVideo "SetupRemoteVideo" method to initialize the remote video view.
    - During a call, you can call this method as many times as necessary to update the display mode of the video view of a remote user.

    @param UserId The ID of the remote user.
    @param RenderMode The rendering mode of the remote video view. See #ERENDER_MODE_TYPE.
    @param MirrorMode
    - The mirror mode of the remote video view. See #EVIDEO_MIRROR_MODE_TYPE.
    - **Note**: The SDK disables the mirror mode by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetRemoteRenderMode( int64 UserId, ERENDER_MODE_TYPE RenderMode, EVIDEO_MIRROR_MODE_TYPE MirrorMode );

   /** Sets whether to receive all remote audio streams by default.

    You can call this method either before or after joining a channel. If you call `SetDefaultMuteAllRemoteAudioStreams (true)` after joining a channel, the remote audio streams of all subsequent users are not received.

    @note If you want to resume receiving the audio stream, call \ref MuteRemoteAudioStream "MuteRemoteAudioStream (false)",
    and specify the ID of the remote user whose audio stream you want to receive.
    To receive the audio streams of multiple remote users, call `MuteRemoteAudioStream (false)` as many times.
    Calling `SetDefaultMuteAllRemoteAudioStreams (false)` resumes receiving the audio streams of subsequent users only.

    @param Mute Sets whether to receive/stop receiving all remote users' audio streams by default:
    - true:  Stops receiving all remote users' audio streams by default.
    - false: (Default) Receives all remote users' audio streams by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetDefaultMuteAllRemoteAudioStreams( bool Mute );

   /** Sets whether to receive all remote video streams by default.

    You can call this method either before or after joining a channel. If you
    call `SetDefaultMuteAllRemoteVideoStreams (true)` after joining a channel,
    the remote video streams of all subsequent users are not received.

    @note If you want to resume receiving the video stream, call
    \ref MuteRemoteVideoStream "MuteRemoteVideoStream (false)",
    and specify the ID of the remote user whose video stream you want to receive.
    To receive the video streams of multiple remote users, call `MuteRemoteVideoStream (false)`
    as many times. Calling `SetDefaultMuteAllRemoteVideoStreams (false)` resumes
    receiving the video streams of subsequent users only.

    @param Mute Sets whether to receive/stop receiving all remote users' video streams by default:
    - true: Stop receiving all remote users' video streams by default.
    - false: (Default) Receive all remote users' video streams by default.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetDefaultMuteAllRemoteVideoStreams( bool Mute );

   /** Stops/Resumes receiving all remote users' audio streams.

    @param Mute Sets whether to receive/stop receiving all remote users' audio streams.
    - true: Stops receiving all remote users' audio streams.
    - false: (Default) Receives all remote users' audio streams.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int MuteAllRemoteAudioStreams( bool Mute );

   /** Adjust the playback volume of the specified remote user.

    After joining a channel, call \ref UIAgora::AdjustPlaybackSignalVolume "AdjustPlaybackSignalVolume" to adjust the playback volume of different remote users,
    or adjust multiple times for one remote user.

    @note
    - Call this method after joining a channel.
    - This method adjusts the playback volume, which is the mixed volume for the specified remote user.
    - This method can only adjust the playback volume of one specified remote user at a time. If you want to adjust the playback volume of several remote users,
    call the method multiple times, once for each remote user.

    @param UserId The user ID, which should be the same as the `Uid` of \ref JoinChannel "JoinChannel"
    @param Volume The playback volume of the voice. The value ranges from 0 to 100:
    - 0: Mute.
    - 100: Original volume.

    @return
    - 0: Success.
   - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int AdjustUserPlaybackSignalVolume( int64 UserId, int Volume );

   /** Stops/Resumes receiving a specified remote user's audio stream.

   @note If you called the \ref MuteAllRemoteAudioStreams method and set `mute` as `true` to stop
    receiving all remote users' audio streams, call the `MuteAllRemoteAudioStreams` method and set `mute` as `false` before calling this method.
    The `MuteAllRemoteAudioStreams` method sets all remote audio streams, while the `MuteRemoteAudioStream` method sets a specified remote audio stream.

   @param UserId The user ID of the specified remote user sending the audio.
   @param Mute Sets whether to receive/stop receiving a specified remote user's audio stream:
   - true: Stops receiving the specified remote user's audio stream.
   - false: (Default) Receives the specified remote user's audio stream.

   @return
   - 0: Success.
   - < 0: Failure.

   */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int MuteRemoteAudioStream( int64 UserId, bool Mute );

   /** Stops/Resumes receiving all video stream from a specified remote user.

    @param  Mute Sets whether to receive/stop receiving all remote users' video streams:
    - true: Stop receiving all remote users' video streams.
    - false: (Default) Receive all remote users' video streams.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int MuteAllRemoteVideoStreams( bool Mute );

   /** Stops/Resumes receiving the video stream from a specified remote user.

    @note If you called the \ref MuteAllRemoteVideoStreams method and
    set `Mute` as `true` to stop receiving all remote video streams, call the `MuteAllRemoteVideoStreams` method and
    set `Mute` as `false` before calling this method.

    @param UserId The user ID of the specified remote user.
    @param Mute Sets whether to stop/resume receiving the video stream from a specified remote user:
    - true: Stop receiving the specified remote user's video stream.
    - false: (Default) Receive the specified remote user's video stream.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int MuteRemoteVideoStream( int64 UserId, bool Mute );

   /** Sets the stream type of the remote video.

    Under limited network conditions, if the publisher has not disabled the dual-stream mode using
    \ref UIAgora::EnableDualStreamMode "EnableDualStreamMode" (false),
    the receiver can choose to receive either the high-quality video stream (the high resolution, and high bitrate video stream) or
    the low-video stream (the low resolution, and low bitrate video stream).

    By default, users receive the high-quality video stream. Call this method if you want to switch to the low-video stream.
    This method allows the app to adjust the corresponding video stream type based on the size of the video window to
    reduce the bandwidth and resources.

    The aspect ratio of the low-video stream is the same as the high-quality video stream. Once the resolution of the high-quality video
    stream is set, the system automatically sets the resolution, frame rate, and bitrate of the low-video stream.

    The method result returns in the \ref UIAgora::OnApiCallExecutedDelegate "OnApiCallExecuted" callback.

    @param UserId The ID of the remote user sending the video stream.
    @param StreamType  Sets the video-stream type. See #EREMOTE_VIDEO_STREAM_TYPE.
    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetRemoteVideoStreamType( int64 UserId, EREMOTE_VIDEO_STREAM_TYPE StreamType );

   /** Sets the default stream type of remote videos.

    Under limited network conditions, if the publisher has not disabled the dual-stream mode using
    \ref UIAgora::EnableDualStreamMode "EnableDualStreamMode" (false),
    the receiver can choose to receive either the high-quality video stream (the high resolution, and high bitrate video stream) or
    the low-video stream (the low resolution, and low bitrate video stream).

    By default, users receive the high-quality video stream. Call this method if you want to switch to the low-video stream.
    This method allows the app to adjust the corresponding video stream type based on the size of the video window to
    reduce the bandwidth and resources. The aspect ratio of the low-video stream is the same as the high-quality video stream.
     Once the resolution of the high-quality video
    stream is set, the system automatically sets the resolution, frame rate, and bitrate of the low-video stream.

    The method result returns in the \ref UIAgora::OnApiCallExecutedDelegate "OnApiCallExecuted" callback.

    @param StreamType Sets the default video-stream type. See #EREMOTE_VIDEO_STREAM_TYPE.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetRemoteDefaultVideoStreamType( EREMOTE_VIDEO_STREAM_TYPE StreamType );

   /** Creates a data stream.

    Each user can create up to five data streams during the lifecycle of the UAgoraChannel.

    @note Set both the `Reliable` and `Ordered` parameters to `true` or `false`. Do not set one as `true` and the other as `false`.

    @param StreamId The ID of the created data stream.
    @param Reliable Sets whether or not the recipients are guaranteed to receive the data stream from the sender within five seconds:
    - true: The recipients receive the data stream from the sender within five seconds. If the recipient does not receive the data stream within five seconds,
    an error is reported to the application.
    - false: There is no guarantee that the recipients receive the data stream within five seconds and no error message is reported for
    any delay or missing data stream.
    @param Ordered Sets whether or not the recipients receive the data stream in the sent order:
    - true: The recipients receive the data stream in the sent order.
    - false: The recipients do not receive the data stream in the sent order.

    @return
    - Returns 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int CreateDataStream( int& StreamId, bool Reliable, bool Ordered );

   /** Sends data stream messages to all users in a channel.

    The SDK has the following restrictions on this method:
    - Up to 30 packets can be sent per second in a channel with each packet having a maximum size of 1 kB.
    - Each client can send up to 6 kB of data per second.
    - Each user can have up to five data streams simultaneously.

    A successful \ref SendStreamMessage method call triggers
    the \ref OnStreamMessageDelegate "OnStreamMessage" callback on the remote client, from which the remote user gets the stream message.

    A failed \ref SendStreamMessage method call triggers
    the \ref OnStreamMessageErrorDelegate "OnStreamMessage" callback on the remote client.

    @note
    - This method applies only to the Communication profile or to the hosts in the Live-broadcast profile. If an audience in the Live-broadcast profile calls this method, the audience may be switched to a host.
    - Ensure that you have created the data stream using \ref CreateDataStream before calling this method.

    @param StreamId  The ID of the sent data stream, returned in the \ref CreateDataStream method.
    @param Data The sent data.
    @param Length The length of the sent data.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SendStreamMessage( int StreamId, const FString& Data, int64 Length );

   /** Publishes the local stream to a specified CDN live RTMP address.  (CDN live only.)

    The SDK returns the result of this method call in the \ref UIAgora::OnStreamPublishedDelegate "OnStreamPublished" callback.

    The \ref AddPublishStreamUrl method call triggers
    the \ref OnRtmpStreamingStateChangedDelegate "OnRtmpStreamingStateChanged" callback on the local client
    to report the state of adding a local stream to the CDN.

    @note
    - Ensure that the user joins the channel before calling this method.
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
    - This method adds only one stream RTMP URL address each time it is called.

    @param  Url The CDN streaming URL in the RTMP format. The maximum length of this parameter is 1024 bytes. The RTMP URL address must not contain special characters, such as Chinese language characters.
    @param  TranscodingEnabled Sets whether transcoding is enabled/disabled:
    - true: Enable transcoding. To [transcode](https://docs.agora.io/en/Agora%20Platform/terms?platform=All%20Platforms#transcoding) the audio or video streams when publishing them to CDN live, often used for combining the audio and video streams of multiple hosts in CDN live. If you set this parameter as `true`, ensure that you call the \ref SetLiveTranscoding method before this method.
    - false: Disable transcoding.

    @return
    - 0: Success.
    - < 0: Failure.
         - #ERR_INVALID_ARGUMENT (2): The RTMP URL address is NULL or has a string length of 0.
         - #ERR_NOT_INITIALIZED (7): You have not initialized `UAgoraChannel` when publishing the stream.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int AddPublishStreamUrl( const FString& Url, bool TranscodingEnabled );

   /** Removes an RTMP stream from the CDN.

    This method removes the RTMP URL address (added by the \ref AddPublishStreamUrl method) from a CDN live stream.

    The SDK returns the result of this method call in the \ref UIAgora::OnStreamUnpublishedDelegate "OnStreamUnpublished" callback.

    The \ref RemovePublishStreamUrl method call triggers
    the \ref OnRtmpStreamingStateChangedDelegate "OnRtmpStreamingStateChanged" callback on the local client to report the state of removing an RTMP stream from the CDN.

    @note
    - This method removes only one RTMP URL address each time it is called.
    - The RTMP URL address must not contain special characters, such as Chinese language characters.

    @param Url The RTMP URL address to be removed. The maximum length of this parameter is 1024 bytes.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int RemovePublishStreamUrl( const FString& Url );

   /** Sets the video layout and audio settings for CDN live. (CDN live only.)

    The SDK triggers the \ref OnTranscodingUpdatedDelegate "OnTranscodingUpdated" callback when you
    call the `SetLiveTranscoding` method to update the transcoding setting.

    @note
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*..
    - If you call the `SetLiveTranscoding` method to set the transcoding setting for the first time, the SDK does not trigger the `OnTranscodingUpdated` callback.

    @param Transcoding Sets the CDN live audio/video transcoding settings. See LiveTranscoding.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int SetLiveTranscoding( const FLiveTranscoding &Transcoding );

   /** Adds a voice or video stream URL address to a live broadcast.

   The \ref UIAgora::OnStreamPublishedDelegate "OnStreamPublished" callback returns the inject status.
   If this method call is successful, the server pulls the voice or video stream and injects it into a live channel.
   This is applicable to scenarios where all audience members in the channel can watch a live show and interact with each other.

    The \ref AddInjectStreamUrl method call triggers the following callbacks:
   - The local client:
     - \ref OnStreamInjectedStatusDelegate "OnStreamInjectedStatus" , with the state of the injecting the online stream.
     - \ref OnUserJoinedDelegate "OnUserJoined" (uid: 666), if the method call is successful and the online media stream is injected into the channel.
   - The remote client:
     - \ref OnUserJoinedDelegate "OnUserJoined" (uid: 666), if the method call is successful and the online media stream is injected into the channel.

    @note
    - Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
    - This method applies to the Native SDK v2.4.1 and later.
    - This method applies to the Live-Broadcast profile only.
    - You can inject only one media stream into the channel at the same time.

    @param Url The URL address to be added to the ongoing live broadcast. Valid protocols are RTMP, HLS, and HTTP-FLV.
    - Supported audio codec type: AAC.
    - Supported video codec type: H264 (AVC).
    @param Config The InjectStreamConfig object that contains the configuration of the added voice or video stream.

    @return
    - 0: Success.
    - < 0: Failure.
       - #ERR_INVALID_ARGUMENT (2): The injected URL does not exist. Call this method again to inject the stream and ensure that the URL is valid.
       - #ERR_NOT_READY (3): The user is not in the channel.
       - #ERR_NOT_SUPPORTED (4): The channel profile is not live broadcast. Call the \ref UIAgora::SetChannelProfile "SetChannelProfile" method and set the channel profile to live broadcast before calling this method.
       - #ERR_NOT_INITIALIZED (7): The SDK is not initialized. Ensure that the UAgoraChannel object is initialized before calling this method.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int AddInjectStreamUrl( const FString& Url, const FInjectStreamConfig& Config );

   /** Removes the voice or video stream URL address from a live broadcast.

    This method removes the URL address (added by the \ref AddInjectStreamUrl method) from the live broadcast.

    @note If this method is called successfully, the SDK triggers the \ref OnUserOfflineDelegate "OnUserOffline" callback and returns a stream uid of 666.

    @param Url Pointer to the URL address of the added stream to be removed.

    @return
    - 0: Success.
    - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int RemoveInjectStreamUrl( const FString& Url );

   /** Starts to relay media streams across channels.

     After a successful method call, the SDK triggers the
     \ref OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged" and \ref OnChannelMediaRelayEventDelegate
     "OnChannelMediaRelayEvent" callbacks, and these callbacks return the state and events of the media stream relay.

     - If the \ref OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged" callback returns #RELAY_STATE_RUNNING (2) and #RELAY_OK (0), and the
     \ref OnChannelMediaRelayEventDelegate "OnChannelMediaRelayEvent" callback returns #RELAY_EVENT_PACKET_SENT_TO_DEST_CHANNEL (4), the broadcaster starts
     sending data to the destination channel.

     - If the \ref OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged" callback returns #RELAY_STATE_FAILURE (3),
     an exception occurs during the media stream relay.
     @note
      - Call this method after the \ref JoinChannel method.
      - This method takes effect only when you are a broadcaster in a
      Live-broadcast channel.
      - After a successful method call, if you want to call this method again, ensure that you call the
       \ref StopChannelMediaRelay method to quit the current relay.
      - Contact sales-us@agora.io before implementing this function.
      - We do not support string user accounts in this API.

     @param Configuration The configuration of the media stream relay:
     FChannelMediaRelayConfiguration.

     @return
     - 0: Success.
     - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int StartChannelMediaRelay( const FChannelMediaRelayConfiguration& Configuration );

   /** Updates the channels for media stream relay.

     After a successful \ref StartChannelMediaRelay method call, if you want to relay the media stream to more channels,
     or leave the current relay channel, you can call the \ref UpdateChannelMediaRelay method.

     After a successful method call, the SDK triggers the \ref OnChannelMediaRelayEventDelegate "OnChannelMediaRelayEvent"
     callback with the #RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL (7) state code.

     @note
     Call this method after the \ref StartChannelMediaRelay method to update the destination channel.

     @param Configuration The media stream relay configuration:
     FChannelMediaRelayConfiguration.

     @return
     - 0: Success.
     - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int UpdateChannelMediaRelay( const FChannelMediaRelayConfiguration& Configuration );

   /** Stops the media stream relay.

    Once the relay stops, the broadcaster quits all the destination channels.

    After a successful method call, the SDK triggers the \ref OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged" callback.
    If the callback returns #RELAY_STATE_IDLE (0) and #RELAY_OK (0), the broadcaster successfully  stops the relay.

    @note
    If the method call fails, the SDK triggers the \ref OnChannelMediaRelayStateChangedDelegate "OnChannelMediaRelayStateChanged"
    callback with the #RELAY_ERROR_SERVER_NO_RESPONSE (2) or #RELAY_ERROR_SERVER_CONNECTION_LOST (8) state code. You can leave the channel by
    calling the \ref LeaveChannel method, and the media stream relay automatically stops.

    @return
      - 0: Success.
      - < 0: Failure.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      int StopChannelMediaRelay();

   /** Gets the current connection state of the SDK.

    @return #ECONNECTION_STATE_TYPE.
    */
   UFUNCTION( BlueprintCallable, Category = "Agora|Channel" )
      ECONNECTION_STATE_TYPE GetConnectionState();

protected:

   TSharedPtr< agora::blueprints::ChannelEventHandler > channelEventHandler = nullptr;

   TSharedPtr < agora::rtc::ue4::AgoraRtcChannel > rtcChannel = nullptr;

private:

   int Initialize( agora::rtc::ue4::AgoraRtcChannel* Channel );
   /**
Forced use. Some \ref rtcChannel methods use structures with pointes fileds.
Using points in blueprints is inconvenient (You should inherit from UObject).
These pointers were replaced with structures and converted values are stored here.
@see SetLiveTranscoding
*/
   std::unique_ptr< agora::rtc::TranscodingUser[] > users = nullptr;
   /** @ref users */
   std::unique_ptr< agora::rtc::RtcImage > watermark = nullptr;
   /** @ref users */
   std::unique_ptr< agora::rtc::RtcImage > backgroundImage = nullptr;

   /**
  @ref users
  @see StartChannelMediaRelay
  @see UpdateChannelMediaRelay
  */
   std::unique_ptr< agora::rtc::ChannelMediaInfo[] > destInfos = nullptr;

   /**
   @ref users
   @see StartChannelMediaRelay
   @see UpdateChannelMediaRelay
   */
   std::unique_ptr< agora::rtc::ChannelMediaInfo > srcInfo = nullptr;

private:

   /**
  Used for handling Channel callbacks.
  @param DeltaTime Game time passed since the last call.
  */
   virtual void Tick( float DeltaTime );

   /** Makes this object tickable for Unreal.*/
   virtual bool IsTickable() const { return true; }

   /**
 Tickable utill.
 @return The stat id to use for this tickable.
 */
   virtual TStatId GetStatId() const override { return Super::GetStatID(); }
};

