#pragma once
#include "Int4.h"
#include "ConsoleScreen.h"
#include <iostream>
#include <conio.h>


// ���� �̴ϼȶ�����
const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };


class Player
{
public:
    // ���۷����� �⺻������ 8����Ʈ �����Դϴ�.
    // int4�� �׳� 16����Ʈ�Դϴ�.
    // int4&�� �׳� 8����Ʈ�Դϴ�.
    // int4*�� �׳� 8����Ʈ�Դϴ�.

    // ���� �������� ���ڰ� ���ļ� 8����Ʈ�� �Ѿ��
    // �װ� ����ü�� Ŭ������ ��� �������·� �ѱ�°� ��κ��� ��Ȳ����
    // ������ �̵��̴�.

    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        // ������ �׳� ���� �ȴ�.
        // => ���� �������.
        // => �����Ϸ��� �⺻�������� �����Ǿ� �ִ�.
        Pos = _Pos;
    }

    // �����ڿ��� ���ϼ��� ����.
    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input(ConsoleScreen* _Sreen)
    {
        char Select = (char)_getch();

        int4 MovePos = { 0, 0 };

        switch (Select)
        {
        case 'a':

            MovePos = Left;

            // ȭ�� �ٱ����� ������ �ʾҴٸ� <= �ൿ true
            // ���� �̵��Ѵ�.
            // 4 5 + -1 0
            // 3 5 
            // int4 NextPos = GetPos() + Left;
            //if (false == _Sreen->IsScreenOut(GetPos() + Left))
            //{
            //    AddPos(Left);
            //}

            // ������ ���ƿ´�.
            //AddPos(Left);
            //if (true == _Sreen->IsScreenOut(GetPos()))
            //{
            //    AddPos(Right);
            //}
            break;
        case 'd':
            MovePos = Right;

            //if (false == _Sreen->IsScreenOut(GetPos() + Right))
            //{
            //    AddPos(Right);
            //}

            break;
        case 'w':
            MovePos = Up;

            //if (false == _Sreen->IsScreenOut(GetPos() + Up))
            //{
            //    AddPos(Up);
            //}
            break;
        case 's':
            MovePos = Down;
            break;
        default:
            break;
        }

        if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
        {
            AddPos(MovePos);
        }

    }

protected:

private:



    int4 Pos;
};