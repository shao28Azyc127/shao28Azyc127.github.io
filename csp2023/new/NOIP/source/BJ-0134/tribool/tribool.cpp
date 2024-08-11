#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline char readc()
{
    char ch=getchar();
    while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-'){ch=getchar();}
    return ch;
}
ll C;
ll n,m;
ll a[100005];
ll r[100005];
vector<vector<pll> >graph(100005);
void add_edge(ll u,ll v,ll w)
{
    graph[u].push_back({v,w});
}
void dfs(ll u,ll col)
{
    if(col==3)
    {
        if(r[u]!=3)r[u]=3;
        else return;
        ll sz=graph[u].size();
        for(int i=0;i<sz;i++)
        {
            ll v=graph[u][i].first;
            if(r[v]==3)continue;
            dfs(v,3);
        }
        return;
    }
    if(r[u])
    {
        if(r[u]!=col)dfs(u,3);
        return;
    }
    r[u]=col;
    ll sz=graph[u].size();
    for(int i=0;i<sz;i++)
    {
        if(r[u]==3)return;
        ll v=graph[u][i].first,w=graph[u][i].second;
        if(w==0)dfs(v,col);
        else dfs(v,3-col);
    }
}
void solve()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=m;i++)
    {
        char op=readc();
        if(op=='T')
        {
            ll x=read();
            a[x]=n+1;
        }
        if(op=='F')
        {
            ll x=read();
            a[x]=(-n-1);
        }
        if(op=='U')
        {
            ll x=read();
            a[x]=0;
        }
        if(op=='+')
        {
            ll x=read(),y=read();
            a[x]=a[y];
        }
        if(op=='-')
        {
            ll x=read(),y=read();
            a[x]=0-a[y];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>(-n-1)&&a[i]<(n+1)&&a[i]!=0)
        {
            ll p=a[i],q=0;
            if(p<0)q=1,p*=(-1);
            if(p==i)
            {
                if(q==1)a[i]=0;
                continue;
            }
            add_edge(i,p,q);
            add_edge(p,i,q);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==n+1)dfs(i,1);
        if(a[i]==(-n-1))dfs(i,2);
        if(a[i]==0)dfs(i,3);
    }
    for(int i=1;i<=n;i++)
    {
        if(!r[i])
        {
            dfs(i,1);
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]==3)res++;
    }
    cout<<res<<'\n';
    for(int i=1;i<=n+1;i++)a[i]=r[i]=0;
    for(int i=0;i<=n;i++)graph[i].clear();
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
//    clock_t start=clock();
    C=read();
    ll t=read();
    while(t--)solve();
//    clock_t end=clock();
//    cout<<'\n'<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}