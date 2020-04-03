//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoSettingsWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"

#include "VideoCallPlayerController.h"

UVideoSettingsWidget::UVideoSettingsWidget(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
}

void UVideoSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// buttons
	if (CancelButton)
	{
		UTextBlock* CancelButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		CancelButtonTextBlock->SetText(FText::FromString("Cancel"));
		CancelButton->AddChild(CancelButtonTextBlock);
		CancelButton->OnClicked.AddDynamic(this, &UVideoSettingsWidget::OnCancel);
	}

	if (ConfirmButton)
	{
		UTextBlock* ConfirmButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		ConfirmButtonTextBlock->SetText(FText::FromString("Confirm"));
		ConfirmButton->AddChild(ConfirmButtonTextBlock);
		ConfirmButton->OnClicked.AddDynamic(this, &UVideoSettingsWidget::OnConfirm);
	}

	if (ResolutionComboBox)
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, FName("OnResolutionComboBoxSelectionChanged"));
		ResolutionComboBox->OnSelectionChanged.Add(Delegate);
	}

	if (ResolutionTextBlock)
	{
		ResolutionTextBlock->SetText(FText::FromString("Resolution"));
	}

	//fill ResolutionComboBox
	Options.emplace(0, Entry(640, 360, agora::rtc::FRAME_RATE_FPS_15));
	ResolutionComboBox->AddOption(Options.at(0).TextOption);

	SelectedIndex = 0;
	ResolutionComboBox->SetSelectedIndex(SelectedIndex);

	Options.emplace(1, Entry(640, 480, agora::rtc::FRAME_RATE_FPS_15));
	ResolutionComboBox->AddOption(Options.at(1).TextOption);

	Options.emplace(2, Entry(1280, 720, agora::rtc::FRAME_RATE_FPS_30));
	ResolutionComboBox->AddOption(Options.at(2).TextOption);
}

void UVideoSettingsWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UVideoSettingsWidget::OnCancel()
{
	ResolutionComboBox->SetSelectedIndex(SelectedIndex);
	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->SwitchOnEnterChannelWidget(std::move(VideoCallPtr));
	}
}

void UVideoSettingsWidget::OnConfirm()
{
	auto Index = ResolutionComboBox->GetSelectedIndex();
	auto Found = Options.find(Index);
	if (Found == Options.end())
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find selected resolution option."));
		return;
	}
	if (!VideoCallPtr)
	{
		return;
	}
	VideoCallPtr->SetResolution(Found->second.Width, Found->second.Height, Found->second.FrameRate);
	SelectedIndex = Index;

	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->SwitchOnEnterChannelWidget(std::move(VideoCallPtr));
	}
}

void UVideoSettingsWidget::SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController)
{
	PlayerController = VideoCallPlayerController;
}

void UVideoSettingsWidget::SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	VideoCallPtr = std::move(PassedVideoCallPtr);
}

void UVideoSettingsWidget::GetCurrentResolution(
	int& Width,
	int& Height,
	agora::rtc::FRAME_RATE& FrameRate) const
{
	auto Index = ResolutionComboBox->GetSelectedIndex();
	auto Found = Options.find(Index);
	if (Found == Options.end())
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find selected resolution option."));
		return;
	}
	Width = Found->second.Width;
	Height = Found->second.Height;
	FrameRate = Found->second.FrameRate;
}

FString UVideoSettingsWidget::GetCurrentResolution() const
{
	auto Index = ResolutionComboBox->GetSelectedIndex();
	auto Found = Options.find(Index);
	if (Found == Options.end())
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find selected resolution option."));
		return "";
	}
	return Found->second.TextOption;
}