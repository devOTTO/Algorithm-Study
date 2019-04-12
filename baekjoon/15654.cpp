//15654 N과 M(5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<bool> isused;
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
        if(!isused[i])
        {
            isused[i] = 1;
            vis.push_back(i);
            func();
            isused[i] = 0;
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

    isused = vector<bool>(n, false);
    func();

    return 0;
}
