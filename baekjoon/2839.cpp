//
// Created by 융미 on 2019-04-28.
// 2839 설탕 배달
#include <cstdio>
int main(){

    int input;
    int count = 0;
    scanf("%d", &input);


    while(input > 0){
        if(input % 5 == 0){
            input -=5;
            count++;
        }
        else if(input % 3 ==0){
            input -=3;
            count++;
        }
        else if(input > 5){
            input -=5;
            count++;
        }
        else{
            count = -1;
            break;
        }

    }

    printf("%d", count);
    return 0;

}

