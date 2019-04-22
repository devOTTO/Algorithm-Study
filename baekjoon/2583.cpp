//
// Created by 융미 on 2019-04-20.
//2583 영역 구하기
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0,0};
int dy[4] = {0,0,1,-1};

int m, n, k;
int arr[100][100];
bool vis[100][100];
vector<tuple<int,int,int,int>> xy;
vector<int> area;

void getInput();
void checkArea();
void bfs();
void printAns();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    getInput();
    checkArea();
    bfs();
    printAns();

    return 0;
}

void getInput(){
    cin >> m >> n >> k;
    int x1, y1,x2,y2;
    for(int i = 0; i<k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        xy.push_back(make_tuple(x1, y1, x2, y2)); //좌표 입력 받
    }

}

void checkArea() {

    for (auto c : xy) {
        for (int i = get<1>(c); i < get<3>(c); i++) //y
        {
            for (int j = get<0>(c); j < get<2>(c); j++)//x
            {
                arr[i][j] = 1;
            }
        }
    }
}

void bfs(){
    queue<pair<int,int>> q;
    int _area = 0;

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(arr[i][j] == 1 || vis[i][j] == 1) continue; //사각 영역이거나 방문했으면 패스

            vis[i][j] = 1;// 방문 check
            q.push({i,j});
            _area = 1;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int l = 0; l<4; l++)
                {
                    int nx = cur.first+dx[l];
                    int ny = cur.second + dy[l];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] == 1 || arr[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                    _area++;
                }
            }
            area.push_back(_area);

        }
    }

}

void printAns()
{
    sort(area.begin(), area.end());
    int size = area.size();
    cout << size << '\n';
    for(int i = 0; i< size; i++)
    {
        cout << area[i] << ' ';
    }
}