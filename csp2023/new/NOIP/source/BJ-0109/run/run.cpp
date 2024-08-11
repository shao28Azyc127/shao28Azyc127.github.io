#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int N=1e3+5;
int c,t;
int n,m,k,d;
int dp[N][N];
vector< pair<int,int> > vec[N];
bool cmp(pair<int,int> x, pair<int,int> y)
{
    return x.first<y.first;
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int i,j;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(i=1; i<=n; i++)
            vec[i].clear();
        for(i=1; i<=m; i++)
        {
            int x,y,v;
            scanf("%lld%lld%lld",&x,&y,&v);
            vec[x].push_back(make_pair(y,v));
        }
        for(i=1; i<=n; i++)
            sort(vec[i].begin(),vec[i].end(),cmp);
        for(i=0; i<=n; i++)
            for(j=0; j<=k; j++)
                dp[i][j]=-1e15;
        dp[0][0]=0;
        int ans=0;
        for(i=1; i<=n; i++)
        {
            int maxn=0;
            for(j=0; j<=k; j++)
                maxn=max(maxn,dp[i-1][j]);
            dp[i][0]=max(dp[i][0],maxn);
            ans=max(ans,dp[i][0]);
            int temp=0,sum=0;
            for(j=1; j<=k; j++)
            {
                while(temp<vec[i].size() && vec[i][temp].first<=j)
                    sum+=vec[i][temp].second,temp++;
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+sum);
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
