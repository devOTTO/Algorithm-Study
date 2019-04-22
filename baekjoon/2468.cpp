//
// Created by 융미 on 2019-04-23.
//2468 안전 영역
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool check[101]; //입력 숫자 확인 배열
int arr[MAX][MAX]; //입력 배열
int vis[MAX][MAX]; //방문 확인 배열
vector<int> nums; //입력 높이
vector<int> result; //결과
int n;

void getInput(); //입력 함수
void printOutput(); //결과 프린트 함수
int bfs(int height); //bfs

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    getInput();
    printOutput();

    return 0;
}

void getInput()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> arr[i][j];
            check[arr[i][j]] = true;
        }
    }
}

void printOutput()
{
    for(int i = 1; i<101; i++)
    {
        if(check[i]) nums.push_back(i);
    }
    int num = 0;
    for(auto v : nums)
    {
       num = bfs(v);
       result.push_back(num);
    }

    cout << *max_element(result.begin(), result.end());
}

int bfs(int height)
{
    memset(vis,0,sizeof(vis));
    int num = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < n;j ++)
        {
            if(arr[i][j] <= height) continue;
            if(vis[i][j]) continue;

            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = 1;

            while(q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || arr[nx][ny] <= height) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }

            num++;
        }
    }
    return num;
}