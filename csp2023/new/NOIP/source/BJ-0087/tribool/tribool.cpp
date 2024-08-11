#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int now[100005];
int fuhao[100005];
int vis[100005],ans;
int dis[100005];
void dfs(int x)
{
    if(vis[x])
    {
        return;
    }
    vis[x]=3;
    if(now[x]==0)
    {
        if(fuhao[x]==0)
        {
            vis[x]=2;
            ans++;
        }
        else
        {
            vis[x]=1;
        }
        return;
    }
    if(vis[now[x]]==3)
    {
        if(dis[x]*dis[now[x]]*fuhao[x]==1)
        {
            vis[x]=1;
        }
        else
        {
            vis[x]=2;
            ans++;
        }
        return;
    }
    dis[now[x]]=dis[x]*fuhao[x];
    dfs(now[x]);
    if(vis[now[x]]==2)
    {
        vis[x]=2;
        ans++;
    }
    if(vis[now[x]]==1)
    {
        vis[x]=1;
    }
    return;
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int waste;
    cin>>waste>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            now[i]=i;
            fuhao[i]=1;
        }
        char op;
        int x,y;
        for(int i=1;i<=m;i++)
        {
            cin>>op;
            if(op=='+')
            {
                cin>>x>>y;
                now[x]=now[y];
                fuhao[x]=fuhao[y];
            }
            else if(op=='-')
            {
                cin>>x>>y;
                now[x]=now[y];
                fuhao[x]=-fuhao[y];
            }
            else
            {
                cin>>x;
                now[x]=0;
                if(op=='T')
                {
                    fuhao[x]=1;
                }
                else if(op=='F')
                {
                    fuhao[x]=-1;
                }
                else
                {
                    fuhao[x]=0;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        /*for(int i=1;i<=n;i++)
        {
            cout<<"::"<<i<<" "<<fuhao[i]<<" "<<now[i]<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dis[i]=1;
                dfs(i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
