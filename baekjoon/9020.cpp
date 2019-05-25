//
// Created by 융미 on 2019-05-25.
//*9020 골드바흐의 추측
#include <iostream>
using namespace std;
#define MAX 10000
int sosu[MAX+1];

void print(int n)
{
    int i, j;
    int mid = n >> 1;
    for(i = j = mid; i > 0; i--, j++)
    {
        if(!sosu[i] && !sosu[j])
        {cout << i << " " << j << '\n';
            return;}
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sosu[0] = true;
    sosu[1] = true;

    for(int i = 2; i*i <= MAX; i++)
    {
        for(int j = 0; i*(i+j) <= MAX; j++)
        {
            sosu[i*(i+j)] = true;
        }
    }

    int num;
    cin >> num;
    int n;
    while(num--){
        cin >> n;
        print(n);
    }

    return 0;
}