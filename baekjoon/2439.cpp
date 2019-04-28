//
// Created by 융미 on 2019-04-28.
//2439 별 찍기 - 2
#include <cstdio>
int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 0; i<a; ++i)
    {
        for(int j = 1; j<a-i; ++j)
        {printf(" ");}
        for(int j = 0; j<=i; ++j)
        {printf("*");}

        printf("\n");
    }

    return 0;
}
