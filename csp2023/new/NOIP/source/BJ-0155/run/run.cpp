#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[1010][1010];
ll dp[1010][1010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                sum[i][j]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            sum[x][y]+=v;
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1e17;
        dp[0][0]=0;
        ll mx=0;
        for(int i=1;i<=n;i++)
        {
            ll now=0;
            dp[i][0]=mx;
            for(int j=1;j<=k;j++)
            {
                now+=sum[i][j];
                dp[i][j]=dp[i-1][j-1]-d+now;
                mx=max(mx,dp[i][j]);
                //cout<<dp[i][j]<<' ';
            }//cout<<endl;
        }
        ll ans=0;
        for(int j=0;j<=k;j++)
        {
            ans=max(ans,dp[n][j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}