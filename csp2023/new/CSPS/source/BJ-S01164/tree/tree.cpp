#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<vector>
using namespace std;
long long n,a[100005],b[100005],c[100005],d[100005],uu,vv,sum,e[100005],p=1,vis[100005],ti,maxn=0,dis[100005];
vector<long long> adj[200005];
struct o{
    long long xx,dd;
    bool operator <(const o &y) const {
        return y.dd<dd;
    }
};
void bfs(long long x){
    vis[x]=1;
    for(long long i=0;i<adj[x].size();i++){
        long long v=adj[x][i];
        if(vis[v]==0){
            dis[v]+=dis[x]+1;
        bfs(v);
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        b[i]=max(b[i],p);
        d[i]=(a[i]+b[i]-1)/b[i];
    }
    for(long long i=1;i<n;i++){
        cin>>uu>>vv;
        adj[uu].push_back(vv);
        adj[vv].push_back(uu);
    }
    e[++ti]=1;
    bfs(1);
    for(long long i=1;i<=n;i++){
        maxn=max(maxn,d[i]+dis[i]);
    }
    cout<<maxn;
    return 0;
}
