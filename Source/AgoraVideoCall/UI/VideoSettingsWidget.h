//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


#include <map>

#include "VideoCall.h"

#include "VideoSettingsWidget.generated.h"

class AVideoCallPlayerController;
/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UVideoSettingsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UVideoSettingsWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:

	UFUNCTION(BlueprintCallable)
		void OnCancel();

	UFUNCTION(BlueprintCallable)
		void OnConfirm();

	void SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController);

	void SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void GetCurrentResolution(
		int& Width,
		int& Height,
		agora::rtc::FRAME_RATE& FrameRate) const;

	FString GetCurrentResolution() const;
public:
	AVideoCallPlayerController* PlayerController = nullptr;

	TUniquePtr<VideoCall> VideoCallPtr;

	struct Entry
	{
		Entry(
			int PassedWidth,
			int PassedHeight,
			agora::rtc::FRAME_RATE PassedFrameRate)
			: Width(PassedWidth)
			, Height(PassedHeight)
			, FrameRate(PassedFrameRate)
		{
			TextOption = FString::FromInt(Width) + "x"
				+ FString::FromInt(Height) + " " + FString::FromInt(FrameRate) + "fps";
		}
		int Width;
		int Height;
		agora::rtc::FRAME_RATE FrameRate;
		FString TextOption;
	};
	std::map<int, Entry> Options;

	int32 SelectedIndex = 0;
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* CancelButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* ConfirmButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = ( BindWidget ))
		UTextBlock* ResolutionTextBlock = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UComboBoxString* ResolutionComboBox = nullptr;
};
