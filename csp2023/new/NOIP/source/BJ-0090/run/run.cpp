#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
long long dp[1005][1005];
struct opt
{
    int lv;
    long long val;
};
vector<opt>g[100005];
bool cmp(opt a,opt b)
{
    return a.lv<b.lv;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    int c, _;
    cin.tie(0);
    cout.tie(0);
    cin>>c>>_;
    while(_--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        k=min(k,n);
        if(n<=1000)
        {
            for(int i=1;i<=m;i++)
            {
                int x,y,v;
                cin>>x>>y>>v;
                g[x].push_back({y,v});
            }
            for(int i=1;i<=n;i++)
            {
                sort(g[i].begin(),g[i].end(),cmp);
            }
            memset(dp,-0x3f,sizeof(dp));
            dp[0][0]=0;
            for(int i=1;i<=n;i++)
            {
                int tt=0;
                long long val=0;
                for(int j=0;j<=k;j++)
                {
                    dp[i][0]=max(dp[i][0],dp[i-1][j]);
                }
                for(int j=1;j<=k;j++)
                {
                    
                    while(tt<(int)(g[i].size())&&g[i][tt].lv<=j)
                    {
                        val+=g[i][tt].val;
                        tt++;
                    }
                    //cout<<i<<' '<<j<<' '<<val<<"???\n";
                    dp[i][j]=dp[i-1][j-1]-d+val;
                }
            }
            long long ans=0;
            for(int i=0;i<=k;i++)
            {
                //cout<<dp[n][i]<<"??\n";
                ans=max(ans,dp[n][i]);
            }
            cout<<ans<<'\n';
            
        }
    }
}
