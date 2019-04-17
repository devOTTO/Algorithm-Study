//1697 숨바꼭질
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int MAX_RANGE = 100000;
bool vis[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;

    cin >> n >> k;

    queue<pair<int,int>> q;
    q.push({0,n});
    vis[n] = 1;
    int i = 0;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int now = cur.second;

        if(now == k)
        {
            cout << cur.first;
            break;
        }


        int nt = cur.first+1;
        if(now - 1 >= 0 && vis[now-1]!=1)
        {

            q.push({nt,now-1});
            vis[now-1] = 1;
        }
        if(now + 1 <= MAX_RANGE && vis[now+1] != 1)
        {
            q.push({nt,now+1});
            vis[now+1] = 1;
        }
        if(now*2 <= MAX_RANGE && vis[now*2] != 1)
        {
            q.push({nt, now*2});
            vis[now*2] = 1;
        }

    }

    return 0;
}
