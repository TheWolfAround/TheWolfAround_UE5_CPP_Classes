// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectArea.generated.h"

class USphereComponent;

UCLASS()
class UE5_CPP_CLASSES_API AEffectArea : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TWA_Interactable, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;

public:
	// Sets default values for this actor's properties
	AEffectArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnEnter(UPrimitiveComponent* OverlappedComp,
	             AActor* OtherActor,
	             UPrimitiveComponent* OtherComp,
	             int32 OtherBodyIndex,
	             bool bFromSweep,
	             const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeave(UPrimitiveComponent* OverlappedComp,
				 AActor* OtherActor,
				 UPrimitiveComponent* OtherComp,
				 int32 OtherBodyIndex);
};
