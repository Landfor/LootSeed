﻿// HomeWork0518.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
using namespace std;


//int ChCount = 0;
//while (Arr[ChCount])
//{
//    char PrintCh = Arr[ChCount];
//    putchar(PrintCh);
//    ++ChCount;
//}

int StringCount(char* _Arr) 
{
    // 위쪽 예제코드를 참고하세요
    int ChCount = 0;
    while (&_Arr[ChCount])
    {
        char PrintCh = ChCount;
        putchar(PrintCh);
        ++ChCount;
    }
    return 0;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    // 1. 들어온 글자를 전부 '1'로 채워봐라.
    //  1-1. 함수 내부에서 하지 말고
    // for while도 생각하지 말고
    _Arr[100] = 1;//x

    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "aaaa";
        // 5이 나와야 합니다.
        // 글자수를 세는 함수입니다.
        int a = 0;

        int Result = StringCount(&Arr[100]);


        cout << "입력한 문장 : " << Result << endl;
    }

    {
        char Arr[100] = "aaa bbb ccc";

        Arr[0] = '1';

        // Arr[100] = "1111111111111";
        
        // 3이 나와야 합니다.
        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');

        int a = 0;
    }

    
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
