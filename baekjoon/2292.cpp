//
// Created by 융미 on 2019-04-26.
//2292 벌집
#include <cstdio>

int main()
{
    int input = 0;
    scanf("%d", &input);
    int sum = 1;
    int count = 1;
    while(input > sum)
    {
        sum += 6*(count++);
    }
    printf("%d", count);
    return 0;
}