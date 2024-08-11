#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long long n,d;
const int N=1e5+5;
long long dp[N];
long long dis[N];
long long z;
long long p[N];
long long minn[N];
int minp[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    dis[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>z;
        dis[i]=dis[i-1]+z;
    }
    minn[0]=2e9;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        if(p[i]<minn[i-1])
        {
            minn[i]=p[i];
            minp[i]=i;
        }
        else
        {
            minn[i]=minn[i-1];
            minp[i]=minp[i-1];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[minp[i-1]]+p[minp[i-1]]*ceil((dis[i]-dis[minp[i-1]]-(d-dis[minp[i-1]]%d)%d)*1.0/d);
    }
    cout<<dp[n];
    return 0;
}

