//
// Created by 융미 on 2019-04-28.
//1316 그룹 단어 체커
#include <cstdio>
#include <cstring>

int main(){

    int num;
    char arr[101];
    int len;
    int answer;
    scanf("%d", &num);

    answer = num;

    for(int i = 0; i<num; i++){
        scanf("%s", arr);
        len = strlen(arr);
        bool check[26] = {false, };
        for(int j = 1; j<len; 저 j++){
            if(arr[j-1] != arr[j]) //만약 이전 단어랑 같지 않다면
            {
                if(check[arr[j] - 97]) //이전에 나왔던 단어라면
                {
                    answer--;
                    break;
                }
                else{
                    check[arr[j-1] - 97] = true;
                }
            }
        }
    }

    printf("%d", answer);


    return 0;
}
