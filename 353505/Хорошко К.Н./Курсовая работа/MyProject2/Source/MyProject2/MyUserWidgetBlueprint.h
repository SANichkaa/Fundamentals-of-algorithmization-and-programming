#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetBlueprint.h"
#include <iostream>
#include "MyUserWidgetBlueprint.generated.h"


using namespace std;

UCLASS()
class MYPROJECT2_API UMyUserWidgetBlueprint : public UUserWidgetBlueprint
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable) TArray<FString> vec_number();
	UFUNCTION(BlueprintCallable) TArray<FString> vec_time();
	
};
