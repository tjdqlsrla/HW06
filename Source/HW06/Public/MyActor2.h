// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class HW06_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticComp;


	FVector StartLocation;
	bool bMoveForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float ActorRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float ReversMaxRange;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
