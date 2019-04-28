//
// Created by 융미 on 2019-04-28.
//1065 한수
#include <cstdio>

int main(){

    int num;
    int han;

    scanf("%d", &num);

    if(num<100) han=num;
    else{
        han=99;
        for(int i = 100; i<=num; i++){

            if(((i/100) - ((i%100)/10)) == (((i%100)/10)-((i%100)%10))){
                han++;
            }
        }
    }

    printf("%d", han);
    return 0;
}
