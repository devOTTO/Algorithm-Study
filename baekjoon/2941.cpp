//
// Created by 융미 on 2019-04-28.
//2941 크로아티아 알파벳
#include <cstdio>
#include <cstring>

int main()
{
    char arr[101];
    scanf("%s", arr);
    int count = 0;
    int len = strlen(arr);

    for(int i = 0; i<len; i++)
    {

        if (arr[i] == 'c' && (arr[i+1] == '=' || arr[i+1] == '-')) i++;
        else if (arr[i] == 'd') {
            if (arr[i+1] == '-') i++;
            else if (arr[i+1] == 'z' && arr[i+2] == '=') i+=2;
        }
        else if ((arr[i] == 'l' || arr[i] == 'n') && arr[i+1] == 'j') i++;
        else if ((arr[i] == 's' || arr[i] == 'z') && arr[i+1] == '=') i++;


        count++;

    }
    printf("%d" , count);
    return 0;
}
