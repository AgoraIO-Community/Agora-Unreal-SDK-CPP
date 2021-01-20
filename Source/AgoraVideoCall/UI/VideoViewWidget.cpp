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
	Width = 1080;
	Height = 720;

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
    Buffer = nullptr;
	delete UpdateTextureRegion;
    UpdateTextureRegion = nullptr;
}

void UVideoViewWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
    FScopeLock lock(&Mutex);
	Super::NativeTick(MyGeometry, DeltaTime);
    
    if (needUpdateFlag) {
        if (UpdateTextureRegion->Width != Width ||
            UpdateTextureRegion->Height != Height)
        {
            UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 111"));
            auto NewUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);

            auto NewRenderTargetTexture = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8);
            
            UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 222"));
            NewRenderTargetTexture->UpdateTextureRegions(0, 1, NewUpdateTextureRegion, Width * 4, (uint32)4, Buffer);
            UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 333"));
            NewRenderTargetTexture->UpdateResource();
            Brush.SetResourceObject(NewRenderTargetTexture);
            UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 444"));
            RenderTargetImage->SetBrush(Brush);
            //UClass's such as UTexture2D are automatically garbage collected when there is no hard pointer references made to that object.
            //So if you just leave it and don't reference it elsewhere then it will be destroyed automatically.
            if (TmpUpdateTextureRegion) {
                delete TmpUpdateTextureRegion;
                UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 555"));
                TmpUpdateTextureRegion = nullptr;
            }
            TmpUpdateTextureRegion = UpdateTextureRegion;
            RenderTargetTexture = NewRenderTargetTexture;
            UpdateTextureRegion = NewUpdateTextureRegion;
            needUpdateFlag = false;
            UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 666"));
            return;
        }
        UE_LOG(LogTemp, Warning, TEXT("CFUpdateTextureRegion2D 777"));
        RenderTargetTexture->UpdateTextureRegions(0, 1, UpdateTextureRegion, Width * 4, (uint32)4, Buffer);
        if (TmpUpdateTextureRegion) {
            delete TmpUpdateTextureRegion;
            TmpUpdateTextureRegion = nullptr;
        }
        needUpdateFlag = false;
    }
}

void UVideoViewWidget::UpdateBuffer(
    uint32_t uid,
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
    userId = uid;
    needUpdateFlag = true;
    UE_LOG(LogTemp, Warning, TEXT("UpdateBuffer 111   uid: %d"), uid);
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
    FScopeLock lock(&Mutex);
	for (uint32 i = 0; i < Width * Height; ++i)
	{
		Buffer[i * 4 + 0] = 0x32;
		Buffer[i * 4 + 1] = 0x32;
		Buffer[i * 4 + 2] = 0x32;
		Buffer[i * 4 + 3] = 0xFF;
	}
    userId = -1;
}
