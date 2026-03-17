#include "Nave.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"

ANave::ANave()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cubo(TEXT("/Engine/BasicShapes/Cube"));

	if (Cubo.Succeeded())
	{
		Mesh->SetStaticMesh(Cubo.Object);
	}

	bFormando = false;
	PosicionObjetivo = FVector::ZeroVector;
}

void ANave::BeginPlay()
{
	Super::BeginPlay();
}

void ANave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Pos = GetActorLocation();

	if (bFormando)
	{
		FVector NuevaPos = FMath::VInterpTo(Pos, PosicionObjetivo, DeltaTime, 2.0f);
		SetActorLocation(NuevaPos);
	}
	else
	{
		float Tiempo = GetWorld()->TimeSeconds;

		Pos.X += FMath::Sin(Tiempo) * 200 * DeltaTime;
		Pos.Y += FMath::Cos(Tiempo) * 200 * DeltaTime;

		Pos.X = FMath::Clamp(Pos.X, -2000.f, 2000.f);
		Pos.Y = FMath::Clamp(Pos.Y, -2000.f, 2000.f);

		SetActorLocation(Pos);
	}
}