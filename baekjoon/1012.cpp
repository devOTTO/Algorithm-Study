//1012 유기농 배추
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[50][50];
bool vis[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int init(){
    for(int i =0; i<50; i++)
    {
        for(int j =0; j<50; j++)
        {
            arr[i][j] = 0;
            vis[i][j]= 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;
    cin >> tc;

    for(int i = 0; i<tc; i++)
    {
        int num;
        int n, m;
        int ji = 0;

        init();

        cin >> n >> m >> num;
        for(int j =0 ;j<num; j++)
        {
            int x,y;
            cin >> x >> y;
            arr[x][y] = 1;
        }

        //bfs


        for(int o = 0; o < n; o++)
        {
            for(int p = 0; p < m; p++)
            {
                if(vis[o][p] == 1|| arr[o][p] == 0) continue;

                queue<pair<int,int>>  q;
                vis[o][p] = 1;
                q.push(make_pair(o,p));
                ji++;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();


                    for(int k = 0; k<4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] == 1 || arr[nx][ny] == 0) continue;

                        vis[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }

        cout << ji << '\n';
    }




    return 0;
}
