//
// Created by 융미 on 2019-05-25.
//*4948 베르트랑 공준
#include <iostream>
using namespace std;
#define MAX 2*123456
bool sosu[MAX + 1];

int sosuNum(int n)
{
    int cnt = 0;
    for(int i = n+1; i<=2*n; i++)
    {
        if(!sosu[i]) cnt++;
    }
    return cnt;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sosu[1] = true;
    sosu[0] = true;

    for(int i = 2; i*i <= MAX; i++)
    {
        for(int j = 0; i*(i+j) <= MAX; j++)
        {
            sosu[i*(i+j)] = true;
        }
    }

    int n =-1;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        cout << sosuNum(n) << '\n';
    }

    return 0;
}
