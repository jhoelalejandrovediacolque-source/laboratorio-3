#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Nave.generated.h"

UCLASS()
class NAVESUSFX_API ANave : public AActor
{
	GENERATED_BODY()

public:
	ANave();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	FVector PosicionObjetivo;
	bool bFormando;
};