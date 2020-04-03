//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <vector>
#include <functional>


namespace agora
{
namespace rtc
{
namespace ue4
{
class AgoraAudioDeviceManager;
class AudioDeviceCollection;
class AgoraRtcEngine;
}
}
}

/**
 * 
 */
class AGORAVIDEOCALL_API AudioInOutDeviceManager
{
public:
	AudioInOutDeviceManager() = delete;
	AudioInOutDeviceManager(
		TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine);

	~AudioInOutDeviceManager();

	static TUniquePtr<AudioInOutDeviceManager> Create(
		TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine);

public:
	uint32 GetRecordingDeviceCount();

	uint32 GetPlaybackDeviceCount();

	std::vector<FString> GetRecordingDevices();

	FString GetCurrRecordingDeviceName();

	std::vector<FString> GetPlaybackDevices();

	FString GetCurrPlaybackDeviceName();

	bool SetCurrRecordingDevice(const FString& DeviceID);

	FString GetRecordingDeviceID(const FString& DeviceName);

	bool SetCurrPlaybackDevice(const FString& DeviceID);

	FString GetPlaybackDeviceID(const FString& DeviceName);

	bool GetRecordingDevice(uint32 Index, FString& DeviceName, FString& DeviceID);

	bool GetPlaybackDevice(uint32 Index, FString& DeviceName, FString& DeviceID);

	bool SetPlaybackDeviceVolume(int Volume);

	int GetPlaybackDeviceVolume() const;

	bool SetRecordingDeviceVolume(int Volume);

	int GetRecordingDeviceVolume() const;

	bool TestRecordingDevice();

	bool StopRecordingDeviceTest();

	bool TestPlaybackDevice(const FString& AudioFile);

	bool StopPlaybackDeviceTest();

private:
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEnginePtr;

	TUniquePtr<agora::rtc::ue4::AgoraAudioDeviceManager> DeviceManagerPtr;
	TUniquePtr<agora::rtc::ue4::AudioDeviceCollection> RecordingDevicesPtr;
	TUniquePtr<agora::rtc::ue4::AudioDeviceCollection> PlaybackDevicesPtr;
};
