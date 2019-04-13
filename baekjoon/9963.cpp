//9963 N-Queen
#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt;

vector<bool> isused1; //열
vector<bool> isused2; // 우향 대각선 / x+y
vector<bool> isused3; // 좌향 대각선 \ x-y+n-1

void nqueen(int cur)
{
    if(cur == n)//다 놨다면
    {
        cnt++;
        return;
    }
    for(int i = 0; i<n; i++)
    {
        if(isused1[i]||isused2[cur+i]||isused3[cur-i+n-1]) continue;
        isused1[i] = 1;
        isused2[cur+i] = 1;
        isused3[cur-i+n-1]=1; //사용 체크
        nqueen(cur+1); //다음열루 들어감
        isused1[i] = 0; //나왔다고 체크
        isused2[cur+i] = 0;
        isused3[cur-i+n-1]=0;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    isused1 = vector<bool>(n, false);
    isused2 = vector<bool>(2*n-1, false);
    isused3 = vector<bool>(2*n-1, false);

    nqueen(0);
    cout << cnt;

    return 0;
}
