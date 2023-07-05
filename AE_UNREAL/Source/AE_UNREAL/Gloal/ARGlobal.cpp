// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGlobal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "GlobalDebugUserWidget.h"

class UGlobalDebugUserWidget* UARGlobal::DebugWidget = nullptr;

void UARGlobal::ARDebugTextInit()
{
	// �������� �ڵ����� ����������
	// delete�� �Ѵٰ� 
	DebugWidget = nullptr;
}

void UARGlobal::ARDebugTextPrint(class AActor* _AActor, TSubclassOf<UUserWidget> _Widget, const FString& _Text)
{
	// ���⼭ ���� ������ ���ٸ�
	// ����� ���� �Ѵ�.
	// ������ ����.
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
			// ������ �����Ҷ��� ������ �����Ƿ� �̰͵� ó�����ش�.
			return;
		}

		DebugWidget = Cast<UGlobalDebugUserWidget>(NewWidGet);
		DebugWidget->AddToViewport(1000);
	}

	DebugWidget->AddDebugText(_Text);
}