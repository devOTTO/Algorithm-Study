//15652 N과 M(4)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

void func(int k)
{
    if(arr.size() == m)
    {
        for(int i = 0; i<m; i++)
        {
            cout << arr[i] + 1 << ' ';
        }
        cout << '\n';
    }
    for(int i = k; i<n; i++)
    {
        if(arr.size() < m)
        {
            arr.push_back(i);
            func(i);
            arr.pop_back();
        }
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    func(0);

    return 0;
}
