// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomShape.generated.h"

UCLASS()
class UE5_CPP_CLASSES_API ARandomShape : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = TWA_Interactable, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
public:
	// Sets default values for this actor's properties
	ARandomShape();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnTouch(UPrimitiveComponent* HitComp,
				 AActor* OtherActor,
				 UPrimitiveComponent* OtherComp,
				 FVector NormalizeImpulse,
				 const FHitResult& Hit);

	UFUNCTION()
	void OnEnter(UPrimitiveComponent* OverlappedComp,
				 AActor* OtherActor,
				 UPrimitiveComponent* OtherComp,
				 int32 OtherBodyIndex,
				 bool bFromSweep,
				 const FHitResult& SweepResult);
};









