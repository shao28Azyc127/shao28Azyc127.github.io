#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
const int MAXN=1e5+10;
struct Edge
{
    int ver,nxt,w;
}e[MAXN*2],e2[MAXN*2];
int head[MAXN],h2[MAXN],tot=0,t2=0;
void add(int u,int v,int w)
{
    e[++tot].ver=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot;
}
void add2(int u,int v,int w)
{
    e2[++t2].ver=v;
    e2[tot].w=w;
    e2[tot].nxt=head[u];
    h2[u]=t2;
}
int cu[MAXN],c[MAXN],val[MAXN],opp[MAXN];
bool vis[MAXN];
int f[MAXN];
int find(int x)
{
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    x=find(x);y=find(y);
    int i;
    f[x]=y;
    return;
}
int tmp[MAXN];
void Fix(int u,int cl)
{
    if(vis[u]) return;
    vis[u]=true;
    int i;
    for(i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].ver,w=e[i].w;
        if(w)
        {
            tmp[v]=!tmp[u];
            Fix(v,!cl);
        }
        else
        {
            tmp[v]=tmp[u];
            Fix(v,cl);
        }
    }
    return;
}
void Val(int u,int cl)
{
    int i;
    if(vis[u]) return;
    vis[u]=true;
    for(i=h2[u];i;i=e2[i].nxt)
    {
        int v=e2[i].ver,w=e2[i].w;
        if(w)
        {
            c[v]=!c[u];
            Val(v,!cl);
        }
        else
        {
            c[v]=c[u];
            Val(v,cl);
        }
    }
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T,n,m,i,j;
    scanf("%d %d",&C,&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            f[i]=i;
            head[i]=h2[i]=0;
            cu[i]=0;
            c[i]=-1;
            val[i]=-1;
            opp[i]=-1;
        }
        tot=0;t2=0;
        for(i=1;i<=m;i++)
        {
            char op;
            int u,v;
            cin>>op;
            if(op=='+')
            {
                scanf("%d %d",&u,&v);
                add(v,u,0);
                add2(u,v,0);
                merge(u,v);
                if(c[v]==2)
                {
                    c[u]=2;
                    continue;
                }
                if(~c[u] && ~c[v])
                {
                    if(c[u]!=c[v])
                    {
                        for(j=1;j<=n;j++) vis[j]=false;
                        for(j=1;j<=n;j++) tmp[j]=c[j];
                        tmp[u]=tmp[v];
                        int old=tmp[u];
                        Fix(u,tmp[v]);
                        if(old!=tmp[u]) cu[u]=cu[v]=1;
                    }
                }
                else if(~c[u] && !(~c[v])) c[v]=c[u];
                else if(~c[v] && !(~c[u])) c[u]=c[v];
                else c[u]=c[v]=0;
            }
            else if(op=='-')
            {
                scanf("%d %d",&u,&v);
                add(v,u,1);
                add2(u,v,1);
                merge(u,v);
                if(c[v]==2)
                {
                    c[u]=2;
                    continue;
                }
                if(~c[u] && ~c[v])
                {
                    if(c[u]==c[v])
                    {
                        for(j=1;j<=n;j++) vis[j]=false;
                        for(j=1;j<=n;j++) tmp[j]=c[j];

                        tmp[u]=!tmp[v];
                        int old=tmp[u];
                        Fix(u,!tmp[v]);
                        if(old!=tmp[u]) cu[u]=cu[v]=1;
                    }
                }
                else if(~c[u] && !(~c[v])) c[v]=!c[u];
                else if(~c[v] && !(~c[u])) c[u]=!c[v];
                else
                {
                    c[u]=1;
                    c[v]=0;
                }
                if(u==v) cu[u]=1;
            }
            else
            {
                scanf("%d",&u);
                for(j=1;j<=n;j++) vis[j]=false;
                if(op=='T')
                {
                    c[u]=1;Val(u,1);
                }
                else if(op=='F')
                {
                    c[u]=0;
                    Val(u,0);
                }
                else
                {
                    for(j=1;j<=n;j++) if(find(j)==find(u)) c[j]=2;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(cu[i]) cu[find(i)]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(cu[find(i)]) cu[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(c[i]==2) cu[i]=1;
        }/*
        for(i=1;i<=n;i++)
        {
            if(~val[i])
            {
                if(~c[i])
                {
                    if(!(~opp[find(i)]))
                    {
                        if(val[i]==c[i]) opp[find(i)]=0;
                        else opp[find(i)]=1;
                    }
                    if(val[i]!=c[i] && opp[find(i)]==0) cu[i]=1;
                    if(val[i]==c[i] && opp[find(i)]==1) cu[i]=1;
                }
                else
                {
                    c[i]=val[i];
                    opp[find(i)]=0;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(cu[i]) cu[find(i)]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(cu[find(i)]) cu[i]=1;
        }*/
        int res=0;
        for(i=1;i<=n;i++)
        {
            res+=cu[i];
            //if(cu[i]) printf("%d ",i);
        }
        printf("\n%d\n",res);
    }
    return 0;
}
