//
// Created by 융미 on 2019-04-26.
//1475 방 번호
#include <cstdio>

int main()
{
    int num;
    int arr[10] = {0, };
    scanf("%d", &num);
    if(num == 0)
        printf("%d", 1);
    else{
        while(num){
            arr[num%10]++;
            num/=10;
        }

        int big = (arr[9] + arr[6] + 1)/2;

        arr[6] = 0;

        for(int i = 0; i<9; i++)
        {
            if(arr[i] > big)
                big = arr[i];
        }

        printf("%d", big);
    }

    return 0;
}
