//
// Created by 융미 on 2019-04-20.
//7562 나이트의 이동
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int dis[300][300];
int tc, l;
int sx,sy, tx,ty;

void getInput();
int bfs();
void initArr();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for(int i = 0; i<tc; i++)
    {
        getInput();
        initArr();
        cout << bfs() << '\n';
    }

    return 0;
}

void getInput(){
    cin >> l;
    cin >> sx >> sy;
    cin >> tx >> ty;
}

int bfs(){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dis[sx][sy] = 0;

    while (!q.empty())
    {

        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        if(x == tx && y == ty) return dis[x][y];

        for(int i = 0; i<8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx == tx && ny == ty) return dis[x][y]+1;
            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if(dis[nx][ny]!=-1) continue;

            q.push({nx,ny});
            dis[nx][ny] = dis[x][y] + 1;

        }

    }

}

void initArr(){
    memset(dis,-1,sizeof(dis));
}

