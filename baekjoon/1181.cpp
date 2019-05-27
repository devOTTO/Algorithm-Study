//
// Created by 융미 on 2019-05-28.
//*1181 단어 정렬
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;


//comparator 작성
bool com(string a, string b)
{
    if(a.length() < b.length()) return true;
    if(a.length() == b.length()){
        if(a < b) return true;
        else return false;
    }

    return false;
}

set<string> s; //set은 기본적으로 중복된 값 허용 안함
vector<string> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string tmp;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;

        s.insert(tmp);

    }

    for(set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        v.push_back(*it);
    }
    sort(v.begin(), v.end(), com);

    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] << '\n';
    }

    return 0;

}
