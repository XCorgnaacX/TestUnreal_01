// Fill out your copyright notice in the Description page of Project Settings.


#include "TU_ExplosiveBarrel.h"

#include "Engine/World.h"
#include "Materials/MaterialInterface.h"
#include "DrawDebugHelpers.h"


// Sets default values
ATU_ExplosiveBarrel::ATU_ExplosiveBarrel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName("PhysicsActor");
	Mesh->SetSimulatePhysics(true);

	Material = CreateDefaultSubobject<UMaterialInterface>("Material");

	Explosion = CreateDefaultSubobject<URadialForceComponent>("Explosion");
	Explosion->SetupAttachment(Mesh);

	Explosion->Radius = 500.0f;  // Adjust radius as needed
	Explosion->ImpulseStrength = 1000.0f;  // Set impulse strength
	Explosion->bImpulseVelChange = true;  // Ignore mass for the impulse
	Explosion->bAutoActivate = false;  // FireImpulse manually
}

// Called when the game starts or when spawned
void ATU_ExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Mesh->OnComponentHit.AddDynamic(this, &ATU_ExplosiveBarrel::OnHit);
	
}


void ATU_ExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explosion->FireImpulse();

	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrel"));

	UE_LOG(LogTemp, Warning, TEXT("OtherActor : %s, at game time : %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);


	FString CombinedString = FString::Printf(TEXT("Hit at Location : %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);

}
