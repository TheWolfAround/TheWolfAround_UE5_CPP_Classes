// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMainCharacter::AMainCharacter()
{
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationYaw = false;
	this->bUseControllerRotationRoll = false;

	TObjectPtr<UCharacterMovementComponent> MovementComponent = this->GetCharacterMovement();
	MovementComponent->bOrientRotationToMovement = true;

	this->CameraArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("TWA SpringArmComponent"));
	this->CameraArmComponent->SetupAttachment(this->RootComponent.Get());
	this->CameraArmComponent->TargetArmLength = 400.0f;
	this->CameraArmComponent->bUsePawnControlRotation = true;

	this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TWA CameraComponent"));
	this->CameraComponent->SetupAttachment(this->CameraArmComponent.Get(), USpringArmComponent::SocketName);
	this->CameraComponent->bUsePawnControlRotation = false;
}
