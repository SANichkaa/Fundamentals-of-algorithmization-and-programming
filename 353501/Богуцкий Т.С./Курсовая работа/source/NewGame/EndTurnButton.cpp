// Fill out your copyright notice in the Description page of Project Settings.

#include "EndTurnButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"
#include "random"
#include "cstdlib"


bool UEndTurnButton::Initialize()
{
	Super::Initialize();

	knopka->OnClicked.AddDynamic(this, &UEndTurnButton::EndTurnButtonClicked);

	menubutton->OnClicked.AddDynamic(this, &UEndTurnButton::MenuButtonClicked);
	
	buttonfirst->OnClicked.AddDynamic(this, &UEndTurnButton::ButtonfirstClicked);

	buttonsecond->OnClicked.AddDynamic(this, &UEndTurnButton::ButtonsecondClicked);

	buttonthird->OnClicked.AddDynamic(this, &UEndTurnButton::ButtonthirdClicked);

	WinScreen->SetVisibility(ESlateVisibility::Hidden);
	LooseScreen->SetVisibility(ESlateVisibility::Hidden);
	DodgeHero->SetVisibility(ESlateVisibility::Hidden);
	DodgeFirstEnemy->SetVisibility(ESlateVisibility::Hidden);
	DodgeSecondEnemy->SetVisibility(ESlateVisibility::Hidden);
	
	return true;
}

void UEndTurnButton::EnableButtons() {
	FText txt = NSLOCTEXT("MyNamespace", "KeyString", "Выбрать карту");
	FLinearColor NewColor(0.0f, 1.0f, 1.0f, 1.0f);
	buttonfirst->SetIsEnabled(true);
	buttonfirsttext->SetColorAndOpacity(NewColor);
	buttonfirsttext->SetText(txt);

	buttonsecond->SetIsEnabled(true);
	buttonsecondtext->SetColorAndOpacity(NewColor);
	buttonsecondtext->SetText(txt);

	buttonthird->SetIsEnabled(true);
	buttonthirdtext->SetColorAndOpacity(NewColor);
	buttonthirdtext->SetText(txt);
}

void UEndTurnButton::SetAndBlockButtons(int cardcode){
	if (cardcode == 1) {
		FText firstcard = NSLOCTEXT("MyNamespace", "KeyString", "Карта выбрана");
		FLinearColor PurpleColor(0.8f, 0.0f, 0.8f);
		buttonfirsttext->SetColorAndOpacity(PurpleColor);
		buttonfirsttext->SetText(firstcard);

		FText othercards = NSLOCTEXT("MyNamespace", "KeyString", "ЗАБЛОКИРОВАНО");
		FLinearColor RedColor(1.0f, 0.0f, 0.0f);
		buttonsecondtext->SetColorAndOpacity(RedColor);
		buttonsecondtext->SetText(othercards);

		if (shield == false) {
			buttonthirdtext->SetColorAndOpacity(RedColor);
			buttonthirdtext->SetText(othercards);
		}

		buttonfirst->SetIsEnabled(false);
		buttonsecond->SetIsEnabled(false);
		buttonthird->SetIsEnabled(false);
	}
	else if (cardcode == 2) {
		FText secondcard = NSLOCTEXT("MyNamespace", "KeyString", "Карта выбрана");
		FLinearColor PurpleColor(0.8f, 0.0f, 0.8f);
		buttonsecondtext->SetColorAndOpacity(PurpleColor);
		buttonsecondtext->SetText(secondcard);

		FText othercards = NSLOCTEXT("MyNamespace", "KeyString", "ЗАБЛОКИРОВАНО");
		FLinearColor RedColor(1.0f, 0.0f, 0.0f);
		buttonfirsttext->SetColorAndOpacity(RedColor);
		buttonfirsttext->SetText(othercards);
		buttonthirdtext->SetColorAndOpacity(RedColor);
		buttonthirdtext->SetText(othercards);

		buttonfirst->SetIsEnabled(false);
		buttonsecond->SetIsEnabled(false);
		buttonthird->SetIsEnabled(false);
	}
	else {
		FText thirdcard = NSLOCTEXT("MyNamespace", "KeyString", "Карта выбрана");
		FLinearColor PurpleColor(0.8f, 0.0f, 0.8f);
		buttonthirdtext->SetColorAndOpacity(PurpleColor);
		buttonthirdtext->SetText(thirdcard);

		FText othercards = NSLOCTEXT("MyNamespace", "KeyString", "ЗАБЛОКИРОВАНО");
		FLinearColor RedColor(1.0f, 0.0f, 0.0f);
		buttonsecondtext->SetColorAndOpacity(RedColor);
		buttonsecondtext->SetText(othercards);

		buttonsecond->SetIsEnabled(false);
		buttonthird->SetIsEnabled(false);
	}
}

void UEndTurnButton::RandDamageWith_WithoutShield() {
	// генерация урона 
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	min_without_shield = 15.0;
	max_without_shield = 25.0;
	damage_without_shield = min_without_shield + (max_without_shield - min_without_shield) * static_cast<double>(std::rand()) / RAND_MAX;

	std::srand(static_cast<unsigned>(std::time(nullptr)));
	min_with_shield = 5;
	max_with_shield = 15;
	damage_with_shield = min_with_shield + (max_with_shield - min_with_shield) * static_cast<double>(std::rand()) / RAND_MAX;
}

void UEndTurnButton::DealDamage() {
	RandDamageWith_WithoutShield();

	// НАНЕСЕНИЕ УРОНА ВРАГУ
	if (shield) {

		if (firstenemyhp != 0.0) {
			firstenemyhp >= damage_with_shield ? firstenemyhp -= damage_with_shield : firstenemyhp = 0.0;
			FText helperfirstenemy = FText::AsNumber(firstenemyhp);
			FirstEnemyHealth->SetText(helperfirstenemy);
			if (firstenemyhp == 0) FirstEnemyAttack->SetText(helperfirstenemy);
		}

		else if (firstenemyhp == 0.0) {
			secondenemyhp >= damage_with_shield ? secondenemyhp -= damage_with_shield : secondenemyhp = 0.0;
			FText helpersecondenemy = FText::AsNumber(secondenemyhp);
			SecondEnemyHealth->SetText(helpersecondenemy);
			if (secondenemyhp == 0) SecondEnemyAttack->SetText(helpersecondenemy);
		}
	}
	else {

		if (firstenemyhp != 0.0) {
			firstenemyhp >= damage_without_shield ? firstenemyhp -= damage_without_shield : firstenemyhp = 0.0;
			FText helperfirstenemy = FText::AsNumber(firstenemyhp);
			FirstEnemyHealth->SetText(helperfirstenemy);
			if (firstenemyhp == 0.0) FirstEnemyAttack->SetText(helperfirstenemy);
		}

		else if (firstenemyhp == 0.0) {
			secondenemyhp >= damage_without_shield ? secondenemyhp -= damage_without_shield : secondenemyhp = 0.0;
			FText helpersecondenemy = FText::AsNumber(secondenemyhp);
			SecondEnemyHealth->SetText(helpersecondenemy);
			if (secondenemyhp == 0.0) SecondEnemyAttack->SetText(helpersecondenemy);
		}
	}
}

void UEndTurnButton::GetDamage(){

	// генерация рандомного получаемого урона
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	double min_damage = 5;
	double max_damage = 15;
	double damage_first_enemy = min_damage + (max_damage - min_damage) * static_cast<double>(std::rand()) / RAND_MAX;
	double damage_second_enemy = min_damage + (max_damage - min_damage) * static_cast<double>(std::rand()) / RAND_MAX;
	double fulldamage = damage_first_enemy + damage_second_enemy;

	FMath::RandRange(1, 10) == 1 ? dodge_hero = true : dodge_hero = false;

	if (dodge_hero) DodgeHero->SetVisibility(ESlateVisibility::Visible);
	else {

		if (shieldsuccess == false) {
			if (firstenemyhp != 0) {
				herohp >= fulldamage ? herohp -= fulldamage : herohp = 0;
				FText helperhero = FText::AsNumber(herohp);
				HeroHealth->SetText(helperhero);
			}
			else {
				herohp >= damage_first_enemy ? herohp -= damage_first_enemy : herohp = 0;
				FText helperhero = FText::AsNumber(herohp);
				HeroHealth->SetText(helperhero);
			}
		}

		else {
			FText info1 = NSLOCTEXT("MyNamespace", "KeyString", "Щит спас");
			DodgeHero->SetText(info1);
			DodgeHero->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UEndTurnButton::WinOrLoose(){

	if (herohp == 0) {
		FText death = FText::AsNumber(herohp);
		HeroAttack->SetText(death);
		DodgeHero->SetVisibility(ESlateVisibility::Hidden);
		DodgeFirstEnemy->SetVisibility(ESlateVisibility::Hidden);
		DodgeSecondEnemy->SetVisibility(ESlateVisibility::Hidden);
		LooseScreen->SetVisibility(ESlateVisibility::Visible);
	}

	else if (herohp != 0 && firstenemyhp == 0 && secondenemyhp == 0) {
		DodgeHero->SetVisibility(ESlateVisibility::Hidden);
		DodgeFirstEnemy->SetVisibility(ESlateVisibility::Hidden);
		DodgeSecondEnemy->SetVisibility(ESlateVisibility::Hidden);
		WinScreen->SetVisibility(ESlateVisibility::Visible);
	}

}

void UEndTurnButton::EndTurnButtonClicked()
{
	FText info2 = NSLOCTEXT("MyNamespace", "KeyString", "Увернулся");
	DodgeHero->SetText(info2);
	DodgeHero->SetVisibility(ESlateVisibility::Hidden);

	EnableButtons();
	GetDamage();
	WinOrLoose();
	
	shield = false;
	shieldsuccess = false;
	dodge_hero = false;
	steps++;

	FText ammountofsteps = FText::AsNumber(steps);
	stepcounter->SetText(ammountofsteps);

	if (firstenemyhp == 0.0)
		DodgeFirstEnemy->SetVisibility(ESlateVisibility::Visible);
	if (secondenemyhp == 0.0)
		DodgeSecondEnemy->SetVisibility(ESlateVisibility::Visible);
}

void UEndTurnButton::MenuButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true, "");
	SetVisibility(ESlateVisibility::Hidden);

	RefreshStats();

	WinScreen->SetVisibility(ESlateVisibility::Hidden);
	LooseScreen->SetVisibility(ESlateVisibility::Hidden);
	DodgeHero->SetVisibility(ESlateVisibility::Hidden);
}

void UEndTurnButton::RefreshStats() {
	herohp = 100;
	FText helperhero = FText::AsNumber(herohp);
	FText helperattack = NSLOCTEXT("MyNamespace", "KeyString", "5 - 25");
	HeroHealth->SetText(helperhero);
	HeroAttack->SetText(helperattack);

	firstenemyhp = 100;
	FText helperfirstenemy = FText::AsNumber(firstenemyhp);
	FText helperfirstattack = NSLOCTEXT("MyNamespace", "KeyString", "5 - 15");
	FirstEnemyHealth->SetText(helperfirstenemy);
	FirstEnemyAttack->SetText(helperfirstattack);

	secondenemyhp = 100;
	FText helpersecondenemy = FText::AsNumber(secondenemyhp);
	FText helpersecondattack = NSLOCTEXT("MyNamespace", "KeyString", "5 - 15");
	SecondEnemyHealth->SetText(helpersecondenemy);
	SecondEnemyAttack->SetText(helpersecondattack);

	steps = 0;
	shield = false;
	shieldsuccess = false;
	dodge_hero = false;
	dodge_first_enemy = false;
	dodge_second_enemy = false;

	EnableButtons();
}

void UEndTurnButton::ButtonfirstClicked()
{ 
	SetAndBlockButtons(1);
	DealDamage();
	WinOrLoose();
}

void UEndTurnButton::ButtonsecondClicked()
{
	SetAndBlockButtons(2);
	if (herohp != 0) {
		herohp <= 75 ? herohp += 25 : herohp = 100;
		FText helperherohealth = FText::AsNumber(herohp);
		HeroHealth->SetText(helperherohealth);
	}
}

void UEndTurnButton::ButtonthirdClicked()
{
	SetAndBlockButtons(3);
	shield = true;
	FMath::RandRange(1, 2) == 1 ? shieldsuccess = true : shieldsuccess = false;
}