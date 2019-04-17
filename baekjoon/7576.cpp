//7576 토마토
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define MAX_RANGE 1000

int arr[MAX_RANGE][MAX_RANGE];
int vis[MAX_RANGE][MAX_RANGE];


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >> m >> n;
    int unto = 0;
    int to = 0;
    int visited = 0;
    int dis = 0;

    queue<pair<int,int>> q;

    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
            {
                q.push({i,j});
                vis[i][j] = 1;
                visited++;
                if(vis[i][j] > dis) dis = vis[i][j];
                to++;
            }
            else if(arr[i][j] == 0) unto++;
        }
    }


    //bfs




    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for(int k = 0; k<4; k++)
        {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] != 0 || arr[nx][ny] == -1 || arr[nx][ny] == 1) continue;

            q.push({nx,ny});
            arr[nx][ny] = 1;

            vis[nx][ny] = vis[cur.first][cur.second]+1;
            visited++;
            if(vis[nx][ny] > dis) dis = vis[nx][ny];
        }
    }



    if(visited == to) cout << 0;
    else if(visited - to == unto) cout << dis - 1;
    else if(visited - to != unto) cout << -1;


    return 0;
}
