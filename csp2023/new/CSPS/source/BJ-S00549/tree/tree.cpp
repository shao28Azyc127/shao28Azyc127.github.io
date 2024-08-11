#include <bits/stdc++.h>
#define ll long long
#define N 200002
using namespace std;
ll n,a[N],b[N],c[N],k[N],ans;
struct node{
    ll u,w,d;
};
bool operator >(node a,node b){
    return a.w>b.w;
}
vector<int> e[N];
void bfs(ll s){
    priority_queue<node,vector<node>,greater<node> > q;
    q.push({s,k[s],1});
    while(q.size()){
        auto t=q.top();
        ll u=t.u,ww=t.w,day1=t.d;
        q.pop();
        ans=max(ans,day1+ww-1);
        for(int v:e[u]){
            q.push({v,k[v],day1+1});
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        k[i]=a[i]/b[i];
        if(a[i]%b[i])  k[i]++;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    bfs(1);
    cout<<ans;
    return 0;
}