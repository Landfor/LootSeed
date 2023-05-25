#pragma once
// #include "Player.h"
#include <iostream>

class Player; // Player라는 클래스가 있을거니까 믿고 써.
class Monster
{
	// c++에서는 함수에도 그걸 만든 프로그래머의 의도를 부여할수가 있습니다.

public:
	//void LvUp() 
	//{
	//	Att += 10;
	//}

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
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};

