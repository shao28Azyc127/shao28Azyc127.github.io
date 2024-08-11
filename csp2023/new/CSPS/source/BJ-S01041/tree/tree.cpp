#include <bits/stdc++.h>
using namespace std;
ifstream fin("tree.in");
ofstream fout("tree.out");

struct IO{
    char buf[10*1024*1024],*p{buf};
    IO(){ fin.read(buf,sizeof(buf)); }
    IO& operator>>(auto& x){
        x=0;
        for(;!(*p>='0'&&*p<='9');++p);
        for(; (*p>='0'&&*p<='9');++p) (x*=10)+=*p^'0';
        return *this;
    }
}IO;
#define fin IO
using ll=long long;
using lll=__int128;
enum{ N=100005 };
int n;
vector<int> G[N];
int fa[N];
ll a[N],b[N],c[N];
int lim[N]; // 地块i最晚在第lim[i]天种上树
inline lll calc(int i,int l,int r){ // 地块i的树生长[l,r]这些天，长成的高度
    auto f=[i](int l,int r){ return (r-l+1)*b[i]+lll(c[i])*(l+r)*(r-l+1)/2; };
    if(c[i]>=0) return f(l,r);
    const int p=(b[i]-1)/(-c[i]);
    if(p<l) return r-l+1;
    if(p>r) return f(l,r);
    return (r-p)+f(l,p);
}
bool check(const int D){ // D天够不够达成题目要求
    for(int i=1;i<=n;i++){
        int L{0},R{D};
        while(L<R){
            const int mid=(L+R+1)>>1;
            if(calc(i,mid,D)>=a[i]) L=mid;
            else R=mid-1;
        }
        if(L==0) return false;
        lim[i]=L;
    }

    struct CMP{ bool operator()(int u,int v)const{ return lim[u]<lim[v]; }};
    priority_queue<int,vector<int>,CMP> q;
    static int deg[N];
    for(int u=1;u<=n;u++){ deg[u]=G[u].size(); if(deg[u]==1) q.push(u); }
    for(int clc{n};clc>=2;clc--){
        const int u=q.top(); q.pop();
        if(lim[u]<clc) return false;
        --u[fa][deg];
        if(u[fa][deg]==1) q.push(u[fa]);
    }
    return true;
}
void dfs(int u,int fa){
    u[::fa]=fa;
    for(int v:G[u]) if(v!=fa) dfs(v,u);
}
int main(){
    fin>>n;
    for(int i=1;i<=n;i++) fin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int u,v; fin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1,0);

    int L=1, R=1e9;
    while(L<R){
        const int mid=(L+R)>>1;
        if(check(mid)) R=mid;
        else L=mid+1;
    }
    fout<<L<<'\n';

    return 0;
}