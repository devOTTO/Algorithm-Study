//
// Created by 융미 on 2019-04-28.
//1157 단어 공부
#include <cstdio>
#include <cstring>
#include <algorithm>

int main(){

    char arr[1000001];
    int len;
    int max = -1;
    int count[26] = {0, };
    int num = 0;
    int index = 0;
    scanf("%s", arr);

    len = strlen(arr);

    for(int i = 0; i<len; i++)
    {
        if(arr[i] >= 'A' && arr[i] <= 'Z')
            count[arr[i] - 65 ]++;
        else
            count[arr[i]-97]++;
    }

    for(int i = 0; i<26;i++)
    {
        if(max <= count[i])
        {
            max = count[i];
            index = i;
        }
    }

    for(int i= 0;i<26;i++)
    {
        if(count[i] == max)
        {
            num++;
        }
    }

    if(num > 1)
        printf("?");
    else
        printf("%c", index+65);

    return 0;
}