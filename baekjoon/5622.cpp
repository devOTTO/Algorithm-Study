//
// Created by 융미 on 2019-04-28.
//5622 다이얼
#include <cstdio>
#include <cstring>

int main()
{
    char arr[16];
    int nums[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    int len, result = 0;

    scanf("%s", arr);

    len = strlen(arr);

    for(int i = 0; i<len; i++)
    {
        result+= nums[arr[i]-'A'] +1;
    }

    printf("%d", result);
    return 0;
}
