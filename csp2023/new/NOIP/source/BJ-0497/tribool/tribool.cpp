#include <bits/stdc++.h>
using namespace std;
int n,m,c,t,mark[100010],ans;
int vis[100010];
bool flag[100010];
bool dfs(int now)
{
    vis[now]=1;
   // cout<<now<<endl;
    if((mark[now]<=0&&mark[now]!=-3)||vis[mark[now]]==1)
    {
        mark[now]=0;
        return 0;
    }
    if(mark[now]==-3||vis[mark[now]]==-1)
    {
        flag[now]=1;
        mark[now]=-3;
        vis[now]=-1;
        return 1;
    }
    if(dfs(mark[now]))
    {
        flag[now]=1;
        vis[now]=-1;
        mark[now]=-3;
        return 1;
    }
    mark[now]=mark[mark[now]];
    return 0;
    
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        memset(flag,0,sizeof(flag));
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            char x;
            int y,z;
            cin>>x;
            if(x=='T')
            {
                cin>>y;
                mark[y]=-1;
            }
            if(x=='F')
            {
                cin>>y;
                mark[y]=-2;
            }
            if(x=='U')
            {
                cin>>y;
                mark[y]=-3;
            }
            if(x=='+')
            {
                cin>>y>>z;
                if(mark[z])
                    mark[y]=mark[z];
                else
                    mark[y]=z;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&mark[i]>0)
                dfs(i);
            else if(!vis[i]&&mark[i]==-3)
                flag[i]=1;
        }
        for(int i=1;i<=n;i++)
            if(flag[i])
                ans++;
        cout<<ans<<endl;
    }
}