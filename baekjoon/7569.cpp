//7569 토마토(3중)
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

#define MAX_RANGES 100

int arr[MAX_RANGES][MAX_RANGES][MAX_RANGES];
int vis[MAX_RANGES][MAX_RANGES][MAX_RANGES];


int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,h;

    cin >> m >> n >> h;
    int unto = 0;
    int to = 0;
    int visited = 0;
    int dis = 0;

    queue<tuple<int,int,int>> q;

    for(int k = 0; k < h; k++)
    {
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                cin >> arr[k][i][j];
                if(arr[k][i][j] == 1)
                {
                    q.push(make_tuple(k,i,j));
                    vis[k][i][j] = 1;
                    visited++;
                    if(vis[k][i][j] > dis) dis = vis[k][i][j];
                    to++;
                }
                else if(arr[k][i][j] == 0) unto++;
            }
        }

    }


    //bfs
    while(!q.empty())
    {
        tuple<int,int,int> cur = q.front();
        q.pop();
        for(int k = 0; k<6; k++)
        {
            int nz = get<0>(cur) + dz[k];
            int nx = get<1>(cur) + dx[k];
            int ny = get<2>(cur) + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(vis[nz][nx][ny] != 0 || arr[nz][nx][ny] == -1 || arr[nz][nx][ny] == 1) continue;

            q.push(make_tuple(nz,nx,ny));
            arr[nz][nx][ny] = 1;

            vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            visited++;
            if(vis[nz][nx][ny] > dis) dis = vis[nz][nx][ny];
        }
    }



    if(visited == to) cout << 0;
    else if(visited - to == unto) cout << dis - 1;
    else if(visited - to != unto) cout << -1;


    return 0;
}
