//
// Created by 융미 on 2019-05-02.
//5014 스타트링크
#include <iostream>
#include <queue>
#include <utility>
#define MAX 1000001
using namespace std;
int f,s,g,u,d;
bool vis[MAX];

int bfs()
{
    queue<pair<int,int>> q;
    q.push({s,0});
    vis[s] = 1;

    while(!q.empty()) {
        auto now = q.front();
        int ncur = now.first;
        int nt = now.second;
        q.pop();


        if (ncur == g) return nt;
        if (ncur + u <= f) {
            if (!vis[ncur + u]) {
                vis[ncur + u] = 1;
                q.push({ncur + u, nt+1});
            }
        }

        if (ncur - d >= 1) {
            if (!vis[ncur - d]) {
                vis[ncur - d] = 1;
                q.push({ncur - d, nt+1});
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    int result = bfs();
    if(result == -1)
    {
        cout << "use the stairs";
    }else cout << result;

    return 0;
}
