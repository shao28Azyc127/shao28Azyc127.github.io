#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define int long long
using namespace std;
int n,head[MAXN],p=0,incnt[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int dpA[MAXN];

struct node{
    int e,next;
}eg[MAXN*2];

void addedge(int s,int e)
{
    eg[p].e=e;
    eg[p].next=head[s];
    head[s]=p++;
    incnt[s]++;
    incnt[e]++;
}

void dfsA(int u,int fa)
{
    if (a[u]%b[u]==0)
        dpA[u]=a[u]/b[u];
    else
        dpA[u]=1+(a[u]/b[u]);
    for (int i=head[u];i!=-1;i=eg[i].next)
    {
        int v=eg[i].e;
        if (v==fa) continue;
        dfsA(v,u);
        dpA[u]=max(dpA[u],dpA[v]+1);
    }
}

signed main()
{
    int x,y;
    int flagA=1,flagB=1,flagC=1,flagD=1;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(head,-1,sizeof(head));
    memset(incnt,0,sizeof(incnt));
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if (c[i]!=0) flagA=0;
    }
    for (int i=1;i<n;i++)
    {
        cin>>x>>y;
        if (y!=x+1) flagB=0;
        if (x!=1) flagD=0;
        addedge(x,y);
    }
    for (int i=1;i<=n;i++)
    {
        if (incnt[i]!=2)
        {
            flagD=0;
            break;
        }
    }

    if (flagA)
    {
        dfsA(1,-1);
        cout<<dpA[1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}