#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,ans=LLONG_MAX;
int u[20010],v[20010],a[20010];
bool flag;
bool vis[10010][100];
vector<int> g[10010];

void solve(int p,int mod,int stp){
    if(vis[p][mod]){
        if(flag){
            flag=false;
            return;
        }
        flag=true;
        mod--;
        if(mod<0){
            mod=k-1;
        }
        for(int q:g[p]){
            solve(q,mod,stp+1);
        }
        return;
    }
    vis[p][mod]=true;
    if(p==1){
        if(stp%k==0&&mod==0){
            ans=min(ans,stp);
        }
        return;
    }
    mod--;
    if(mod<0){
        mod=k-1;
    }
    for(int q:g[p]){
        solve(q,mod,stp+1);
    }
}

signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        g[v[i]].push_back(u[i]);
    }
    solve(n,0,0);
    if(ans==LLONG_MAX){
        cout<<-1;
    }
    else{
        cout<<ans;
    }

    return 0;
}
