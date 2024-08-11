#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010],c[100010];
vector <int> vc[100010];
int u,v,n,ans,id,vis[100010];
int ceilc(int id){
    return (a[id]+b[id]-1)/b[id];
}
signed  main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for (int i=1; i<=n; i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for (int i=1; i<n; i++){
        scanf("%lld%lld",&u,&v);
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    priority_queue <pair<int,int> > q;
    q.push(make_pair(ceilc(1),1));vis[1]=1;
    while (!q.empty()){
        auto tmp=q.top(); q.pop();
        ans=max(ans,id+ceilc(tmp.second));
        for (auto x:vc[tmp.second]){
            if (!vis[x]) {q.push(make_pair(ceilc(x),x)); vis[x]=1;}
        }
        id++;
    }
    cout<<ans;
    return 0;
}
