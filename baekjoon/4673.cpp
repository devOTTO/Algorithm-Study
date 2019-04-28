//
// Created by 융미 on 2019-04-28.
//4673 셀프 넘버
#include <cstdio>

int d(int num){
    int sum = num;
    while(num!=0)
    {
        sum += num%10;
        num = num/10;
    }
    return sum;
}

int main()
{
    bool arr[10001] = {false, };
    for (int i = 1; i<10001; i++)
    {
        int num = d(i);
        if(num<=10000){
            arr[num] = true;
        }
    }

    for(int i = 1; i<10001; i++)
    {
        if(!arr[i]) printf("%d\n", i);
    }
    return 0;
}
