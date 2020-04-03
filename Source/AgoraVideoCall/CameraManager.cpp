//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "CameraManager.h"

#include "AgoraVideoDeviceManager.h"
#include "AgoraRtcEngine.h"
#include "AgoraMediaEngine.h"

#include "VideoFrameObserver.h"

CameraManager::CameraManager(
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine,
	TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEngine)
{
	if (!RtcEngine || !MediaEngine)
	{
		return;
	}
	RtcEngine->enableVideo();//TODO:in VideoCall?
	RtcEnginePtr = std::move(RtcEngine);
	MediaEnginePtr = std::move(MediaEngine);
	DeviceManagerPtr = TUniquePtr<agora::rtc::ue4::AgoraVideoDeviceManager>(
		agora::rtc::ue4::AgoraVideoDeviceManager::Create(RtcEnginePtr.Get()));
	if (!DeviceManagerPtr)
	{
		return;
	}
	CollectionPtr = TUniquePtr<agora::rtc::ue4::VideoDeviceCollection>(
		DeviceManagerPtr->enumerateVideoDevices());
}

CameraManager::~CameraManager()
{

}

TUniquePtr<CameraManager> CameraManager::Create(
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine,
	TSharedPtr<agora::media::ue4::AgoraMediaEngine> MediaEngine)
{
	return MakeUnique<CameraManager>(std::move(RtcEngine), std::move(MediaEngine));
}

uint32 CameraManager::GetDeviceCount()
{
	if (!CollectionPtr)
		return 0;

	return CollectionPtr->getCount();
}

FString CameraManager::GetCurrDeviceID()
{
	if (!DeviceManagerPtr)
	{
		return FString();
	}

	char DefaultDeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
	DeviceManagerPtr->getDevice(DefaultDeviceId);
	return FString(ANSI_TO_TCHAR(DefaultDeviceId));
}

bool CameraManager::SetCurrDevice(const FString& PassedDeviceID)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}

	char* DeviceID = TCHAR_TO_ANSI(*PassedDeviceID);
	int nRet = DeviceManagerPtr->setDevice(DeviceID);
	return nRet == 0 ? true : false;
}

FString CameraManager::GetDeviceID(const FString& DeviceNameToFind)
{
	if (!CollectionPtr)
		return "";

	auto NumDevices = CollectionPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = CameraManager::GetDevice(Index, DeviceName, DeviceID);
		if (bRes)
		{
			if (DeviceNameToFind == DeviceName)
			{
				return DeviceID;
			}
		}
	}
	return FString();
}

FString CameraManager::GetCurrDeviceName()
{
	if (!DeviceManagerPtr || !CollectionPtr)
	{
		return FString();
	}

	char DefaultDeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
	DeviceManagerPtr->getDevice(DefaultDeviceId);

	auto NumDevices = CollectionPtr->getCount();
	for (int i = 0; i < NumDevices; ++i)
	{
		char DeviceName[agora::rtc::MAX_DEVICE_ID_LENGTH];
		char DeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
		CollectionPtr->getDevice(i, DeviceName, DeviceId);

		UE_LOG(LogTemp, Warning, TEXT("deviceName: %s, deviceId: %s"),
			*FString(ANSI_TO_TCHAR(DeviceName)), *FString(ANSI_TO_TCHAR(DeviceId)));

		if (strcmp(DeviceId, DefaultDeviceId) == 0)
		{
			return FString(ANSI_TO_TCHAR(DeviceName));
		}
	}
	return FString();
}

std::vector<FString> CameraManager::GetVideoDevices()
{
	std::vector<FString> output;
	if (!CollectionPtr)
		return output;

	auto NumDevices = CollectionPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = GetDevice(Index, DeviceName, DeviceID);
		if (bRes)
		{
			output.push_back(DeviceName);
		}
	}
	return output;
}

bool CameraManager::GetDevice(uint32 Index, FString& DeviceName, FString& DeviceID)
{
	if (!CollectionPtr)
		return false;

	if (Index >= GetDeviceCount())
		return false;

	char Name[agora::rtc::MAX_DEVICE_ID_LENGTH];
	char Id[agora::rtc::MAX_DEVICE_ID_LENGTH];
	int nRet = CollectionPtr->getDevice(Index, Name, Id);
	if (nRet != 0)
		return false;

	DeviceName = FString(ANSI_TO_TCHAR(Name));
	DeviceID = FString(ANSI_TO_TCHAR(Id));

	return true;
}

void CameraManager::TestCameraDevice(
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback)
{
	if (!MediaEnginePtr || !RtcEnginePtr)
	{
		return;
	}
	if (!VideoFrameObserverPtr)
	{
		VideoFrameObserverPtr = TUniquePtr<VideoFrameObserver>(new VideoFrameObserver());
		VideoFrameObserverPtr->setOnCaptureVideoFrameCallback(std::move(Callback));
		MediaEnginePtr->registerVideoFrameObserver(VideoFrameObserverPtr.Get());
	}
	RtcEnginePtr->enableVideo();

	RtcEnginePtr->startPreview();
}

void CameraManager::StopCameraDeviceTest()
{
	if (!MediaEnginePtr || !RtcEnginePtr)
	{
		return;
	}
	RtcEnginePtr->stopPreview();

	MediaEnginePtr->registerVideoFrameObserver(nullptr);
	VideoFrameObserverPtr.Reset();
}