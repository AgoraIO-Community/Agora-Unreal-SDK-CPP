//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoViewWidget.h"

#include "EngineUtils.h"
#include "Engine/Texture2D.h"

#include <algorithm>

UVideoViewWidget::UVideoViewWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultTexture(TEXT("Texture2D'/Game/Textures/cameraoff_mainVideo.cameraoff_mainVideo'"));
	if (DefaultTexture.Succeeded())
	{
		CameraoffTexture = DefaultTexture.Object;
	}
}

void UVideoViewWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//TODO:
	Width = 640;
	Height = 360;

	RenderTargetTexture = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8 );

	BufferSize = Width * Height * 4;
	Buffer = new uint8[BufferSize];
	for (uint32 i = 0; i < Width * Height; ++i)
	{
		Buffer[i * 4 + 0] = 0x32;
		Buffer[i * 4 + 1] = 0x32;
		Buffer[i * 4 + 2] = 0x32;
		Buffer[i * 4 + 3] = 0xFF;
	}
	UpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	RenderTargetTexture->UpdateTextureRegions(0, 1, UpdateTextureRegion, Width * 4, (uint32)4, Buffer);
    RenderTargetTexture->UpdateResource();

	Brush.SetResourceObject(RenderTargetTexture);
    RenderTargetImage->SetBrush(Brush);
}

void UVideoViewWidget::NativeDestruct()
{
	Super::NativeDestruct();

	delete[] Buffer;
	delete UpdateTextureRegion;
}

void UVideoViewWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	FScopeLock lock(&Mutex);

	if (UpdateTextureRegion->Width != Width ||
		UpdateTextureRegion->Height != Height)
	{
		auto NewUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);

		auto NewRenderTargetTexture = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8);
		
		NewRenderTargetTexture->UpdateTextureRegions(0, 1, NewUpdateTextureRegion, Width * 4, (uint32)4, Buffer);
        NewRenderTargetTexture->UpdateResource();
        
		Brush.SetResourceObject(NewRenderTargetTexture);
		RenderTargetImage->SetBrush(Brush);
		//UClass's such as UTexture2D are automatically garbage collected when there is no hard pointer references made to that object.
		//So if you just leave it and don't reference it elsewhere then it will be destroyed automatically.
        if (TmpUpdateTextureRegion) {
            delete TmpUpdateTextureRegion;
            TmpUpdateTextureRegion = nullptr;
        }
        TmpUpdateTextureRegion = UpdateTextureRegion;
		RenderTargetTexture = NewRenderTargetTexture;
		UpdateTextureRegion = NewUpdateTextureRegion;
		return;
	}
    
	RenderTargetTexture->UpdateTextureRegions(0, 1, UpdateTextureRegion, Width * 4, (uint32)4, Buffer);
    if (TmpUpdateTextureRegion) {
        delete TmpUpdateTextureRegion;
        TmpUpdateTextureRegion = nullptr;
    }
}

void UVideoViewWidget::UpdateBuffer(
	uint8* RGBBuffer,
	uint32_t NewWidth,
	uint32_t NewHeight,
	uint32_t NewSize)
{
	FScopeLock lock(&Mutex);

	if (!RGBBuffer)
	{
		return;
	}

	if (BufferSize == NewSize)
	{
		std::copy(RGBBuffer, RGBBuffer + NewSize, Buffer);
	}
	else
	{
		delete[] Buffer;
		BufferSize = NewSize;
		Width = NewWidth;
		Height = NewHeight;
		Buffer = new uint8[BufferSize];
		std::copy(RGBBuffer, RGBBuffer + NewSize, Buffer);
	}
}

void UVideoViewWidget::ResetBuffer()
{
	for (uint32 i = 0; i < Width * Height; ++i)
	{
		Buffer[i * 4 + 0] = 0x32;
		Buffer[i * 4 + 1] = 0x32;
		Buffer[i * 4 + 2] = 0x32;
		Buffer[i * 4 + 3] = 0xFF;
	}
    userId = 0;
}
