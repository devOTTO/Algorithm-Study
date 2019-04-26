//
// Created by 융미 on 2019-04-26.
//2775 부녀회장이 될테야
#include <cstdio>

int bunyu(int k, int n);

int main(){
    int tc,k,n;

    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", bunyu(k,n));
    }
    return 0;
}

int bunyu(int k, int n)
{
    if(n == 1)   // base case 1호
        return 1;

    if(k == 0) //base case 0층
        return n;

    return bunyu(k, n-1) + bunyu(k-1,n);
}
