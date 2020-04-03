//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <vector>
#include <functional>

class VideoFrameObserver;
namespace agora 
{
namespace media
{
namespace ue4
{
class AgoraMediaEngine;
}
}
namespace rtc
{
namespace ue4
{
class AgoraVideoDeviceManager;
class VideoDeviceCollection;
class AgoraRtcEngine;
}
}
}

/**
 * 
 */
class AGORAVIDEOCALL_API CameraManager
{
public:
	CameraManager() = delete;
	CameraManager(
		TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine,
		TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEngine);

	~CameraManager();

	static TUniquePtr<CameraManager> Create(
		TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine,
		TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEngine);

public:
	uint32 GetDeviceCount();

	FString GetCurrDeviceID();

	bool SetCurrDevice(const FString& DeviceID);

	FString GetDeviceID(const FString& DeviceName);

	FString GetCurrDeviceName();

	std::vector<FString> GetVideoDevices();

	bool GetDevice(uint32 Index, FString& DeviceName, FString& DeviceID);

	void TestCameraDevice(
		std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback);

	void StopCameraDeviceTest();

	bool IsTesting() const { return VideoFrameObserverPtr ? true : false; };

private:
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEnginePtr;
	TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEnginePtr;

	TUniquePtr<VideoFrameObserver> VideoFrameObserverPtr;

	TUniquePtr<agora::rtc::ue4::AgoraVideoDeviceManager> DeviceManagerPtr;
	TUniquePtr<agora::rtc::ue4::VideoDeviceCollection> CollectionPtr;
};
