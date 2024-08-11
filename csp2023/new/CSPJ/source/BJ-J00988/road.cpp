#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int n,d;
int l[N],pr[N],dp[N][N];
int zl,v;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        cin>>l[i];
        zl+=l[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>pr[i];
    }
    if(zl%d!=0) v=zl/d+1;
    else v=zl/d;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v;j++)
        {
            for(int k=0;k<=v;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-k*1]+pr[i]);

            }
        }

    }
    cout<<dp[n][v];
    return 0;
}