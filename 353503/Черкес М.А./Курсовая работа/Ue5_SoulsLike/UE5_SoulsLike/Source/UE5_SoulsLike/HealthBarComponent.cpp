// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarComponent.h"
#include "HealthBar.h"
#include "ProgressBar.h"

void UHealthBarComponent::setHealthPercent(float Percent)
{
	if (HealthBarWidget == nullptr)
	{
		HealthBarWidget = Cast<UHealthBar>(GetUserWidgetObject());
	}
	if (HealthBarWidget && HealthBarWidget->ProgressBar_HealthBar)
	{
		HealthBarWidget->ProgressBar_HealthBar->SetPercent(Percent);
	}
}