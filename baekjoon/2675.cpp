//
// Created by 융미 on 2019-04-28.
//2675 문자열 반복
#include <cstdio>
#include <cstring>
int main(){
    char arr[21];
    int tc, R;

    scanf("%d", &tc);

    for(int i = 0; i<tc; i++)
    {
        scanf("%d %s", &R, arr);

        for(int j = 0; j<strlen(arr); j++)
        {
            for(int k = 0; k<R; k++){
                printf("%c",arr[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
