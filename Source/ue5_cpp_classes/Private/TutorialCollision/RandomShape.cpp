// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomShape.h"


// Sets default values
ARandomShape::ARandomShape()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TWA StaticMeshComponent"));
	this->StaticMeshComponent->OnComponentHit.AddDynamic(this, &ARandomShape::OnTouch);
	this->StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ARandomShape::OnEnter);
}

// Called when the game starts or when spawned
void ARandomShape::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARandomShape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARandomShape::OnTouch(UPrimitiveComponent* HitComp,
                           AActor* OtherActor,
                           UPrimitiveComponent* OtherComp,
                           FVector NormalizeImpulse,
                           const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("You Subscribed! <3"));
}

void ARandomShape::OnEnter(UPrimitiveComponent* OverlappedComp,
                           AActor* OtherActor,
                           UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex,
                           bool bFromSweep,
                           const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, TEXT("You Liked the Video! <3"));
}
