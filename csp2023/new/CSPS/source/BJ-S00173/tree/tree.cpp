// Tang hai yin Forever!!!
#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=300000+5;
int n;
vector<int> A[n_MAX];
long long a[n_MAX]; int k[n_MAX],b[n_MAX],lim[n_MAX],bd[n_MAX];
int t[n_MAX],d[n_MAX],Fa[n_MAX],pre[n_MAX];
void DFS(const int u)
{
    for(const int v:A[u])
    {
        if(v==pre[u]) continue;
        pre[v]=u,DFS(v);
    }
}
int find(const int u)
{
    if(Fa[u]==u) return u;
    Fa[u]=find(Fa[u]);
    return Fa[u];
}
__int128 mul(const __int128 x,const int y)
{
    return (x*y);
}
__int128 sum(int n,const int k,const int b,const int lim)
{
    if(!n) return 0;
    else if(k>=0) return (mul(n,b)+mul(mul(n,n+1)>>1,k));
    else
    {
        int add=0;
        if(n>=lim) add=(n-lim+1),n=(lim-1);
        return ((mul(n,b)+mul(mul(n,n+1)>>1,k))+add);
    }
}
set<pair<int,int>> pq;
bool check(const int r)
{
    pq.clear();
    For(i,1,n)
    {
        const __int128 S=sum(r,k[i],b[i],lim[i]);
        if(S<a[i]) return false;
        int L=1,R=min(r,n+500);
        while(L<R)
        {
            const int mid=((L+R+1)>>1);
            if((S-sum(mid-1,k[i],b[i],lim[i]))>=a[i]) L=mid;
            else R=(mid-1);
        }
        t[i]=L,d[i]=1,Fa[i]=i,pq.insert({t[i],i});
    }
    while(!pq.empty())
    {
        const int u=(pq.begin()->second);
        pq.erase(pq.begin());
        if(u==1)
        {
            if(t[u]<d[u]) return false;
        }
        else
        {
            const int f=find(pre[u]);
            pq.erase({t[f],f});
            t[f]=min(t[f]+d[u],t[u]);
            d[f]+=d[u];
            Fa[u]=f;
            pq.insert({t[f],f});
        }
    }
    return true;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    For(i,1,n)
    {
        cin>>a[i]>>b[i]>>k[i];
        if(k[i]<0) lim[i]=(((b[i]-1)/(-k[i]))+1);
    }
    For(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    DFS(1);
    int l=1,r=1010000000;
    while(l<r)
    {
        const int mid=((l+r)>>1);
        if(check(mid)) r=mid;
        else l=(mid+1);
    }
    cout<<l<<'\n'; return 0;
}