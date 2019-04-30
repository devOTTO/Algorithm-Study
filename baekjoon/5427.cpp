//
// Created by 융미 on 2019-04-30.
//5427 불
//개인적으로 내가 쓴 풀이가 런타임 에러가 10번? 은 나서 너무 고생했다..
#include <iostream>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

#define MAX 1000

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int w, h, tc, x, y;
bool vis[MAX][MAX];
string arr[MAX];
//string tempArr[MAX]; 이런 식으로 배열을 복사하니 런타임 에러

void getInput(); //입력을 받는 함수
//void getFire(); //불을 옮겨 붙이는 함수 이거도 따로 뺐다가 런타임 에러
int bfs(); //거리 계산
void printResult();
queue<pair<int,int>> f;
queue<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for(int i = 0; i<tc; i++){
        getInput();
        printResult();
    }

    return 0;
}

void getInput()
{
    cin >> w >> h;
    memset(vis, 0, sizeof(vis));

    while(!q.empty())
        q.pop();
    while(!f.empty())
        f.pop();

    for(int i = 0; i<h; i++)
    {
        cin >> arr[i];
        for(int j = 0; j<w; j++)
        {
            if(arr[i][j] == '@')
            { x = i; y = j;}
            if(arr[i][j] == '*')
                f.push({i,j});
        }
    }
}

//void getFire(){
////    memcpy(tempArr,arr,sizeof(arr));
////    for(int i = 0; i<h; i++)
////    {
////        tempArr[i] = arr[i];
////        for(int j = 0; j<w; j++)
////        {
////            if(tempArr[i][j] != '*') continue;
////                for(int k = 0; k<4; k++)
////                {
////                    int nx = i + dx[k];
////                    int ny = j + dy[k];
////
////                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
////                    if(tempArr[nx][ny] != '.') continue;
////                    arr[nx][ny] = '*';
////                }
////
////        }
////    }
//    int size = f.size();
//    for(int i = 0; i<size; i++)
//    {
//       auto cur = f.front();
//       f.pop();
//
//            for(int k = 0; k<4; k++)
//            {
//                int nx = cur.first + dx[k];
//                int ny = cur.second + dy[k];
//
//                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
//                if(arr[nx][ny] != '.') continue;
//                arr[nx][ny] = '*';
//                f.push({nx,ny});
//           }
//
//    }
//
//}

int bfs()
{
    q.push({x,y});
    vis[x][y] = 1;
    int count = 0;
    while(!q.empty())
    {
        //getFire();
        int size = f.size();
        for(int i = 0; i<size; i++)
        {
            auto cur = f.front();
            f.pop();

            for(int k = 0; k<4; k++)
            {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(arr[nx][ny] != '.') continue;
                arr[nx][ny] = '*';
                f.push({nx,ny});
            }

        }

        int curSize = q.size();
        for (int k = 0; k < curSize; k++) {
            auto cur = q.front();
            q.pop();
            int cx = cur.first;
            int cy = cur.second;

            //끝에 있으면 1초뒤 탈출 가능
            if (cx == 0 || cx == h - 1 || cy == 0 || cy == w - 1)
                return ++count;

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (arr[nx][ny] != '.' || vis[nx][ny] == 1) continue;

                q.push({nx, ny});
                vis[nx][ny] = 1;
            }

        }
        count++;
    }

    return -1;
}

void printResult()
{
    int result = bfs();

    if(result == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << result << '\n';
}

