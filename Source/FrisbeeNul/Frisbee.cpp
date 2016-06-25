// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "Frisbee.h"


// Sets default values
AFrisbee::AFrisbee()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->shape = CreateDefaultSubobject<UBoxComponent>(TEXT("Shape"));

	this->mesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	this->RootComponent = this->mesh;
	this->shape->AttachTo(this->RootComponent);
}


void AFrisbee::attachToPlayer(AActor* playerOwner) {
	this->mesh->SetSimulatePhysics(false);
	this->AttachRootComponentToActor(playerOwner, "", EAttachLocation::KeepWorldPosition);
	this->playerOwner = playerOwner;
}

void AFrisbee::unattachToPlayer() {
	this->AttachRootComponentToActor(this, "", EAttachLocation::KeepWorldPosition);
	this->mesh->SetSimulatePhysics(true);
	this->playerOwner = false;
}

// Called when the game starts or when spawned
void AFrisbee::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFrisbee::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

