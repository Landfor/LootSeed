// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHead.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASnakeHead::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASnakeHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 0.0000000000000000000000000000001

	// 코드로하면 정말 짜증나고 열받는 것들이 있고.



	// AddActorLocalOffset(FVector::RightVector);

	// UE_LOG(LogTemp, Warning, TEXT("Snake Warning")); // 노란색
}

void ASnakeHead::LeftMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector);
}


void ASnakeHead::RightMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector);
}
void ASnakeHead::UpMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::UpVector);
}
void ASnakeHead::DownMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::DownVector);
}

void ASnakeHead::LeftAction()
{
	AddActorLocalOffset(FVector::LeftVector * 100.0f);
}
void ASnakeHead::RightAction()
{
	AddActorLocalOffset(FVector::RightVector * 100.0f);
}
void ASnakeHead::UpAction()
{
	AddActorLocalOffset(FVector::UpVector * 100.0f);
}
void ASnakeHead::DownAction()
{
	AddActorLocalOffset(FVector::DownVector * 100.0f);
}