//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "DeviceTestWidget.h"
#include "Blueprint/WidgetTree.h"

#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFileManager.h"

#include "VideoViewWidget.h"
#include "VideoCallPlayerController.h"

#include "AudioInOutDeviceManager.h"

#include <fstream>


UDeviceTestWidget::UDeviceTestWidget(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
}

void UDeviceTestWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// buttons
	if (MicrophoneTestButton)
	{
		UTextBlock* TestTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TestTextBlock->SetText(FText::FromString("Test"));
		MicrophoneTestButton->AddChild(TestTextBlock);
		MicrophoneTestButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnMicrophoneTest);
	}

	if (SpeakersTestButton)
	{
		UTextBlock* TestTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TestTextBlock->SetText(FText::FromString("Test"));
		SpeakersTestButton->AddChild(TestTextBlock);
		SpeakersTestButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnSpeakersTest);
	}

	if (CameraTestButton)
	{
		UTextBlock* TestTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TestTextBlock->SetText(FText::FromString("Test"));
		CameraTestButton->AddChild(TestTextBlock);
		CameraTestButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnCameraTest);
	}

	if (EchoTestButton)
	{
		UTextBlock* EchoTestButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		EchoTestButtonTextBlock->SetText(FText::FromString("EchoTest"));
		EchoTestButton->AddChild(EchoTestButtonTextBlock);
		EchoTestButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnEchoTest);
	}

	if (CancelButton)
	{
		UTextBlock* CancelButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		CancelButtonTextBlock->SetText(FText::FromString("Cancel"));
		CancelButton->AddChild(CancelButtonTextBlock);
		CancelButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnCancel);
	}

	if (ConfirmButton)
	{
		UTextBlock* ConfirmButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		ConfirmButtonTextBlock->SetText(FText::FromString("Confirm"));
		ConfirmButton->AddChild(ConfirmButtonTextBlock);
		ConfirmButton->OnClicked.AddDynamic(this, &UDeviceTestWidget::OnConfirm);
	}

	// text blocks
	if (MicrophoneTextBlock)
		MicrophoneTextBlock->SetText(FText::FromString("Input Device:"));

	if (SpeakersTextBlock)
		SpeakersTextBlock->SetText(FText::FromString("Output Device:"));

	if (CameraTextBlock)
		CameraTextBlock->SetText(FText::FromString("Camera:"));

	if (MicrophoneVolumeTextBlock)
		MicrophoneVolumeTextBlock->SetText(FText::FromString("Volume"));

	if (SpeakersVolumeTextBlock)
		SpeakersVolumeTextBlock->SetText(FText::FromString("Volume"));

	if (MicrophoneVolumeSlider)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnMicrophoneVolumeChanged"));
		//MicrophoneVolumeSlider->OnValueChanged.Add(Delegate);
		MicrophoneVolumeSlider->OnMouseCaptureEnd.Add(Delegate);
	}

	if (SpeakersVolumeSlider)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnSpeakersVolumeChanged"));
		SpeakersVolumeSlider->OnMouseCaptureEnd.Add(Delegate);
	}

	if (MicrophoneComboBox)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnMicrophoneComboBoxSelectionChanged"));
		MicrophoneComboBox->OnSelectionChanged.Add(Delegate);
	}
	if (SpeakersComboBox)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnSpeakersComboBoxSelectionChanged"));
		SpeakersComboBox->OnSelectionChanged.Add(Delegate);
	}
	if (CameraComboBox)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnCameraComboBoxSelectionChanged"));
		CameraComboBox->OnSelectionChanged.Add(Delegate);
	}
}

void UDeviceTestWidget::NativeDestruct()
{
	Super::NativeDestruct();

}

void UDeviceTestWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	float AspectRatio = 0;
	if (VideoHeight != 0)
	{
		AspectRatio = VideoWidth / (float)VideoHeight;
		TestVideoViewWidgetSizeBox->SetMinAspectRatio(AspectRatio);
		TestVideoViewWidgetSizeBox->SetMinDesiredWidth(VideoWidth);
		TestVideoViewWidgetSizeBox->SetMinDesiredHeight(VideoHeight);
	}
}

void UDeviceTestWidget::OnMicrophoneVolumeChanged()
{
	if (AudioDeviceManagerPtr)
	{
		float Value = MicrophoneVolumeSlider->GetValue();
		int Volume = static_cast<int>(Value);
		AudioDeviceManagerPtr->SetRecordingDeviceVolume(Volume);
	}
}

void UDeviceTestWidget::OnSpeakersVolumeChanged()
{
	if (AudioDeviceManagerPtr)
	{
		float Value = SpeakersVolumeSlider->GetValue();
		int Volume = static_cast<int>(Value);
		AudioDeviceManagerPtr->SetPlaybackDeviceVolume(Volume);
	}
}

void UDeviceTestWidget::OnMicrophoneComboBoxSelectionChanged()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	FString Option = MicrophoneComboBox->GetSelectedOption();
	FString DeviceID = AudioDeviceManagerPtr->GetRecordingDeviceID(Option);
	AudioDeviceManagerPtr->SetCurrRecordingDevice(DeviceID);
}

void UDeviceTestWidget::OnSpeakersComboBoxSelectionChanged()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	FString Option = SpeakersComboBox->GetSelectedOption();
	FString DeviceID = AudioDeviceManagerPtr->GetPlaybackDeviceID(Option);
	AudioDeviceManagerPtr->SetCurrPlaybackDevice(DeviceID);
}

void UDeviceTestWidget::OnCameraComboBoxSelectionChanged()
{
	if (!CameraManagerPtr)
	{
		return;
	}
	FString Option = CameraComboBox->GetSelectedOption();
	FString DeviceID = CameraManagerPtr->GetDeviceID(Option);
	CameraManagerPtr->SetCurrDevice(DeviceID);
}

void UDeviceTestWidget::OnMicrophoneTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (0 == MicrophoneComboBox->GetOptionCount())
	{
		return;
	}
	if (!IsTestingRecording)
	{
		StartMicrophoneTest();
	}
	else
	{
		StopMicrophoneTest();
	}
}

void UDeviceTestWidget::StartMicrophoneTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (!IsTestingRecording)
	{
		AudioDeviceManagerPtr->TestRecordingDevice();
		IsTestingRecording = true;

		auto Child = MicrophoneTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("Stop"));
		}
	}
}

void UDeviceTestWidget::StopMicrophoneTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (IsTestingRecording)
	{
		AudioDeviceManagerPtr->StopRecordingDeviceTest();
		IsTestingRecording = false;

		auto Child = MicrophoneTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("Test"));
		}
	}
}

void UDeviceTestWidget::OnSpeakersTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (0 == SpeakersComboBox->GetOptionCount())
	{
		return;
	}
	if(!IsTestingPlayback)
	{
		StartSpeakersTest();
	}
	else
	{
		StopSpeakersTest();
	}
}

void UDeviceTestWidget::StartSpeakersTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (!IsTestingPlayback)
	{
		FString AudioFile = CreateAudioFileForSpeakersTest();
        if(AudioFile.IsEmpty())
        {
            return;
        }

		AudioDeviceManagerPtr->TestPlaybackDevice(AudioFile);
		IsTestingPlayback = true;

		auto Child = SpeakersTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("Stop"));
		}
	}
}

void UDeviceTestWidget::StopSpeakersTest()
{
	if (!AudioDeviceManagerPtr)
	{
		return;
	}
	if (IsTestingPlayback)
	{
		AudioDeviceManagerPtr->StopPlaybackDeviceTest();
		IsTestingPlayback = false;

		auto Child = SpeakersTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("Test"));
		}
	}
}

void UDeviceTestWidget::OnCameraTest()
{
	if (!CameraManagerPtr)
	{
		return;
	}
	if (0 == CameraComboBox->GetOptionCount())
	{
		return;
	}
	if (!CameraManagerPtr->IsTesting())
	{
		StartCameraTest();
	}
	else
	{
		StopCameraTest();
	}
}

void UDeviceTestWidget::StartCameraTest()
{
	if (!CameraManagerPtr)
	{
		return;
	}
	auto OnFrameCallback = [this](
		std::uint8_t* Buffer,
		std::uint32_t Width,
		std::uint32_t Height,
		std::uint32_t Size)
	{
		if (!TestVideoViewWidget)
		{
			return;
		}
		VideoWidth = Width;
		VideoHeight = Height;

		TestVideoViewWidget->UpdateBuffer(0, Buffer, Width, Height, Size);
	};
	CameraManagerPtr->TestCameraDevice(OnFrameCallback);

	auto Child = CameraTestButton->GetChildAt(0);
	UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
	if (TestTextBlock)
	{
		TestTextBlock->SetText(FText::FromString("Stop"));
	}
}

void UDeviceTestWidget::StopCameraTest()
{
	if (!CameraManagerPtr)
	{
		return;
	}
	CameraManagerPtr->StopCameraDeviceTest();

	if (TestVideoViewWidget)
	{
		TestVideoViewWidget->ResetBuffer();
	}
	auto Child = CameraTestButton->GetChildAt(0);
	UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
	if (TestTextBlock)
	{
		TestTextBlock->SetText(FText::FromString("Test"));
	}
}

void UDeviceTestWidget::OnEchoTest()
{
	if (!IsEchoTesting)
	{
		StartEchoTest();
	}
	else
	{
		StopEchoTest();
	}
}

void UDeviceTestWidget::StartEchoTest()
{
	if (!VideoCallPtr)
	{
		return;
	}
	if (!IsEchoTesting)
	{
		VideoCallPtr->EnableEchoTest(true);
		IsEchoTesting = true;

		auto Child = EchoTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("StopEcho"));
		}
	}
}

void UDeviceTestWidget::StopEchoTest()
{
	if (!VideoCallPtr)
	{
		return;
	}
	if (IsEchoTesting)
	{
		VideoCallPtr->EnableEchoTest(false);
		IsEchoTesting = false;

		auto Child = EchoTestButton->GetChildAt(0);
		UTextBlock* TestTextBlock = Cast<UTextBlock>(Child);
		if (TestTextBlock)
		{
			TestTextBlock->SetText(FText::FromString("EchoTest"));
		}
	}
}

void UDeviceTestWidget::OnCancel()
{
	if (AudioDeviceManagerPtr)
	{
		//reset to init values
		AudioDeviceManagerPtr->SetRecordingDeviceVolume(MicrophoneVolume);
		AudioDeviceManagerPtr->SetPlaybackDeviceVolume(SpeakersVolume);

	}

	FString Option = MicrophoneComboBox->GetSelectedOption();
	if(DefaultRecordingDeviceName != Option)
	{
		FString DeviceID = AudioDeviceManagerPtr->GetRecordingDeviceID(DefaultRecordingDeviceName);
		AudioDeviceManagerPtr->SetCurrRecordingDevice(DeviceID);
	}
	Option = SpeakersComboBox->GetSelectedOption();
	if (DefaultPlaybackDeviceName != Option)
	{
		FString DeviceID = AudioDeviceManagerPtr->GetPlaybackDeviceID(DefaultPlaybackDeviceName);
		AudioDeviceManagerPtr->SetCurrPlaybackDevice(DeviceID);
	}
	Option = CameraComboBox->GetSelectedOption();
	if (DefaultVideoDeviceName != Option)
	{
		FString DeviceID = CameraManagerPtr->GetDeviceID(DefaultVideoDeviceName);
		CameraManagerPtr->SetCurrDevice(DeviceID);
	}

	OnExit();
}

void UDeviceTestWidget::OnConfirm()
{
	OnExit();
}

void UDeviceTestWidget::OnExit()
{
	if (CameraManagerPtr && CameraManagerPtr->IsTesting())
	{
		StopCameraTest();
	}

	StopMicrophoneTest();
	StopSpeakersTest();

	StopEchoTest();

	CameraManagerPtr.Reset();
	AudioDeviceManagerPtr.Reset();

	CameraComboBox->ClearOptions();
	MicrophoneComboBox->ClearOptions();
	SpeakersComboBox->ClearOptions();

	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->SwitchOnEnterChannelWidget(std::move(VideoCallPtr));
	}
}

void UDeviceTestWidget::SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController)
{
	PlayerController = VideoCallPlayerController;
}

void UDeviceTestWidget::SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	VideoCallPtr = std::move(PassedVideoCallPtr);

	if (!CameraManagerPtr)
	{
		CameraManagerPtr = VideoCallPtr->GetCameraManager();
	}
	if (CameraManagerPtr)
	{
		auto ActiveVideoDeviceName = CameraManagerPtr->GetCurrDeviceName();
		if (!ActiveVideoDeviceName.IsEmpty())
		{
			CameraComboBox->AddOption(ActiveVideoDeviceName);
			CameraComboBox->SetSelectedIndex(0);
			auto VideoDevices = CameraManagerPtr->GetVideoDevices();
			for (const auto& VideoDevice : VideoDevices)
			{
				if (VideoDevice != ActiveVideoDeviceName)
				{
					CameraComboBox->AddOption(VideoDevice);
				}
			}
			DefaultVideoDeviceName = ActiveVideoDeviceName;
		}
	}
	

	if (!AudioDeviceManagerPtr)
	{
		AudioDeviceManagerPtr = VideoCallPtr->GetAudioDeviceManager();
	}
	if (AudioDeviceManagerPtr)
	{
		auto ActiveRecordingDeviceName = AudioDeviceManagerPtr->GetCurrRecordingDeviceName();
		if (!ActiveRecordingDeviceName.IsEmpty())
		{
			MicrophoneComboBox->AddOption(ActiveRecordingDeviceName);
			MicrophoneComboBox->SetSelectedIndex(0);
			auto RecordingDevices = AudioDeviceManagerPtr->GetRecordingDevices();
			for (const auto& RecordingDevice : RecordingDevices)
			{
				if (RecordingDevice != ActiveRecordingDeviceName)
				{
					MicrophoneComboBox->AddOption(RecordingDevice);
				}
			}
			DefaultRecordingDeviceName = ActiveRecordingDeviceName;
		}

		auto ActivePlaybackDeviceName = AudioDeviceManagerPtr->GetCurrPlaybackDeviceName();
		if (!ActivePlaybackDeviceName.IsEmpty())
		{
			SpeakersComboBox->AddOption(ActivePlaybackDeviceName);
			SpeakersComboBox->SetSelectedIndex(0);
			auto PlaybackDevices = AudioDeviceManagerPtr->GetPlaybackDevices();
			for (const auto& PlaybackDevice : PlaybackDevices)
			{
				if (PlaybackDevice != ActivePlaybackDeviceName)
				{
					SpeakersComboBox->AddOption(PlaybackDevice);
				}
			}
			DefaultPlaybackDeviceName = ActivePlaybackDeviceName;

			SpeakersVolume = AudioDeviceManagerPtr->GetPlaybackDeviceVolume();
			SpeakersVolumeSlider->SetValue(SpeakersVolume);

			MicrophoneVolume = AudioDeviceManagerPtr->GetRecordingDeviceVolume();
			MicrophoneVolumeSlider->SetValue(MicrophoneVolume);
		}
	}
}

//helper function
namespace little_endian_io
{
template <typename Word>
std::ostream& write_word(std::ostream& outs, Word value, unsigned size = sizeof(Word))
{
	for (; size; --size, value >>= 8)
		outs.put(static_cast <char> (value & 0xFF));
	return outs;
}
}

FString UDeviceTestWidget::CreateAudioFileForSpeakersTest()
{
    FString AudioContentDir;
#if PLATFORM_WINDOWS
	const FString& RelPath = FPaths::ProjectDir();
	const FString& FullPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*RelPath);
    
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ContentDir = FPaths::Combine(*FullPath, TEXT("Content/"));
	if (!PlatformFile.DirectoryExists(*ContentDir))
	{
		bool bRes = PlatformFile.CreateDirectory(*ContentDir);
        if(!bRes)
        {
            return "";
        }
	}
	AudioContentDir = FPaths::Combine(*ContentDir, TEXT("Audio/"));
	if (!PlatformFile.DirectoryExists(*AudioContentDir))
	{
		bool bRes = PlatformFile.CreateDirectory(*AudioContentDir);
        if(!bRes)
        {
            return "";
        }
	}
#endif
    
#if PLATFORM_MAC
    AudioContentDir = "/Library/Caches/";
#endif
    FString AudioFile = FPaths::Combine(*AudioContentDir, TEXT("ID_TEST_AUDIO.wav"));
	{
		std::ifstream f(TCHAR_TO_ANSI(*AudioFile));
		if (f.good())
		{
			return AudioFile;
		}
	}

	std::ofstream f(TCHAR_TO_ANSI(*AudioFile), std::ios::binary);

	using namespace little_endian_io;
	// Write the file headers
	f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
	write_word(f, 16, 4);  // no extension data
	write_word(f, 1, 2);  // PCM - integer samples
	write_word(f, 2, 2);  // two channels (stereo file)
	write_word(f, 44100, 4);  // samples per second (Hz)
	write_word(f, 176400, 4);  // (Sample Rate * BitsPerSample * Channels) / 8
	write_word(f, 4, 2);  // data block size (size of two integer samples, one for each channel, in bytes)
	write_word(f, 16, 2);  // number of bits per sample (use a multiple of 8)

	// Write the data chunk header
	size_t data_chunk_pos = f.tellp();
	f << "data----";  // (chunk size to be filled in later)

	// Write the audio samples
	// (We'll generate a single C4 note with a sine wave, fading from left to right)
	constexpr double two_pi = 6.283185307179586476925286766559;
	constexpr double max_amplitude = 32760;  // "volume"

	double hz = 44100;    // samples per second
	double frequency = 261.626;  // middle C
	double seconds = 2.5;      // time

	int N = hz * seconds;  // total number of samples
	for (int n = 0; n < N; n++)
	{
		double amplitude = (double)n / N * max_amplitude;
		double value = sin((two_pi * n * frequency) / hz);
		write_word(f, (int)(amplitude  * value), 2);
		write_word(f, (int)((max_amplitude - amplitude) * value), 2);
	}

	// (We'll need the final file size to fix the chunk sizes above)
	size_t file_length = f.tellp();

	// Fix the data chunk header to contain the data size
	f.seekp(data_chunk_pos + 4);
	write_word(f, file_length - data_chunk_pos + 8);

	// Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
	f.seekp(0 + 4);
	write_word(f, file_length - 8, 4);

	f.close();

	return AudioFile;
}
