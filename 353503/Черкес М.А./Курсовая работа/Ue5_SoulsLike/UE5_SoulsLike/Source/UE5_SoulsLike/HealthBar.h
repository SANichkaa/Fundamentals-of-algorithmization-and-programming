// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget.h"
#include "HealthBar.generated.h"

class UProgressBar;

/**
 * 
 */
UCLASS()
class DARKSANDS_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
public:
		UPROPERTY(meta=(BindWidget))
		UProgressBar* ProgressBar_HealthBar;
};
