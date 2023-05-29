#pragma once

#include <iostream>
#include "Int4.h"
#include "ConsoleScreen.h"

class Wall
{
public:
    int4 Wall_Pos()
    {
        return Pos;
    }

    bool IsWallBlock(const int4& _Pos) const
    {
        if (Wall_Pos = _Pos)
        {
            return false;
        }
        return true;
    }

private:

	int4 WallPos;
	char Block = '0';
	char ArrScreen[YLine][XLine + 1] = {};
};
