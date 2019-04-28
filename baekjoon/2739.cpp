//
// Created by 융미 on 2019-04-28.
//2739 구구단
#include <cstdio>
int main(){

    int a;
    scanf("%d", &a);

    for(int i = 0; i<9; i++)
    {
        printf("%d * %d = %d\n", a, i+1, a*(i+1));
    }

    return 0;
}

