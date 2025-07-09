// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComp"));
	StaticComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MeshMaterial(TEXT("/Game/CyberpunkIndustries/Materials/Material_PanelPublicity.Material_PanelPublicity"));
	if (MeshMaterial.Succeeded())
	{
		StaticComp->SetMaterial(0, MeshMaterial.Object);
	}
	MoveSpeed = 100.0f;
	MaxRange = 200.0f;
	ReversMaxRange = MaxRange * 2;
}


// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	bMoveForward = true;

}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ActorRange += MoveSpeed * DeltaTime;


	if (bMoveForward)
	{
		AddActorWorldOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
		if (MaxRange <= ActorRange)
		{
			bMoveForward = false;
		}
		UE_LOG(LogTemp, Error, TEXT("%.2f"), ActorRange);
	}
	else
	{
		AddActorWorldOffset(FVector(0.0f, MoveSpeed * DeltaTime * -1, 0.0f));
		UE_LOG(LogTemp, Error, TEXT("%.2f"), ActorRange);
		if (ActorRange >= ReversMaxRange)
		{
			bMoveForward = true;
			ActorRange = 0.0f;
		}
	}


	
	
}