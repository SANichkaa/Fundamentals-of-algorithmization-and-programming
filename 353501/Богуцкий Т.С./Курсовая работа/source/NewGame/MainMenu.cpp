// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"

bool UMainMenu::Initialize()
{
	Super::Initialize();
	
	StartGameButton->OnClicked.AddDynamic(this, &UMainMenu::StartGame);
	StartGameButton->AddChild(StartGameText);

	QuitGameButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	QuitGameButton->AddChild(QuitGameText);

	FText txt1 = NSLOCTEXT("MyNamespace", "KeyString", "Новая игра");
	StartGameText->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f));
	StartGameText->SetText(txt1);

	FText txt2 = NSLOCTEXT("MyNamespace", "KeyString", "Выйти");
	QuitGameText->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f));
	QuitGameText->SetText(txt2);

	FText txt3 = NSLOCTEXT("MyNamespace", "KeyString", "STS");
	Title->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 0.0f));
	Title->SetText(txt3);

	return true;
}

void UMainMenu::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainLevel", true, "");
	SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenu::QuitGame()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}
