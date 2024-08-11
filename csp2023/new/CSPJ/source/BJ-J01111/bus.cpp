#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,z,f;
int v[10010][10010];
int dp[10010][110];
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j]=0x3f3f3f3f;
        }
    }
    dp[1][0]=0;
    for(int i=1;i<k;i++)
    {
        dp[1][i]=0x3f3f3f3f;
    }
    for(int i=0;i<k;i++)
    {
        dp[0][i]=0x3f3f3f3f;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            v[i][j]=0x3f3f3f3f;
        }
    }
}
void dfs(int i,int l,int a)
{
    //cout<<endl<<i<<" "<<l<<" "<<a<<endl;
    for(int j=0;j<k;j++)
    {
        f=dp[l][((!j)?(k-1):(j-1))]+1;
        if(f<a)
        {
            f+=((a-f)/k+((a%f)?1:0))*k;
        }
        dp[i][j]=min(dp[i][j],f);
        //cout<<dp[i][j]<<" ";
    }
    //cout<<endl;
    if(v[i][i]!=0x3f3f3f3f)
    {
        for(int j=0;j<k;j++)
        {
            f=dp[j][((!j)?(k-1):(j-1))]+1;
            if(f<v[i][j])
            {
                f+=((v[i][j]-f)/k+((v[i][j]%f)?1:0))*k;
            }
            dp[i][j]=min(dp[i][j],f);
        }
    }
    if(i==n)
    {
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(v[i][j]!=0x3f3f3f3f)
        {
            if(i==j)
            {
                continue;
            }
            dfs(j,i,v[i][j]);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        v[x][y]=min(v[x][y],z);
    }
    dfs(1,0,0);
    if(dp[n][0]==0x3f3f3f3f)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
