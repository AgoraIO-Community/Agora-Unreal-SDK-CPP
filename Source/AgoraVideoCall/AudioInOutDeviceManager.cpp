//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "AudioInOutDeviceManager.h"

#include "AgoraAudioDeviceManager.h"
#include "AgoraRtcEngine.h"

AudioInOutDeviceManager::AudioInOutDeviceManager(
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine)
{
	if (!RtcEngine)
	{
		return;
	}
	RtcEnginePtr = std::move(RtcEngine);

	DeviceManagerPtr = TUniquePtr<agora::rtc::ue4::AgoraAudioDeviceManager>(
		agora::rtc::ue4::AgoraAudioDeviceManager::Create(RtcEnginePtr.Get()));
	if (!DeviceManagerPtr)
	{
		return;
	}
	RecordingDevicesPtr = TUniquePtr<agora::rtc::ue4::AudioDeviceCollection>(
		DeviceManagerPtr->enumerateRecordingDevices());
	PlaybackDevicesPtr = TUniquePtr<agora::rtc::ue4::AudioDeviceCollection>(
		DeviceManagerPtr->enumeratePlaybackDevices());
}

AudioInOutDeviceManager::~AudioInOutDeviceManager()
{

}

TUniquePtr<AudioInOutDeviceManager> AudioInOutDeviceManager::Create(
	TSharedPtr<agora::rtc::ue4::AgoraRtcEngine> RtcEngine)
{
	return MakeUnique<AudioInOutDeviceManager>(std::move(RtcEngine));
}

uint32 AudioInOutDeviceManager::GetRecordingDeviceCount()
{
	if (!RecordingDevicesPtr)
		return 0;

	return RecordingDevicesPtr->getCount();
}

uint32 AudioInOutDeviceManager::GetPlaybackDeviceCount()
{
	if (!PlaybackDevicesPtr)
		return 0;

	return PlaybackDevicesPtr->getCount();
}

std::vector<FString> AudioInOutDeviceManager::GetRecordingDevices()
{
	std::vector<FString> output;
	if (!RecordingDevicesPtr)
		return output;
	auto NumDevices = RecordingDevicesPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = GetRecordingDevice(Index, DeviceName, DeviceID);
		if (bRes)
		{
			output.push_back(DeviceName);
		}
	}
	return output;
}

FString AudioInOutDeviceManager::GetCurrRecordingDeviceName()
{
	if (!DeviceManagerPtr || !RecordingDevicesPtr)
	{
		return FString();
	}

	char DefaultDeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
	DeviceManagerPtr->getRecordingDevice(DefaultDeviceId);
	auto NumDevices = RecordingDevicesPtr->getCount();
	for (int i = 0; i < NumDevices; ++i)
	{
		char DeviceName[agora::rtc::MAX_DEVICE_ID_LENGTH];
		char DeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
		RecordingDevicesPtr->getDevice(i, DeviceName, DeviceId);

		UE_LOG(LogTemp, Warning, TEXT("RecordingDevice deviceName: %s, deviceId: %s"),
			*FString(ANSI_TO_TCHAR(DeviceName)), *FString(ANSI_TO_TCHAR(DeviceId)));

		if (strcmp(DeviceId, DefaultDeviceId) == 0)
		{
			return FString(ANSI_TO_TCHAR(DeviceName));
		}
	}
	return FString();
}

std::vector<FString> AudioInOutDeviceManager::GetPlaybackDevices()
{
	std::vector<FString> output;
	if (!PlaybackDevicesPtr)
		return output;
	auto NumDevices = PlaybackDevicesPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = GetPlaybackDevice(Index, DeviceName, DeviceID);
		if (bRes)
		{
			output.push_back(DeviceName);
		}
	}
	return output;
}

FString AudioInOutDeviceManager::GetCurrPlaybackDeviceName()
{
	if (!DeviceManagerPtr || !PlaybackDevicesPtr)
	{
		return FString();
	}

	char DefaultDeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
	DeviceManagerPtr->getPlaybackDevice(DefaultDeviceId);

	auto NumDevices = PlaybackDevicesPtr->getCount();
	for (int i = 0; i < NumDevices; ++i)
	{
		char DeviceName[agora::rtc::MAX_DEVICE_ID_LENGTH];
		char DeviceId[agora::rtc::MAX_DEVICE_ID_LENGTH];
		PlaybackDevicesPtr->getDevice(i, DeviceName, DeviceId);

		UE_LOG(LogTemp, Warning, TEXT("PlaybackDevice deviceName: %s, deviceId: %s"),
			*FString(ANSI_TO_TCHAR(DeviceName)), *FString(ANSI_TO_TCHAR(DeviceId)));

		if (strcmp(DeviceId, DefaultDeviceId) == 0)
		{
			return FString(ANSI_TO_TCHAR(DeviceName));
		}
	}
	return FString();
}

bool AudioInOutDeviceManager::SetCurrRecordingDevice(const FString& PassedDeviceID)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}

	char* DeviceID = TCHAR_TO_ANSI(*PassedDeviceID);
	int nRet = DeviceManagerPtr->setPlaybackDevice(DeviceID);
	return nRet == 0 ? true : false;
}

FString AudioInOutDeviceManager::GetRecordingDeviceID(const FString& DeviceNameToFind)
{
	if (!RecordingDevicesPtr)
		return "";
	auto NumDevices = RecordingDevicesPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = GetRecordingDevice(Index, DeviceName, DeviceID);
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

bool AudioInOutDeviceManager::SetCurrPlaybackDevice(const FString& PassedDeviceID)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}

	char* DeviceID = TCHAR_TO_ANSI(*PassedDeviceID);
	int nRet = DeviceManagerPtr->setRecordingDevice(DeviceID);
	return nRet == 0 ? true : false;
}

FString AudioInOutDeviceManager::GetPlaybackDeviceID(const FString& DeviceNameToFind)
{
	if (!PlaybackDevicesPtr)
		return "";
	auto NumDevices = PlaybackDevicesPtr->getCount();
	for (int Index = 0; Index < NumDevices; ++Index)
	{
		FString DeviceName;
		FString DeviceID;
		bool bRes = GetPlaybackDevice(Index, DeviceName, DeviceID);
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

bool AudioInOutDeviceManager::GetRecordingDevice(uint32 Index, FString& DeviceName, FString& DeviceID)
{
	if (!RecordingDevicesPtr)
		return false;

	if (Index >= GetRecordingDeviceCount())
		return false;

	char Name[agora::rtc::MAX_DEVICE_ID_LENGTH];
	char Id[agora::rtc::MAX_DEVICE_ID_LENGTH];
	int nRet = RecordingDevicesPtr->getDevice(Index, Name, Id);
	if (nRet != 0)
		return false;

	DeviceName = FString(ANSI_TO_TCHAR(Name));
	DeviceID = FString(ANSI_TO_TCHAR(Id));

	return true;
}

bool AudioInOutDeviceManager::GetPlaybackDevice(uint32 Index, FString& DeviceName, FString& DeviceID)
{
	if (!PlaybackDevicesPtr)
		return false;

	if (Index >= GetRecordingDeviceCount())
		return false;

	char Name[agora::rtc::MAX_DEVICE_ID_LENGTH];
	char Id[agora::rtc::MAX_DEVICE_ID_LENGTH];
	int nRet = PlaybackDevicesPtr->getDevice(Index, Name, Id);
	if (nRet != 0)
		return false;

	DeviceName = FString(ANSI_TO_TCHAR(Name));
	DeviceID = FString(ANSI_TO_TCHAR(Id));

	return true;
}

bool AudioInOutDeviceManager::SetPlaybackDeviceVolume(int Volume)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int nRet = DeviceManagerPtr->setPlaybackDeviceVolume(Volume);
	if (nRet != 0)
		return false;
	return true;
}

int AudioInOutDeviceManager::GetPlaybackDeviceVolume() const
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int Volume = 0;
	int nRet = DeviceManagerPtr->getPlaybackDeviceVolume(&Volume);
	if (nRet != 0)
		return 0;
	return Volume;
}

bool AudioInOutDeviceManager::SetRecordingDeviceVolume(int Volume)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int nRet = DeviceManagerPtr->setRecordingDeviceVolume(Volume);
	if (nRet != 0)
		return false;
	return true;
}

int AudioInOutDeviceManager::GetRecordingDeviceVolume() const
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int Volume = 0;
	int nRet = DeviceManagerPtr->getRecordingDeviceVolume(&Volume);
	if (nRet != 0)
		return 0;
	return Volume;
}

bool AudioInOutDeviceManager::TestRecordingDevice()
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int nRet = DeviceManagerPtr->startRecordingDeviceTest(1000);
	if (nRet != 0)
		return false;
	return true;
}

bool AudioInOutDeviceManager::StopRecordingDeviceTest()
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int nRet = DeviceManagerPtr->stopRecordingDeviceTest();
	if (nRet != 0)
		return false;
	return true;
}

bool AudioInOutDeviceManager::TestPlaybackDevice(const FString& AudioFile)
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
    if(AudioFile.IsEmpty())
    {
        return false;
    }
	char* TestAudioFilePath = TCHAR_TO_ANSI(*AudioFile);
	int nRet = DeviceManagerPtr->startPlaybackDeviceTest(TestAudioFilePath);
	if (nRet != 0)
	{
		return false;
	}

	return true;
}

bool AudioInOutDeviceManager::StopPlaybackDeviceTest()
{
	if (!DeviceManagerPtr)
	{
		return false;
	}
	int nRet = DeviceManagerPtr->stopPlaybackDeviceTest();
	if (nRet != 0)
		return false;
	return true;
}
