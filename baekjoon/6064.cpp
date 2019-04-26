//
// Created by 융미 on 2019-04-26.
//6064 카잉 달력
#include <cstdio>

int gcd(int x, int y);

int main()
{
    int tc, m,n,x,y, tempX, tempY;
    int lcm = 0;
    int count = 0;
    scanf("%d", &tc);

    while(tc--){
        scanf("%d %d %d %d", &m, &n, &x, &y);

        lcm =  m*n/gcd(m,n);
        tempX = 1;
        tempY = 1;
        for(count = x; count<=lcm; count+=m)
        {
            tempX = (count-1)%m + 1;
            tempY = (count-1)%n + 1;

            if(tempX == x && tempY == y)
                break;
        }
        if(count > lcm)
            count = -1;

        printf("%d\n", count);

    }



    return 0;

}

int gcd(int x, int y)
{
        if(x%y == 0) //base case
            return y;

        return gcd(y, x%y);

}












