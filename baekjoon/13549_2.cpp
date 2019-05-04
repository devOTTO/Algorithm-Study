//
// Created by 융미 on 2019-05-04.
//*13549 숨바꼭질3 우선 순위 큐 사용 버전

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

#define MAX 100001
bool vis[MAX];
int n,k;

int bfs(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,n});
    vis[n] = 1;

    if(n == k)
        return 0;

    while(!q.empty())
    {
        auto cur = q.top();
        q.pop();
        int x = cur.second;

        if(x == k) return cur.first;

        int nx = 2*x;
        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({cur.first,nx});
            vis[nx] = 1;
        }

        int nt = cur.first+1;

        nx = x + 1;
        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({nt,nx});
            vis[nx] = 1;
        }

        nx = x - 1;
        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({nt,nx});
            vis[nx] = 1;
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cout << bfs();

    return 0;
}

