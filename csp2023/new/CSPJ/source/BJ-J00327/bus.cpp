#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=2e4+10,K=1e2+10;
struct Node{
    ll v,w;
    bool operator<(const Node &o)const{
        return v>o.v;
    }
};
ll val[M],nex[M],h[N],w[M];
ll dis[N][K],cnt,n,m,k;
bool vis[N][K];
void add_edge(ll u,ll v,ll a){
    val[++cnt]=v,w[cnt]=a;
    nex[cnt]=h[u],h[u]=cnt;
}
void dijkstra(){
    priority_queue<Node> q;
    memset(dis,0x3f,sizeof(dis));
    dis[1][0]=0;
    Node tp;
    tp.v=1,tp.w=0;
    q.push(tp);
    while(!q.empty()){
        Node t=q.top();
        q.pop();
        vis[t.v][t.w%k]=1;
        for(ll i=h[t.v];i;i=nex[i]){
            ll tp=w[i]-w[i]%k+(t.w+1)%k;
            if(tp<w[i]){
                tp+=k;
            }
            ll tpans=max(t.w+1,tp);
            if(vis[val[i]][(t.w+1)%k]==0&&dis[val[i]][(t.w+1)%k]>tpans){
                dis[val[i]][(t.w+1)%k]=tpans;
                Node tp2;
                tp2.v=val[i],tp2.w=tpans;
                q.push(tp2);
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++){
        ll u,v,a;
        scanf("%lld%lld%lld",&u,&v,&a);
        add_edge(u,v,a);
    }
    dijkstra();
    if(dis[n][0]>1e9){
        printf("-1");
    }else{
        printf("%lld",dis[n][0]);
    }
    return 0;
}
