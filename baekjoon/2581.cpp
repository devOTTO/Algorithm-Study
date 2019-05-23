//
// Created by 융미 on 2019-05-23.
//*2581 소수
#include <iostream>
using namespace std;

int m, n;

bool isSosu(int num){

    if(num == 1) return 0;
    if(num == 2) return 1;
    for(int i = 2; i<num; i++)
    {
        if(num%i== 0)
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    int sum = 0;
    int min = 10001;
    for(int i = m; i<= n; i++)
    {
        if(isSosu(i))
        {
            sum+= i;
            if(min > i) min = i;
        }
    }

    if(sum == 0)
    {
        cout << -1;
    }
    else {
        cout << sum << '\n';
        cout << min << '\n';
    }
    return 0;
}


