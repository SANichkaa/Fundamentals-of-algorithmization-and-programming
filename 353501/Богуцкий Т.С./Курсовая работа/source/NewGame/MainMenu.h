// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class NEWGAME_API UMainMenu : public UUserWidget
{

	GENERATED_BODY()

	virtual bool Initialize();

	// КНОПКИ
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* StartGameButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitGameButton;

	// ТЕКСТ И ФОН
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* StartGameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* QuitGameText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* Title;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* MainMenuBackground;

	// ФУНКЦИИ
	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void QuitGame();
};
