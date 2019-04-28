//
// Created by 융미 on 2019-04-28.
//10039 평균 점수
#include <cstdio>

int main()
{
    int score;
    int result = 0;

    for(int i = 0; i<5;i++)
    {
        scanf("%d", &score);
        if(score<40) score=40;
        result+=score;
    }

    printf("%d", result/5);
    return 0;
}

