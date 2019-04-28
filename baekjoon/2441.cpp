//
// Created by 융미 on 2019-04-28.
//2441 별 찍기 - 4
#include <iostream>

int main() {
    int a;
    std::cin >> a;
    for(int i = 0; i<a; ++i)
    {
        for(int j = 0; j<i; ++j)
        {std::cout << ' ';}
        for(int j = 0; j<a-i; ++j)
        {std::cout << '*';}

        std::cout << '\n';
    }

    return 0;
}
