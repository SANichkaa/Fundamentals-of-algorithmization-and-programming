// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndTurnButton.generated.h"

/**
 * 
 */
UCLASS()
class NEWGAME_API UEndTurnButton : public UUserWidget
{
	GENERATED_BODY()

	float herohp = 100;
	float firstenemyhp = 100;
	float secondenemyhp = 100;

	double min_without_shield = 15.0;
	double max_without_shield = 25.0;
	double damage_without_shield;
	double min_with_shield = 5;
	double max_with_shield = 15;
	double damage_with_shield;

	int steps = 0;

	bool shield = false;
	bool shieldsuccess = false;
	bool dodge_hero = false;
	bool dodge_first_enemy = false;
	bool dodge_second_enemy = false;

	virtual bool Initialize();

	// КНОПКИ

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* knopka;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* buttonfirst;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* buttonsecond;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* buttonthird;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* menubutton;

	// ПОЛЯ С ТЕКСТОМ

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* buttonfirsttext;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* buttonsecondtext;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* buttonthirdtext;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DodgeHero;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DodgeFirstEnemy;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DodgeSecondEnemy;

	//HEALTH и ATTACK

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HeroHealth;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* FirstEnemyHealth;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SecondEnemyHealth;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HeroAttack;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* FirstEnemyAttack;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SecondEnemyAttack;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* stepcounter;

	// Картинки

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* WinScreen;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* LooseScreen;


	UFUNCTION()
	void EndTurnButtonClicked();

	UFUNCTION()
	void MenuButtonClicked();
	
	UFUNCTION()
	void ButtonfirstClicked();

	UFUNCTION()
	void ButtonsecondClicked();

	UFUNCTION()
	void ButtonthirdClicked();

	UFUNCTION()
	void RefreshStats();

	UFUNCTION()
	void EnableButtons();

	UFUNCTION()
	void SetAndBlockButtons(int cardcode);

	UFUNCTION()
	void RandDamageWith_WithoutShield();

	UFUNCTION()
	void DealDamage();

	UFUNCTION()
	void GetDamage();

	UFUNCTION()
	void WinOrLoose();
};
