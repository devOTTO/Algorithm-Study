//
// Created by 융미 on 2019-04-28.
//8958 OX퀴즈
#include <cstdio>
#include <cstring>

int main(){

    char arr[80];
    int n = 0;
    int point;
    int score;

    scanf("%d", &n);


    for(int i = 0; i<n; i++)
    {
        scanf("%s", arr);
        point = 0;
        score = 0;

        for(int j = 0; j < strlen(arr); j++)
        {
            if(arr[j] == 'O')
            {
                point++;
                score+=point;
            }
            else if(arr[j] == 'X'){

                point = 0;
            }
        }
        printf("%d\n", score);
    }


    return 0;
}