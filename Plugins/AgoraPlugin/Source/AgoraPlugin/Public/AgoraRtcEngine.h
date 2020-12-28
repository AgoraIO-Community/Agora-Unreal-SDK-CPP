//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#if (defined(__APPLE__) && TARGET_OS_IPHONE)
#include <Agora/iOS/Include/IAgoraRtcChannel.h>
#include <Agora/iOS/Include/IAgoraRtcEngine.h>
#else
#include <Agora/IAgoraRtcEngine.h>
#include <Agora/IAgoraRtcChannel.h>
#endif

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

namespace agora
{

namespace media
{
namespace ue4
{
class AgoraMediaEngine;
}
}

namespace blueprints
{
class AgoraAudioManager;
class AgoraVideoManager;
}

namespace rtc
{
namespace ue4
{
class AParameter;

/**
* Wrapper around agora::rtc::IRtcEngine.
*/
class AGORAPLUGIN_API AgoraRtcEngine
{
public:
	AgoraRtcEngine() = delete;
	AgoraRtcEngine(const AgoraRtcEngine& other);
	AgoraRtcEngine(AgoraRtcEngine&& other) noexcept;
	AgoraRtcEngine& operator=(const AgoraRtcEngine& other);
	AgoraRtcEngine& operator=(AgoraRtcEngine&& other) noexcept;
	~AgoraRtcEngine();

public:
   /**
   * @brief    Creates the \ref AgoraRtcEngine object and returns the pointer.
   * @return   \arg Success: Pointer to the AgoraRtcEngine object.
   *           \arg Failure: A null pointer.
   */
	static AgoraRtcEngine* createAgoraRtcEngine();

   /**
   * @brief                   Initializes the Agora SDK service.
   * @note                    Ensure that you call the \ref createAgoraRtcEngine and \ref initialize methods before calling any other API.
   * @param  rtcEngineContext Pointer to the RTC engine context. See \ref RtcEngineContext.
   * @return                  \arg 0: Success.
   *                          \arg < 0: Failure.
   */
	int initialize(const agora::rtc::RtcEngineContext& rtcEngineContext);

	//TODO:?
	void setSyncForRelease(bool sync);

   /** Sets the channel profile of AgoraRtcEngine.
    *
    * The AgoraRtcEngine object differentiates channel profiles and applies optimization algorithms accordingly.
    * For example, it prioritizes smoothness and low latency for a video call, and prioritizes video quality for the interactive live video streaming.
    *
    * @warning
    * - To ensure the quality of real-time communication, we recommend that all users in a channel use the same channel profile.
    * - Call this method before calling \ref joinChannel. You cannot set the channel profile once you have joined the channel.
    * - The default audio route and video encoding bitrate are different in different channel profiles. For details, see
    * \ref setDefaultAudioRouteToSpeakerphone and \ref setVideoEncoderConfiguration.
    *
    * @param profile The channel profile of the AgoraRtcEngine. See #CHANNEL_PROFILE_TYPE.
    * @return
    * - 0(ERR_OK): Success.
    * - < 0: Failure.
    *  - -2 (ERR_INVALID_ARGUMENT): The parameter is invalid.
    *  - -7(ERR_NOT_INITIALIZED): The SDK is not initialized.
    */
	int setChannelProfile(agora::rtc::CHANNEL_PROFILE_TYPE profile);

   /**
    * @brief       Sets the role of the user, such as a host or an audience (default), before joining a channel in a live broadcast.
    * @brief       In the Live Broadcast profile, when a user switches user roles after joining a channel, a successful \ref setClientRole method call triggers the following callbacks:
    *              \arg  The local client: \ref agora::rtc::IRtcEngineEventHandler::onClientRoleChanged "onClientRoleChanged"
    *              \arg  The remote client: \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" or \ref agora::rtc::IRtcEngineEventHandler::onUserOffline "onUserOffline" (BECOME_AUDIENCE)
    * @brief       This method can be used to switch the user role in a live broadcast after the user joins a channel.
    * @note        This method applies only to the Live-broadcast profile.
    * @param  role Sets the role of the user. See #CLIENT_ROLE_TYPE.
    * @return
    * - 0(ERR_OK): Success.
    * - < 0: Failure.
    *   - -1(ERR_FAILED): A general error occurs (no specified reason).
    *   - -2(ERR_INALID_ARGUMENT): The parameter is invalid.
    *   - -7(ERR_NOT_INITIALIZED): The SDK is not initialized.
    */
	int setClientRole(agora::rtc::CLIENT_ROLE_TYPE role);

   /**
   * @brief             Allows a user to join a channel.
   * @brief             Users in the same channel can talk to each other, and multiple users in the same channel can start a group chat. Users with different App IDs cannot call each other.
   * @brief             You must call the \ref leaveChannel method to exit the current call before entering another channel.
   * @brief             A successful \ref joinChannel method call triggers the following callbacks:
   *                    \arg  The local client: \ref agora::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess"
   *                    \arg  The remote client: \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined", if the user joining the channel is in the Communication profile, or is a BROADCASTER in the Live Broadcast profile.
   * @brief             When the connection between the client and Agora's server is interrupted due to poor network conditions, the SDK tries reconnecting to the server. When the local client successfully rejoins the channel, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onRejoinChannelSuccess "onRejoinChannelSuccess" callback on the local client.
   * @brief             Once a user joins the channel, the user subscribes to the audio and video streams of all the other users in the channel by default, giving rise to usage and billing calculation. If you do not want to subscribe to a specified stream or all remote streams, call the `mute` methods accordingly.
   * @note              A channel does not accept duplicate uids, such as two users with the same uid. If you set uid as 0, the system automatically assigns a uid. If you want to join a channel from different devices, ensure that each device has a different uid.
   * @warning           Ensure that the App ID used for creating the token is the same App ID used by the \ref initialize method for initializing the RTC engine. Otherwise, the CDN live streaming may fail.
   * @param token       The token generated at your server:
                        \arg  For low-security requirements: You can use the temporary token generated in Console.
                        \arg  For high-security requirements: Use the token generated at your server.
   * @param channelId   Pointer to the unique channel name for the Agora RTC session in the string format smaller than 64 bytes. Supported characters:
   *                    \arg The 26 lowercase English letters: a to z
   *                    \arg The 26 uppercase English letters: A to Z
   *                    \arg The 10 numbers: 0 to 9
   *                    \arg The space
   *                    \arg "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ","
   * @param info        (Optional) Pointer to additional information about the channel. This parameter can be set to NULL or contain channel related information. Other users in the channel will not receive this message.
   * @param uid         (Optional) User ID. A 32-bit unsigned integer with a value ranging from 1 to 2^32-1. The uid must be unique. If a uid is not assigned (or set to 0), the SDK assigns and returns a uid in the \ref agora::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess" callback. Your application must record and maintain the returned `uid` since the SDK does not do so.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   *                       - \ref ERR_INVALID_ARGUMENT (-2)
   *                       - \ref ERR_NOT_READY (-3)
   *                       - \ref ERR_REFUSED (-5)
   *                         - You have created an AgoraRtcChannel object with the same channel name.
   *                         - You have joined and published a stream in a channel created by the AgoraRtcChannel object.
   */
	int joinChannel(const char* token, const char* channelId, const char* info, agora::rtc::uid_t uid);

   /**
   * @brief             Switches to a different channel.
   * @brief             This method allows the audience of a Live-broadcast channel to switch to a different channel.
   * @brief             After the user successfully switches to another channel, the \ref agora::rtc::IRtcEngineEventHandler::onLeaveChannel "onLeaveChanenl" and \ref agora::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess" callbacks are triggered to indicate that the user has left the original channel and joined a new one.
   * @brief             Once the user switches to another channel, the user subscribes to the audio and video streams of all the other users in the channel by default, giving rise to usage and billing calculation. If you do not want to subscribe to a specified stream or all remote streams, call the `mute` methods accordingly.
   * @note              This method applies to the audience role in a Live-broadcast channel only.
   * @param token       The token generated at your server:
                        \arg  For low-security requirements: You can use the temporary token generated in Console.
                        \arg  For high-security requirements: Use the token generated at your server.
   * @param channelId   Pointer to the unique channel name for the Agora RTC session in the string format smaller than 64 bytes. Supported characters:
   *                    \arg The 26 lowercase English letters: a to z
   *                    \arg The 26 uppercase English letters: A to Z
   *                    \arg The 10 numbers: 0 to 9
   *                    \arg The space
   *                    \arg "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", "{", "}", "|", "~", ","
   * @return
   * - 0(ERR_OK): Success.
   * - < 0: Failure.
   *   - -1(ERR_FAILED): A general error occurs (no specified reason).
   *   - -2(ERR_INALID_ARGUMENT): The parameter is invalid.
   *   - -5(ERR_REFUSED): The request is rejected, probably because the user is not an audience.
   *   - -7(ERR_NOT_INITIALIZED): The SDK is not initialized.
   *   - -102(ERR_INVALID_CHANNEL_NAME): The channel name is invalid.
   *   - -113(ERR_NOT_IN_CHANNEL): The user is not in the channel.
   */
	int switchChannel(const char* token, const char* channelId);

   /**
   * @brief    Allows a user to leave a channel, such as hanging up or exiting a call.
   * @brief    After joining a channel, the user must call the leaveChannel method to end the call before joining another channel.
   * @brief    This method returns 0 if the user leaves the channel and releases all resources related to the call.
   * @brief    This method call is asynchronous, and the user has not left the channel when the method call returns. Once the user leaves the channel, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel" callback.
   * @brief    A successful \ref leaveChannel method call triggers the following callbacks:
   *           \arg  The local client: \ref agora::rtc::IRtcEngineEventHandler::onLeaveChannel "onLeaveChannel"
   *           \arg  The remote client: \ref agora::rtc::IRtcEngineEventHandler::onUserOffline "onUserOffline", if the user leaving the channel is in the Communication channel, or is a BROADCASTER in the Live Broadcast profile.
   * @note     \arg  If you call the \ref release method immediately after the `leaveChannel` method, the `leaveChannel` process interrupts, and the `onLeaveChannel` callback is not triggered.
   *           \arg  If you call the `leaveChannel` method during a CDN live streaming, the SDK triggers the \ref removePublishStreamUrl method.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   *                 - -1(ERR_FAILED): A general error occurs (no specified reason).
   *                 - -2(ERR_INALID_ARGUMENT): The parameter is invalid.
   *                 - -7(ERR_NOT_INITIALIZED): The SDK is not initialized.
   */
	int leaveChannel();

   /**
   * @brief       Gets a new token when the current token expires after a period of time.
   * @brief       The \a token expires after a period of time once the token schema is enabled when:
   *              \arg  The SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onTokenPrivilegeWillExpire "onTokenPrivilegeWillExpire" callback, or
   *              \arg  The \ref agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged "onConnectionStateChanged" reports `CONNECTION_CHANGED_TOKEN_EXPIRED(9)`.
   * @brief       The application should call this method to get a new token. Failure to do so will result in the SDK disconnecting from the server.
   * @param token Pointer to the new token.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   *                    - -1(ERR_FAILED): A general error occurs (no specified reason).
   *                    - -2(ERR_INALID_ARGUMENT): The parameter is invalid.
   *                    - -7(ERR_NOT_INITIALIZED): The SDK is not initialized.
   */
	int renewToken(const char* token);

   /**
   * @brief             Registers a user account.
   * @brief             Once registered, the user account can be used to identify the local user when the user joins the channel. After the user successfully registers a user account, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onLocalUserRegistered "onLocalUserRegistered" callback on the local client, reporting the user ID and user account of the local user.
   * @brief             To join a channel with a user account, you can choose either of the following:
   *                    \arg  Call the \ref registerLocalUserAccount method to create a user account, and then the \ref joinChannelWithUserAccount method to join the channel.
   *                    \arg  Call the \ref joinChannelWithUserAccount method to join the channel.
   * @brief             The difference between the two is that for the former, the time elapsed between calling the \ref joinChannelWithUserAccount method and joining the channel is shorter than the latter.
   * @note              \arg  Ensure that you set the userAccount parameter. Otherwise, this method does not take effect.
   *                    \arg  Ensure that the value of the userAccount parameter is unique in the channel.
   *                    \arg  To ensure smooth communication, use the same parameter type to identify the user. For example, if a user joins the channel with a user ID, then ensure all the other users use the user ID too. The same applies to the user account. If a user joins the channel with the Agora Web SDK, ensure that the uid of the user is set to the same parameter type.
   * @param appId       The App ID of your project.
   * @param userAccount The user account. The maximum length of this parameter is 255 bytes. Ensure that you set this parameter and do not set it as null. Supported character scopes are:
   *                    \arg The 26 lowercase English letters: a to z
   *                    \arg The 26 uppercase English letters: A to Z
   *                    \arg The 10 numbers: 0 to 9
   *                    \arg The space
   *                    \arg "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", "{", "}", "|", "~", ","
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int registerLocalUserAccount(const char* appId, const char* userAccount);

   /**
   * @brief             Joins the channel with a user account.
   * @brief             After the user successfully joins the channel, the SDK triggers the following callbacks:
   *                    <ul>
   *                    <li> The local client: \ref agora::rtc::IRtcEngineEventHandler::onLocalUserRegistered "onLocalUserRegistered" and \ref agora::rtc::IRtcEngineEventHandler::onJoinChannelSuccess "onJoinChannelSuccess". The remote client: \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" and \ref agora::rtc::IRtcEngineEventHandler::onUserInfoUpdated "onUserInfoUpdated", if the user joining the channel is in the Communication profile, or is a BROADCASTER in the Live Broadcast profile.
   *                    </ul>
   * @note              To ensure smooth communication, use the same parameter type to identify the user. For example, if a user joins the channel with a user ID, then ensure all the other users use the user ID too. The same applies to the user account. If a user joins the channel with the Agora Web SDK, ensure that the uid of the user is set to the same parameter type.
   * @param token 	   The token generated at your server:
   *                    \arg  For low-security requirements: You can use the temporary token generated at Console. For details, see Get a temporary toke.
   *                    \arg  For high-security requirements: Set it as the token generated at your server. For details, see Get a token.
   * @param channelId   The channel name. The maximum length of this parameter is 64 bytes. Supported character scopes are:
   *                    \arg The 26 lowercase English letters: a to z
   *                    \arg The 26 uppercase English letters: A to Z
   *                    \arg The 10 numbers: 0 to 9
   *                    \arg The space
   *                    \arg "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", "{", "}", "|", "~", ","
   * @param userAccount The user account. The maximum length of this parameter is 255 bytes. Ensure that you set this parameter and do not set it as null. Supported character scopes are:
   *                    \arg The 26 lowercase English letters: a to z
   *                    \arg The 26 uppercase English letters: A to Z
   *                    \arg The 10 numbers: 0 to 9
   *                    \arg The space
   *                    \arg "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", "{", "}", "|", "~", ","
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int joinChannelWithUserAccount(const char* token, const char* channelId, const char* userAccount);

   /**
   * @brief             Gets the user information by passing in the user account.
   * @brief             After a remote user joins the channel, the SDK gets the user ID and user account of the remote user, caches them in a mapping table object (userInfo), and triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserInfoUpdated "onUserInfoUpdated" callback on the local client.
   * @brief             After receiving the `onUserInfoUpdated` callback, you can call this method to get the user ID of the remote user from the userInfo object by passing in the user account.
   * @param userAccount The user account of the user. Ensure that you set this parameter.
   * @param userInfo    userInfo A userInfo object that identifies the user:
   *                    \arg  Input: A userInfo object.
   *                    \arg  Output: A userInfo object that contains the user account and user ID of the user.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int getUserInfoByUserAccount(const char* userAccount, UserInfo* userInfo);

   /**
   * @brief             Gets the user information by passing in the user ID.
   * @brief             After a remote user joins the channel, the SDK gets the user ID and user account of the remote user, caches them in a mapping table object (userInfo), and triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserInfoUpdated "onUserInfoUpdated" callback on the local client.
   * @brief             After receiving the `onUserInfoUpdated` callback, you can call this method to get the user account of the remote user from the userInfo object by passing in the user ID.
   * @param uid         The user ID of the remote user. Ensure that you set this parameter.
   * @param userInfo    userInfo A userInfo object that identifies the user:
   *                    \arg  Input: A userInfo object.
   *                    \arg  Output: A userInfo object that contains the user account and user ID of the user.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int getUserInfoByUid(uid_t uid, UserInfo* userInfo);

   /**
   * @brief                   Starts an audio call test.
   * @brief                   This method starts an audio call test to determine whether the audio devices (for example, headset and speaker) and the network connection are working properly.
   * @brief                   In the audio call test, you record your voice. If the recording plays back within the set time interval, the audio devices and the network connection are working properly.
   * @note                    \arg  Call this method before joining a channel.
   *                          \arg  After calling this method, call the \ref stopEchoTest method to end the test. Otherwise, the app cannot run the next echo test, or call the \ref joinChannel method.
   *                          \arg  In the Live-broadcast profile, only a host can call this method.
   * @param intervalInSeconds The time interval (s) between when you speak and when the recording plays back.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int startEchoTest(int intervalInSeconds);

   /**
   * @brief    Stops the audio call test.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int stopEchoTest();

   /**
   * @brief    Enables the video module.
   * @brief    Call this method either before joining a channel or during a call. If this method is called before joining a channel, the call starts in the video mode. If this method is called during an audio call, the audio mode switches to the video mode. To disable the video module, call the \ref disableVideo method.
   * @brief    A successful \ref enableVideo method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserEnableVideo "onUserEnableVideo" (true) callback on the remote client.
   * @note     <ul>
   *           <li> This method affects the internal engine and can be called after the \ref leaveChannel method.
   *           <li> This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the video engine modules separately:
   *           <ul>
   *              <li> \ref enableLocalVideo "enableLocalVideo": Whether to enable the camera to create the local video stream.
   *              <li> \ref muteLocalVideoStream "muteLocalVideoStream": Whether to publish the local video stream.
   *              <li> \ref muteRemoteVideoStream "muteRemoteVideoStream": Whether to subscribe to and play the remote video stream.
   *              <li> \ref muteAllRemoteVideoStreams "muteAllRemoteVideoStreams": Whether to subscribe to and play all remote video streams.
   *           </ul>
   *           </ul>
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int enableVideo();

   /**
   * @brief    Disables the video module.
   * @brief    This method can be called before joining a channel or during a call. If this method is called before joining a channel, the call starts in audio mode. If this method is called during a video call, the video mode switches to the audio mode. To enable the video module, call the \ref enableVideo method.
   * @brief    A successful \ref disableVideo method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserEnableVideo "onUserEnableVideo" (false) callback on the remote client.
   * @note     <ul>
   *           <li> This method affects the internal engine and can be called after the \ref leaveChannel method.
   *           <li> This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the video engine modules separately:
   *           <ul>
   *              <li> \ref enableLocalVideo "enableLocalVideo": Whether to enable the camera to create the local video stream.
   *              <li> \ref muteLocalVideoStream "muteLocalVideoStream": Whether to publish the local video stream.
   *              <li> \ref muteRemoteVideoStream "muteRemoteVideoStream": Whether to subscribe to and play the remote video stream.
   *              <li> \ref muteAllRemoteVideoStreams "muteAllRemoteVideoStreams": Whether to subscribe to and play all remote video streams.
   *           </ul>
   *           </ul>
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int disableVideo();

   /**
   * @brief          Sets the video encoder configuration.
   * @brief          Each video encoder configuration corresponds to a set of video parameters, including the resolution, frame rate, bitrate, and video orientation.
   * @brief          The parameters specified in this method are the maximum values under ideal network conditions. If the video engine cannot render the video using the specified parameters due to poor network conditions, the parameters further down the list are considered until a successful configuration is found.
   * @note           If you do not need to set the video encoder configuration after joining the channel, you can call this method before the \ref enableVideo method to reduce the render time of the first video frame.
   * @param config   Sets the local video encoder configuration. See \ref VideoEncoderConfiguration.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setVideoEncoderConfiguration(const VideoEncoderConfiguration& config);

   /**
   * @brief          Sets the camera capture configuration.
   * @brief          For a video call or live broadcast, generally the SDK controls the camera output parameters. When the default camera capturer settings do not meet special requirements or cause performance problems, we recommend using this method to set the camera capturer configuration:
   *                 <ul>
   *                 <li> If the resolution or frame rate of the captured raw video data are higher than those set by \ref setVideoEncoderConfiguration, processing video frames requires extra CPU and RAM usage and degrades performance. We recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1 to avoid such problems.
   *                 <li> If you do not need local video preview or are willing to sacrifice preview quality, we recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1 to optimize CPU and RAM usage.
   *                 <li> If you want better quality for the local video preview, we recommend setting config as CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2.
   *                 </ul>
   * @note           Call this method before enabling the local camera. That said, you can call this method before calling \ref joinChannel, \ref enableVideo, or \ref enableLocalVideo, depending on which method you use to turn on your local camera.
   * @param config   Sets the camera capturer configuration. See \ref CameraCapturerConfiguration.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setCameraCapturerConfiguration(const CameraCapturerConfiguration& config);

   /**
   * @brief          Sets the local video view and configures the video display settings on the local machine.
   * @brief          The application calls this method to bind each video window (view) of the local video streams and configures the video display settings. Call this method after initialization to configure the local video display settings before joining a channel. The binding is still valid after the user leaves the channel, which means that the window still displays. To unbind the view, set the view in \ref VideoCanvas to NULL.
   *
   * @note
   * - You can call this method either before or after joining a channel.
   * - During a call, you can call this method as many times as necessary to update the display mode of the local video view.   * @param canvas   Pointer to the local video view and settings. See \ref VideoCanvas.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setupLocalVideo(const VideoCanvas& canvas);

   /**
   * @brief          Sets the remote video view.
   * @brief          This method binds the remote user to the video display window (sets the view for the remote user by the specified uid in \ref VideoCanvas).
   * @brief          The application specifies the uid of the remote video in this method before the remote user joins the channel.
   * @brief          If the remote uid is unknown to the application, set it after the application receives the \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" callback.
   * @brief          If the Video Recording function is enabled, the Video Recording Service joins the channel as a dummy client, causing other clients to also receive the \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" callback. Do not bind the dummy client to the application view because the dummy client does not send any video streams. If your application does not recognize the dummy client, bind the remote user to the view when the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onFirstRemoteVideoDecoded "onFirstRemoteVideoDecoded" callback.
   * @brief          To unbind the remote user from the view, set the view in \ref VideoCanvas to NULL. Once the remote user leaves the channel, the SDK unbinds the remote user.
   * @param canvas   Pointer to the remote video view and settings. See \ref VideoCanvas.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setupRemoteVideo(const VideoCanvas& canvas);

   /**
   * @brief    Starts the local video preview before joining the channel.
   * @brief    Before calling this method, you must:
   *           <ul>
   *           <li> Call the \ref setupLocalVideo method to set up the local preview window and configure the attributes.
   *           <li> Call the \ref enableVideo method to enable video.
   *           </ul>
   * @note     Once the startPreview method is called to start the local video preview, if you leave the channel by calling the \ref leaveChannel method, the local video preview remains until you call the \ref stopPreview method to disable it.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int startPreview();

   /**
   * @brief                Prioritizes a remote user's stream.
   * @brief                Use this method with the \ref setRemoteSubscribeFallbackOption method. If the fallback function is enabled for a subscribed stream, the SDK ensures the high-priority user gets the best possible stream quality.
   * @note
   * - The Agora SDK supports setting `userPriority` as high for one user only.
   * - Ensure that you call this method before joining a channel.
   * @param uid            The ID of the remote user.
   * @param userPriority   Sets the priority of the remote user. See \ref PRIORITY_TYPE.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setRemoteUserPriority(agora::rtc::uid_t uid, agora::rtc::PRIORITY_TYPE userPriority);

   /**
   * @brief    Stops the local video preview and disables video.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int stopPreview();

   /**
   * @brief    Enables the audio module.
   * @brief    The audio mode is enabled by default.
   * @note     <ul>
   *           <li> This method affects the internal engine and can be called after the \ref leaveChannel method.
   *           <li> This method resets the internal engine and takes some time to take effect. We recommend using the following API methods to control the video engine modules separately:
   *           <ul>
   *              <li> \ref enableLocalVideo "enableLocalVideo": Whether to enable the camera to create the local video stream.
   *              <li> \ref muteLocalVideoStream "muteLocalVideoStream": Whether to publish the local video stream.
   *              <li> \ref muteRemoteVideoStream "muteRecordingVideoStream": Whether to subscribe to and play the remote video stream.
   *              <li> \ref muteAllRemoteVideoStreams "muteAllRemoteVideoStreams": Whether to subscribe to and play all remote video streams.
   *           </ul>
   *           </ul>
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int enableAudio();

   /**
   * @brief          Disables/Re-enables the local audio function.
   * @brief          The audio function is enabled by default. This method disables or re-enables the local audio function, that is, to stop or restart local audio capturing.
   * @brief          This method does not affect receiving or playing the remote audio streams, and enableLocalAudio(false) is applicable to scenarios where the user wants to receive remote audio streams without sending any audio stream to other users in the channel.
   * @brief          Once the local audio function is disabled or re-enabled, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onLocalAudioStateChanged "onLocalAudioStateChanged" callback,
   * which reports `LOCAL_AUDIO_STREAM_STATE_STOPPED(0)` or `LOCAL_AUDIO_STREAM_STATE_RECORDING(1)`.
   * @note
   * - This method is different from the \ref agora::rtc::IRtcEngine::muteLocalAudioStream "muteLocalAudioStream" method:
   *   - \ref enableLocalAudio: Disables/Re-enables the local audio capturing and processing.
   *     If you disable or re-enable local audio capturing using the `enableLocalAudio` method, the local user may hear a pause in the remote audio playback.
   *   - \ref muteLocalAudioStream: Sends/Stops sending the local audio streams.
   * - You can call this method either before or after joining a channel.
   * @param enabled  Sets whether to disable/re-enable the local audio function:
   *                 \arg  true: (Default) Re-enable the local audio function, that is, to start the local audio capturing device (for example, the microphone).
   *                 \arg  false: Disable the local audio function, that is, to stop local audio capturing.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int enableLocalAudio(bool enabled);

   /**
   * @brief    Disables the audio module.
   * @note     \arg  This method affects the internal engine and can be called after the \ref leaveChannel method. You can call this method either before or after joining a channel.
   *           \arg  This method resets the internal engine and takes some time to take effect. We recommend using the \ref enableLocalAudio and \ref muteLocalAudioStream methods to capture, process, and send the local audio streams.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int disableAudio();

   /**
   * @brief          Sets the audio parameters and application scenarios.
   * @note           \arg  The \a setAudioProfile method must be called before the \ref joinChannel method.
   *                 \arg  In the Communication and Live-broadcast profiles, the bitrate may be different from your settings due to network self-adaptation.
   *                 \arg  In scenarios involving music education, we recommend setting profile as \ref AUDIO_PROFILE_MUSIC_HIGH_QUALITY (4) and scenario as \ref AUDIO_SCENARIO_GAME_STREAMING (3).
   * @param profile  Sets the sample rate, bitrate, encoding mode, and the number of channels. See \ref AUDIO_PROFILE_TYPE.
   * @param scenario Sets the audio application scenario. See \ref AUDIO_SCENARIO_TYPE. Under different audio scenarios, the device uses different volume tracks, i.e. either the in-call volume or the media volume. For details, see What is the difference between the in-call volume and the media volume?.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setAudioProfile(agora::rtc::AUDIO_PROFILE_TYPE profile, agora::rtc::AUDIO_SCENARIO_TYPE scenario);

   /**
   * @brief       Stops/Resumes sending the local audio stream.
   * @brief       A successful \ref muteLocalAudioStream method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserMuteAudio "onUserMuteAudio" callback on the remote client.
   * @note        \arg When `mute` is set as `true`, this method does not disable the microphone, which does not affect any ongoing recording.
   *              \arg If you call \ref setChannelProfile after this method, the SDK resets whether or not to mute the local audio according to the channel profile and user role. Therefore, we recommend calling this method after the \a setChannelProfile method.
   * @param mute  Sets whether to send/stop sending the local audio stream:
   *              \arg  true: Stops sending the local audio stream.
   *              \arg  false: (Default) Sends the local audio stream.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int muteLocalAudioStream(bool mute);

   /**
   * @brief       Stops/Resumes receiving all remote users' audio streams.
   * @param mute  Sets whether to receive/stop receiving all remote users' audio streams.
   *              \arg  true: Stops receiving all remote users' audio streams.
   *              \arg  false: (Default) Receives all remote users' audio streams.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int muteAllRemoteAudioStreams(bool mute);

   /**
   * @brief       Stops/Resumes receiving all remote users' audio streams by default.
   *
   *  You can call this method either before or after joining a channel. If you call `setDefaultMuteAllRemoteAudioStreams (true)` after joining a channel, the remote audio streams of all subsequent users are not received.
   *
   * @note If you want to resume receiving the audio stream, call \ref muteRemoteAudioStream (false),
   * and specify the ID of the remote user whose audio stream you want to receive.
   * To receive the audio streams of multiple remote users, call `muteRemoteAudioStream (false)` as many times.
   * Calling `setDefaultMuteAllRemoteAudioStreams (false)` resumes receiving the audio streams of subsequent users only.   
   * @param mute  Sets whether to receive/stop receiving all remote users' audio streams by default:
   *              \arg  true: Stops receiving all remote users' audio streams by default.
   *              \arg  false: (Default) Receives all remote users' audio streams by default.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int setDefaultMuteAllRemoteAudioStreams(bool mute);
   /** Adjusts the playback volume of a specified remote user.

     You can call this method as many times as necessary to adjust the playback volume of different remote users, or to repeatedly adjust the playback volume of the same remote user.

     @note
     - Call this method after joining a channel.
     - The playback volume here refers to the mixed volume of a specified remote user.
     - This method can only adjust the playback volume of one specified remote user at a time. To adjust the playback volume of different remote users, call the method as many times, once for each remote user.

     @param uid The ID of the remote user.
     @param volume The playback volume of the specified remote user. The value ranges from 0 to 100:
     - 0: Mute.
     - 100: Original volume.

     @return
     - 0: Success.
    - < 0: Failure.
     */
    int adjustUserPlaybackSignalVolume( unsigned int uid, int volume );

   /**
   * @brief          Stops/Resumes receiving a specified remote user's audio stream.
   * @note
   * - You can call this method either before or after joining a channel. If you call it before joining a channel, you need to maintain the `uid` of the remote user on your app level.
   * - If you called the \ref muteAllRemoteAudioStreams method and set \a mute as \a true to stop receiving all remote users' audio streams, call the \a muteAllRemoteAudioStreams method and set \a mute as \a false before calling this method. The \a muteAllRemoteAudioStreams method sets all remote audio streams, while the \a muteRemoteAudioStream method sets a specified remote audio stream.
   * @param userId   User ID of the specified remote user sending the audio.
   * @param mute     Sets whether to receive/stop receiving a specified remote user's audio stream:
   *                 \arg  true: Stops receiving the specified remote user's audio stream.
   *                 \arg  false: (Default) Receives the specified remote user's audio stream.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int muteRemoteAudioStream(agora::rtc::uid_t userId, bool mute);

   /**
   * @brief       Stops/Resumes sending the local video stream.
   * @brief       A successful \ref muteLocalVideoStream method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserMuteVideo "onUserMuteVideo" callback on the remote client.
   * @note        \arg  When set to `true`, this method does not disable the camera which does not affect the retrieval of the local video streams. This method executes faster than the \ref enableLocalVideo method which controls the sending of the local video stream.
   *              \arg  If you call `setChannelProfile` after this method, the SDK resets whether or not to mute the local video according to the channel profile and user role. Therefore, we recommend calling this method after the \a setChannelProfile method.
   * @param mute  Sets whether to send/stop sending the local video stream:
   *              \arg  true: Stop sending the local video stream.
   *              \arg  false: (Default) Send the local video stream.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int muteLocalVideoStream(bool mute);

   /**
   * @brief          Enables/Disables the local video capture.
   * @brief          This method disables or re-enables the local video capturer, and does not affect receiving the remote video stream.
   * @brief          After you call the \ref enableVideo method, the local video capturer is enabled by default. You can call \ref enableLocalVideo "enableLocalVideo"(false) to disable the local video capturer. If you want to re-enable it, call `enableLocalVideo(true)`.
   * @brief          After the local video capturer is successfully disabled or re-enabled, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserEnableLocalVideo "onUserEnableLocalVideo" callback on the remote client.
   * @note           This method affects the internal engine and can be called after the \ref leaveChannel method.
   * @param enabled  Sets whether to disable/re-enable the local video, including the capturer, renderer, and sender:
   *                 \arg  true: (Default) Re-enable the local video.
   *                 \arg  false: Disable the local video. Once the local video is disabled, the remote users can no longer receive the video stream of this user, while this user can still receive the video streams of the other remote users.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int enableLocalVideo(bool enabled);

   /**
   * @brief       Stops/Resumes receiving all video stream from a specified remote user.
   * @note You can call this method either before or after joining a channel.
   * @param mute  Sets whether to receive/stop receiving all remote users' video streams:
   *              \arg  true: Stop receiving all remote users' video streams.
   *              \arg  false: (Default) Receive all remote users' video streams.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int muteAllRemoteVideoStreams(bool mute);

   /**
   * @brief       Stops/Resumes receiving all remote users' video streams by default.
   * @note If you want to resume receiving the video stream, call \ref muteRemoteVideoStream (false), and specify the ID of the remote user whose video stream you want to receive. To receive the video streams of multiple remote users, call `muteRemoteVideoStream (false)` as many times. Calling `setDefaultMuteAllRemoteVideoStreams (false)` resumes receiving the video streams of subsequent users only.
   * @param mute  Sets whether to receive/stop receiving all remote users' video streams by default:
   *              \arg  true: Stop receiving all remote users' video streams by default.
   *              \arg  false: (Default) Receive all remote users' video streams by default.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int setDefaultMuteAllRemoteVideoStreams(bool mute);

   /**
   * @brief          Stops/Resumes receiving the video stream from a specified remote user.
   * @note           If you called the \ref muteAllRemoteVideoStreams method and set mute as true to stop receiving all remote video streams, call the \a muteAllRemoteVideoStreams method and set \a mute as \a false before calling this method.
   * @param userId   User ID of the specified remote user.
   * @param mute     Sets whether to stop/resume receiving the video stream from a specified remote user:
   *                 \arg  true: Stop receiving the specified remote user's video stream.
   *                 \arg  false: (Default) Receive the specified remote user's video stream.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int muteRemoteVideoStream(agora::rtc::uid_t userId, bool mute);

   /**
   * @brief             Sets the remote user's video stream type received by the local user when the remote user sends dual streams.
   * @brief             This method allows the application to adjust the corresponding video-stream type based on the size of the video window to reduce the bandwidth and resources.
   *                    \arg  If the remote user enables the dual-stream mode by calling the \ref enableDualStreamMode method, the SDK receives the high-stream video by default.
   *                    \arg  If the dual-stream mode is not enabled, the SDK receives the high-stream video by default.
   * @brief             The method result returns in the \ref agora::rtc::IRtcEngineEventHandler::onApiCallExecuted "onApiCallExecuted" callback. The SDK receives the high-stream video by default to reduce the bandwidth. 
   *                    If needed, users may use this method to switch to the low-stream video. By default, the aspect ratio of the low-stream video is the same as the high-stream video. 
   *                    Once the resolution of the high-stream video is set, the system automatically sets the resolution, frame rate, and bitrate of the low-stream video.
   * @note You can call this method either before or after joining a channel. If you call both
   * \ref setRemoteVideoStreamType and \ref setRemoteDefaultVideoStreamType, the SDK applies the settings in
   *  the `setRemoteVideoStreamType` method.
   * @param userId      ID of the remote user sending the video stream.
   * @param streamType 	Sets the video-stream type. See \ref REMOTE_VIDEO_STREAM_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setRemoteVideoStreamType(agora::rtc::uid_t userId, agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

   /**
   * @brief             Sets the default video-stream type for the video received by the local user when the remote user sends dual streams.
   *                    \arg  If the dual-stream mode is enabled by calling the \ref enableDualStreamMode method, the user receives the high-stream video by default. The `setRemoteDefaultVideoStreamType` method allows the application to adjust the corresponding video-stream type according to the size of the video window, reducing the bandwidth and resources.
   *                    \arg  If the dual-stream mode is not enabled, the user receives the high-stream video by default.
   * @brief             The result after calling this method is returned in the \ref agora::rtc::IRtcEngineEventHandler::onApiCallExecuted "onApiCallExecuted" callback. The Agora SDK receives the high-stream video by default to reduce the bandwidth. If needed, users can switch to the low-stream video through this method.
   *
   * @note You can call this method either before or after joining a channel. If you call both
   * \ref setRemoteVideoStreamType and \ref setRemoteDefaultVideoStreamType, the SDK applies the settings in
   *  the `setRemoteVideoStreamType` method.
   *
   * @param streamType  Sets the default video-stream type. See \ref REMOTE_VIDEO_STREAM_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setRemoteDefaultVideoStreamType(agora::rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

   /**
   * @brief             Enables the reporting of users' volume indication.
   * @brief             This method enables the SDK to regularly report the volume information of the local user who sends a stream and
   * remote users (up to three) whose instantaneous volumes are the highest to the app. Once you call this method and
   * users send streams in the channel, the SDK triggers the
   * \ref IRtcEngineEventHandler::onAudioVolumeIndication "onAudioVolumeIndication" callback at the time interval set
   * in this method.
   * @note You can call this method either before or after joining a channel.
   * @param interval    Sets the time interval between two consecutive volume indications:
   *                    \arg  ≤ 0: Disables the volume indication.
   *                    \arg  > 0: Time interval (ms) between two consecutive volume indications. We recommend setting interval > 200 ms. Do not set interval < 10 ms, or the `onAudioVolumeIndication` callback will not be triggered.
   * @param smooth      Smoothing factor sets the sensitivity of the audio volume indicator. The value ranges between 0 and 10. The greater the value, the more sensitive the indicator. The recommended value is 3.
   * @param report_vad  \arg  true: Enable the voice activity detection of the local user. Once it is enabled, the vad parameter of the `onAudioVolumeIndication` callback reports the voice activity status of the local user.
   *                    \arg  false: (Default) Disable the voice activity detection of the local user. Once it is disabled, the vad parameter of the `onAudioVolumeIndication` callback does not report the voice activity status of the local user, except for the scenario where the engine automatically detects the voice activity of the local user.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int enableAudioVolumeIndication(int interval, int smooth, bool report_vad);

   /**
   * @brief             Starts an audio recording on the client.
   * @brief             The SDK allows recording during a call. After successfully calling this method, you can record the audio of all the users in the channel and get an audio recording file. Supported formats of the recording file are as follows:
   *                    <ul>
   *                    <li> .wav: Large file size with high fidelity.
   *                    <li> .aac: Small file size with low fidelity.
   *                    </ul>
   * @note              \arg  Ensure that the directory you use to save the recording file exists and is writable.
   *                    \arg  This method is usually called after the \ref joinChannel method. The recording automatically stops when you call the \ref leaveChannel method.
   *                    \arg  For better recording effects, set quality as \ref AUDIO_RECORDING_QUALITY_MEDIUM or \ref AUDIO_RECORDING_QUALITY_HIGH when sampleRate is 44.1 kHz or 48 kHz.
   * @param filePath    Pointer to the absolute file path of the recording file. The string of the file name is in UTF-8.
   * @param sampleRate  Sample rate (Hz) of the recording file. Supported values are as follows:
   *                    \arg  16000
   *                    \arg  (Default) 32000
   *                    \arg  44100
   *                    \arg  48000
   * @param quality     Sets the audio recording quality. See \ref AUDIO_RECORDING_QUALITY_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int startAudioRecording(const char* filePath, int sampleRate, AUDIO_RECORDING_QUALITY_TYPE quality);

   /**
   * @brief    Stops an audio recording on the client.
   * @brief    You can call this method before calling the \ref leaveChannel method else, the recording automatically stops when the \ref leaveChannel method is called.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int stopAudioRecording();

   /**
   * @brief             Starts playing and mixing the music file.
   * @brief             This method mixes the specified local audio file with the audio stream from the microphone, or replaces the microphone's audio stream with the specified local audio file. 
   *                    You can choose whether the other user can hear the local audio playback and specify the number of playback loops. This method also supports online music playback.
   * @brief             A successful \ref startAudioMixing method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onAudioMixingStateChanged "onAudioMixingStateChanged" (PLAY) callback on the local client.
   * @brief             When the audio mixing file playback finishes, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onAudioMixingStateChanged "onAudioMixingStateChanged" (STOPPED) callback on the local client.
   * @note              \arg  Call this method after joining a channel, otherwise issues may occur.
   *                    \arg  If the local audio mixing file does not exist, or if the SDK does not support the file format or cannot access the music file URL, the SDK returns WARN_AUDIO_MIXING_OPEN_ERROR = 701.
   *                    \arg  If you want to play an online music file, ensure that the time interval between calling this method is more than 100 ms, or the AUDIO_MIXING_ERROR_TOO_FREQUENT_CALL(702) error code occurs.
   * @param filePath    Pointer to the absolute path of the local or online audio file to mix. Supported audio formats: 3GP, ASF, ADTS, AVI, MP3, MPEG-4, SAMI, and WAVE. For more information, see Supported Media Formats in Media Foundation.
   * @param loopback    Sets which user can hear the audio mixing:
   *                    \arg  true: Only the local user can hear the audio mixing.
   *                    \arg  false: Both users can hear the audio mixing.
   * @param replace     Sets the audio mixing content:
   *                    \arg  true: Only the specified audio file is published; the audio stream received by the microphone is not published.
   *                    \arg  false: The local audio file is mixed with the audio stream from the microphone.
   * @param cycle       Sets the number of playback loops:
   *                    \arg  Positive integer: Number of playback loops.
   *                    \arg  -1: Infinite playback loops.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int startAudioMixing(const char* filePath, bool loopback, bool replace, int cycle);

   /**
   * @brief    Stops playing and mixing the music file.
   * @brief    Call this method when you are in a channel.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int stopAudioMixing();

   /**
   * @brief    Pauses playing and mixing the music file.
   * @brief    Call this method when you are in a channel.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int pauseAudioMixing();

   /**
   * @brief    Resumes playing and mixing the music file.
   * @brief    Call this method when you are in a channel.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int resumeAudioMixing();

   /**
   * @brief          Adjusts the volume during audio mixing.
   * @note
   * - Calling this method does not affect the volume of audio effect file playback invoked by the \ref playEffect method.
   * - Ensure that this method is called after \ref startAudioMixing.
   * @param volume   Audio mixing volume. The value ranges between 0 and 100 (default).
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int adjustAudioMixingVolume(int volume);

   /**
   * @brief          Adjusts the audio mixing volume for local playback.
   * @note           Ensure that this method is called after \ref startAudioMixing.
   * @param volume   Audio mixing volume for local playback. The value ranges between 0 and 100 (default).
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int adjustAudioMixingPlayoutVolume(int volume);

   /**
   * @brief    Retrieves the audio mixing volume for local playback.
   * @brief    This method helps troubleshoot audio volume related issues.
   * @note     Call this method when you are in a channel.
   * @return   \arg  ≥ 0: The audio mixing volume, if this method call succeeds. The value range is [0,100].
   *           \arg  < 0: Failure.
   */
	int getAudioMixingPlayoutVolume();

   /**
   * @brief          Adjusts the audio mixing volume for publishing (for remote users).
   * @note           Call this method when you are in a channel.
   * @param volume   Audio mixing volume for publishing. The value ranges between 0 and 100 (default).
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int adjustAudioMixingPublishVolume(int volume);

   /**
   * @brief    Retrieves the audio mixing volume for publishing.
   * @brief    This method helps troubleshoot audio volume related issues.
   * @note     Ensure that this method is called after \ref startAudioMixing.
   * @return   \arg  ≥ 0: The audio mixing volume for publishing, if this method call succeeds. The value range is [0,100].
   *           \arg  < 0: Failure.
   */
	int getAudioMixingPublishVolume();

   /**
   * @brief    Retrieves the duration (ms) of the music file.
   * @brief    Call this method when you are in a channel.
   * @return   \arg  ≥ 0: The audio mixing duration, if this method call succeeds.
   *           \arg  < 0: Failure.
   */
	int getAudioMixingDuration();

   /**
   * @brief    Retrieves the playback position (ms) of the music file.
   * @brief    Call this method when you are in a channel.
   * @return   \arg  ≥ 0: The current playback position of the audio mixing, if this method call succeeds.
   *           \arg  < 0: Failure.
   */
	int getAudioMixingCurrentPosition();

   /**
   * @brief       Sets the playback position of the music file to a different starting position (the default plays from the beginning).
   * @param pos   The playback starting position (ms) of the music file.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setAudioMixingPosition(int pos /*in ms*/);

   /**
    * @brief Sets the pitch of the local music file.
    * @note
    * Call this method after calling `startAudioMixing`.
    *
    * @param pitch Sets the pitch of the local music file by chromatic scale. The default value is 0,
    * which means keeping the original pitch. The value ranges from -12 to 12, and the pitch value between
    * consecutive values is a chromatic value. The greater the absolute value of this parameter, the
    * higher or lower the pitch of the local music file.
    *
    * @return         \arg  0: Success.
    *                 \arg  < 0: Failure.
    */
   int setAudioMixingPitch( int pitch );

   /**
   * @brief    Retrieves the volume of the audio effects.
   * @brief    The value ranges between 0 and 100.
   * @note Ensure that this method is called after \ref playEffect.
   * @return   \arg  ≥ 0: Volume of the audio effects, if this method call succeeds.
   *           \arg  < 0: Failure.
   */
	int getEffectsVolume();

   /**
   * @brief          Sets the volume of the audio effects.
   * @note Ensure that this method is called after \ref playEffect.
   * @param volume   Sets the volume of the audio effects. The value ranges between 0 and 100 (default).
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setEffectsVolume(int volume);

   /**
   * @brief          Sets the volume of a specified audio effect.
   * @note Ensure that this method is called after \ref playEffect.
   * @param soundId  ID of the audio effect. Each audio effect has a unique ID.
   * @param volume   Sets the volume of the specified audio effect. The value ranges between 0 and 100 (default).
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setVolumeOfEffect(int soundId, int volume);

   /**
   * @brief             Plays a specified local or online audio effect file.
   * @brief             This method allows you to set the loop count, pitch, pan, and gain of the audio effect file, as well as whether the remote user can hear the audio effect.
   * @brief             To play multiple audio effect files simultaneously, call this method multiple times with different soundIds and filePaths. We recommend playing no more than three audio effect files at the same time.
   * @param soundId     ID of the specified audio effect. Each audio effect has a unique ID.
   * @note              \arg  If the audio effect is preloaded into the memory through the \ref preloadEffect method, the value of \a soundID must be the same as that in the \a preloadEffect method.
   *                    \arg  Playing multiple online audio effect files simultaneously is not supported on macOS and Windows.
   * @param filePath    The absolute path to the local audio effect file or the URL of the online audio effect file.
   * @param loopCount   Sets the number of times the audio effect loops:
   *                    \arg  0: Play the audio effect once.
   *                    \arg  1: Play the audio effect twice.
   *                    \arg  -1: Play the audio effect in an indefinite loop until the \ref stopEffect or \ref stopAllEffects method is called.
   * @param pitch       Sets the pitch of the audio effect. The value ranges between 0.5 and 2. The default value is 1 (no change to the pitch). The lower the value, the lower the pitch.
   * @param pan         Sets the spatial position of the audio effect. The value ranges between -1.0 and 1.0:
   *                    \arg  0.0: The audio effect displays ahead.
   *                    \arg  1.0: The audio effect displays to the right.
   *                    \arg  -1.0: The audio effect displays to the left.
   * @param gain        Sets the volume of the audio effect. The value ranges between 0 and 100 (default). The lower the value, the lower the volume of the audio effect.
   * @param publish     Sets whether or not to publish the specified audio effect to the remote stream:
   *                    \arg  true: The locally played audio effect is published to the Agora Cloud and the remote users can hear it.
   *                    \arg  false: The locally played audio effect is not published to the Agora Cloud and the remote users cannot hear it.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int playEffect(
		int soundId,
		const char* filePath,
		int loopCount,
		double pitch,
		double pan,
		int gain,
		bool publish = false);

   /**
   * @brief          Stops playing a specified audio effect.
   * @param soundId  ID of the audio effect to stop playing. Each audio effect has a unique ID.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int stopEffect(int soundId);

   /**
   * @brief    Stops playing all audio effects.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int stopAllEffects();

   /**
   * @brief          Preloads a specified audio effect file into the memory.
   * @note           This method does not support online audio effect files.
   * @brief          To ensure smooth communication, limit the size of the audio effect file. We recommend using this method to preload the audio effect before calling the \ref joinChannel method.
   * @brief          Supported audio formats: mp3, aac, m4a, 3gp, and wav.
   * @param soundId  ID of the audio effect. Each audio effect has a unique ID.
   * @param filePath Pointer to the absolute path of the audio effect file.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int preloadEffect(int soundId, const char* filePath);

   /**
   * @brief          Releases a specified preloaded audio effect from the memory.
   * @param soundId  ID of the audio effect. Each audio effect has a unique ID.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int unloadEffect(int soundId);

   /**
   * @brief          Pauses a specified audio effect.
   * @param soundId  ID of the audio effect. Each audio effect has a unique ID.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int pauseEffect(int soundId);

   /**
   * @brief    Pauses all audio effects.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int pauseAllEffects();

   /**
   * @brief          Resumes playing a specified audio effect.
   * @param soundId  ID of the audio effect. Each audio effect has a unique ID.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int resumeEffect(int soundId);

   /**
   * @brief    Resumes playing all audio effects.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int resumeAllEffects();

   /**
   * @brief          Enables/Disables stereo panning for remote users.
   * @brief          Ensure that you call this method before joinChannel to enable stereo panning for remote users so that the local user can track the position of a remote user by calling \ref setRemoteVoicePosition.
   * @param enabled  Sets whether or not to enable stereo panning for remote users:
   *                 \arg  true: enables stereo panning.
   *                 \arg  false: disables stereo panning.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int enableSoundPositionIndication(bool enabled);

   /**
   * @brief       Sets the sound position and gain of a remote user.
   * @brief       When the local user calls this method to set the sound position of a remote user, the sound difference between the left and right channels allows the local user to track the real-time position of the remote user, creating a real sense of space. This method applies to massively multiplayer online games, such as Battle Royale games.
   * @note        \arg  For this method to work, enable stereo panning for remote users by calling the \ref enableSoundPositionIndication method before joining a channel.
                  \arg  This method requires hardware support. For the best sound positioning, we recommend using a stereo speaker.
   * @param uid   The ID of the remote user.
   * @param pan   The sound position of the remote user. The value ranges from -1.0 to 1.0:
   *              \arg  0.0: the remote sound comes from the front.
   *              \arg  -1.0: the remote sound comes from the left.
   *              \arg  1.0: the remote sound comes from the right.
   * @param gain  Gain of the remote user. The value ranges from 0.0 to 100.0. The default value is 100.0 (the original gain of the remote user). The smaller the value, the less the gain.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int setRemoteVoicePosition(uid_t uid, double pan, double gain);

   /**
   * @brief       Changes the voice pitch of the local speaker.
   * @param pitch Sets the voice pitch. The value ranges between 0.5 and 2.0. The lower the value, the lower the voice pitch. The default value is 1.0 (no change to the local voice pitch).
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int setLocalVoicePitch(double pitch);

   /**
   * @brief                Sets the local voice equalization effect.
   * @param bandFrequency  Sets the band frequency. The value ranges between 0 and 9, representing the respective 10-band center frequencies of the voice effects, including 31, 62, 125, 500, 1k, 2k, 4k, 8k, and 16k Hz. See \ref AUDIO_EQUALIZATION_BAND_FREQUENCY.
   * @param bandGain       Sets the gain of each band in dB. The value ranges between -15 and 15.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setLocalVoiceEqualization(agora::rtc::AUDIO_EQUALIZATION_BAND_FREQUENCY bandFrequency, int bandGain);

   /**
   * @brief             Sets the local voice reverberation.
   * @brief             v2.4.0 adds the \ref setLocalVoiceReverbPreset method, a more user-friendly method for setting the local voice reverberation. You can use this method to set the local reverberation effect, such as pop music, R&B, rock music, and hip-hop.
   * @param reverbKey   Sets the reverberation key. See \ref AUDIO_REVERB_TYPE.
   * @param value       Sets the value of the reverberation key.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setLocalVoiceReverb(agora::rtc::AUDIO_REVERB_TYPE reverbKey, int value);

   /**
   * @brief                Sets the local voice changer option.
   *
   * This method can be used to set the local voice effect for users in a `COMMUNICATION` channel or hosts in a `LIVE_BROADCASTING` channel.
   * Voice changer options include the following voice effects:
   *
   * - `VOICE_CHANGER_XXX`: Changes the local voice to an old man, a little boy, or the Hulk. Applies to the voice talk scenario.
   * - `VOICE_BEAUTY_XXX`: Beautifies the local voice by making it sound more vigorous, resounding, or adding spacial resonance. Applies to the voice talk and singing scenario.
   * - `GENERAL_VOICE_BEAUTY_XXX`: Adds gender-based beautification effect to the local voice. Applies to the voice talk scenario.
   *   - For a male voice: Adds magnetism to the voice.
   *   - For a female voice: Adds freshness or vitality to the voice.
   * @note
   * - To achieve better voice effect quality, Agora recommends setting the profile parameter in \ref IRtcEngine::setAudioProfile "setAudioProfile" as #AUDIO_PROFILE_MUSIC_HIGH_QUALITY (4) or #AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO (5)
   * - This method works best with the human voice, and Agora does not recommend using it for audio containing music and a human voice.
   * - Do not use this method with \ref IRtcEngine::setLocalVoiceReverbPreset "setLocalVoiceReverbPreset" , because the method called later overrides the one called earlier. For detailed considerations, see the advanced guide *Voice Changer and Reverberation*.
   * - You can call this method either before or after joining a channel.
   * @param voiceChanger   Sets the local voice changer option. The default value is #VOICE_CHANGER_OFF, which means the original voice. See details in #VOICE_CHANGER_PRESET
   * Gender-based beatification effect works best only when assigned a proper gender:
   * - For male: #GENERAL_BEAUTY_VOICE_MALE_MAGNETIC
   * - For female: #GENERAL_BEAUTY_VOICE_FEMALE_FRESH or #GENERAL_BEAUTY_VOICE_FEMALE_VITALITY
   * Failure to do so can lead to voice distortion.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setLocalVoiceChanger(agora::rtc::VOICE_CHANGER_PRESET voiceChanger);

   /** Sets the local voice reverberation option, including the virtual stereo.
    *
    * @deprecated Deprecated from v3.2.0. Use \ref setAudioEffectPreset  or
    * \ref setVoiceBeautifierPreset instead.
    *
    * This method sets the local voice reverberation for users in a `COMMUNICATION` channel or hosts in a `LIVE_BROADCASTING` channel.
    * After successfully calling this method, all users in the channel can hear the voice with reverberation.
    *
    * @note
    * - When calling this method with enumerations that begin with `AUDIO_REVERB_FX`, ensure that you set profile in `setAudioProfile` as
    * `AUDIO_PROFILE_MUSIC_HIGH_QUALITY(4)` or `AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO(5)`; otherwise, this methods cannot set the corresponding voice reverberation option.
    * - When calling this method with `AUDIO_VIRTUAL_STEREO`, Agora recommends setting the `profile` parameter in `setAudioProfile` as `AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO(5)`.
    * - This method works best with the human voice, and Agora does not recommend using it for audio containing music and a human voice.
    * - Do not use this method with `setLocalVoiceChanger`, because the method called later overrides the one called earlier.
    * For detailed considerations, see the advanced guide *Voice Changer and Reverberation*.
    * - You can call this method either before or after joining a channel.
    *
    * @param reverbPreset The local voice reverberation option. The default value is `AUDIO_REVERB_OFF`,
    * which means the original voice.  See #AUDIO_REVERB_PRESET.
    * To achieve better voice effects, Agora recommends the enumeration whose name begins with `AUDIO_REVERB_FX`.
    *
    * @return
    * - 0: Success.
    * - < 0: Failure.
    */
	int setLocalVoiceReverbPreset(agora::rtc::AUDIO_REVERB_PRESET reverbPreset);

   /**
   * @brief          Specifies an SDK output log file.
   * @brief          By default, the SDK outputs five log files, `agorasdk.log`, `agorasdk_1.log`, `agorasdk_2.log`, `agorasdk_3.log`, `agorasdk_4.log`, each with a default size of 1024 KB.
   * These log files are encoded in UTF-8. The SDK writes the latest logs in `agorasdk.log`. When `agorasdk.log` is full, the SDK deletes the log file with the earliest
   * modification time among the other four, renames `agorasdk.log` to the name of the deleted log file, and create a new `agorasdk.log` to record latest logs.
   * @note           Ensure that you call this method immediately after calling the \ref initialize method, otherwise the output log may not be complete.
   * @param filePath The absolute path of log files. The default file path is `C: \Users\<user_name>\AppData\Local\Agora\<process_name>\agorasdk.log`.
   * Ensure that the directory for the log files exists and is writable. You can use this parameter to rename the log files.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setLogFile(const char* filePath);

   /**
   * @brief          Sets the output log level of the SDK.
   * @brief          You can use one or a combination of the log filter levels. The log level follows the sequence of OFF, CRITICAL, ERROR, WARNING, INFO, and DEBUG. Choose a level to see the logs preceding that level.
   * @brief          If you set the log level to WARNING, you see the logs within levels CRITICAL, ERROR, and WARNING.
   * @param filter   Sets the log filter level. See \ref LOG_FILTER_TYPE.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setLogFilter(unsigned int filter);

   /**
   * @brief                   Sets the log file size (KB).
   *
   * @note If you want to set the log file size, ensure that you call
   * this method before \ref IRtcEngine::setLogFile "setLogFile", or the logs are cleared.
   *
   * By default, the SDK outputs five log files, `agorasdk.log`, `agorasdk_1.log`, `agorasdk_2.log`, `agorasdk_3.log`, `agorasdk_4.log`, each with a default size of 1024 KB.
   * These log files are encoded in UTF-8. The SDK writes the latest logs in `agorasdk.log`. When `agorasdk.log` is full, the SDK deletes the log file with the earliest
   * modification time among the other four, renames `agorasdk.log` to the name of the deleted log file, and create a new `agorasdk.log` to record latest logs.
   *
   * @param fileSizeInKBytes  The size (KB) of a log file. The default value is 1024 KB. If you set `fileSizeInKByte` to 1024 KB,
   * the SDK outputs at most 5 MB log files; if you set it to less than 1024 KB, the maximum size of a log file is still 1024 KB.
   * @return                  \arg  0: Success.
   *                          \arg  < 0: Failure.
   */
	int setLogFileSize(unsigned int fileSizeInKBytes);

   /**
   * @deprecated        This method is deprecated, use the \ref  AgoraRtcEngine::setLocalRenderMode( RENDER_MODE_TYPE renderMode, VIDEO_MIRROR_MODE_TYPE mirrorMode ) "setLocalRenderMode"2 method instead.
   * @brief             Sets the local video display mode.
   * @brief             This method can be called multiple times during a call to change the display mode.
   * @param renderMode  Sets the local video display mode. See \ref RENDER_MODE_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setLocalRenderMode(agora::rtc::RENDER_MODE_TYPE renderMode);

   /**
   * @brief             Updates the display mode of the local video view.
   *
   * After initializing the local video view, you can call this method to update its rendering and mirror modes. It affects only the video view that the local user sees, not the published local video stream.
   * @note
   * - Ensure that you have called the \ref setupLocalVideo method to initialize the local video view before calling this method.
   * - During a call, you can call this method as many times as necessary to update the display mode of the local video view.
   * @param renderMode  The rendering mode of the local video view. See \ref RENDER_MODE_TYPE.
   * @param mirrorMode  The mirror mode of the local video view. See  \ref VIDEO_MIRROR_MODE_TYPE.
                        If you use a front camera, the SDK enables the mirror mode by default; if you use a rear camera, the SDK disables the mirror mode by default.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
    int setLocalRenderMode( agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode );

   /**
   * @deprecated        This method is deprecated, use the \ref AgoraRtcEngine::setRemoteRenderMode(agora::rtc::uid_t userId, agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode) "setRemoteRenderMode"2 method instead.
   * @brief             Sets the video display mode of a specified remote user.
   * @brief             This method can be called multiple times during a call to change the display mode.
   * @param userId      ID of the remote user.
   * @param renderMode  Sets the video display mode. See \ref RENDER_MODE_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setRemoteRenderMode(agora::rtc::uid_t userId, agora::rtc::RENDER_MODE_TYPE renderMode);

   /**
   * @brief             Updates the display mode of the video view of a remote user.
   *
   * After initializing the video view of a remote user, you can call this method to update its rendering and mirror modes. This method affects only the video view that the local user sees.
   * @note
   * - Ensure that you have called the \ref setupRemoteVideo method to initialize the remote video view before calling this method.
   * - During a call, you can call this method as many times as necessary to update the display mode of the video view of a remote user.
   * @param userId      The ID of the remote user.
   * @param renderMode  The rendering mode of the remote video view. See \ref RENDER_MODE_TYPE.
   * @param mirrorMode  The mirror mode of the remote video view. See \ref VIDEO_MIRROR_MODE_TYPE. The SDK disables the mirror mode by default.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
   int setRemoteRenderMode( agora::rtc::uid_t userId, agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode );

   /**
   * @deprecated This method is deprecated, use the \ref AgoraRtcEngine::setupLocalVideo "setupLocalVideo" or \ref AgoraRtcEngine::setLocalRenderMode(agora::rtc::RENDER_MODE_TYPE renderMode, agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode) "setLocalRenderMode" method instead.
   * @brief             Sets the local video mirror mode.
   * @brief             You must call this method before calling the \ref startPreview method, otherwise the mirror mode will not work.
   * @note              The SDK enables the mirror mode by default.
   * @param mirrorMode  Sets the local video mirror mode. See \ref VIDEO_MIRROR_MODE_TYPE.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setLocalVideoMirrorMode(agora::rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode);

   /**
   * @brief          Sets the stream mode to the single-stream (default) or dual-stream mode. (Live broadcast only.)
   * @brief          If the dual-stream mode is enabled, the receiver can choose to receive the high stream (high-resolution and high-bitrate video stream), or the low stream (low-resolution and low-bitrate video stream).
   * @param enabled  Sets the stream mode:
   *                 \arg  true: Dual-stream mode.
   *                 \arg  false: (Default) Single-stream mode.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int enableDualStreamMode(bool enabled);

   /**
   * @brief             Sets the external audio source. Please call this method before \ref joinChannel.
   * @param enabled     Sets whether to enable/disable the external audio source:
   *                    \arg  true: Enables the external audio source.
   *                    \arg  false: (Default) Disables the external audio source.
   * @param sampleRate  Sets the sample rate (Hz) of the external audio source, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
   * @param channels    Sets the number of audio channels of the external audio source:
   *                    \arg  1: Mono.
   *                    \arg  2: Stereo.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setExternalAudioSource(bool enabled, int sampleRate, int channels);

   /**
   * @brief             Sets the external audio sink. This method applies to scenarios where you want to use external audio data for playback. After enabling the external audio sink, you can call the \ref agora::media::ue4::AgoraMediaEngine::pullAudioFrame "pullAudioFrame" method to pull the remote audio data, process it, and play it with the audio effects that you want.
   * @note              Once you enable the external audio sink, the app will not retrieve any audio data from the \ref agora::media::IAudioFrameObserver::onPlaybackAudioFrame "onPlaybackAudioFrame" callback.
   * @param enabled     \arg  true: Enables the external audio sink.
   *                    \arg  false: (Default) Disables the external audio sink.
   * @param sampleRate  Sets the sample rate (Hz) of the external audio sink, which can be set as 8000, 16000, 32000, 44100 or 48000.
   * @param channels    Sets the number of audio channels of the external audio sink:
   *                    \arg  1: Mono.
   *                    \arg  2: Stereo.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setExternalAudioSink(bool enabled, int sampleRate, int channels);

   /**
   * @brief                Sets the audio recording format for the \ref agora::media::IAudioFrameObserver::onRecordAudioFrame "onRecordAudioFrame" callback.
   * @param sampleRate     Sets the sample rate (`samplesPerSec`) returned in the `onRecordAudioFrame` callback, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
   * @param channel        Sets the number of audio channels (`channels`) returned in the `onRecordAudioFrame` callback:
   *                       \arg  1: Mono.
   *                       \arg  2: Stereo.
   * @param mode           Sets the use mode (see \ref RAW_AUDIO_FRAME_OP_MODE_TYPE) of the `onRecordAudioFrame` callback.
   * @param samplesPerCall Sets the sample points (`samples`) returned in the `onRecordAudioFrame` callback. `samplesPerCall` is usually set as 1024 for stream pushing.
   * @note The SDK triggers the `onRecordAudioFrame` callback according to the sample interval. Ensure that the sample interval ≥ 0.01 (s). And, Sample interval (sec) = `samplePerCall`/(`sampleRate` × `channel`).
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setRecordingAudioFrameParameters(
		int sampleRate, int channel, agora::rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall);

   /**
   * @brief                Sets the audio playback format for the \ref agora::media::IAudioFrameObserver::onPlaybackAudioFrame "onPlaybackAudioFrame" callback.
   * @param sampleRate     Sets the sample rate (`samplesPerSec`) returned in the `onPlaybackAudioFrame` callback, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
   * @param channel        Sets the number of channels (`channels`) returned in the `onPlaybackAudioFrame` callback:
   *                       \arg  1: Mono.
   *                       \arg  2: Stereo.
   * @param mode           Sets the use mode (see \ref RAW_AUDIO_FRAME_OP_MODE_TYPE) of the onPlaybackAudioFrame callback.
   * @param samplesPerCall Sets the sample points (`samples`) returned in the `onPlaybackAudioFrame` callback. `samplesPerCall` is usually set as 1024 for stream pushing.
   * @note The SDK triggers the `onPlaybackAudioFrame` callback according to the sample interval. Ensure that the sample interval ≥ 0.01 (s). And, Sample interval (sec) = `samplePerCall`/(`sampleRate` × `channel`).
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setPlaybackAudioFrameParameters(
		int sampleRate, int channel, agora::rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall);

   /**
   * @brief                Sets the mixed audio format for the \ref agora::media::IAudioFrameObserver::onMixedAudioFrame "onMixedAudioFrame" callback.
   * @param sampleRate     Sets the sample rate (`samplesPerSec`) returned in the `onMixedAudioFrame` callback, which can be set as 8000, 16000, 32000, 44100, or 48000 Hz.
   * @param samplesPerCall Sets the sample points (`samples`) returned in the `onMixedAudioFrame` callback. samplesPerCall is usually set as 1024 for stream pushing.
   * @note The SDK triggers the `onMixedAudioFrame` callback according to the sample interval. Ensure that the sample interval ≥ 0.01 (s). And, Sample interval (sec) = `samplePerCall`/(`sampleRate` × `channels`).
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);

   /**
   * @brief          Adjusts the recording volume.
   * @note You can call this method either before or after joining a channel.
   * @param volume   Recording volume. To avoid echoes and
   *  improve call quality, Agora recommends setting the value of volume between
   *  0 and 100. If you need to set the value higher than 100, contact
   *  support@agora.io first.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int adjustRecordingSignalVolume(int volume);

   /**
   * @brief          Adjusts the playback volume of the voice.
   * @note
   * - This method adjusts the playback volume that is the mixed volume of all remote users.
   * - You can call this method either before or after joining a channel.
   * - To mute the local audio playback, call both the `adjustPlaybackSignalVolume` and \ref adjustAudioMixingVolume methods and set the volume as `0`.
   * @param volume   The playback volume of the voice. To avoid echoes and
   * improve call quality, Agora recommends setting the value of volume between
   *  0 and 100. If you need to set the value higher than 100, contact support@agora.io first.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int adjustPlaybackSignalVolume(int volume);

   /**
   * @deprecated This method is deprecated. The Native SDK automatically enables interoperability with the Web SDK, so you no longer need to call this method.
   * @brief          Enables interoperability with the Agora Web SDK.
   * @note           \arg  This method applies only to the Live-broadcast profile. In the Communication profile, interoperability with the Agora Web SDK is enabled by default.
   *                 \arg  If the channel has Web SDK users, ensure that you call this method, or the video of the Native user will be a black screen for the Web user.
   * @param enabled  Sets whether to enable/disable interoperability with the Agora Web SDK:
   *                 \arg  true: Enable.
   *                 \arg  false: (Default) Disable.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int enableWebSdkInteroperability(bool enabled);

   /**
   * @brief          Sets the fallback option for the locally published video stream based on the network conditions.
   * @brief          If *option* is set as `STREAM_FALLBACK_OPTION_AUDIO_ONLY(2)`, the SDK will:
   *                 \arg  Disable the upstream video but enable audio only when the network conditions deteriorate and cannot support both video and audio.
   *                 \arg  Re-enable the video when the network conditions improve.
   * @brief          When the locally published video stream falls back to audio only or when the audio-only stream switches back to the video, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onLocalPublishFallbackToAudioOnly "onLocalPublishFallbackToAudioOnly" callback.
   * @note
   * - Agora does not recommend using this method for CDN live streaming, because the remote CDN live user will have a noticeable lag when the locally published video stream falls back to audio only.
   * - Ensure that you call this method before joining a channel.
   * @param option   Sets the fallback option for the locally published video stream:
   *                 \arg  \ref STREAM_FALLBACK_OPTION_DISABLED (0): (Default) No fallback behavior for the locally published video stream when the uplink network condition is poor. The stream quality is not guaranteed.
   *                 \arg  \ref STREAM_FALLBACK_OPTION_AUDIO_ONLY (2): The locally published video stream falls back to audio only when the uplink network condition is poor.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setLocalPublishFallbackOption(agora::rtc::STREAM_FALLBACK_OPTIONS option);

   /**
   * @brief          Sets the fallback option for the remotely subscribed video stream based on the network conditions.
   * @brief          The default setting for @p option is \ref STREAM_FALLBACK_OPTION_VIDEO_STREAM_LOW, where the remotely subscribed video stream falls back to the low-stream video (low resolution and low bitrate) under poor downlink network conditions.
   * @brief          If *option* is set as \ref STREAM_FALLBACK_OPTION_AUDIO_ONLY, the SDK automatically switches the video from a high-stream to a low-stream, or disables the video when the downlink network conditions cannot support both audio and video to guarantee the quality of the audio. The SDK monitors the network quality and restores the video stream when the network conditions improve.
   * @brief          When the remotely subscribed video stream falls back to audio only or when the audio-only stream switches back to the video stream, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onRemoteSubscribeFallbackToAudioOnly "onRemoteSubscribeFallbackToAudioOnly" callback.
   * @note Ensure that you call this method before joining a channel.
   * @param  option  Sets the fallback option for the remotely subscribed video stream. See \ref STREAM_FALLBACK_OPTIONS.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setRemoteSubscribeFallbackOption(agora::rtc::STREAM_FALLBACK_OPTIONS option);

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
   /**
   * @brief    Switches between front and rear cameras.
   * @note     This method is for Android and iOS only.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int switchCamera();

   /**
   * @brief             Switches between front and rear cameras.
   * @note              This method is for Android and iOS only.
   * @param direction   Sets the camera to be used:
   *                    \arg  CAMERA_DIRECTION.CAMERA_REAR: Use the rear camera.
   *                    \arg  CAMERA_DIRECTION.CAMERA_FRONT: Use the front camera.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int switchCamera(CAMERA_DIRECTION direction);

   /**
   * @brief                   Sets the default audio playback route.
   * @brief                   This method sets whether the received audio is routed to the earpiece or speakerphone by default before joining a channel. If a user does not call this method, the audio is routed to the earpiece by default. If you need to change the default audio route after joining a channel, call the  \ref setEnableSpeakerphone method.
   *
   * The default setting for each profile:
   * - `COMMUNICATION`: In a voice call, the default audio route is the earpiece. In a video call, the default audio route is the speakerphone.
   * - `LIVE_BROADCASTING`: Speakerphone.
   *
   * @note                    \arg  This method is for Android and iOS only.
   *                          \arg  Call this method before calling the \ref joinChannel method.
   *                          \arg  Regardless of whether the audio is routed to the speakerphone or earpiece by default, once a headset is plugged in or Bluetooth device is connected, the default audio route changes. The default audio route switches to the earpiece once removing the headset or disconnecting the Bluetooth device.
   * @param defaultToSpeaker  Sets the default audio route:
   *                          -  true: Route the audio to the speakerphone. If the playback device connects to the earpiece or Bluetooth, the audio cannot be routed to the speakerphone.
   *                          -  false: (Default) Route the audio to the earpiece. If a headset is plugged in, the audio is routed to the headset.
   * @return                  \arg  0: Success.
   *                          \arg  < 0: Failure.
   */
	int setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker);

   /** Enables/Disables the audio playback route to the speakerphone.

    This method sets whether the audio is routed to the speakerphone or earpiece.

    See the default audio route explanation in the \ref setDefaultAudioRouteToSpeakerphone method and check whether it is necessary to call this method.

    @note
    - This method is for Android and iOS only.
    - Ensure that you have successfully called the \ref joinChannel method before calling this method.
    - After calling this method, the SDK returns the \ref IRtcEngineEventHandler::onAudioRouteChanged "onAudioRouteChanged" callback to indicate the changes.
    - This method does not take effect if a headset is used.
    - Settings of \ref setAudioProfile and \ref setChannelProfile affect the call
    result of `setEnableSpeakerphone`. The following are scenarios where `setEnableSpeakerphone` does not take effect:
    - If you set `scenario` as `AUDIO_SCENARIO_GAME_STREAMING`, no user can change the audio playback route.
    - If you set `scenario` as `AUDIO_SCENARIO_DEFAULT` or `AUDIO_SCENARIO_SHOWROOM`, the audience cannot change
    the audio playback route. If there is only one broadcaster is in the channel, the broadcaster cannot change
    the audio playback route either.
    - If you set `scenario` as `AUDIO_SCENARIO_EDUCATION`, the audience cannot change the audio playback route.

    @param speakerOn Sets whether to route the audio to the speakerphone or earpiece:
    - true: Route the audio to the speakerphone. If the playback device connects to the earpiece or Bluetooth, the audio cannot be routed to the speakerphone.
    - false: Route the audio to the earpiece. If a headset is plugged in, the audio is routed to the headset.

    @return
    - 0: Success.
    - < 0: Failure.
    */
	int setEnableSpeakerphone(bool speakerOn);

   /**
   * @brief          Sets the volume of the in-ear monitor.
   *
   * @note
   * - This method is for Android and iOS only.
   * - Users must use wired earphones to hear their own voices.
   * - You can call this method either before or after joining a channel.
   * @param volume   Sets the volume of the in-ear monitor. The value ranges between 0 and 100 (default).
   * @note           This method is for Android and iOS only.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setInEarMonitoringVolume(int volume);

   /**
   * @brief          Checks whether the speakerphone is enabled.
   * @note
   * - This method is for Android and iOS only.
   * - You can call this method either before or after joining a channel.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	bool isSpeakerphoneEnabled();
#endif
    
#if defined(__ANDROID__)
   /**
    * @brief         Enables/Disables face detection for the local user. Applies to Android and iOS only.
    * @brief         Once face detection is enabled, the SDK triggers the \ref IRtcEngineEventHandler::onFacePositionChanged "onFacePositionChanged" callback
    * @brief         to report the face information of the local user, which includes the following aspects:
    * @brief            - The width and height of the local video.
    * @brief            - The position of the human face in the local video.
    * @brief            - The distance between the human face and the device screen.
    * @param         enable Determines whether to enable the face detection function for the local user:
    *                   - true: Enable face detection.
    *                   - false: (Default) Disable face detection.
    * @return         \arg  0: Success.
    *                 \arg  < 0: Failure.
    */
   int enableFaceDetection( bool enable );
    
#endif

#if (defined(__APPLE__) && TARGET_OS_IOS)
   /**
   * @brief             Sets the audio session’s operational restriction.
   * @brief             The SDK and the app can both configure the audio session by default. The app may occasionally use other apps or third-party components to manipulate the audio session and restrict the SDK from doing so. This method allows the app to restrict the SDK’s manipulation of the audio session.
   * @brief             You can call this method at any time to return the control of the audio sessions to the SDK.
   * @note              \arg  This method is for iOS only.
   *                    \arg  This method restricts the SDK’s manipulation of the audio session. Any operation to the audio session relies solely on the app, other apps, or third-party components.
   * @param restriction The operational restriction (bit mask) of the SDK on the audio session. See \ref AUDIO_SESSION_OPERATION_RESTRICTION.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setAudioSessionOperationRestriction(AUDIO_SESSION_OPERATION_RESTRICTION restriction);
#endif

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) || defined(_WIN32)
   /**
   * @brief             Enables loopback recording.
   * @brief             If you enable loopback recording, the output of the sound card is mixed into the audio stream sent to the other end.
   * @param enabled     Sets whether to enable/disable loopback recording.
   *                    -  true: Enable loopback recording.
   *                    -  false: (Default) Disable loopback recording.
   * @param deviceName  Pointer to the device name of the sound card. The default value is NULL (the default sound card).
   * @note              \arg  This method is for macOS and Windows only.
   *                    \arg  macOS does not support loopback recording of the default sound card. If you need to use this method, please use a virtual sound card and pass its name to the deviceName parameter. Agora has tested and recommends using soundflower.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int enableLoopbackRecording(bool enabled, const char* deviceName = nullptr);
#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
   /**
   * @brief                Shares the whole or part of a screen by specifying the display ID.
   * @note                 This method is for macOS only.
   * @param displayId      The display ID of the screen to be shared. This parameter specifies which screen you want to share.
   * @param regionRect     (Optional) Sets the relative location of the region to the screen. NIL means sharing the whole screen. See \ref Rectangle. If the specified region overruns the screen, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole screen.
   * @param captureParams  Sets the screen sharing encoding parameters. The default video dimension is 1920 x 1080, that is, 2,073,600 pixels. Agora uses the value of `videoDimension` to calculate the charges.
   * For details, see descriptions in ScreenCaptureParameters.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   *                          -  `ERR_INVALID_ARGUMENT`: the argument is invalid.
   */
	int startScreenCaptureByDisplayId(
		unsigned int displayId,
		const Rectangle& regionRect,
		const ScreenCaptureParameters& captureParams);
#endif

#if defined(_WIN32)
   /**
   * @brief                Shares the whole or part of a screen by specifying the screen rect.
   * @param screenRect     Sets the relative location of the screen to the virtual screen. For information on how to get screenRect, see Share the Screen.
   * @param regionRect     (Optional) Sets the relative location of the region to the screen. NULL means sharing the whole screen. See \ref Rectangle. If the specified region overruns the screen, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole screen.
   * @param captureParams  Sets the screen sharing encoding parameters. The default video dimension is 1920 x 1080, that is, 2,073,600 pixels.
   * Agora uses the value of `videoDimension` to calculate the charges. For details, see descriptions in ScreenCaptureParameters.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   *                          -  #ERR_INVALID_ARGUMENT: the argument is invalid.
   */
	int startScreenCaptureByScreenRect(
		const Rectangle& screenRect,
		const Rectangle& regionRect,
		const ScreenCaptureParameters& captureParams);
#endif

   /**
   * @brief                Shares the whole or part of a window by specifying the window ID.
   * @brief                Since v3.0.0, this method supports sharing with common Windows platforms. Agora tests the mainstream Windows applications, see details as follows:
     <table>
         <tr>
             <td><b>OS version</b></td>
             <td><b>Software</b></td>
             <td><b>Software name</b></td>
             <td><b>Whether support</b></td>
         </tr>
         <tr>
             <td rowspan="8">win10</td>
             <td >Chrome</td>
             <td>76.0.3809.100</td>
             <td>No</td>
         </tr>
         <tr>
             <td>Office Word</td>
             <td rowspan="3">18.1903.1152.0</td>
             <td>Yes</td>
         </tr>
          <tr>
             <td>Office Excel</td>
             <td>No</td>
         </tr>
         <tr>
             <td>Office PPT</td>
             <td>No</td>
         </tr>
      <tr>
             <td>WPS Word</td>
             <td rowspan="3">11.1.0.9145</td>
             <td rowspan="3">Yes</td>
         </tr>
          <tr>
             <td>WPS Excel</td>
         </tr>
         <tr>
             <td>WPS PPT</td>
         </tr>
          <tr>
             <td>Media Player (come with the system)</td>
             <td>All</td>
             <td>Yes</td>
         </tr>
       <tr>
             <td rowspan="8">win8</td>
             <td >Chrome</td>
             <td>All</td>
             <td>Yes</td>
         </tr>
         <tr>
             <td>Office Word</td>
             <td rowspan="3">All</td>
             <td rowspan="3">Yes</td>
         </tr>
          <tr>
             <td>Office Excel</td>
         </tr>
         <tr>
             <td>Office PPT</td>
         </tr>
      <tr>
             <td>WPS Word</td>
             <td rowspan="3">11.1.0.9098</td>
             <td rowspan="3">Yes</td>
         </tr>
          <tr>
             <td>WPS Excel</td>
         </tr>
         <tr>
             <td>WPS PPT</td>
         </tr>
          <tr>
             <td>Media Player(come with the system)</td>
             <td>All</td>
             <td>Yes</td>
         </tr>
       <tr>
             <td rowspan="8">win7</td>
             <td >Chrome</td>
             <td>73.0.3683.103</td>
             <td>No</td>
         </tr>
         <tr>
             <td>Office Word</td>
             <td rowspan="3">All</td>
             <td rowspan="3">Yes</td>
         </tr>
          <tr>
             <td>Office Excel</td>
         </tr>
         <tr>
             <td>Office PPT</td>
         </tr>
      <tr>
             <td>WPS Word</td>
             <td rowspan="3">11.1.0.9098</td>
             <td rowspan="3">No</td>
         </tr>
          <tr>
             <td>WPS Excel</td>
         </tr>
         <tr>
             <td>WPS PPT</td>
         </tr>
          <tr>
             <td>Media Player(come with the system)</td>
             <td>All</td>
             <td>No</td>
         </tr>
     </table>
   * @param windowId       The ID of the window to be shared. For information on how to get the windowId, see Share the Screen.
   * @param regionRect     (Optional) The relative location of the region to the window. NULL/NIL means sharing the whole window. See \ref Rectangle. If the specified region overruns the window, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole window.
   * @param captureParams  Window sharing encoding parameters. The default video dimension is 1920 x 1080, that is, 2,073,600 pixels.
   * Agora uses the value of `videoDimension` to calculate the charges. For details, see descriptions in ScreenCaptureParameters.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   *                          -  #ERR_INVALID_ARGUMENT: the argument is invalid.
   */
	int startScreenCaptureByWindowId(
		view_t windowId,
		const Rectangle& regionRect,
		const ScreenCaptureParameters& captureParams);

   /**
   * @brief             Sets the content hint for screen sharing.
   * @brief             A content hint suggests the type of the content being shared, so that the SDK applies different optimization algorithm to different types of content.
   * @param contentHint Sets the content hint for screen sharing. See VideoContentHint.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setScreenCaptureContentHint(VideoContentHint contentHint);

   /**
   * @brief                Updates the screen sharing parameters.
   * @param captureParams  Sets the screen sharing encoding parameters. See \ref ScreenCaptureParameters.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   *                          -  #ERR_NOT_READY: no screen or windows is being shared.
   */
	int updateScreenCaptureParameters(const ScreenCaptureParameters& captureParams);

   /**
   * @brief             Updates the screen sharing region.
   * @param regionRect  Sets the relative location of the region to the screen or window. NULL means sharing the whole screen or window. See \ref Rectangle. If the specified region overruns the screen or window, the SDK shares only the region within it; if you set width or height as 0, the SDK shares the whole screen or window.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   *                          -  #ERR_NOT_READY: no screen or window is being shared.
   */
	int updateScreenCaptureRegion(const Rectangle& regionRect);

   /**
   * @brief    Stop screen sharing.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int stopScreenCapture();

#endif

   /**
   * @brief          Retrieves the current call ID.
   * @brief          When a user joins a channel on a client, a *callId* is generated to identify the call from the client. Feedback methods, such as \ref rate and \ref complain, must be called after the call ends to submit feedback to the SDK.
   * @brief          The \ref rate and \ref complain methods require the *callId* parameter retrieved from the \a getCallId method during a call. *callId* is passed as an argument into the \ref rate and \ref complain methods after the call ends.
   * @note Ensure that you call this method after joining a channel.
   * @param callId   Pointer to the current call ID.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int getCallId(agora::util::AString& callId);

   /**
   * @brief             Allows a user to rate a call after the call ends.
   * @note Ensure that you call this method after joining a channel.
   * @param callId      Pointer to the ID of the call, retrieved from the \ref getCallId method.
   * @param rating      Rating of the call. The value is between 1 (lowest score) and 5 (highest score). If you set a value out of this range, the \ref ERR_INVALID_ARGUMENT (2) error returns.
   * @param description (Optional) Pointer to the description of the rating, with a string length of less than 800 bytes.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int rate(const char* callId, int rating, const char* description);

   /**
   * @brief             Allows a user to complain about the call quality after a call ends.
   * @note Ensure that you call this method after joining a channel.
   * @param callId      Pointer to the ID of the call, retrieved from the \ref getCallId method.
   * @param description (Optional) Pointer to the description of the complaint, with a string length of less than 800 bytes.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int complain(const char* callId, const char* description);

   /**
   * @brief       Retrieves the SDK version number.
   * @param build Pointer to the build number.
   * @return      The version of the current SDK in the string format. For example, 2.3.1.
   */
	const char* getVersion(int* build);

   /**
   * @brief    Enables the network connection quality test.
   * @brief    This method tests the quality of the users' network connections and is disabled by default.
   * @brief    Before a user joins a channel or before an audience switches to a host, call this method to check the uplink network quality.
   * @brief    This method consumes additional network traffic, and hence may affect communication quality.
   * @brief    Call the \ref disableLastmileTest method to disable this test after receiving the \ref agora::rtc::IRtcEngineEventHandler::onLastmileQuality "onLastmileQuality" callback, and before joining a channel.
   * @note     \arg  Do not call any other methods before receiving the onLastmileQuality callback. Otherwise, the callback may be interrupted by other methods, and hence may not be triggered.
   *           \arg  A host should not call this method after joining a channel (when in a call).
   *           \arg  If you call this method to test the last-mile quality, the SDK consumes the bandwidth of a video stream, whose bitrate corresponds to the bitrate you set in the setVideoEncoderConfiguration method. After you join the channel, whether you have called the disableLastmileTest method or not, the SDK automatically stops consuming the bandwidth.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int enableLastmileTest();

   /**
   * @brief    Disables the network connection quality test.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int disableLastmileTest();

   /**
   * @brief          Starts the last-mile network probe test.
   * @brief          This method starts the last-mile network probe test before joining a channel to get the uplink and downlink last-mile network statistics, including the bandwidth, packet loss, jitter, and round-trip time (RTT).
   * @brief          Call this method to check the uplink network quality before users join a channel or before an audience switches to a host. Once this method is enabled, the SDK returns the following callbacks:
   *                 <ul>
   *                 <li> \ref agora::rtc::IRtcEngineEventHandler::onLastmileQuality "onLastmileQuality": the SDK triggers this callback within two seconds depending on the network conditions. This callback rates the network conditions and is more closely linked to the user experience.
   *                 <li> \ref agora::rtc::IRtcEngineEventHandler::onLastmileProbeResult "onLastmileProbeResult": the SDK triggers this callback within 30 seconds depending on the network conditions. This callback returns the real-time statistics of the network conditions and is more objective.
   *                 </ul>
   * @note           \arg  This method consumes extra network traffic and may affect communication quality. We do not recommend calling this method together with enableLastmileTest.
   *                 \arg  Do not call other methods before receiving the `onLastmileQuality` and `onLastmileProbeResult` callbacks. Otherwise, the callbacks may be interrupted.
   *                 \arg  In the Live-broadcast profile, a host should not call this method after joining a channel.
   * @param config   Sets the configurations of the last-mile network probe test. See \ref LastmileProbeConfig.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int startLastmileProbeTest(const LastmileProbeConfig& config);

   /**
   * @brief    Stops the last-mile network probe test.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int stopLastmileProbeTest();

   /**
   * @brief    Retrieves the warning or error description.
   * @return   code \ref WARN_CODE_TYPE or \ref ERROR_CODE_TYPE returned in the \ref agora::rtc::IRtcEngineEventHandler::onWarning "onWarning" or \ref agora::rtc::IRtcEngineEventHandler::onError "onError" callback.
   */
	const char* getErrorDescription(int code);

   /**
   * @brief          Enables built-in encryption with an encryption password before users join a channel.
   * @brief          All users in a channel must use the same encryption password. The encryption password is automatically cleared once a user leaves the channel.
   * @brief          If an encryption password is not specified, the encryption functionality will be disabled.
   * @note           \arg  Do not use this method for CDN live streaming.
   *                 \arg  For optimal transmission, ensure that the encrypted data size does not exceed the original data size + 16 bytes. 16 bytes is the maximum padding size for AES encryption.
   * @param secret   Pointer to the encryption password.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int setEncryptionSecret(const char* secret);

   /**
   * @brief                Sets the built-in encryption mode.
   * @brief                The Agora SDK supports built-in encryption, which is set to the *aes-128-xts* mode by default. Call this method to use other encryption modes.
   * @brief                All users in the same channel must use the same encryption mode and password.
   * @brief                Refer to the information related to the AES encryption algorithm on the differences between the encryption modes.
   * @note                 Call the setEncryptionSecret method to enable the built-in encryption function before calling this method.
   * @param encryptionMode \arg  Pointer to the set encryption mode:
   *                       \arg  "aes-128-xts": (Default) 128-bit AES encryption, XTS mode.
   *                       \arg  "aes-128-ecb": 128-bit AES encryption, ECB mode.
   *                       \arg  "aes-256-xts": 256-bit AES encryption, XTS mode.
   *                       \arg  "": When encryptionMode is set as NULL, the encryption mode is set as "aes-128-xts" by default.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int setEncryptionMode(const char* encryptionMode);

   /**
   * @brief          Registers a packet observer.
   * @brief          The Agora SDK allows your application to register a packet observer to receive callbacks for voice or video packet transmission.
   * @note           \arg  The size of the packet sent to the network after processing should not exceed 1200 bytes, otherwise, the packet may fail to be sent.
   *                 \arg  Ensure that both receivers and senders call this method, otherwise, you may meet undefined behaviors such as no voice and black screen.
   *                 \arg  When you use CDN live streaming, recording or storage functions, Agora doesn't recommend calling this method.
   *                 \arg  Call this method before joining a channel.
   * @param observer Pointer to the registered packet observer. See \ref IPacketObserver.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int registerPacketObserver(IPacketObserver* observer);

   /**
   * @brief          Creates a data stream.
   * @brief          Each user can create up to five data streams during the lifecycle of the RtcEngine.
   * @note
   * - Set both the reliable and ordered parameters to true or false. Do not set one as true and the other as false.
   * - Ensure that you call this method after joining a channel.
   * @param streamId Pointer to the ID of the created data stream.
   * @param reliable Sets whether or not the recipients are guaranteed to receive the data stream from the sender within five seconds:
   *                 -  true: The recipients receive the data stream from the sender within five seconds. If the recipient does not receive the data stream within five seconds, an error is reported to the application.
   *                 -  false: There is no guarantee that the recipients receive the data stream within five seconds and no error message is reported for any delay or missing data stream.
   * @param ordered  Sets whether or not the recipients receive the data stream in the sent order:
   *                 -  true: The recipients receive the data stream in the sent order.
   *                 -  false: The recipients do not receive the data stream in the sent order.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int createDataStream(int* streamId, bool reliable, bool ordered);

   /**
   * @brief          Sends data stream messages to all users in a channel.
   * @brief          The SDK has the following restrictions on this method:
   *                 -  Up to 30 packets can be sent per second in a channel with each packet having a maximum size of 1 kB.
   *                 -  Each client can send up to 6 kB of data per second.
   *                 -  Each user can have up to five data streams simultaneously.
   * @brief          A successful \ref sendStreamMessage method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onStreamMessage "onStreamMessage" callback on the remote client, from which the remote user gets the stream message.
   * @brief          A failed \ref sendStreamMessage method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onStreamMessage "onStreamMessage" callback on the remote client.
   * @note           This method applies only to the Communication profile or to the hosts in the Live-broadcast profile. If an audience in the Live-broadcast profile calls this method, the audience may be switched to a host.
   * @param streamId ID of the sent data stream, returned in the \ref createDataStream method.
   * @param data     Pointer to the sent data.
   * @param length   Length of the sent data.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int sendStreamMessage(int streamId, const char* data, size_t length);

   /**
   * @brief                      Publishes the local stream to a specified CDN live RTMP address. (CDN live only.)
   * @brief                      The SDK returns the result of this method call in the \ref agora::rtc::IRtcEngineEventHandler::onStreamPublished "onStreamPublished" callback.
   * @brief                      The *addPublishStreamUrl* method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onRtmpStreamingStateChanged "onRtmpStreamingStateChanged" callback on the local client to report the state of adding a local stream to the CDN.
   * @note                       \arg  Ensure that the user joins the channel before calling this method.
   *                             \arg  Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
   *                             \arg  This method adds only one stream RTMP URL address each time it is called.
   *                             \arg  This method applies to Live Broadcast only.
   * @param url                  The CDN streaming URL in the RTMP format. The maximum length of this parameter is 1024 bytes. The RTMP URL address must not contain special characters, such as Chinese language characters.
   * @param transcodingEnabled   Sets whether transcoding is enabled/disabled:
   *                             true: Enable transcoding, to transcode the audio or video streams when publishing them to CDN live, often used for combining the audio and video streams of multiple hosts in CDN live. If you set this parameter as true, ensure that you call the \ref setLiveTranscoding method before this method.
   *                             false: Disable transcoding.
   * @return                     \arg  0: Success.
   *                             \arg  < 0: Failure.
   *                                - \ref ERR_INVALID_ARGUMENT (2): The RTMP URL address is NULL or has a string length of 0.
   *                                - \ref ERR_NOT_INITIALIZED (7): You have not initialized the RTC engine when publishing the stream.
   */
	int addPublishStreamUrl(const char* url, bool transcodingEnabled);

   /**
   * @brief       Removes an RTMP stream from the CDN. (CDN live only.)
   * @brief       This method removes the RTMP URL address (added by the \ref addPublishStreamUrl method) from a CDN live stream. The SDK returns the result of this method call in the \ref agora::rtc::IRtcEngineEventHandler::onStreamUnpublished "onStreamUnpublished" callback.
   * @brief       The \ref removePublishStreamUrl method call triggers the \ref agora::rtc::IRtcEngineEventHandler::onRtmpStreamingStateChanged "onRtmpStreamingStateChanged" callback on the local client to report the state of removing an RTMP stream from the CDN.
   * @note        \arg  This method removes only one RTMP URL address each time it is called.
   *              \arg  The RTMP URL address must not contain special characters, such as Chinese language characters.
   *              \arg  This method applies to Live Broadcast only.
   * @param url   The RTMP URL address to be removed. The maximum length of this parameter is 1024 bytes.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int removePublishStreamUrl(const char* url);

   /**
   * @brief             Sets the video layout and audio settings for CDN live. (CDN live only.)
   * @brief             The SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onTranscodingUpdated "onTranscodingUpdated" callback when you call the `setLiveTranscoding` method to update the transcoding setting.
   * @note              \arg  This method applies to Live Broadcast only.
   *                    \arg  Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Push Streams to CDN*.
   *                    \arg  If you call the `setLiveTranscoding` method to update the transcoding setting for the first time, the SDK does not trigger the `onTranscodingUpdated` callback.
   *                    \arg  Ensure that you call this method after joining a channel.
   *                    \arg  Agora supports pushing media streams in RTMPS protocol to the CDN only when you enable transcoding.
   * @param transcoding Sets the CDN live audio/video transcoding settings. See \ref LiveTranscoding.
   * @return            \arg  0: Success.
   *                    \arg  < 0: Failure.
   */
	int setLiveTranscoding(const LiveTranscoding& transcoding);

   /**
   * @brief                Adds a watermark image to the local video.
   * @brief                This method adds a PNG watermark image to the local video in a live broadcast. Once the watermark image is added, all the audience in the channel (CDN audience included), and the recording device can see and capture it. Agora supports adding only one watermark image onto the local video, and the newly watermark image replaces the previous one.
   * @brief                The watermark position depends on the settings in the \ref setVideoEncoderConfiguration method:
   *                       <ul>
   *                       <li> If the orientation mode of the encoding video is \ref ORIENTATION_MODE_FIXED_LANDSCAPE, or the landscape mode in \ref ORIENTATION_MODE_ADAPTIVE, the watermark uses the landscape orientation.
   *                       <li> If the orientation mode of the encoding video is \ref ORIENTATION_MODE_FIXED_PORTRAIT, or the portrait mode in \ref ORIENTATION_MODE_ADAPTIVE, the watermark uses the portrait orientation.
   *                       <li> When setting the watermark position, the region must be less than the dimensions set in the *setVideoEncoderConfiguration* method. Otherwise, the watermark image will be cropped.
   *                       </ul>
   * @note                 \arg  Ensure that you have called the \ref enableVideo method to enable the video module before calling this method.
   *                       \arg  If you only want to add a watermark image to the local video for the audience in the CDN live broadcast channel to see and capture, you can call this method or the \ref setLiveTranscoding method.
   *                       \arg  This method supports adding a watermark image in the PNG file format only. Supported pixel formats of the PNG image are RGBA, RGB, Palette, Gray, and Alpha_gray.
   *                       \arg  If the dimensions of the PNG image differ from your settings in this method, the image will be cropped or zoomed to conform to your settings.
   *                       \arg  If you have enabled the local video preview by calling the \ref startPreview method, you can use the *visibleInPreview* member in the \ref WatermarkOptions class to set whether or not the watermark is visible in preview.
   *                       \arg  If you have mirrored the local video by calling the \ref setLocalVideoMirrorMode method, the watermark image in preview is also mirrored.
   * @param watermarkUrl   The local file path of the watermark image to be added. This method supports adding a watermark image from the local absolute or relative file path.
   * @param options        Pointer to the watermark's options to be added. See \ref WatermarkOptions for more infomation.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int addVideoWatermark(const char* watermarkUrl, const WatermarkOptions& options);

   /**
   * @brief    Removes the watermark image from the video stream added by the \ref addVideoWatermark method.
   * @return   \arg  0: Success.
   *           \arg  < 0: Failure.
   */
	int clearVideoWatermarks();

   /**
   * @brief          Enables/Disables image enhancement and sets the options.
   * @note Call this method after calling the \ref enableVideo method.
   * @param enabled  Sets whether or not to enable image enhancement:
   *                 -  true: enables image enhancement.
   *                 -  false: disables image enhancement.
   * @param options  Sets the image enhancement option. See \ref BeautyOptions.
   */
	int setBeautyEffectOptions(bool enabled, BeautyOptions options);

   /**
   * @brief          Adds a voice or video stream URL address to a live broadcast.
   * @brief          The \ref agora::rtc::IRtcEngineEventHandler::onStreamPublished "onStreamPublished" callback returns the inject status. If this method call is successful, the server pulls the voice or video stream and injects it into a live channel. This is applicable to scenarios where all audience members in the channel can watch a live show and interact with each other.
   * @brief          The `addInjectStreamUrl` method call triggers the following callbacks:
   *                 <ul>
   *                 <li> The local client:
   *                    <ul>
   *                    <li> \ref agora::rtc::IRtcEngineEventHandler::onStreamInjectedStatus "onStreamInjectedStatus", with the state of the injecting the online stream.
   *                    <li> \ref agora::rtc::IRtcEngineEventHandler::onUserJoined "onUserJoined" (uid: 666), if the method call is successful and the online media stream is injected into the channel.
   *                    </ul>
   *                 <li> The remote client:
   *                    <ul>
   *                    <li> onUserJoined (uid: 666), if the method call is successful and the online media stream is injected into the channel.
   *                    </ul>
   *                 </ul>
   * @note           \arg  Ensure that you enable the RTMP Converter service before using this function. See Prerequisites in the advanced guide *Inject Online Media Streams.
   *                 \arg  This method applies to the `LIVE_BROADCASTING` profile only.
   *                 \arg You can inject only one media stream into the channel at the same time.
   *                 \arg Ensure that you call this method after joining a channel.
   * @param url      Pointer to the URL address to be added to the ongoing live broadcast. Valid protocols are RTMP, HLS, and FLV.
   *                    \arg  Supported FLV audio codec type: AAC.
   *                    \arg  Supported FLV video codec type: H264 (AVC).
   * @param config   Pointer to the InjectStreamConfig object that contains the configuration of the added voice or video stream.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   *                    -  \ref ERR_INVALID_ARGUMENT (2): The injected URL does not exist. Call this method again to inject the stream and ensure that the URL is valid.
   *                    -  \ref ERR_NOT_READY (3): The user is not in the channel.
   *                    -  \ref ERR_NOT_SUPPORTED (4): The channel profile is not live broadcast. Call the \ref setChannelProfile method and set the channel profile to live broadcast before calling this method.
   *                    -  \ref ERR_NOT_INITIALIZED (7): The SDK is not initialized. Ensure that the \ref IRtcEngine object is initialized before calling this method.
   */
	int addInjectStreamUrl(const char* url, const InjectStreamConfig& config);

   /**
   * @brief                Starts to relay media streams across channels.
   * @brief                After a successful method call, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onChannelMediaRelayStateChanged "onChannelMediaRelayStateChanged" and \ref agora::rtc::IRtcEngineEventHandler::onChannelMediaRelayEvent "onChannelMediaRelayEvent" callbacks, and these callbacks return the state and events of the media stream relay.
   *                       <ul>
   *                       <li> If the `onChannelMediaRelayStateChanged` callback returns \ref RELAY_STATE_RUNNING (2) and \ref RELAY_OK (0), and the `onChannelMediaRelayEvent` callback returns \ref RELAY_EVENT_PACKET_SENT_TO_DEST_CHANNEL (4), the broadcaster starts sending data to the destination channel.
   *                       <li> If the `onChannelMediaRelayStateChanged` callback returns \ref RELAY_STATE_FAILURE (3), an exception occurs during the media stream relay.
   *                       </ul>
   * @note                 \arg  Call this method after the \ref joinChannel method.
   *                       \arg  This method takes effect only when you are a broadcaster in a Live-broadcast channel.
   *                       \arg  After a successful method call, if you want to call this method again, ensure that you call the \ref stopChannelMediaRelay method to quit the current relay.
   *                       \arg  Contact sales-us@agora.io before implementing this function.
   *                       \arg We do not support string user accounts in this API.
   * @param configuration  The configuration of the media stream relay: \ref ChannelMediaRelayConfiguration.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int startChannelMediaRelay(const ChannelMediaRelayConfiguration& configuration);

   /**
   * @brief                Updates the channels for media stream relay. After a successful \ref startChannelMediaRelay method call, if you want to relay the media stream to more channels, or leave the current relay channel, you can call the \ref updateChannelMediaRelay method.
   * @brief                After a successful method call, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onChannelMediaRelayEvent "onChannelMediaRelayEvent" callback with the \ref RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL (7) state code.
   * @note                 Call this method after the \ref startChannelMediaRelay method to update the destination channel.
   * param  configuration  The media stream relay configuration: \ref ChannelMediaRelayConfiguration.
   * @return               \arg  0: Success.
   *                       \arg  < 0: Failure.
   */
	int updateChannelMediaRelay(const ChannelMediaRelayConfiguration& configuration);

   /**
   * @brief       Stops the media stream relay.
   * @brief       Once the relay stops, the broadcaster quits all the destination channels.
   * @brief       After a successful method call, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onChannelMediaRelayStateChanged "onChannelMediaRelayStateChanged" callback. If the callback returns \ref RELAY_STATE_IDLE (0) and \ref RELAY_OK (0), the broadcaster successfully stops the relay.
   * @note        If the method call fails, the SDK triggers the `onChannelMediaRelayStateChanged` callback with the \ref RELAY_ERROR_SERVER_NO_RESPONSE (2) or \ref RELAY_ERROR_SERVER_CONNECTION_LOST (8) state code. You can leave the channel by calling the \ref leaveChannel method, and the media stream relay automatically stops.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int stopChannelMediaRelay();

   /**
   * @brief       Removes the voice or video stream URL address from a live broadcast.
   * @brief       This method removes the URL address (added by the \ref addInjectStreamUrl method) from the live broadcast.
   * @note        If this method is called successfully, the SDK triggers the \ref agora::rtc::IRtcEngineEventHandler::onUserOffline "onUserOffline" callback and returns a stream uid of 666.
   * @param url   Pointer to the URL address of the added stream to be removed.
   * @return      \arg  0: Success.
   *              \arg  < 0: Failure.
   */
	int removeInjectStreamUrl(const char* url);

	bool registerEventHandler(IRtcEngineEventHandler* eventHandler);

	bool unregisterEventHandler(IRtcEngineEventHandler* eventHandler);

   /**
   * @brief    Gets the current connection state of the SDK.
   * @return   \ref  CONNECTION_STATE_TYPE.
   */
	agora::rtc::CONNECTION_STATE_TYPE getConnectionState();

   /**
   * @brief          Registers the metadata observer.
   * @brief          Registers the metadata observer. You need to implement the \ref IMetadataObserver class and specify the metadata type in this method. A successful call of this method triggers the \ref agora::rtc::IMetadataObserver::getMaxMetadataSize "getMaxMetadataSize" callback. This method enables you to add synchronized metadata in the video stream for more diversified live broadcast interactions, such as sending shopping links, digital coupons, and online quizzes.
   * @note           \arg  Call this method before the joinChannel method.
   *                 \arg  This method applies to the Live-broadcast channel profile.
   * @param observer The \ref IMetadataObserver class. See the definition of \ref IMetadataObserver for details.
   * @param type     See \ref agora::rtc::IMetadataObserver::METADATA_TYPE "METADATA_TYPE". The SDK supports VIDEO_METADATA (0) only for now.
   * @return         \arg  0: Success.
   *                 \arg  < 0: Failure.
   */
	int registerMediaMetadataObserver(IMetadataObserver* observer, IMetadataObserver::METADATA_TYPE type);

	/** Provides technical preview functionalities or special customizations by configuring the SDK with JSON options.

	 The JSON options are not public by default. Agora is working on making commonly used JSON options public in a standard way.

	 @param parameters Sets the parameter as a JSON string in the specified format.

	 @return
	 - 0: Success.
	 - < 0: Failure.
	 */
	int setParameters( const char* parameters );

   /** Creates and gets an `AgoraRtcChannel` object.

    To join more than one channel, call this method multiple times to create as many `AgoraRtcChannel` objects as needed, and
    call the \ref AgoraRtcChannel::joinChannel "joinChannel" method of each created `AgoraRtcChannel` object.

    After joining multiple channels, you can simultaneously subscribe to streams of all the channels, but publish a stream in only one channel at one time.
    @param channelId The unique channel name for an Agora RTC session. It must be in the string format and not exceed 64 bytes in length. Supported character scopes are:
    - All lowercase English letters: a to z.
    - All uppercase English letters: A to Z.
    - All numeric characters: 0 to 9.
    - The space character.
    - Punctuation characters and other symbols, including: "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ",".

    @note
    - This parameter does not have a default value. You must set it.
    - Do not set it as the empty string "". Otherwise, the SDK returns #ERR_REFUSED (5).

    @return
    - The `AgoraRtcChannel` object, if the method call succeeds.
    - An empty pointer NULL, if the method call fails.
    - `agora::rtc::ERR_REFUSED(5)`, if you set channelId as the empty string "".
    */
   agora::rtc::IChannel* createChannel( const char *channelId );

public:
	friend class agora::media::ue4::AgoraMediaEngine;
   friend class agora::blueprints::AgoraVideoManager;
   friend class agora::blueprints::AgoraAudioManager;
	friend class AgoraVideoDeviceManager;
	friend class AgoraAudioDeviceManager;
	friend class AgoraLiveEngine;
   friend class AParameter;
private:
   /**
   * @brief       Releases all \ref IRtcEngine resources.
   * @param sync  \arg  true: (Synchronous call) The result returns after the \ref IRtcEngine 
   *                    resources are released. The application should not call this method in the SDK 
   *                    generated callbacks. Otherwise, the SDK must wait for the callbacks to return to 
   *                    recover the associated \ref IRtcEngine resources, resulting in a deadlock. 
   *                    The SDK automatically detects the deadlock and converts this method into an  
   *                    asynchronous call, causing the test to take additional time.
   *              \arg  false: (Asynchronous call) The result returns immediately, even when the \ref 
   *                    IRtcEngine resources have not been released. The SDK releases all resources.
   * @note        Do not immediately uninstall the SDK's dynamic library after the call, or it may cause a 
   *              crash due to the SDK clean-up thread not quitting.
   */
	void release(bool sync = false);

private:
	AgoraRtcEngine(agora::rtc::IRtcEngine2* rtcEngine);

private:
	agora::rtc::IRtcEngine2* m_rtcEngine = nullptr;
	bool m_sync = false;
};

/**
* Wrapper around agora::rtc::AParameter. See agora::rtc::IRtcEngineParameters methods description.
*/
class AParameter : public agora::rtc::AParameter
{
public:
   AParameter( AgoraRtcEngine* agoraRtcEngine )
      : agora::rtc::AParameter( agoraRtcEngine->m_rtcEngine ) {}
};
}
}
}
