// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Frisbee.generated.h"

UCLASS()
class FRISBEENUL_API AFrisbee : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AFrisbee();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void attachToPlayer(AActor* playerOwner);

	void unattachToPlayer();

	AActor* playerOwner;



	UPROPERTY(EditAnywhere)
		UShapeComponent* shape;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	
	
};
