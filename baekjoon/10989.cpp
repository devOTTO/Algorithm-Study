//
// Created by 융미 on 2019-04-26.
//10989 수 정렬하기 3
#include <cstdio>

int main() {
    int arr[10001]={0,};

    int N;
    int num;

    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &num);
        arr[num]++;
    }

    for(int i = 1; i<=10000; i++)
    {
        for(int j= 0; j<arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}


