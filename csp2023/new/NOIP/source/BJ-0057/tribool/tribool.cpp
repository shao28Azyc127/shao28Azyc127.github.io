#include <bits/stdc++.h>
using namespace std;

const int NR=1e5+100;
char opt[NR];
int flag[NR],to[NR],zhi[NR];
int fa[NR],num[NR],cnt[NR];

int find(int now)
{
    if(fa[now]!=now) return fa[now]=find(fa[now]);
    else return fa[now];
}

void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) zhi[i]=0,flag[i]=1,to[i]=i,fa[i]=i;
    for(int i=1;i<=n;i++) cnt[i]=num[i]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%s",opt);
        if(opt[0]=='+')
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(zhi[v]!=0) zhi[u]=zhi[v];
            else flag[u]=flag[v],to[u]=to[v],zhi[u]=0;
        }
        else if(opt[0]=='-')
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(zhi[v]!=0) zhi[u]=4-zhi[v];
            else flag[u]=1-flag[v],to[u]=to[v],zhi[u]=0;
        }
        else if(opt[0]=='T')
        {
            int u;
            scanf("%d",&u);
            zhi[u]=1;
        }
        else if(opt[0]=='F')
        {
            int u;
            scanf("%d",&u);
            zhi[u]=3;
        }
        else if(opt[0]=='U')
        {
            int u;
            scanf("%d",&u);
            zhi[u]=2;
        }
    }
    /*printf("===\n");
    for(int i=1;i<=n;i++) printf("%d %d %d\n",flag[i],to[i],zhi[i]);
    printf("===\n");*/
    for(int i=1;i<=n;i++)
    {
        if(zhi[i]!=0)
        {
            num[find(i)]=zhi[i];
        }
        else
        {
            int u=i,v=to[i];
            if(find(u)!=find(v)) fa[find(u)]=find(v);
            else{
                int now=v,tot=0;
                if(flag[i]==0) tot++;
                if(u!=v)
                {
                    while(true)
                    {
                        if(flag[now]==0) tot++;
                        now=to[now];
                        if(now==u) break;
                    }
                }
                //printf("edge %d %d %d\n",u,v,tot);
                if(tot%2==1) num[find(i)]=2;
            }
        }
    }
    for(int i=1;i<=n;i++) cnt[find(i)]++;
    int ans=0;
    for(int i=1;i<=n;i++) if(i==find(i)&&num[i]==2) ans+=cnt[i];
    printf("%d\n",ans);
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
