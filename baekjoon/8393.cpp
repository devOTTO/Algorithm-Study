//
// Created by 융미 on 2019-04-28.
//8393 합
#include <cstdio>
int main()
{
    int a, result=0;
    scanf("%d", &a);

    while(a>0)
    {
        result+=a--;
    }
    printf("%d", result);
    return 0;
}

