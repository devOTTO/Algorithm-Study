//
// Created by 융미 on 2019-04-28.
//2577 숫자의 개수
#include <cstdio>
#include <cstring>

int main()
{
    int count[10] = {0,}; //0123456789

    int a, b,c;

    scanf("%d %d %d", &a, &b, &c);

    int result = a*b*c;
    int i = 0;
    while(result != 0)
    {
        count[result%10]++;
        result /= 10;
    }

    for(i = 0; i<10; i++)
    {
        printf("%d\n", count[i]);
    }



    return 0;


}
