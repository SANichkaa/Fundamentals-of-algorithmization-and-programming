#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <ctime>
#include "Spawn.generated.h"


UCLASS()
class MYPROJECT2_API ASpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable) int Spawn_code(int param);
	UFUNCTION(BlueprintCallable) int Random_Mod(int param);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
