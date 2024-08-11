#include<iostream>
using namespace std;
const int MAXN=1e2+10;
typedef long long ll;
struct Edge{
    ll to,next;
}e[MAXN<<1];
ll n;
ll head[MAXN],tot;
ll a[MAXN],b[MAXN],c[MAXN];
inline void Add(ll u,ll v){
    e[++tot]={v,head[u]};
    head[u]=tot;
}
bool vis[MAXN];
ll h[MAXN];
void f(ll x){
    for(ll i=1;i<=n;i++){
        if(vis[i]){
            h[i]+=max(b[i]+x*c[i],1ll);
        }
    }
}
ll minl=1e14;
ll r[MAXN];
ll stp[MAXN];
void Check(){
    /*for(int i=1;i<=n;i++){
        cout<<stp[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;*/
    for(ll i=n+1;i;i++){
        bool flag=1;
        for(ll j=1;j<=n;j++){
            if(h[j]<a[j]) flag=0;
            if(h[j]<a[j]){
                h[j]+=max(b[j]+i*c[j],1ll);
            }
        }
        if(flag){
            minl=min(minl,i-1);
            break;
        }
        /*for(int j=1;j<=n;j++){
            cout<<h[j]<<" ";
        }
        cout<<endl;*/
    }
    //cout<<"minl:"<<minl<<endl;
}
void Dfs(ll time,ll u){
    //cout<<"tm:"<<time<<endl;
    stp[time]=u;
    /*for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
    cout<<endl;*/
    f(time);
    if(time==n){
        Check();
        return;
    }
    for(int i=1;i<=n;i++){
        r[i]=h[i];
    }
    for(ll i=1;i<=n;i++){
        if(vis[i]){
            for(ll j=head[i];j;j=e[j].next){
                ll v=e[j].to;
                if(!vis[v]){
                    vis[v]=1;
                    Dfs(time+1,v);
                    vis[v]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        h[i]=r[i];
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        Add(u,v),Add(v,u);
    }
    vis[1]=1;
    Dfs(1,1);
    cout<<minl;
    return 0;
}