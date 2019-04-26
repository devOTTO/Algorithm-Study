//
// Created by 융미 on 2019-04-26.
//1193 분수찾기
#include <cstdio>

int main()
{
    int input = 0;
    scanf("%d", &input);
    int sum = 0;
    int count = 0;
    int up = 0;
    int down = 0;

    while(input > sum)
    {
        sum += ++count;
    }

    int k = input - (sum - count);

    if(count%2)//홀
    {
        up = count - k + 1;
        down = k;
    }
    else{
        up = k;
        down = count - k + 1;
    }
    printf("%d/%d", up, down);
    return 0;
}
