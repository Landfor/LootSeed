// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SnakeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AE_UNREAL_API ASnakeGameMode : public AGameMode
{
	GENERATED_BODY()

	// 이걸 통해서 알려줄수가 있다.
	// 액터의 타입을 교환할수 있게 만든 자료형이
	// TSubclassOf 입니다.
	// TSubclassOf<AActor> CreateWallType;

	UFUNCTION(BlueprintCallable)
	void CreateOutWall(int _X, int _Y, TSubclassOf<AActor> _WallType);

	void BeginPlay() override;
};
