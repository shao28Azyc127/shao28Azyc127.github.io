#include<bits/stdc++.h>
using namespace std;
const int N1=1010,N2=100010;
int cas,T,n,m; char op;
//1,2
int x[20],y[20]; char opt[20];
int ans,cnt,fl[20],now[20]; bool sec;
bool qwq=0;
void cal1()
{
    for(int i=1;i<=n;i++) now[i]=fl[i];
    for(int i=1;i<=m;i++)
    {
        if(qwq==1) cout<<opt[i]<<" "<<x[i]<<" "<<y[i]<<endl;
        if(opt[i]=='+') now[y[i]]=now[x[i]];
        else if(opt[i]=='-') now[y[i]]=(now[x[i]]==2)?now[x[i]]:!now[x[i]];
        else if(opt[i]=='T') now[y[i]]=1;
        else if(opt[i]=='F') now[y[i]]=0;
        else if(opt[i]=='U') now[y[i]]=2;
        if(qwq==1) for(int i=1;i<=n;i++) cout<<now[i]<<" ";
        if(qwq==1) cout<<endl;
    }
    qwq=0;
    sec=1; cnt=0;
    for(int i=1;i<=n;i++)
        if(now[i]!=fl[i]) sec=0;
    for(int i=1;i<=n;i++)
        if(fl[i]==2) cnt++;
    if(sec) ans=min(ans,cnt);
    //cout<<ans<<endl;
    //for(int i=1;i<=n;i++) cout<<fl[i]<<" ";
    //cout<<endl;
    return;
}
void dfs(int u)
{
    if(u==n+1) {cal1(); return;}
    fl[u]=1; dfs(u+1);
    fl[u]=0; dfs(u+1);
    fl[u]=2; dfs(u+1);
    return;
}
//

//5,6
int tx,ty; int fa[N2];
bool vis[N2];
int tot,head[N2],ver[N2],nxt[N2];
int f(int x)
{
    if(fa[x]!=x) fa[x]=f(fa[x]);
    return fa[x];
}
/*
void cal2(int x)
{
    //cout<<head[x]<<"^"<<endl;
    for(int j=head[x];j;j=nxt[j])
    {
        //cout<<ver[j]<<"*"<<endl;
        vis[ver[j]]=1;
        cal2(ver[j]);
    }
    return;
}
void add(int x,int y)
{
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
*/
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&cas,&T); int trt=T;
    if(cas==1 || cas==2)
    {
        while(T--)
        {
            scanf("%d%d",&n,&m); ans=n+1;
            for(int i=1;i<=m;i++)
            {
                cin>>opt[i]; scanf("%d",&y[i]);
                if(opt[i]!='T' && opt[i]!='F' && opt[i]!='U') scanf("%d",&x[i]);
            }
            dfs(1);
            printf("%d\n",ans);
        }
        return 0;
    }
    else if(cas==5 || cas==6)
    {
        if(cas==2) T=trt;
        while(T--)
        {
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++) vis[i]=0,fa[i]=i;
            for(int i=1;i<=m;i++)
            {
                cin>>op; scanf("%d",&ty);
                if(op=='U') vis[ty]=1,fa[ty]=ty;
                else
                {
                    scanf("%d",&tx);
                    if(vis[tx]) vis[ty]=1;
                    else vis[ty]=0;
                    tx=f(tx); ty=f(ty);
                    if(tx!=ty) fa[ty]=tx;
                }
            }
            cnt=0;
            /*
            for(int i=1;i<=n;i++)
                if(fa[i]!=i) add(fa[i],i);
            //cout<<head[959]<<"()"<<nxt[head[959]]<<"***"<<ver[head[959]]<<endl;
            for(int i=1;i<=n;i++)
                if(fa[i]==i && vis[i]) cal2(i);*/
            for(int i=1;i<=n;i++)
                if(vis[i]) cnt++;
            for(int i=1;i<=n;i++)
            {
                int lst=f(i);
                if(vis[lst] && !vis[i]) cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
