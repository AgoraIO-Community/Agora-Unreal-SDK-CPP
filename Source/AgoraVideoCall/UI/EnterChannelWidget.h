//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/RichTextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"
#include "Components/Image.h"

#include "VideoCall.h"

#include "EnterChannelWidget.generated.h"

class AVideoCallPlayerController;
/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UEnterChannelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEnterChannelWidget(const FObjectInitializer& objectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:
	UFUNCTION(BlueprintCallable)
		void OnJoin();

	UFUNCTION(BlueprintCallable)
		void OnTest();

	UFUNCTION(BlueprintCallable)
		void OnVideoSettings();

	//TODO: move to new base class?
	void SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController);

	void SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void UpdateVideoSettingsButtonText(FString newValue);

	void UpdateVersionText(FString newValue);
public:
	AVideoCallPlayerController* PlayerController = nullptr;

	TUniquePtr<VideoCall> VideoCallPtr;
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* HeaderTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* DescriptionTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UEditableTextBox* ChannelNameTextBox = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UEditableTextBox* EncriptionKeyTextBox = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* EncriptionTypeTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UComboBoxString* EncriptionTypeComboBox = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* JoinButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* TestButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UButton* VideoSettingsButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* ContactsTextBlock = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* BuildInfoTextBlock = nullptr;

};
