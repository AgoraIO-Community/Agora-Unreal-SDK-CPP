//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoCallWidget.h"

#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CanvasPanelSlot.h"

#include "VideoViewWidget.h"

#include "VideoCallPlayerController.h"

UVideoCallWidget::UVideoCallWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		EndCallButtonTextureFinder(TEXT("Texture'/Game/ButtonTextures/hangup.hangup'"));
	if (EndCallButtonTextureFinder.Succeeded())
	{
		EndCallButtonTexture = EndCallButtonTextureFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		AudioButtonMuteTextureFinder(TEXT("Texture'/Game/ButtonTextures/mute.mute'"));
	if (AudioButtonMuteTextureFinder.Succeeded())
	{
		AudioButtonMuteTexture = AudioButtonMuteTextureFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		AudioButtonUnmuteTextureFinder(TEXT("Texture'/Game/ButtonTextures/unmute.unmute'"));
	if (AudioButtonUnmuteTextureFinder.Succeeded())
	{
		AudioButtonUnmuteTexture = AudioButtonUnmuteTextureFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		VideomodeButtonCameraonTextureFinder(TEXT("Texture'/Game/ButtonTextures/cameraon.cameraon'"));
	if (VideomodeButtonCameraonTextureFinder.Succeeded())
	{
		VideomodeButtonCameraonTexture = VideomodeButtonCameraonTextureFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		VideomodeButtonCameraoffTextureFinder(TEXT("Texture'/Game/ButtonTextures/cameraoff.cameraoff'"));
	if (VideomodeButtonCameraoffTextureFinder.Succeeded())
	{
		VideomodeButtonCameraoffTexture = VideomodeButtonCameraoffTextureFinder.Object;
	}
}

void UVideoCallWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitButtons();
}

void UVideoCallWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (VideoCallPtr)
	{
		VideoCallPtr->StopCall();
	}
}

void UVideoCallWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

}

void UVideoCallWidget::OnStartCall(
	const FString& ChannelName,
	const FString& EncryptionKey,
	const FString& EncryptionType)
{
	if (!VideoCallPtr)
	{
		return;
	}

	auto OnLocalFrameCallback = [this](
		std::uint8_t* Buffer,
		std::uint32_t Width,
		std::uint32_t Height,
		std::uint32_t Size)
	{
		VideoCallViewWidget->UpdateAdditionalVideoBuffer(Buffer, Width, Height, Size);
	};
	VideoCallPtr->RegisterOnLocalFrameCallback(OnLocalFrameCallback);

	auto OnRemoteFrameCallback = [this](
		std::uint8_t* Buffer,
		std::uint32_t Width,
		std::uint32_t Height,
		std::uint32_t Size)
	{
		VideoCallViewWidget->UpdateMainVideoBuffer(Buffer, Width, Height, Size);
	};
	VideoCallPtr->RegisterOnRemoteFrameCallback(OnRemoteFrameCallback);

	VideoCallPtr->StartCall(ChannelName, EncryptionKey, EncryptionType);
}

void UVideoCallWidget::OnEndCall()
{
	if (VideoCallPtr)
	{
		VideoCallPtr->StopCall();
	}

	if (VideoCallViewWidget)
	{
		VideoCallViewWidget->ResetBuffers();
	}

	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->EndCall(std::move(VideoCallPtr));
	}
}

void UVideoCallWidget::OnMuteLocalAudio()
{
	if (!VideoCallPtr)
	{
		return;
	}
	if (VideoCallPtr->IsLocalAudioMuted())
	{
		VideoCallPtr->MuteLocalAudio(false);
		SetAudioButtonToMute();
	}
	else
	{
		VideoCallPtr->MuteLocalAudio(true);
		SetAudioButtonToUnMute();
	}
}

void UVideoCallWidget::OnChangeVideoMode()
{
	if (!VideoCallPtr)
	{
		return;
	}
	if (!VideoCallPtr->IsLocalVideoMuted())
	{
		VideoCallPtr->MuteLocalVideo(true);

		SetVideoModeButtonToCameraOn();
	}
	else
	{
		VideoCallPtr->EnableVideo(true);
		VideoCallPtr->MuteLocalVideo(false);

		SetVideoModeButtonToCameraOff();
	}
}

void UVideoCallWidget::InitButtons()
{
	if (EndCallButtonTexture)
	{
		EndCallButton->WidgetStyle.Normal.SetResourceObject(EndCallButtonTexture);
		EndCallButton->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		EndCallButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Type::Image;

		EndCallButton->WidgetStyle.Hovered.SetResourceObject(EndCallButtonTexture);
		EndCallButton->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		EndCallButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;

		EndCallButton->WidgetStyle.Pressed.SetResourceObject(EndCallButtonTexture);
		EndCallButton->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		EndCallButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	}
	EndCallButton->OnClicked.AddDynamic(this, &UVideoCallWidget::OnEndCall);

	SetAudioButtonToMute();
	MuteLocalAudioButton->OnClicked.AddDynamic(this, &UVideoCallWidget::OnMuteLocalAudio);

	SetVideoModeButtonToCameraOff();
	VideoModeButton->OnClicked.AddDynamic(this, &UVideoCallWidget::OnChangeVideoMode);

}

void UVideoCallWidget::SetVideoModeButtonToCameraOff()
{
	if (VideomodeButtonCameraoffTexture)
	{
		VideoModeButton->WidgetStyle.Normal.SetResourceObject(VideomodeButtonCameraoffTexture);
		VideoModeButton->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Type::Image;

		VideoModeButton->WidgetStyle.Hovered.SetResourceObject(VideomodeButtonCameraoffTexture);
		VideoModeButton->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;

		VideoModeButton->WidgetStyle.Pressed.SetResourceObject(VideomodeButtonCameraoffTexture);
		VideoModeButton->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	}
}

void UVideoCallWidget::SetVideoModeButtonToCameraOn()
{
	if (VideomodeButtonCameraonTexture)
	{
		VideoModeButton->WidgetStyle.Normal.SetResourceObject(VideomodeButtonCameraonTexture);
		VideoModeButton->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Type::Image;

		VideoModeButton->WidgetStyle.Hovered.SetResourceObject(VideomodeButtonCameraonTexture);
		VideoModeButton->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;

		VideoModeButton->WidgetStyle.Pressed.SetResourceObject(VideomodeButtonCameraonTexture);
		VideoModeButton->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		VideoModeButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	}
}

void UVideoCallWidget::SetAudioButtonToMute()
{
	if (AudioButtonMuteTexture)
	{
		MuteLocalAudioButton->WidgetStyle.Normal.SetResourceObject(AudioButtonMuteTexture);
		MuteLocalAudioButton->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Type::Image;

		MuteLocalAudioButton->WidgetStyle.Hovered.SetResourceObject(AudioButtonMuteTexture);
		MuteLocalAudioButton->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;

		MuteLocalAudioButton->WidgetStyle.Pressed.SetResourceObject(AudioButtonMuteTexture);
		MuteLocalAudioButton->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	}
}

void UVideoCallWidget::SetAudioButtonToUnMute()
{
	if (AudioButtonUnmuteTexture)
	{
		MuteLocalAudioButton->WidgetStyle.Normal.SetResourceObject(AudioButtonUnmuteTexture);
		MuteLocalAudioButton->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Type::Image;

		MuteLocalAudioButton->WidgetStyle.Hovered.SetResourceObject(AudioButtonUnmuteTexture);
		MuteLocalAudioButton->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;

		MuteLocalAudioButton->WidgetStyle.Pressed.SetResourceObject(AudioButtonUnmuteTexture);
		MuteLocalAudioButton->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		MuteLocalAudioButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	}
}

void UVideoCallWidget::SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController)
{
	PlayerController = VideoCallPlayerController;
}

void UVideoCallWidget::SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	VideoCallPtr = std::move(PassedVideoCallPtr);
}