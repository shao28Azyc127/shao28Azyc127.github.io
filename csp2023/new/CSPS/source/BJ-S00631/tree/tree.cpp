#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define REPG(i,g,x) for(int i=g.head[x];~i;i=g.edge[i].nxt)
#define LL long long
#define mem(a,n) memset(a,n,sizeof(a))

inline LL read(){
    LL s=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+c-'0';
    return s*f;
}

const int N=1e5+5;
LL a[N],b[N],c[N];
struct graph{
    int head[N],cnt;
    struct node{
        int to,nxt;
    }edge[2*N];
    inline void add(int x,int y){
        edge[++cnt]=(node){y,head[x]};head[x]=cnt;
    }
}g;

namespace A{
    priority_queue<pair<int,int> > q;
    int rk[N],ct;bool vis[N];
    inline void getrk(){
        q.push(make_pair((a[1]+b[1]-1)/b[1],1));vis[1]=1;ct=0;
        while(!q.empty()){
            int u=q.top().second;q.pop();
            rk[++ct]=u;
            REPG(i,g,u){
                int v=g.edge[i].to;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(make_pair((a[v]+b[v]-1)/b[v],v));
            }
        }
    }
    inline bool check(int x){
        rep(i,1,ct) if((LL)(x-i+1)*b[rk[i]]<a[rk[i]]) return 0;
        return 1;
    }
    inline int erfen(int l,int r){
        if(l>=r) return l;
        int mid=(l+r)>>1;
        if(check(mid)) return erfen(l,mid);
        return erfen(mid+1,r);
    }
    inline void solve(){
        getrk();
        //if(check(27742908)) printf("Yes\n");
        printf("%d\n",erfen(0,1e9));
    }
}
int n;
namespace BC{
    int rk[N],ct;bool vis[N];
    inline void getrk(){
        int p=1;rk[1]=1;ct=1;vis[1]=1;
        while(ct<n){
            REPG(i,g,p){
                int v=g.edge[i].to;
                if(vis[v]) continue;
                vis[v]=1;
                rk[++ct]=v;
            }p=rk[ct];
        }
    }

    inline bool check(int x){
        rep(i,1,ct){
            int p=rk[i];
            if(c[p]>=0){
                if(b[p]*(x-i+1)+(__int128)c[p]*(i+x)*(x-i+1)/2<a[p]) return 0;
            }else{
                int t=(b[p]-1-c[p]-1)/(-c[p]);
                if(b[p]*(t-i)+(__int128)c[p]*(i+t-1)*(t-i)/2+(x-t+1)<a[p]) return 0;
            }
        }
        return 1;
    }

    inline int erfen(int l,int r){
        if(l>=r) return l;
        int mid=(l+r)>>1;
        if(check(mid)) return erfen(l,mid);
        return erfen(mid+1,r);
    }
    inline void solve(){
        getrk();
        printf("%d\n",erfen(0,1e9));
    }
}

int du[N];

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    mem(g.head,-1);
    n=read();
    rep(i,1,n) a[i]=read(),b[i]=read(),c[i]=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        du[u]++,du[v]++;
        g.add(u,v);g.add(v,u);
    }

    bool flag=1;
    rep(i,1,n) if(c[i]!=0) flag=0;
    if(flag){
        A::solve();
    }
    flag=1;
    rep(i,1,n) if(du[i]>2) flag=0;
    if(flag){
        BC::solve();
    }
    return 0;
}

