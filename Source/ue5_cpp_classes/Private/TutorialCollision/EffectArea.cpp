// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectArea.h"
#include "Components/SphereComponent.h"
#include "CharacterBase.h"


// Sets default values
AEffectArea::AEffectArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("TWA SphereComponent"));
	this->SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEffectArea::OnEnter);
	this->SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AEffectArea::OnLeave);
}

// Called when the game starts or when spawned
void AEffectArea::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEffectArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEffectArea::OnEnter(UPrimitiveComponent* OverlappedComp,
                          AActor* OtherActor,
                          UPrimitiveComponent* OtherComp,
                          int32 OtherBodyIndex,
                          bool bFromSweep,
                          const FHitResult& SweepResult)
{
	TObjectPtr<ACharacterBase> Player = Cast<ACharacterBase>(OtherActor);

	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("You Entered the Effect Area"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("An Actor Entered the Effect Area"));
	}
}

void AEffectArea::OnLeave(UPrimitiveComponent* OverlappedComp,
                          AActor* OtherActor,
                          UPrimitiveComponent* OtherComp,
                          int32 OtherBodyIndex)
{
	TObjectPtr<ACharacterBase> Player = Cast<ACharacterBase>(OtherActor);

	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("You Left the Effect Area"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("An Actor Left the Effect Area"));
	}
}












