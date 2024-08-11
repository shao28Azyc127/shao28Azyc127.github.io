#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d;
int dp[100010][2];
vector<pair<int,int>> e[100010];
vector<int> qzh[100010];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int testid,t; cin>>testid>>t; while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int i=1; i<=m; ++i)
        {
            int x,y,v; cin>>x>>y>>v;
            e[x-y+1].push_back({x,v});
        }
        for(int i=1; i<=n; ++i)
        {
            sort(e[i].begin(),e[i].end());
            int sum=0;
            qzh[i].clear();
            for(pair<int,int> j:e[i]) sum+=j.second,qzh[i].push_back(sum);
        }
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1; i<=n; ++i)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            int sum=0;
            for(int j=i; j>=max(1ll,i-k+1); --j)
            {
                int wz=lower_bound(e[j].begin(),e[j].end(),make_pair(i,(int)1e18))-e[j].begin();
                if(wz!=0) sum+=qzh[j][wz-1];
                dp[i][1]=max(dp[i][1],dp[j-1][0]-(i-j+1)*d+sum);
            }
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}
