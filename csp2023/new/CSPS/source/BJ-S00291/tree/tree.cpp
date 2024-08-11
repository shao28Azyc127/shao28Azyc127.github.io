#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005],h[100005];
int b[100005],c[100005];
vector<int> es[100005];
bool vis[100005];
int main(){
    #ifndef JZQ
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        es[u].push_back(v);
        es[v].push_back(u);
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(auto u:es[1]) pq.push({c[u],u});
    int x=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        x++;
        vis[p.second]=1;
        for(auto u:es[p.second]) if(!vis[u]) pq.push({c[u],u});
        for(int i=1;i<=n;i++){
            if(vis[i]) h[i]+=max(b[i]+1ll*x*c[i],1ll);
        }
    }
    while(true){
        bool flag=true;
        for(int i=1;i<=n;i++) if(h[i]<a[i]) flag=false;
        if(flag) break;
        x++;
        for(int i=1;i<=n;i++) h[i]+=max(b[i]+1ll*x*c[i],1ll);
    }
    printf("%d",x);
    return 0;
}