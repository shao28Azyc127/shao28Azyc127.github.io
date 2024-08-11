#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=2e4+5;
vector<int> tre[maxn];
struct node
{
    int v,w;
};
vector<node> G[maxn];
int fa[maxn];
int n,m,k,a[maxn],cnt,ans=0x3f3f3f3f;

bool dfs2(int u,int time)
{
    if(u==n)
    {
        if(time%k==0)
        {
            ans=min(ans,time);
            return 1;
        }
        return 0;
    }
    bool ok=0;
    _for(i,0,G[u].size()-1)
    {
        int v=G[u][i].v;
        fa[v]=u;
//        if(time<G[u][i].w) continue;
        bool tmp=dfs2(v,time+1);
        if(tmp) ok=1;
        fa[v]=0;
    }
    return ok;
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    bool ok=1;
    _for(i,1,m)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w!=0) ok=0;
        G[u].push_back((node){v,w});
    }
    if(ok)
    {
        bool OK=dfs2(1,0);
        if(!OK)
        {
            cout<<-1<<endl;
            return 0;
        }
        else if(ans==0x3f3f3f3f) cout<<-1<<endl;
        else cout<<ans<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
