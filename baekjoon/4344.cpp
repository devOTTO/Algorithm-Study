//
// Created by 융미 on 2019-04-28.
//4344 평균은 넘겠지
#include <cstdio>

int main(){
    int tc, num, sum, count;
    float mean;
    int *arr;

    scanf("%d", &tc);

    for(int i = 0; i<tc; i++)
    {
        scanf("%d", &num);

        arr = new int[num];
        sum = 0;
        count = 0;
        for(int j= 0; j<num; j++)
        {
            scanf("%d", &arr[j]);
            sum+=arr[j];
        }

        mean = sum/num;

        for(int j = 0; j<num; j++)
        {
            if(arr[j] > mean){
                count++;
            }
        }

        printf("%.3f%%\n", (float)count/num*100);
        delete arr;
    }
    return 0;
}