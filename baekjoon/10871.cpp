//
// Created by 융미 on 2019-04-28.
//10871 X보다 작은 수
#include <cstdio>
#include <algorithm>
int main(){

    int len, num, input;

    scanf("%d %d", &len, &num);

    for(int i=0; i<len; i++){
        scanf("%d", &input);

        if(input < num)
        printf("%d ", input);
    }




    return 0;
}
