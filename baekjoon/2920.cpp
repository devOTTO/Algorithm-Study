//
// Created by 융미 on 2019-04-28.
//2920 음계
#include <cstdio>

int main()
{
    int arr[8];
    int a = 0;
    int d = 0;

    for(int i = 0; i<8; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<7; i++)
    {
        if(arr[i] - arr[i+1] == -1)
            a++;
        else if(arr[i] - arr[i+1] == 1)
            d++;
    }

    if(a == 7)
        printf("ascending");
    else if(d == 7)
        printf("descending");
    else
        printf("mixed");

    return 0;
}



