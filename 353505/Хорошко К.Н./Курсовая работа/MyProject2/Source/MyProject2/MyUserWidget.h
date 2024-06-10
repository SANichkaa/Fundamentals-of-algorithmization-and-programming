// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <iostream>
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable) TArray<FString> vec_number();
	UFUNCTION(BlueprintCallable) TArray<FString> vec_time();
	UFUNCTION(BlueprintCallable) void output(FString param);
};
