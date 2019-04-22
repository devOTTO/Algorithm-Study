//
// Created by 융미 on 2019-04-20.
//10026 적록색약
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int n;
string arr[100];
bool vis[100][100];

void getInput();
int bfs(bool b); //적록 색약이 아닌 사람 false


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getInput();
    cout << bfs(false) << ' ';
    memset(vis,false,sizeof(vis));
    cout << bfs(true);



    return 0;
}

void getInput()
{
    cin >> n;
    string s;
    for(int i = 0; i<n; i++)
    {
        cin >> s;
        arr[i] = s;
    }

}

int bfs(bool b)
{
    int num = 0;
    char target = '\0';
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++){
            if(vis[i][j] == 1) continue;

            target = arr[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = 1;

            while(!q.empty()){

                auto cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first+dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny<0 || ny >= n) continue;
                    if(vis[nx][ny] == 1) continue;

                    //적록 색약 일 경우

                    if(b && (target == 'R' || target == 'G') && arr[nx][ny] == 'B') continue;
                    if(b && (target == 'B') && (arr[nx][ny] != target)) continue;

                    if(!b && (arr[nx][ny] != target)) continue;

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            num++;
        }
    }
    return num;
}

