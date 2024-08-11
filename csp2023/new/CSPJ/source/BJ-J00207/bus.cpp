#include <bits/stdc++.h>

using namespace std;
int ans = INT_MAX;int n,k;
bool d[(int)1e4 + 10][(int)1e4 + 10];
void dfs(int kkk,int kk){
    if(kk == n){
        if(kkk % k == 0){
            ans = min(ans,kkk);
        }
    }
    for(int i = 1;i <= n;i++){
        if(d[kkk][i]){
            dfs(kkk + 1,i);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdin);
    int m,u,v,qs;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        cin >> u >> v >> qs;
        d[u][v] = true;
    }
    dfs(1,0);
    if(ans == INT_MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
}
