#include <bits/stdc++.h>
using namespace std;

const int NR=1e5+100;
int f[NR],son[NR],dep[NR],b[NR],c[NR],n;
long long a[NR];
int tp[NR],mn[NR],qwq[NR];
struct node
{
    int id,tim;
}t[NR];
vector <int> g[NR];

void dfs(int now,int fa)
{
    f[now]=fa,son[now]=1,dep[now]=dep[fa]+1;
    for(int i=0;i<g[now].size();i++)
    {
        int u=g[now][i];
        if(u==fa) continue;
        dfs(u,now);
        son[now]+=son[u];
    }
}

void pou(int now,int fa,int top)
{
    int hson=-1,mx=0;
    tp[now]=top,mn[top]=dep[now],qwq[top]=-1;
    for(int i=0;i<g[now].size();i++)
    {
        int u=g[now][i];
        if(u==fa) continue;
        if(son[u]>mx) mx=son[u],hson=u;
    }
    if(hson!=-1) pou(hson,now,top);
    for(int i=0;i<g[now].size();i++)
    {
        int u=g[now][i];
        if(u==fa) continue;
        if(u==hson) continue;
        pou(u,now,u);
    }
}

bool cmp(node x,node y)
{
    return x.tim<y.tim;
}

bool check(int tim)
{
    memset(qwq,-1,sizeof(qwq));
    memset(t,0,sizeof(t));
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        int chg=0;
        if(c[i]>=0) chg=2e9;
        if(c[i]<0){
            int num=(1-b[i])/c[i];
            while(b[i]+c[i]*(num+1)>1) num++;
            while(b[i]+c[i]*num<1) num--;
            chg=num;
        }
        //if(tim==61035) printf("chg %d %d\n",i,chg);
        int l=1,r=tim;
        t[i].tim=-1;
        t[i].id=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            long long A=mid,B=max(min(chg,tim),mid-1),C=tim;
            long long num=0;
            if((1e18/((B-A+1)*(A+B)/2))<abs(c[i])) num=1e18;
            else
            {
                num=1ll*(B-A+1)*b[i]+(B-A+1)*(A+B)/2*c[i];
                num+=C-B;
            }
            if(num>=a[i]) t[i].tim=mid,l=mid+1;
            else r=mid-1;
        }
        //printf("fjskflsjflsdfjls %lld\n",t[i].tim);
        if(t[i].tim==-1) flag=false;
    }
    sort(t+1,t+n+1,cmp);
    /*printf("==========%d\n",tim);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",t[i].id,t[i].tim);
    }*/
    int now_time=0;
    for(int i=1;i<=n;i++)
    {
        int now=t[i].id;
        while(now!=0)
        {
            int lian=tp[now];
            if(dep[now]<=qwq[lian]) break;
            if(qwq[lian]==-1) now_time+=dep[now]-dep[lian]+1,qwq[lian]=dep[now],now=f[lian];
            else {
                now_time+=dep[now]-qwq[lian],qwq[lian]=dep[now];break;
            }
        }
        if(now_time>t[i].tim) flag=false;
        //printf("=== %d %d\n",t[i].id,now_time);
    }
    return flag;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    pou(1,0,1);
    int l=1,r=1e9,ans=1e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)==true) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}

