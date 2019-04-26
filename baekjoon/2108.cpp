//
// Created by 융미 on 2019-04-26.
//2108 통계학
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){

    int num = 0;
    int arr[8001] = {0,};
    int temp = 0;
    int sansul = 0;
    int mid = 0;
    int most = -1;
    std::vector<int> bin;
    int first = 8001;
    int last = -1;
    int count = 0;

    std::cin >> num;
    for(int i = 0; i<num; i++)
    {
        std::cin >> temp;
        ++arr[temp+4000];
    }

    //산술
    for(int i = 0; i<8001; i++)
    {
        if(arr[i] != 0)
        {
            if(i<first)
                first = i;
            if(i>last)
                last = i;

            if(most < arr[i])
            {
                bin.clear();
                most = arr[i];
            }
            if(most == arr[i])
                bin.push_back(i);

            for(int j = 0; j<arr[i]; j++)
            {

                if(++count == (num/2 + 1))
                {
                    mid = i-4000;
                }
                sansul+=(i-4000);
            }
        }
    }

    std::cout << floor((double)sansul/num+0.5) << '\n';

    //중앙
    std::cout << mid << '\n';

    //최빈
    most = bin[0];
    // 최빈값이 여러개인 경우 두번째로 작은 값 선택
    if (bin.size() > 1) {
        sort(bin.begin(), bin.end());
        most = bin[1];
    }
    std::cout << most - 4000 << '\n';

    //범위
    std::cout << last - first;

    return 0;
}

