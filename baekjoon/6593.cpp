//
// Created by 융미 on 2019-05-03.
//6593 상범 빌딩
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 30

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int l,r,c;
tuple<int,int,int> start;
tuple<int,int,int> escape;

int dis[MAX][MAX][MAX];
char arr[MAX][MAX][MAX];

void initMEM(){
    memset(dis,-1,sizeof(dis));
    memset(arr,' ', sizeof(arr));
}


void bfs(){


    queue<tuple<int,int,int>> q;
    q.push(start);
    dis[get<0>(start)][get<1>(start)][get<2>(start)] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int z = get<0>(cur);
        int x = get<1>(cur);
        int y = get<2>(cur);



        for(int i = 0; i<6; i++)
        {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];


            if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;

            if(dis[nz][nx][ny] != -1) continue;
            if(arr[nz][nx][ny] == '#') continue;

            q.push(make_tuple(nz,nx,ny));
            dis[nz][nx][ny] = dis[z][x][y] + 1;

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char t;

    while(true){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        initMEM();
        for(int i = 0; i<l; i++)
        {
            for(int j = 0; j<r; j++)
            {
                for(int k = 0; k<c; k++)
                {
                    cin >> t;
                    arr[i][j][k] = t;
                    if(arr[i][j][k] == 'S')
                        start = make_tuple(i,j,k);
                    else if(arr[i][j][k] == 'E')
                        escape = make_tuple(i,j,k);
                }
            }
        }



        bfs();

        if(dis[get<0>(escape)][get<1>(escape)][get<2>(escape)] != -1){
            cout << "Escaped in " << dis[get<0>(escape)][get<1>(escape)][get<2>(escape)] << " minute(s)." << '\n';
        }
        else cout << "Trapped!"<< '\n';
    }



    return 0;
}