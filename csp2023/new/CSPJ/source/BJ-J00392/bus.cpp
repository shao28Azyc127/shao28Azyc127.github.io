#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[20010][20010]={0};
int ans=-1;
void dfs(int s,int t)
{
    if(t>ans&&ans!=-1)
        return ;
    if(s==n)
    {
        if((t%k)==0)
        {
            if(ans==-1||t<ans)
                ans=t;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[s][i]!=0&&a[s][i]>=t)
            dfs(i,t+1);
    }
    return ;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int x,y,q;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>q;
        a[x][y]=q;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}