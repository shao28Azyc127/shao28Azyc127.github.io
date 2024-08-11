#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
#define maxn 100005
typedef long long ll;
struct edge{
    ll to,next;
}e[maxn*2];
ll n,a[maxn],b[maxn],c[maxn],d[maxn],tot,ans;
bool vis[maxn]={false,true};
void addedge(ll u,ll v){
    e[++tot].to=v;
    e[tot].next=d[u];
    d[u]=tot;
    return;
}
void f(void){
    priority_queue<pair<ll,ll> > q;
    q.push(make_pair(ceil((float)(a[1])/(float)(b[1])),1));
    for(ll i=0;i<n;i++){
        pair<ll,ll> now=q.top();
        q.pop();
        ans=max(ans,now.first+i);
        for(ll i=d[now.second];i;i=e[i].next){
            if(!vis[e[i].to]){
                q.push(make_pair(ceil((float)(a[e[i].to])/(float)(b[e[i].to])),e[i].to));
                vis[e[i].to]=true;
            }
        }
    }
    return;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    f();
    cout<<ans;
    return 0;
}
