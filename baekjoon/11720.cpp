//
// Created by 융미 on 2019-04-28.
//11720 숫자의 합
#include <cstdio>
int main(){

    int n, x, result = 0;
    scanf("%d", &n);

    while(n--){
        scanf("%1d", &x);
        result += x;
    }
    printf("%d", result);

    return 0;
}

