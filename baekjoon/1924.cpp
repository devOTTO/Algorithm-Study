//
// Created by 융미 on 2019-04-26.
//1924 2007년
#include <cstdio>
int main(){

    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
    char days[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int x, y, count = 0;

    scanf("%d %d", &x, &y);

    for(int i = 0; i < x-1; i++)
    {
        count += month[i];
    }
    count += y;

    printf("%s", days[count%7]);

    return 0;
}