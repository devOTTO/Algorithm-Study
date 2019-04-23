//
// Created by 융미 on 2019-04-23.
//2573 빙산

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 300
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n, m;
int age;
int arr[MAX][MAX];
bool vis[MAX][MAX];

void getInput(); //입력 함수
void getAge(); //시간 지나는 함수
int check(); //덩어리 체크 함수
void printOutput(); //결과 출력 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getInput();
    printOutput();

    return 0;
}

void getInput()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin >> arr[i][j];
    }
}

void printOutput()
{
    int result = 1;
    while(true)
    {
        age++;
        getAge();
        result = check();
        if(result >= 2) {cout << age; break;}
        if(result == 0) {cout << 0; break;}
    }
}

void getAge(){
    int tempArr[MAX][MAX];
    memset(tempArr,0,sizeof(tempArr));

    for(int i = 1; i<n-1; i++)
    {
        for(int j = 1; j<m-1; j++)
        {
            if(arr[i][j] == 0) continue;
            int count = 0;
            for(int k = 0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(arr[nx][ny] != 0) continue;
                count++;
            }
            tempArr[i][j] = arr[i][j] - count;
            if(tempArr[i][j] < 0) tempArr[i][j] = 0; //0 보다 작을 수 없다. 이조건 때문에 2번 틀림..
        };
    }
    memcpy(arr,tempArr, sizeof(arr));

}

int check(){
    memset(vis, 0, sizeof(vis));

    int count = 0;
    for(int i = 1; i<n-1; i++)
    {
        for(int j = 1; j<m-1; j++)
        {
            if(arr[i][j] == 0 || vis[i][j] == 1) continue;

            queue<pair<int,int>> q;

            q.push({i,j});
            vis[i][j] = 1;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 1 || nx >= n-1 || ny < 1 || ny >= m-1) continue;
                    if(arr[nx][ny] == 0 || vis[nx][ny] == 1) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
            count++;
        }
    }

    return count;
}

