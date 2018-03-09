// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h" 


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPETHEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
        
public:
    UPROPERTY(EditAnywhere)
    ATriggerVolume *Trigger;
    
    UPROPERTY(EditAnywhere)
    float DoorOpenDuration;

private:
    void OpenDoor();
    void CloseDoor();

    AActor *Owner;
    AActor *DefaultPlayer;    
    float LastDoorOpenTime;
};