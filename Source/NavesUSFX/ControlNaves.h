#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlNaves.generated.h"

class ANave;

UCLASS()
class NAVESUSFX_API AControlNaves : public AActor
{
	GENERATED_BODY()

public:
	AControlNaves();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ANave> ClaseNave;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:

	TArray<ANave*> Naves;
	float Tiempo;
	bool bEnFormacion;
};