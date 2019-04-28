//
// Created by 융미 on 2019-04-28.
//1546 평균
#include <cstdio>
#include <algorithm>

int main(){

    int num, score, max, mean =0;
    scanf("%d", &num);

    int* arr = new int[num];
    for(int i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
        mean+=arr[i];
    }

    max = *std::max_element(arr, arr+num);
    printf("%2f", (float)mean*100/(max*num));

    return 0;
}

