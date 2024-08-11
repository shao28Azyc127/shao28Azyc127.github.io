#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1145141919810;
const ll mod=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
char c[2000005];
int lst[2000005];
int lstp[26];
int to[4000005],nxt[4000005],fir[2000005];
void add_edge(ll u,ll v,ll pos)
{
    to[pos]=v;
    nxt[pos]=fir[u];
    fir[u]=pos;
}
ll fat[2000005];
int ok[2000005],lstc[2000005][26];
bool vis[2000005];
void dfs(ll u,ll fa)
{
    fat[u]=fa;
    for(int i=fir[u];i;i=nxt[i])
    {
        ll v=to[i];
        if(v==fa)continue;
        dfs(v,u);
    }
}
ll lstok[2000005];
ll f[2000005];
void solve()
{
    n=read();
    scanf("%s",c);
    for(int i=1;i<=n;i++)
    {
        ll p=c[i-1]-'a';
        lst[i]=lstp[p];
        lstp[p]=i;
        ll too=max(lst[i]-1,0);
        add_edge(i,too,i+i-1);
        add_edge(too,i,i+i);
    }
    dfs(0,0);
    for(int u=1;u<=n;u++)
    {
        for(int i=0;i<=25;i++)lstc[u][i]=lstc[ok[u]-1][i];
        lstc[u][c[u-1]-'a']=u;
        if(lstc[u][c[u]-'a'])ok[u+1]=lstc[u][c[u]-'a'];
        else fat[u+1]=0;
    } 
    for(int i=1;i<=n;i++)
    {
        if(ok[i])f[i]=f[ok[i]-1]+1;
    }
    ll res=0;
    for(int i=1;i<=n;i++)res+=f[i];
    cout<<res<<'\n';
    return;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
//    clock_t start=read();
    ll t=1;
    while(t--)solve();
//    clock_t end=read();
//    cout<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}