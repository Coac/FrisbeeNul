// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "GetFrisbeeComponent.h"


// Sets default values for this component's properties
UGetFrisbeeComponent::UGetFrisbeeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGetFrisbeeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGetFrisbeeComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	float distance = this->frisbee->GetDistanceTo(this->GetOwner());

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (controller->IsInputKeyDown(EKeys::A) && distance < 200.0f) {
		this->frisbee->mesh->AddForce(FVector(0, 0, 500000));
	}
}
