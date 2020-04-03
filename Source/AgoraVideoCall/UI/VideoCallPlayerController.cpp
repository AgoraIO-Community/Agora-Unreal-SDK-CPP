//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoCallPlayerController.h"

#include "Blueprint/UserWidget.h"

#include "EnterChannelWidget.h"
#include "DeviceTestWidget.h"
#include "VideoCallWidget.h"
#include "VideoSettingsWidget.h"

void AVideoCallPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//initialize wigets
	if (wEnterChannelWidget) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		if (!EnterChannelWidget)
		{
			EnterChannelWidget = CreateWidget<UEnterChannelWidget>(this, wEnterChannelWidget);
			EnterChannelWidget->SetVideoCallPlayerController(this);
		}
		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (EnterChannelWidget)
		{
			//let add it to the view port
			EnterChannelWidget->AddToViewport();
		}
		//Show the Cursor.
		bShowMouseCursor = true;
	}
	if (wDeviceTestWidget)
	{
		if (!DeviceTestWidget)
		{
			DeviceTestWidget = CreateWidget<UDeviceTestWidget>(this, wDeviceTestWidget);
			DeviceTestWidget->SetVideoCallPlayerController(this);
		}
		if (DeviceTestWidget)
		{
			DeviceTestWidget->AddToViewport();
		}
		DeviceTestWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (wVideoCallWidget)
	{
		if (!VideoCallWidget)
		{
			VideoCallWidget = CreateWidget<UVideoCallWidget>(this, wVideoCallWidget);
			VideoCallWidget->SetVideoCallPlayerController(this);
		}
		if (VideoCallWidget)
		{
			VideoCallWidget->AddToViewport();
		}
		VideoCallWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (wVideoSettingsWidget)
	{
		if (!VideoSettingsWidget)
		{
			VideoSettingsWidget = CreateWidget<UVideoSettingsWidget>(this, wVideoSettingsWidget);
			VideoSettingsWidget->SetVideoCallPlayerController(this);
		}
		if (VideoSettingsWidget)
		{
			VideoSettingsWidget->AddToViewport();
		}
		VideoSettingsWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	//create video call and switch on the EnterChannelWidget
	VideoCallPtr = MakeUnique<VideoCall>();

	if (VideoSettingsWidget)
	{
		int Width = 0;
		int Height = 0;
		agora::rtc::FRAME_RATE FrameRate = agora::rtc::FRAME_RATE::FRAME_RATE_FPS_1;
		VideoSettingsWidget->GetCurrentResolution(Width, Height, FrameRate);

		VideoCallPtr->SetResolution( Width, Height, FrameRate);
	}

	FString Version = VideoCallPtr->GetVersion();
	Version = "Agora version: " + Version;
	EnterChannelWidget->UpdateVersionText(Version);

	SwitchOnEnterChannelWidget(std::move(VideoCallPtr));
}

void AVideoCallPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AVideoCallPlayerController::StartCall(
	TUniquePtr<VideoCall> PassedVideoCallPtr,
	const FString& ChannelName,
	const FString& EncryptionKey,
	const FString& EncryptionType)
{
	SwitchOnVideoCallWidget(std::move(PassedVideoCallPtr));

	VideoCallWidget->OnStartCall(
		ChannelName,
		EncryptionKey,
		EncryptionType);
}

void AVideoCallPlayerController::EndCall(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	SwitchOnEnterChannelWidget(std::move(PassedVideoCallPtr));
}

void AVideoCallPlayerController::SwitchOnEnterChannelWidget(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	if (!EnterChannelWidget)
	{
		return;
	}

	if (VideoSettingsWidget)
	{
		auto CurrentResolution = VideoSettingsWidget->GetCurrentResolution();
		EnterChannelWidget->UpdateVideoSettingsButtonText(std::move(CurrentResolution));
	}

	EnterChannelWidget->SetVideoCall(std::move(PassedVideoCallPtr));
	EnterChannelWidget->SetVisibility(ESlateVisibility::Visible);
}

void AVideoCallPlayerController::SwitchOnTestWidget(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	if (!DeviceTestWidget)
	{
		return;
	}
	DeviceTestWidget->SetVideoCall(std::move(PassedVideoCallPtr));
	DeviceTestWidget->SetVisibility(ESlateVisibility::Visible);
}

void AVideoCallPlayerController::SwitchOnVideoCallWidget(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	if (!VideoCallWidget)
	{
		return;
	}
	VideoCallWidget->SetVideoCall(std::move(PassedVideoCallPtr));
	VideoCallWidget->SetVisibility(ESlateVisibility::Visible);
}

void AVideoCallPlayerController::SwitchOnVideoSettingsWidget(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	if (!VideoSettingsWidget)
	{
		return;
	}
	VideoSettingsWidget->SetVideoCall(std::move(PassedVideoCallPtr));
	VideoSettingsWidget->SetVisibility(ESlateVisibility::Visible);
}