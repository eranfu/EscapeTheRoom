// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
    Super::BeginPlay();
    Owner = GetOwner();
    DefaultPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();
    UE_LOG(LogTemp, Warning, TEXT("Hello I am in OpenDoor! %s"), *Owner->GetName());
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (Trigger != nullptr && Trigger->IsOverlappingActor(DefaultPlayer))
    {
        OpenDoor();
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }

    if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorOpenDuration)
    {
        CloseDoor();
    }
}

void UOpenDoor::OpenDoor()
{
    Owner->SetActorRelativeRotation(FRotator(0, 90, 0));
}

void UOpenDoor::CloseDoor()
{
    Owner->SetActorRelativeRotation(FRotator(0, 0, 0));
}
