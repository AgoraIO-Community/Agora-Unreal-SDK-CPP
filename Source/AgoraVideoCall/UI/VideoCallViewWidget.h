//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"

#include "VideoViewWidget.h"

#include "VideoCallViewWidget.generated.h"

/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UVideoCallViewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UVideoCallViewWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:
	void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void UpdateMainVideoBuffer(uint32_t uid,
		uint8* RGBBuffer,
		uint32_t Width,
		uint32_t Height,
		uint32_t Size);

	void UpdateAdditionalVideoBuffer(
		uint8* RGBBuffer,
		uint32_t Width,
		uint32_t Height,
		uint32_t Size);

	void ResetBuffers();
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UVideoViewWidget* MainVideoViewWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		USizeBox* MainVideoSizeBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UVideoViewWidget* AdditionalVideoViewWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		USizeBox* AdditionalVideoSizeBox = nullptr;

public:
	int32 MainVideoWidth = 0;
	int32 MainVideoHeight = 0;
};
