#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
template<typename T>
inline void write(T x){
    if(x>=10) write(x/10);
    putchar(x%10+48);
}
const ll N=2e4+10,K=110,INF=0x3f3f3f3f;
int n,m,k,in[N];
ll f[N][K];
    int ecnt,head[N];
    struct E{
        int v,next;ll w;
    }e[N];
    void add(int u,int v,ll w){
        e[++ecnt]={v,head[u],w};
        head[u]=ecnt;
    }
void topu(){
    queue<int> q;
    q.push(1);
    memset(f,INF,sizeof(f));
    f[1][0]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            for(int j=0;j<k;++j){
                //if(f[u][j]>=INF) continue;
                ll x;
                if(e[i].w<=f[u][j]+1) x=f[u][j]+1;
                else{
                    x=f[u][j]+1+((e[i].w-(f[u][j]+1))/k)*k;
                    if((e[i].w-(f[u][j]+1))%k!=0) x+=k;
                }
                f[v][(j+1)%k]=min(f[v][(j+1)%k],x);
            }
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    read(n);read(m);read(k);
    for(int i=1;i<=m;++i){
        int u,v;ll w;
        read(u);read(v);read(w);
        add(u,v,w);
        in[v]++;
    }
    //for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    //for(int i=1;i<=n;++i) cout<<id[i]<<" ";
    /*
    for(int i=1;i<=n;++i){
        for(int j=e.head[i];j;j=e.e[j].next){
            if(id[i]!=id[e.e[j].v]){
                c.add(id[i],id[e.e[j].v],e.e[j].w);
            }
        }
    }
    */
    topu();
    if(f[n][0]>=INF) printf("-1");
    else printf("%lld",f[n][0]);
    return 0;
}
