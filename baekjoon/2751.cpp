//
// Created by 융미 on 2019-04-26.
//2751 수 정렬하기 2
#include <cstdio>
#include <algorithm>

int main(){
    int arr[1000000];
    int num;

    scanf("%d", &num);
    int i = 0;
    int j = num;
    while(j--){
        scanf("%d", &arr[i++]);
    }

    std::sort(arr, arr+num);
    i = 0;
    while(num--)
    {
        printf("%d\n", arr[i++]);
    }
    return 0;
}
