//
// Created by 융미 on 2019-05-26.
//*1011 Fly me to the Alpha Centauri
#include <iostream>
#include <cmath>
using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    int x, y;
    while(tc--) {
        cin >> x >> y;

        long long i = 1, dist = y - x;
        while (i * i <= dist) {
            i++;
        }
        i--;
        dist = ceil((double) (dist - i * i) / i);
        cout << i + i - 1 + dist << '\n';
    }
    return 0;
}
