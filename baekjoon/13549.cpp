//
// Created by 융미 on 2019-05-04.
//*13549 숨바꼭질3
//주의할 점 : *2는 순간이동해서 0초이므로, 더 작은 값을 출력할 것
// 우선 순위 큐를 사용해도 좋을 것 같다
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

#define MAX 100001
bool vis[MAX];
int n,k;

int bfs(){
    queue<pair<int,int>> q;
    q.push({n,0});
    vis[n] = 1;
    int ret = INT_MAX;

    if(n == k)
        return 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        vis[x] = 1;

        if(x == k) ret = min(ret,cur.second);

        int nx = 2*x;

        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({nx,cur.second});
        }

        int nt = cur.second+1;
        nx = x + 1;
        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({nx,nt});
        }

        nx = x - 1;
        if(nx >= 0 && nx < MAX && vis[nx]!=1) {
            q.push({nx,nt});
        }

    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cout << bfs();

    return 0;
}


