// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeGameMode.h"

void ASnakeGameMode::BeginPlay() 
{
	Super::BeginPlay();

	int X = 3;
	int Y = 3;

	// [][][][][]
	// []      []
	// []      []
	// []      []
	// [][][][][]

	
}

void ASnakeGameMode::CreateOutWall(int _X, int _Y, TSubclassOf<AActor> _WallType)
{
	// Wall::StaticClass() <= 지금 내가 생성하려는 액터가 뭔지를 알려줍니다.
// 이 내부에서 블루프린트 wall을 알수 있어야 한다.
	for (size_t i = 0; i < _X + 2; i++)
	{
		FTransform Trans;

		AActor* SpawnedActor1 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);
	}
}