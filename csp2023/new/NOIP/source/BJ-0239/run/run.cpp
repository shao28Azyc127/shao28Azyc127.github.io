#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int to;
    long long w;
};
vector<node> v[N];
int x[N],y[N];
long long w[N],dp[N],mx[N];
bool cmp(node a,node b)
{
    return a.to>b.to;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,m,k;
    long long d,hv;
    while(t--)
    {
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%lld",&x[i],&y[i],&w[i]);
            for(int j=1;j<=k-y[i];j++)v[x[i]+j].push_back((node){x[i]-y[i]+1,w[i]});
            if(y[i]<=k)v[x[i]].push_back((node){x[i]-y[i]+1,w[i]});
        }
        for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end(),cmp);
        dp[0]=0;
        mx[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=-d;
            hv=0;
            for(int j=0;j<v[i].size();j++)
            {
                hv+=v[i][j].w;
                dp[i]=max(dp[i],mx[max(0,v[i][j].to-2)]+hv-1ll*(i-v[i][j].to+1)*d);
            }
            mx[i]=max(mx[i-1],dp[i]);
        }
        printf("%lld\n",mx[n]);
    }
    return 0;
}
