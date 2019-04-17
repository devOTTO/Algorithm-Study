//2667 단지 번호 붙이기
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0,0};
int dy[4] = {0,0,1,-1};

string arr[25];
bool vis[25][25];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    //bfs
    queue<pair<int,int>> q;
    vector<int> areaQ;

    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(vis[i][j] == 1 || arr[i][j] != '1') continue;

            int area = 0;
            q.push({i,j});
            vis[i][j] = 1;

            while(!q.empty())
            {
                area++;
                auto cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] == 1 || arr[nx][ny] != '1') continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;

                }
            }

            areaQ.push_back(area);
        }
    }

    sort(areaQ.begin(), areaQ.end());

    cout << areaQ.size() << '\n';
   for(int i =0; i<areaQ.size(); i++)
   {
       cout << areaQ[i] << '\n';
   }
    return 0;

}

