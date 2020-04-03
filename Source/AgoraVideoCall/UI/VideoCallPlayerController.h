//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Templates/UniquePtr.h"

#include "VideoCall.h"

#include "VideoCallPlayerController.generated.h"

class UEnterChannelWidget;
class UDeviceTestWidget;
class UVideoCallWidget;
class UVideoSettingsWidget;

/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API AVideoCallPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wEnterChannelWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wDeviceTestWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wVideoCallWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wVideoSettingsWidget;

	// Variable to hold the widget After Creating it.
	UEnterChannelWidget* EnterChannelWidget = nullptr;

	UDeviceTestWidget* DeviceTestWidget = nullptr;

	UVideoCallWidget* VideoCallWidget = nullptr;

	UVideoSettingsWidget* VideoSettingsWidget = nullptr;

	TUniquePtr<VideoCall> VideoCallPtr;

	// Override BeginPlay()
	void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void StartCall(
		TUniquePtr<VideoCall> PassedVideoCallPtr,
		const FString& ChannelName,
		const FString& EncryptionKey,
		const FString& EncryptionType
		);

	void EndCall(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void SwitchOnEnterChannelWidget(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void SwitchOnTestWidget(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void SwitchOnVideoCallWidget(TUniquePtr<VideoCall> PassedVideoCallPtr);

	void SwitchOnVideoSettingsWidget(TUniquePtr<VideoCall> PassedVideoCallPtr);
};
