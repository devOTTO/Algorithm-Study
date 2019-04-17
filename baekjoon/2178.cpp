//2178 미로탐색
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

string arr[100]; //배열
int dis[100][100];//거리 배열

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    //bfs
    //항상 1.1 에서 출발
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dis[0][0] = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny] != 0 || arr[nx][ny] != '1') continue;

            dis[nx][ny] = dis[cur.first][cur.second] + 1;
            q.push(make_pair(nx,ny));
        }
    }

    cout << dis[n-1][m-1];

    return 0;
}
