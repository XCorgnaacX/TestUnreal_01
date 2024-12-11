// Fill out your copyright notice in the Description page of Project Settings.


#include "TU_ItemChest.h"
#include "Components/StaticMeshComponent.h"

// Add default functionality here for any IINT_TU_Interface functions that are not pure virtual.


// Sets default values
ATU_ItemChest::ATU_ItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110;

}

void ATU_ItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(110, 0, 0));
}


// Called when the game starts or when spawned
void ATU_ItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATU_ItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

