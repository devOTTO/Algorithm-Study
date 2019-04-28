//
// Created by 융미 on 2019-04-28.
//1110 더하기 사이클
#include <cstdio>

int main()
{
    int num, result, count=0;

    scanf("%d", &num);
    result = num;
    while(true)
    {
        if(result<10){
            result = result*10 + result;
        }
        else{
            result = (result%10)*10 + (result%10 + result/10)%10;

        }
        count++;
        if(result == num)
        {
            printf("%d", count);
            break;
        }
    }
    return 0;
}