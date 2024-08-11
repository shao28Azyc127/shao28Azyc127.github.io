#include<bits/stdc++.h>
using namespace std;

// Let LRH bless me, I love LRH forever !!!
#define int long long
const int Maxn=1e5+10;
struct Place{
    int a,b,c;
}P[Maxn];
int Aim[Maxn];
struct Edge{
    int to;
    int nxt;
}E[Maxn<<1];
int head[Maxn],tot;
void addedge(int u,int v)
{
    tot++;
    E[tot].to=v;
    E[tot].nxt=head[u];
    head[u]=tot;
}
int n;
int now[Maxn];
vector<int> canput;
int ans=1000000010;
void chk()
{
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        // now[i]= begin time
    /*
        int Q=0;
        int res=now[i];
        while(1)
        {
            Q+=max(P[i].b+res*P[i].c,1);
            if(Q>=P[i].a) break;
            res++;
        }
        maxx=max(maxx,res);
        */
        if(P[i].c==0)
        {
            int need=P[i].a/P[i].b+(P[i].a%P[i].b!=0);
            int res=now[i]+need-1;
            maxx=max(maxx,res);
        }else if(P[i].c>0){
            int A=P[i].b+now[i]*P[i].c;
            int l=now[i],r=100000000,res=-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                int news=P[i].b+mid*P[i].c;
                if(((news+A)*((news-A)/P[i].c+1)/2)>=P[i].a)
                {
                    res=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }

            int news=P[i].b+4*P[i].c;
            int ans=(news+A)*((news-A)/P[i].c+1)/2;
            maxx=max(maxx,res);
        }else{
            int MaxC=(1-P[i].b)/P[i].c;
            if(P[i].b+MaxC*P[i].c<=1) MaxC--;
            if(now[i]>MaxC)
            {
                int res=now[i]+P[i].c-1;
                maxx=max(maxx,res);
                continue;
            }
            int A=P[i].b+now[i]*P[i].c;
            int B=P[i].b+MaxC*P[i].c;
            int C=(A+B)*((B-A)/P[i].c + 1)/2;
            if(C>P[i].a)
            {
                int l=now[i],r=MaxC,res=-1;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    int news=P[i].b+mid*P[i].c;
                    if((news+A)*((news-A)/P[i].c+1)/2>=P[i].a)
                    {
                        r=mid-1;
                        res=mid;
                    }else{
                        l=mid+1;
                    }
                }
                maxx=max(maxx,res);
            }else{
                int res=MaxC+(P[i].a-C);
                maxx=max(maxx,res);
            }
        }
    }
    ans=min(ans,maxx);
}
void dfs(int u,int time)
{
    now[u]=time;
    if(time==n-1)
    {
        chk();
        return ;
    }
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].to;
        if(now[v]==-1) canput.push_back(v);
    }
    for(int i=0;i<canput.size();i++)
    {
        if(now[canput[i]]!=-1) continue;
        dfs(canput[i],time+1);
    }
}
int dep[Maxn];
void DFS(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].to;
        if(v==fa) continue;
        DFS(v,u);
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(now,-1,sizeof(now));
    scanf("%lld",&n);
    int tag=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&P[i].a,&P[i].b,&P[i].c);
    }

    bool flag=1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        addedge(u,v);
        addedge(v,u);
        if(abs(u-v)!=1) flag=0;
    }
    if(n<=20)
    {
        dfs(1,1);
        printf("%lld\n",ans);
        return 0;
    }
    if(flag==1)
    {
        for(int i=1;i<=n;i++)
        {
            now[i]=i;
        }
        chk();
        printf("%lld\n",ans);
        return 0;
    }
    return 0;
}
