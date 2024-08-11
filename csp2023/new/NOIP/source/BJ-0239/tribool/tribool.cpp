#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int to,w;
};
vector<node> v[N];
int id[N],xr[N],is[N],vis[N],w[N],flag,hv;
char s[10];
void dfs1(int x)
{
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)if(!vis[v[x][i].to])dfs1(v[x][i].to);
}
void dfs2(int x)
{
    hv++;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i].to])
        {
            w[v[x][i].to]=w[x]^v[x][i].w;
            dfs2(v[x][i].to);
        }
        else if((w[x]^v[x][i].w)!=w[v[x][i].to])flag=1;
    }
}
void dfs3(int x)
{
    hv++;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)if(!vis[v[x][i].to])dfs3(v[x][i].to);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,m;
    int x,y,ans;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)id[i]=i,xr[i]=0,is[i]=-1,vis[i]=0,w[i]=-1,v[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s);
            if(s[0]=='+')
            {
                scanf("%d%d",&x,&y);
                if(id[y]!=-1)
                {
                    xr[x]=xr[y];
                    id[x]=id[y];
                    is[x]=-1;
                }
                else is[x]=is[y],id[x]=-1;
            }
            else if(s[0]=='-')
            {
                scanf("%d%d",&x,&y);
                if(id[y]!=-1)
                {
                    xr[x]=!xr[y];
                    id[x]=id[y];
                    is[x]=-1;
                }
                else
                {
                    if(is[y]==2)is[x]=2;
                    else is[x]=!is[y];
                    id[x]=-1;
                }
            }
            else
            {
                scanf("%d",&x);
                id[x]=-1;
                if(s[0]=='F')is[x]=0;
                else if(s[0]=='T')is[x]=1;
                else is[x]=2;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(id[i]!=-1)
            {
                v[i].push_back((node){id[i],xr[i]});
                v[id[i]].push_back((node){i,xr[i]});
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)if(is[i]!=-1&&is[i]!=2&&!vis[i])dfs1(i);
        for(int i=1;i<=n;i++)
        {
            if(is[i]==2&&!vis[i])
            {
                hv=0;
                dfs3(i);
                ans+=hv;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                w[i]=0;
                flag=0;
                hv=0;
                dfs2(i);
                if(flag)ans+=hv;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
