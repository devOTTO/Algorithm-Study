//
// Created by 융미 on 2019-04-28.
//2448 별 찍기 - 11
#include <iostream>

char arr[3072][6144];

void star(int h, int x, int y) //입력은 삼각형의 높이, x, y좌표
{
    //base case : 삼각형 높이가 3인 경우 삼각형 찍고 탈출
    if(h==3){
        arr[y][x] = '*';
        arr[y+1][x-1] = '*';
        arr[y+1][x+1] = '*';
        arr[y+2][x-2] = '*';
        arr[y+2][x-1] = '*';
        arr[y+2][x] = '*';
        arr[y+2][x+1] = '*';
        arr[y+2][x+2] = '*';
        return;
    }

    //위 삼각형
    star(h/2, x, y);
    //왼쪽 삼각형
    star(h/2, x-(h/2), y+(h/2));
    //오른쪽 삼각형
    star(h/2, x+(h/2), y+(h/2));
}

int main(){

    int input = 0;
    std::cin>>input;

    //배열 공백 초기화
    for(int i = 0; i<input; i++)
    {
        for(int j = 0; j < input*2 -1; j++){
            arr[i][j] = ' ';
        }
    }

    star(input, input-1, 0);

    for(int i = 0; i<input; i++)
    {
        for(int j = 0; j < input*2 -1; j++){
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}

////*2448 재귀 별찍기-C출력 버전
//#include <cstdio>
//
//char arr[3072][6144];
//
//void star(int h, int x, int y) //입력은 삼각형의 높이, x, y좌표
//{
//    //base case : 삼각형 높이가 3인 경우 삼각형 찍고 탈출
//    if(h==3){
//        arr[y][x] = '*';
//        arr[y+1][x-1] = '*';
//        arr[y+1][x+1] = '*';
//        arr[y+2][x-2] = '*';
//        arr[y+2][x-1] = '*';
//        arr[y+2][x] = '*';
//        arr[y+2][x+1] = '*';
//        arr[y+2][x+2] = '*';
//        return;
//    }
//
//    //위 삼각형
//    star(h/2, x, y);
//    //왼쪽 삼각형
//    star(h/2, x-(h/2), y+(h/2));
//    //오른쪽 삼각형
//    star(h/2, x+(h/2), y+(h/2));
//}
//
//int main(){
//
//    int input = 0;
//    scanf("%d", &input);
//
//    //배열 공백 초기화
//    for(int i = 0; i<input; i++)
//    {
//        for(int j = 0; j < input*2 -1; j++){
//            arr[i][j] = ' ';
//        }
//    }
//
//    star(input, input-1, 0);
//
//    for(int i = 0; i<input; i++)
//    {
//        for(int j = 0; j < input*2 -1; j++){
//            printf("%c", arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}






