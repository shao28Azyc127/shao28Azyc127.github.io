#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 0,ans = 0;
    scanf("%d",&n);
    while(n)
    {
        cnt++;
        if (n % 3 == 1 && !ans) ans = cnt;
        n -= (n - 1) / 3 + 1;
    }
    printf("%d %d\n",cnt,ans);
}
