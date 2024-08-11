#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
struct node
{
    int x,y,v;
}a[20010];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
long long dp[20010];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++)
    {
        cin >> a[i].x >> a[i].y >>a[i].v;
    }
    sort(a+1,a+m+1,cmp);
    dp[1]=0;
    for(int i=2; i<n; i++)
    {
        dp[i]=9e18;
        for(int j=1; j<=m; j++)
        {
            if(a[j].x>i) break;
            if(a[j].y==i)
            {
                long long g=dp[a[j].x];
                long long p=0LL+(a[j].v+k-1)/k*k+g%k;
                if(p-k>=g) p-=k;
                dp[i]=min(dp[i],p+1);
            }
        }
    }
    dp[n]=9e18;
    for(int j=1; j<=m; j++)
    {
        if(a[j].y==n)
        {
            long long g=dp[a[j].x];
            long long p=0LL+(a[j].v+k-1)/k*k+g%k;
            if(p-k>=g) p-=k;
            p++;
            int lc=(p+k-1)/k*k;
            if((p%k)%2==lc%2)
            {
                p=lc;
                dp[n]=min(dp[n],p);
            }
            if((p%k)%2==(lc+k)%2)
            {
                p=lc+k;
                dp[n]=min(dp[n],p);
            }
        }
    }
    if(dp[n]==9e18) cout << -1;
    else cout << dp[n];
    return 0;
}