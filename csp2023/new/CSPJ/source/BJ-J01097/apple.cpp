#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n;
int ans;
bool flag=true;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    n=read();
    int cnt=0;
    while (n>0)
    {
        if (n%3==1&&flag)
        {
            ans=cnt+1;
            flag=false;
        }
        n-=(n-1)/3+1;
        cnt++;
    }
    printf("%lld %lld",cnt,ans);
    return 0;
}
