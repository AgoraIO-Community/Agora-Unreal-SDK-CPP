//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoCallViewWidget.h"

#include "Components/CanvasPanelSlot.h"

UVideoCallViewWidget::UVideoCallViewWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UVideoCallViewWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UVideoCallViewWidget::NativeDestruct()
{
	Super::NativeDestruct();

}

void UVideoCallViewWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	auto ScreenSize = MyGeometry.GetLocalSize();

	if (MainVideoHeight != 0)
	{
		float AspectRatio = 0;
		AspectRatio = MainVideoWidth / (float)MainVideoHeight;

		auto MainVideoGeometry = MainVideoViewWidget->GetCachedGeometry();
		auto MainVideoScreenSize = MainVideoGeometry.GetLocalSize();
		if (MainVideoScreenSize.X == 0)
		{
			return;
		}

		auto NewMainVideoHeight = MainVideoScreenSize.Y;
		auto NewMainVideoWidth = AspectRatio * NewMainVideoHeight;

		MainVideoSizeBox->SetMinDesiredWidth(NewMainVideoWidth);
		MainVideoSizeBox->SetMinDesiredHeight(NewMainVideoHeight);

		UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(MainVideoSizeBox->Slot);
		CanvasSlot->SetAutoSize(true);

		FVector2D NewPosition;
		NewPosition.X = -NewMainVideoWidth / 2;
		NewPosition.Y = -NewMainVideoHeight / 2;
		CanvasSlot->SetPosition(NewPosition);
	}
}

void UVideoCallViewWidget::UpdateMainVideoBuffer(
	uint8* RGBBuffer,
	uint32_t Width,
	uint32_t Height,
	uint32_t Size)
{
	if (!MainVideoViewWidget)
	{
		return;
	}
	MainVideoWidth = Width;
	MainVideoHeight = Height;
	MainVideoViewWidget->UpdateBuffer(RGBBuffer, Width, Height, Size);
}

void UVideoCallViewWidget::UpdateAdditionalVideoBuffer(
	uint8* RGBBuffer,
	uint32_t Width,
	uint32_t Height,
	uint32_t Size)
{
	if (!AdditionalVideoViewWidget)
	{
		return;
	}
	AdditionalVideoViewWidget->UpdateBuffer(RGBBuffer, Width, Height, Size);
}

void UVideoCallViewWidget::ResetBuffers()
{
	if (!MainVideoViewWidget || !AdditionalVideoViewWidget)
	{
		return;
	}
	MainVideoViewWidget->ResetBuffer();
	AdditionalVideoViewWidget->ResetBuffer();
}