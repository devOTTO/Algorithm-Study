//15656 N과 M(7)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> vis;

void func(){
    if(vis.size() == m)
    {
        for(int i =0; i<m; i++)
        {
            cout << arr[vis[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i =0; i<n; i++)
    {
        if(vis.size() < m)
        {
            vis.push_back(i);
            func();
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

    func();

    return 0;
}
