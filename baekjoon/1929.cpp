//
// Created by 융미 on 2019-05-24.
//*1929 소수 구하기
//에라토스테네스의 체를 이용해야 시간 초과가 나지 않음
#include <iostream>
using namespace std;
int m, n;
#define MAX 1000000

bool check[MAX+1];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    check[1] = true;

    for(int i = 2; i * i<= MAX; i++)
    {
        for(int j = 0; i*(i+j)<= MAX; j++)
        {
            check[i*(i+j)] = true;
        }
    }

    for(int i = m; i<= n; i++)
    {
        if(!check[i]) cout << i << '\n';
    }

    return 0;
}
