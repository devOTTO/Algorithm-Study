//
// Created by 융미 on 2019-04-28.
//10809 알파벳 찾기
#include <cstdio>
#include <cstring>

int main(){

    char arr[101];
    int check[26];

    for(int i = 0; i<26; i++)
        check[i] = -1;

    scanf("%s", arr);

    for(int i = 0; i<strlen(arr); i++){
        for(int j = 0; j < 26; j++)
        {
            if(arr[i] == (char)(j+97) && check[j] == -1)
            {
                check[j] = i;
            }
        }

    }

    for(int i = 0; i<26; i++)
        printf("%d ", check[i]);

    return 0;
}