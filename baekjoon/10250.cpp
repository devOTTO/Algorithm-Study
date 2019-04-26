//
// Created by 융미 on 2019-04-26.
//10250 ACM 호텔
#include <cstdio>

int main(){
    int tc;
    int h, w, n;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d %d", &h, &w, &n);
        n--;
        int floor = n%h + 1;
        int num = n/h+1;

        printf("%d\n", floor*100 + num);

    }
    return 0;
}