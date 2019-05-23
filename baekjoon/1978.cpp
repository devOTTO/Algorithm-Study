//
// Created by 융미 on 2019-05-23.
//*1978 소수 찾기
#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[100];
bool check[100];

//재귀 아닌 버전
int findSosu(){

    for(int i = 0; i< N; i++){

        if(arr[i] == 1){
            check[i] = true;
            continue;
        }

        if(arr[i] == 2)
        {
            check[i] = false;
            continue;
        }

        for(int j = 2; j< arr[i]; j++)
        {

            if((arr[i])%j == 0)
            {check[i] = true; break;}
        }

    }

    int cnt = 0;

    for(int i = 0; i<N; i++)
    {
        if(!check[i]) cnt++;
    }
    cout << cnt;
}

int main() {

    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> arr[i];
    }
    findSosu();
    return 0;
}
