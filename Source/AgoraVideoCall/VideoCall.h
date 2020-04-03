//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <functional>
#include <vector>

#include "AgoraRtcEngine.h"
#include "AgoraMediaEngine.h"

#include "CameraManager.h"
#include "AudioInOutDeviceManager.h"

class VideoFrameObserver;

/**
 * 
 */
class AGORAVIDEOCALL_API VideoCall
{
public:
	VideoCall();
	~VideoCall();

	FString GetVersion() const;

	void SetResolution(int Width, int Height, agora::rtc::FRAME_RATE FrameRate);

	void RegisterOnLocalFrameCallback(
		std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnLocalFrameCallback);
	void RegisterOnRemoteFrameCallback(
		std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnRemoteFrameCallback);

	void StartCall(
		const FString& ChannelName,
		const FString& EncryptionKey,
		const FString& EncryptionType);

	void StopCall();

	bool MuteLocalAudio(bool bMuted = true);
	bool IsLocalAudioMuted();

	bool MuteLocalVideo(bool bMuted = true);
	bool IsLocalVideoMuted();

	bool EnableVideo(bool bEnable = true);

	TUniquePtr<CameraManager> GetCameraManager();

	TUniquePtr<AudioInOutDeviceManager> GetAudioDeviceManager();

	bool EnableEchoTest(bool bEnable);
private:
	void InitAgora();

private:
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEnginePtr;
	TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEnginePtr;

	TUniquePtr<VideoFrameObserver> VideoFrameObserverPtr;

	//callback
	//data, w, h, size
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnLocalFrameCallback;
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> OnRemoteFrameCallback;

	bool bLocalAudioMuted = false;
	bool bLocalVideoMuted = false;
};
