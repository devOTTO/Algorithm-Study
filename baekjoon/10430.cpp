//
// Created by 융미 on 2019-04-28.
// 10430 나머지
#include <cstdio>
int main(){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", (a+b)%c);
    printf("%d\n", (a%c + b%c)%c);
    printf("%d\n", (a*b)%c);
    printf("%d", (a%c*b%c)%c);
    return 0;
}

