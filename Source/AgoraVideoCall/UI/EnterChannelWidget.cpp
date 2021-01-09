//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "EnterChannelWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"

#include "VideoCallPlayerController.h"
#include "DeviceTestWidget.h"

UEnterChannelWidget::UEnterChannelWidget(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
}

void UEnterChannelWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HeaderTextBlock)
		HeaderTextBlock->SetText(FText::FromString("Enter a conference room name"));

	if (DescriptionTextBlock)
		DescriptionTextBlock->SetText(FText::FromString("If you are the first person to specify this name, \
the room will be created and you will\nbe placed in it. \
If it has already been created you will join the conference in progress"));

	if (ChannelNameTextBox)
		ChannelNameTextBox->SetHintText(FText::FromString("Channel Name"));

	if (EncriptionKeyTextBox)
		EncriptionKeyTextBox->SetHintText(FText::FromString("Encription Key"));

	if (EncriptionTypeTextBlock)
		EncriptionTypeTextBlock->SetText(FText::FromString("Enc Type:"));

	if (EncriptionTypeComboBox)
	{
		EncriptionTypeComboBox->AddOption("aes-128");
		EncriptionTypeComboBox->AddOption("aes-256");
		EncriptionTypeComboBox->SetSelectedIndex(0);
	}

	if (JoinButton)
	{
		UTextBlock* JoinTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		JoinTextBlock->SetText(FText::FromString("Join"));
		JoinButton->AddChild(JoinTextBlock);
		JoinButton->OnClicked.AddDynamic(this, &UEnterChannelWidget::OnJoin);
	}

	if (TestButton)
	{
		UTextBlock* TestTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TestTextBlock->SetText(FText::FromString("Test"));
		TestButton->AddChild(TestTextBlock);
		TestButton->OnClicked.AddDynamic(this, &UEnterChannelWidget::OnTest);
        
        if( UGameplayStatics::GetPlatformName() == TEXT( "IOS" ) )
        {
            TestButton->SetVisibility( ESlateVisibility::Hidden );
        }
	}

	if (VideoSettingsButton)
	{
		UTextBlock* TextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TextBlock->SetText(FText::FromString("Resolution"));
		VideoSettingsButton->AddChild(TextBlock);
		VideoSettingsButton->OnClicked.AddDynamic(this, &UEnterChannelWidget::OnVideoSettings);
	}

	if (ContactsTextBlock)
		ContactsTextBlock->SetText(FText::FromString("agora.io Contact support: 400 632 6626"));

	if (BuildInfoTextBlock)
		BuildInfoTextBlock->SetText(FText::FromString(" "));
}

void UEnterChannelWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UEnterChannelWidget::OnJoin()
{
	if (!PlayerController || !VideoCallPtr)
	{
		return;
	}

	FString ChannelName = ChannelNameTextBox->GetText().ToString();

	FString EncryptionKey = EncriptionKeyTextBox->GetText().ToString();
	FString EncryptionType = EncriptionTypeComboBox->GetSelectedOption();

	SetVisibility(ESlateVisibility::Collapsed);

	PlayerController->StartCall(
		std::move(VideoCallPtr),
		ChannelName,
		EncryptionKey,
		EncryptionType);
}

void UEnterChannelWidget::OnTest()
{
	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->SwitchOnTestWidget(std::move(VideoCallPtr));
	}
}

void UEnterChannelWidget::OnVideoSettings()
{
	if (PlayerController)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		PlayerController->SwitchOnVideoSettingsWidget(std::move(VideoCallPtr));
	}
}

void UEnterChannelWidget::SetVideoCallPlayerController(AVideoCallPlayerController* VideoCallPlayerController)
{
	PlayerController = VideoCallPlayerController;
}

void UEnterChannelWidget::SetVideoCall(TUniquePtr<VideoCall> PassedVideoCallPtr)
{
	VideoCallPtr = std::move(PassedVideoCallPtr);
}

void UEnterChannelWidget::UpdateVideoSettingsButtonText(FString newValue)
{
	if (VideoSettingsButton)
	{
		auto Child = VideoSettingsButton->GetChildAt(0);
		UTextBlock*TextBlock = Cast<UTextBlock>(Child);
		if (TextBlock)
		{
			TextBlock->SetText(FText::FromString(newValue));
		}
	}
}

void UEnterChannelWidget::UpdateVersionText(FString newValue)
{
	BuildInfoTextBlock->SetText(FText::FromString(newValue));
}
