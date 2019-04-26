//
// Created by 융미 on 2019-04-26.
//1427 소트인사이드

#include <cstdio>
#include <algorithm>

int main(){
    int arr[10] = {0, };
    int input = 0;

    scanf("%d", &input);

    int i = 0;
    while(input){
        arr[i++] = input%10;
        input /=10;
    }


    std::sort(arr,arr+i);

    for(int j = i - 1; j>-1; j--)
        printf("%d", arr[j]);

    return 0;
}

