//
// Created by 융미 on 2019-04-28.
//2440 별 찍기 - 3
#include <cstdio>
int main()
{
    int a;
    scanf("%d", &a);

    for(int i = a; i>0; --i){
        for(int j = 0; j<i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


