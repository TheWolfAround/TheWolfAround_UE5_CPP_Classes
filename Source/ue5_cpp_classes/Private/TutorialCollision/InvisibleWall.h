// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvisibleWall.generated.h"

class UBoxComponent;

UCLASS()
class UE5_CPP_CLASSES_API AInvisibleWall : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TWA_Interactable, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxComponent;

public:
	// Sets default values for this actor's properties
	AInvisibleWall();

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
};
