// Fill out your copyright notice in the Description page of Project Settings.


#include "InvisibleWall.h"
#include "Components/BoxComponent.h"
#include "CharacterBase.h"


// Sets default values
AInvisibleWall::AInvisibleWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TWA BoxComponent"));
	this->BoxComponent->OnComponentHit.AddDynamic(this, &AInvisibleWall::OnTouch);
}

// Called when the game starts or when spawned
void AInvisibleWall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInvisibleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInvisibleWall::OnTouch(UPrimitiveComponent* HitComp,
                             AActor* OtherActor,
                             UPrimitiveComponent* OtherComp,
                             FVector NormalizeImpulse,
                             const FHitResult& Hit)
{
	TObjectPtr<ACharacterBase> Player = Cast<ACharacterBase>(OtherActor);

	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("You Hit the Invisible Wall"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("An Actor Hit the Invisible Wall"));
	}
}















