// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGlobal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "GlobalDebugUserWidget.h"

class UGlobalDebugUserWidget* UARGlobal::DebugWidget = nullptr;

void UARGlobal::ARDebugTextInit()
{
	// 끝날을때 자동으로 지워지지만
	// delete를 한다고 
	DebugWidget = nullptr;
}

void UARGlobal::ARDebugTextPrint(class AActor* _AActor, TSubclassOf<UUserWidget> _Widget, const FString& _Text)
{
	// 여기서 만약 위젯이 없다면
	// 만들어 내야 한다.
	// 위젯이 없어.
	if (nullptr == DebugWidget)
	{
		UWorld* World = _AActor->GetWorld();

		if (nullptr == World && false == World->IsValidLowLevel())
		{
			return;
		}

		UUserWidget* NewWidGet = CreateWidget<UUserWidget>(World, _Widget);

		if (nullptr == NewWidGet)
		{
			// 생성에 실패할때까 있을수 있으므로 이것도 처리해준다.
			return;
		}

		DebugWidget = Cast<UGlobalDebugUserWidget>(NewWidGet);
		DebugWidget->AddToViewport(1000);
	}

	DebugWidget->AddDebugText(_Text);
}