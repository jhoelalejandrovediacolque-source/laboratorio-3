#include "ControlNaves.h"
#include "Nave.h"
#include "Kismet/GameplayStatics.h"

AControlNaves::AControlNaves()
{
	PrimaryActorTick.bCanEverTick = true;

	Tiempo = 0.f;
	bEnFormacion = false;
}

void AControlNaves::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 20; i++)
	{
		FVector Posicion(i * 200.f, 0.f, 300.f);

		ANave* NuevaNave = GetWorld()->SpawnActor<ANave>(ClaseNave, Posicion, FRotator::ZeroRotator);

		if (NuevaNave)
		{
			Naves.Add(NuevaNave);
		}
	}
}

void AControlNaves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Tiempo += DeltaTime;

	if (Tiempo > 5 && !bEnFormacion)
	{
		APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		if (Pawn)
		{
			FVector Base = Pawn->GetActorLocation() + Pawn->GetActorForwardVector() * 800;

			int Index = 0;
			int Fila = 1;

			while (Index < Naves.Num())
			{
				for (int j = 0; j < Fila && Index < Naves.Num(); j++)
				{
					float OffsetX = Fila * 200;
					float OffsetY = (j - Fila / 2.0f) * 200;

					FVector Pos = Base + FVector(OffsetX, OffsetY, 0);

					Naves[Index]->PosicionObjetivo = Pos;
					Naves[Index]->bFormando = true;

					Index++;
				}

				Fila++;
			}
		}

		bEnFormacion = true;
	}

	if (Tiempo > 10)
	{
		for (ANave* Nave : Naves)
		{
			if (Nave)
			{
				Nave->bFormando = false;
			}
		}

		bEnFormacion = false;
		Tiempo = 0;
	}
}