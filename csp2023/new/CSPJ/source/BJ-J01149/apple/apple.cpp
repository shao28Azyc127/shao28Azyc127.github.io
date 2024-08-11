#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cnt=0,ans=0;
    while(n)
    {
        cnt++;
        int t=n%3;
        if(t==1 && !ans) ans=cnt;
        n-=n/3;
        if(t>=1) n--;
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}