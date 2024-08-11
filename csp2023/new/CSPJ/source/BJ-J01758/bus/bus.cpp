# include <bits/stdc++.h>
using namespace std;
struct node{
    int v;
    int time;
};
int n,m,k;
bool p[10002];
vector <node> a[10002];
void init(){
    memset(p,0,sizeof(p));
    return;
}
int max_time = -1;
int ntime = 0;
int ans = 1e9;
void dfs(int u,int kk){
    if(u==n){
        if(kk%k==0){
            ans = min(ans,ntime+kk);
        }
        return;
    }
    p[u] = 1;
    for(int i=0;i<a[u].size();i++){
        if(p[a[u][i].v]==0&&ntime+kk>=a[u][i].time){
            dfs(a[u][i].v,kk+1);
        }
    }
    p[u] = 0;
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,time;
        cin>>u>>v>>time;
        a[u].push_back({v,time});
        max_time = max(max_time,time);
    }
    for(int i=0;i<=max_time;i+=k){
        dfs(1,0);
        init();
        ntime+=k;
    }
    if(ans==1e9) cout<<-1;
    else cout<<ans;
    return 0;
}
