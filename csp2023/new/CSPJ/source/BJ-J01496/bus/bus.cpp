#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct Edge
{
    int v,a,nex;
}e[N<<1];
int head[N],ecnt;
inline void addedge(int u,int v,int a)
{
    e[++ecnt]={v,a,head[u]};
    head[u]=ecnt;
}
int n,m,k;
int lim=1e9;
bool flag;
void dfs(int x,int step,int st)
{
    if(step+st>lim)return;
    //printf("%d %d %d\n",x,step,st);
    if(x==n&&step%k==0)
    {
        st+=3-st%3;
        lim=min(lim,step+st);
    }
    for(int it=head[x];it;it=e[it].nex)
    {
        int y=e[it].v,t=e[it].a;
        if(step+st<t)
        {
            st=t-step;
            st+=3-st%3;
        }
        dfs(y,step+1,st);

    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        scanf("%d %d %d",&u,&v,&a);
        addedge(u,v,a);
    }
    dfs(1,0,0);
    printf("%d",lim);
    return 0;
}
