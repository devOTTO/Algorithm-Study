//15666 N과 M(12)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> vis;

void func(int k){
    if(vis.size() == m)
    {
        for(int i =0; i<m; i++)
        {
            cout << arr[vis[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    bool check[10001] = {};
    for(int i =k; i<n; i++)
    {
        if(!check[arr[i]] && vis.size() < m)
        {
            check[arr[i]] = 1;
            vis.push_back(i);
            func(i);
            vis.pop_back();

        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int k;
    for(int i =0; i<n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());

    func(0);

    return 0;
}
