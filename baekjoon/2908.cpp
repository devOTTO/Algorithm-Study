//
// Created by 융미 on 2019-04-28.
//2908 상수
#include <cstdio>

int sangsu(int n);

int main(){

    int a,b;

    scanf("%d %d", &a, &b);
    a = sangsu(a);
    b = sangsu(b);
    if(a>b)
        printf("%d", a);
    else
        printf("%d",b);


    return 0;
}

int sangsu(int n){
    int result = 0;
    result = (n%10)*100;
    n /= 10;
    result += (n%10)*10;
    n /= 10;
    result += n;

    return result;
}
