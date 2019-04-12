//15650 N과 M(2)
#include <iostream>
#include <vector>
using namespace std;

vector<bool> isused;
vector<int> arr;

int n, m;

void func(int k){
    if(arr.size() == m)
    {
        for(int i = 0; i<m; i++)
        {
            cout << arr[i] + 1 << ' ';
        }
        cout << '\n';
    }

    for(int i =k; i<n; i++)
    {
        if(!isused[i])
        {
            isused[i] = 1;
            arr.push_back(i);
            func(i+1);
            arr.pop_back();
            isused[i]=0;

        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    isused=vector<bool>(n, false);

    func(0);
    return 0;
}
