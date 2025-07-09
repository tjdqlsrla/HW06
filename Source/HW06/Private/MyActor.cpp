// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MeshMaterial(TEXT("/Game/CyberpunkIndustries/Materials/Material_NoSignal_TV.Material_NoSignal_TV"));
	if (MeshMaterial.Succeeded())
	{
		StaticComp->SetMaterial(0,MeshMaterial.Object);
	}

	RotationSpeed = 90.0f;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	
	

}

