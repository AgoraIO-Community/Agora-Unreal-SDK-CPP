//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Image.h"

#include "VideoViewWidget.generated.h"

/**
 * 
 */
UCLASS()
class AGORAVIDEOCALL_API UVideoViewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UVideoViewWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	void NativeDestruct() override;

public:
	void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void UpdateBuffer(
        uint32_t uid,
		uint8* RGBBuffer,
		uint32_t Width,
		uint32_t Height,
		uint32_t Size);

	void ResetBuffer();

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UImage* RenderTargetImage = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UTexture2D* RenderTargetTexture = nullptr;

	UTexture2D* CameraoffTexture = nullptr;

	uint8* Buffer = nullptr;
	uint32_t Width = 0;
	uint32_t Height = 0;
	uint32 BufferSize = 0;
    uint32_t userId = 0;
	FUpdateTextureRegion2D* UpdateTextureRegion = nullptr;
    FUpdateTextureRegion2D* TmpUpdateTextureRegion = nullptr;
	FSlateBrush Brush;
	FCriticalSection Mutex;
    bool needUpdateFlag = false;
};

