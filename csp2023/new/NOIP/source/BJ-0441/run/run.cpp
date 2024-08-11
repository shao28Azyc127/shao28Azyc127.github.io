#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
struct node
{
    int jc,jl;
    node()
    {

    }
    node(int _jc,int _jl)
    {
        jc=_jc;
        jl=_jl;
    }
};
vector<node> cha[1005];
int ca,T,n,m,k,d,maxx[1005];
void init()
{
    memset(maxx,0,sizeof(maxx));
    memset(dp,0,sizeof(dp));
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>ca>>T;
    while(T--)
    {
        init();
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            cha[x].push_back(node(y,v));
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=min(k,i);j++)
            {
                if(j==0)
                {
                    dp[i][j]=maxx[i-1];
                    maxx[i]=max(maxx[i],dp[i][j]);
                    continue;
                }
                dp[i][j]=dp[i-1][j-1]-d;
                for(int k=0;k<cha[i].size();k++)
                    if((cha[i][k].jc)<=j)
                        dp[i][j]+=cha[i][k].jl;
                maxx[i]=max(maxx[i],dp[i][j]);
            }
        }
        int ans=-0x3f3f3f3f;
        for(int i=0;i<=min(k,n);i++)
            ans=max(ans,dp[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
