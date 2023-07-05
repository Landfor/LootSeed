// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// 애니메이션에 집중할거냐
// 캐릭터에 집중할 거냐?

// UMETA는 각 옵션마다 설정을 다르게 해줄수 있습니다.

UENUM(BlueprintType)
enum class TPSAniState : uint8
{
	None UMETA(Display = "사용하지 마시오"),
	Idle UMETA(Display = "서있기"),
	LeftMove UMETA(Display = "왼쪽이동"),
	RightMove UMETA(Display = "오른쪽이동"),
	ForwardMove UMETA(Display = "앞으로이동"),
	BackwardMove UMETA(Display = "뒤로이동"),
	Jump UMETA(Display = "점프"),
	Attack UMETA(Display = "공격"),
};