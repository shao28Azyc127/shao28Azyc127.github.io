#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> e[10005];
vector<int> ti[10005];
int ans;
void dfs(int u,int time){
    if(u == n && time % k == 0){
        ans = min(ans,time);
        return ;
    }
    for(int i=0;i<e[u].size();i++){
        int v = e[u][i];
        if(time >= ti[u][i]){
            dfs(v,time + 1);
        }
    }
    return ;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    int mxa = 0;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin >> u >> v >> a;
        e[u].push_back(v);
        ti[u].push_back(a);
        mxa = max(mxa,a);
    }
    ans = 1e8;
    for(int i=0;i<=mxa + 2 * k + 10;i+=k){
        dfs(1,i);
    }
    cout << ans;
    return 0;
}
