#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn],b[maxn],c[maxn];
vector<long long> g[maxn];
bool vis[maxn];
long long path[maxn];
long long len;
long long n,m;
long long ans=1e9+7;
long long check_path(){
    long long af[maxn]; memset(af,0,sizeof(af));
    bool flag=0;
    for(long long i=n-1,day=1;i>=0;i--,day++) for(long long j=1;j<=day;j++) af[i]+=max((long long)(1),b[path[i]]+c[path[i]]*j);
    for(long long i=0;i<n;i++) if(a[path[i]]>af[i]){
        flag=1; break;
    }
    if(!flag) return n;
    for(long long day=n+1;;day++){
        flag=0;
        for(long long i=0;i<n;i++) af[i]+=max((long long)(1),b[path[i]]+c[path[i]]*day);
        for(long long i=0;i<n;i++){
            if(a[path[i]]>af[i]){
                flag=1; break;
            }
        }
        if(!flag) return day;
    }
    return 1e9+7;
}
void dfs(long long x){
    if(len==n){
//        for(long long i=0;i<n;i++) cout<<path[i]<<' ';
//        cout<<endl;
        ans=min(ans,check_path());
        return;
    }
    for(long long j=1;j<=n;j++){
        for(long long i=0;i<g[j].size();i++){
            long long xx=g[j][i];
            if(vis[xx]) continue;
            path[len++]=xx;
            vis[xx]=1;
            dfs(xx);
            vis[xx]=0;
            len--;
        }
    }
    return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n; m=n-1;
    for(long long i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(long long i=0;i<m;i++){
        long long u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    path[len++]=1;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
