//2146 다리 만들기
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n;
int arr[101][101];
int vis[101][101];
int dis[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){

    cin >> n;
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<pair<int,int>> q;
    int island = 1;

    //bfs 섬 찾기
   for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(arr[i][j] == 0 || vis[i][j] == 1) continue;
            q.push({i,j});
            vis[i][j] = 1;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                arr[cur.first][cur.second] = island;
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(arr[nx][ny] == 0 || vis[nx][ny] == 1)continue;

                    q.push({nx,ny});
                    vis[nx][ny]= 1;
                }


            }
            island++;
        }
    }
    vector<int> minvec;
    while(!q.empty()) q.pop();


    //min island 찾기
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(arr[i][j] == 0) continue; //바다면 패스
            for(int i = 0; i < n; i++) fill(dis[i],dis[i]+n,-1);
            q.push({i,j});
            dis[i][j] = 0;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 아닌 경우
                    if(dis[nx][ny] >= 0) continue; //이전 방문
                    if(arr[nx][ny] == arr[i][j]) continue;//같은 섬인 경우
                    if(arr[nx][ny] != 0) //바다가 아닌 경우! 섬이다
                    {
                        minvec.push_back(dis[cur.first][cur.second]);
                        break;
                    }
                    dis[nx][ny] = dis[cur.first][cur.second]+ 1;
                    q.push({nx,ny});

                }
            }

        }
    }


    cout << *min_element(minvec.begin(), minvec.end());


    return 0;
}
//더럽지만 나중에 고쳐야지
