// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.

const int XLine = 20;
const int YLine = 10;


// 이녀석은 캡슐화된 클래스라기 보다는 기본자료형
class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }


};

// 리스 이니셜라이저
const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

// Init('*')

// [*][*][0] \n
// [*][*][0] \n

class ConsoleScreen
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }

    bool IsScreenOut(const int4& _Pos) const
    {
        if (0 > _Pos.X)
        {
            return true;
        }

        if (0 > _Pos.Y)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
    }


    void Print() const
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:
    // 레퍼런스는 기본적으로 8바이트 참조입니다.
    // int4를 그냥 16바이트입니다.
    // int4&를 그냥 8바이트입니다.
    // int4*를 그냥 8바이트입니다.

    // 내가 넣으려는 인자가 합쳐서 8바이트가 넘어갈때
    // 그걸 구조체나 클래스로 묶어서 참조형태로 넘기는게 대부분의 상황에서
    // 무조건 이득이다.

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
        // 뭔가가 그냥 거저 된다.
        // => 내가 만들었다.
        // => 컴파일러나 기본문법으로 생략되어 있다.
        Pos = _Pos;
    }

    // 생성자에는 붙일수가 없다.
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

            // 화면 바깥으로 나가지 않았다면 <= 행동 true
            // 나는 이동한다.
            // 4 5 + -1 0
            // 3 5 
            // int4 NextPos = GetPos() + Left;
            //if (false == _Sreen->IsScreenOut(GetPos() + Left))
            //{
            //    AddPos(Left);
            //}

            // 가고나서 돌아온다.
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

// 기계어적으로 볼때 함수가 호출되고 함수의 메모리를 만들고
// 메모리를 정리하는 담당자를 정해야하는 규칙이 있는데.
// C++에서는 그걸 직접 정해줄수 있는 문법이 또 있는거야.
// 컴파일러가 가장 최적의 함수호출규약을 알아서 정해줍니다.
void /*__cdecl*/ Function()
{

}

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    // 클래스의경우에는 
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.Print();

        MainPlayer.Input(&Screen);
    }


}
