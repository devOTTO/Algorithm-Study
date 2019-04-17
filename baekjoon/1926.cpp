//1926 그림

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int arr[500][500];
bool vis[500][500];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int num = 0; //그림 수
    int max = 0; //최대 그림 넓이

    cin >> n >> m;
    //input 받기
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    //bfs
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(arr[i][j] == 0 || vis[i][j]==1) //방문했거나, 색칠 안된 칸이면 pass
                continue;

            num++;
            vis[i][j] = 1;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));

            int area = 0;

            while(!q.empty())
            {
                area++;
                pair<int, int> cur = q.front();
                q.pop();

                for(int k =0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx < 0 || nx >=n || ny < 0 || ny>=m) continue;
                    if(vis[nx][ny] ==1 || arr[nx][ny] == 0) continue;
                    vis[nx][ny] =1;
                    q.push(make_pair(nx,ny));
                }
            }
            if(area>max) max = area;

        }
    }

    cout << num << '\n';
    cout << max << '\n';
    return 0;
}

