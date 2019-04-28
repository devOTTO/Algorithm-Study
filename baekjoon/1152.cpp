//
// Created by 융미 on 2019-04-28.
//1152 단어의 개수
#include <cstdio>
#include <cstring>
#define MAX 1000000

int main() {
    char input[MAX+1];

    int count = 1;

    fgets(input, MAX+1, stdin);

    //시작할때 공백, 맨뒤 공백 예외처리
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
            count++;
    }
    if(input[0] == ' ')
        count--;

    if(input[strlen(input)-2]==' ')
        count--;

    printf("%d", count);

    return 0;
}