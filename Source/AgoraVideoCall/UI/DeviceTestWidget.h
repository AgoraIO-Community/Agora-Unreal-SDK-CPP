//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"

#include "VideoCall.h"

#include "DeviceTestWidget.generated.h"

class AVideoCallPlayerController;
class UVideoViewWidget;
/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UDeviceTestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UDeviceTestWidget(const FObjectInitializer& objectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:
	void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void OnMicrophoneVolumeChanged();

	UFUNCTION(BlueprintCallable)
		void OnSpeakersVolumeChanged();

	UFUNCTION(BlueprintCallable)
		void OnMicrophoneComboBoxSelectionChanged();

	UFUNCTION(BlueprintCallable)
		void OnSpeakersComboBoxSelectionChanged();

	UFUNCTION(BlueprintCallable)
		void OnCameraComboBoxSelectionChanged();

	UFUNCTION(BlueprintCallable)
		void OnMicrophoneTest();

	UFUNCTION(BlueprintCallable)
		void OnSpeakersTest();

	UFUNCTION(BlueprintCallable)
		void OnCameraTest();

	UFUNCTION(BlueprintCallable)
		void OnEchoTest();

	UFUNCTION(BlueprintCallable)
		void OnCancel();

	UFUNCTION(BlueprintCallable)
		void OnConfirm();

	void OnExit();

	void SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController);

	void SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void StartCameraTest();
	void StopCameraTest();

	void StartMicrophoneTest();
	void StopMicrophoneTest();

	void StartSpeakersTest();
	void StopSpeakersTest();

	void StartEchoTest();
	void StopEchoTest();

	FString CreateAudioFileForSpeakersTest();
public:
	AVideoCallPlayerController* PlayerController = nullptr;

	TUniquePtr<VideoCall> VideoCallPtr;

	TUniquePtr<CameraManager> CameraManagerPtr;
	TUniquePtr<AudioInOutDeviceManager> AudioDeviceManagerPtr;

	float MicrophoneVolume = 0;
	float SpeakersVolume = 0;

	FString DefaultVideoDeviceName;
	FString DefaultRecordingDeviceName;
	FString DefaultPlaybackDeviceName;

	bool IsTestingRecording = false;
	bool IsTestingPlayback = false;
	bool IsEchoTesting = false;

	int32 VideoWidth = 0;
	int32 VideoHeight = 0;

public:
	// buttons
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* MicrophoneTestButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* SpeakersTestButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* CameraTestButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* EchoTestButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* CancelButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* ConfirmButton = nullptr;

	// text blocks
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* MicrophoneTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* SpeakersTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* CameraTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* MicrophoneVolumeTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* SpeakersVolumeTextBlock = nullptr;

	// combo boxes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UComboBoxString* MicrophoneComboBox = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UComboBoxString* SpeakersComboBox = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UComboBoxString* CameraComboBox = nullptr;

	// sliders
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		USlider* MicrophoneVolumeSlider = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		USlider* SpeakersVolumeSlider = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UVideoViewWidget* TestVideoViewWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		USizeBox* TestVideoViewWidgetSizeBox = nullptr;
};
