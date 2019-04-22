//
// Created by 융미 on 2019-04-20.
//2206 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
using namespace std;

#define MAX 1000

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n, m;
string arr[MAX];
int dis[MAX][MAX][2];

void getInput();
int bfs();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getInput();
    cout << bfs();


    return 0;
}


void getInput(){
    cin >> n >> m;
    string s;
    for(int i = 0; i<n; i++)
    {
        cin >> s;
        arr[i] = s;
    }
}

int bfs()
{
    memset(dis, -1, sizeof(dis));

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    dis[0][0][0] = 1;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = get<0>(cur);
        int y  = get<1>(cur);
        int check = get<2>(cur);

        if(x == n-1 && y == m-1) return dis[n-1][m-1][check];

        for(int i = 0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int tocheck = check;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny][check] != -1) continue;
            if(arr[nx][ny] == '1' && tocheck == 1 ) continue;
            if(arr[nx][ny] == '1' && tocheck == 0) tocheck = 1;

            dis[nx][ny][tocheck] = dis[x][y][check] + 1;
            q.push(make_tuple(nx,ny,tocheck));

        }

    }

    return -1;
}