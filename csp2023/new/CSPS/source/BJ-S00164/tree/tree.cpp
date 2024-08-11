#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=1e5+10;
int fst[N],nxt[2*N],v[2*N],cnt;
int a[N],b[N],c[N],qwq[N],ans;
bool vis[N];
priority_queue<pii > q;
inline int read()
{
    int ss=0,ww=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') ww=-1; ch=getchar();}
    while(ch>='0' && ch<='9') ss=(ss<<1)+(ss<<3)+(ch^48),ch=getchar();
    return ss*ww;
}
void add(int x,int y)
{
    v[++cnt]=y;
    nxt[cnt]=fst[x],fst[x]=cnt;
}
void bfs()
{
    q.push(mp(qwq[1],1)); int d=0;
    while(!q.empty())
    {
        int x=q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x]=1,ans=max(ans,d+qwq[x]);
        for(int i=fst[x];i;i=nxt[i]) q.push(mp(qwq[v[i]],v[i]));
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n=read(),x,y;
    // return 0;
    for(int i=1;i<=n;i++) 
    {
        a[i]=read(),b[i]=read(),c[i]=read();
        qwq[i]=(a[i]+b[i]-1)/b[i];
    }
    for(int i=1;i<n;i++)
    {
        x=read(),y=read();
        add(x,y),add(y,x);
    }
    bfs(); printf("%lld",ans);
    return 0;
}