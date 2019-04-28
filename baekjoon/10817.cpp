//
// Created by 융미 on 2019-04-28.
//10817 세 수
#include <cstdio>
#include <algorithm>
int main(){
    int arr[3];
    int result;

    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    std::sort(arr,arr+3);

    for(int i = 0; i<3; i++)
    printf("%d\n", arr[i]);
}
