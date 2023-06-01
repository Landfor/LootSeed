#pragma once
// #include "int"

// 헤더에서 다른 헤더를 추가하는 것은 보통 최대한 줄여야 한다.
// #include "Monster.h"
#include <iostream>

const int LineCount = 40;

int StringCount(const char* _Arr)
{
	// 위쪽 예제코드를 참고하세요
	int ChCount = 0;
	while (_Arr[ChCount])
	{
		++ChCount;
	}

	return ChCount;
}

class Monstar;
class Player
{
public:
	void StatusRender()
	{
		int Count = 0;

		Count = StringCount(Name);

		// 40개로 맞춰오세요.

		// 줄바꿈이 안되고 있습니다.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("공격력 : %d\n", Att);
		printf_s("체  력 : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

	}

	void DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s가 %s를 공격했습니다.\n", _AttName, Name);
		printf_s("%s는 %d의 데미지를 입었습니다.\n", Name, _Att);
	}

	void Damage(int _Att)
	{
		Hp -= _Att;
	}

	// 
	const char* GetName()
	{
		return Name;
	}

	int GetAtt()
	{
		return Att;
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}


private:
	// 캡슐화
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;

};
