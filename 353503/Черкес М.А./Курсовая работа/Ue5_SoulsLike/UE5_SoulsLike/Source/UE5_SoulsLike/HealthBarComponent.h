// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetComponent.h"
#include "HealthBarComponent.generated.h"

/**
 *
 */
UCLASS()
class DARKSANDS_API UHealthBarComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	void setHealthPercent(float Percent);
private:
	UPROPERTY()
	class UHealthBar* HealthBarWidget;

};