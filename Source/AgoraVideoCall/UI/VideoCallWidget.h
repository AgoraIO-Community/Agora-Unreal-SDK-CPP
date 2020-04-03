//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Templates/UniquePtr.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Engine/Texture2D.h"

#include "VideoCall.h"

#include "VideoCallViewWidget.h"

#include "VideoCallWidget.generated.h"

class AVideoCallPlayerController;
class UVideoViewWidget;
/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UVideoCallWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UVideoCallWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:
	void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void OnStartCall(
		const FString& ChannelName,
		const FString& EncryptionKey,
		const FString& EncryptionType);

	UFUNCTION(BlueprintCallable)
		void OnEndCall();

	UFUNCTION(BlueprintCallable)
		void OnMuteLocalAudio();

	UFUNCTION(BlueprintCallable)
		void OnChangeVideoMode();

	void SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController);

	void SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr);
public:
	AVideoCallPlayerController* PlayerController = nullptr;

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UVideoCallViewWidget* VideoCallViewWidget = nullptr;

	//Buttons
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* EndCallButton = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* MuteLocalAudioButton = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* VideoModeButton = nullptr;

	//Button textures
	int32 ButtonSizeX = 96;
	int32 ButtonSizeY = 96;
	UTexture2D* EndCallButtonTexture = nullptr;
	UTexture2D* AudioButtonMuteTexture = nullptr;
	UTexture2D* AudioButtonUnmuteTexture = nullptr;
	UTexture2D* VideomodeButtonCameraoffTexture = nullptr;
	UTexture2D* VideomodeButtonCameraonTexture = nullptr;

	TUniquePtr<VideoCall> VideoCallPtr;
private:
	void InitButtons();

	void SetVideoModeButtonToCameraOff();
	void SetVideoModeButtonToCameraOn();

	void SetAudioButtonToMute();
	void SetAudioButtonToUnMute();
};
