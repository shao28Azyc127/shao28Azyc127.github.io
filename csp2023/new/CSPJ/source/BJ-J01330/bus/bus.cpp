#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int maxn = 1e3+10;
int n, m, k, ans;
queue<int>e[maxn];
int used[maxn];
int t[maxn];
int dfs(int nn, int m){
    if(nn == n) return m;
    for(int i = 0;i<e[nn].size();i++){
        used[e[nn][i]] = true;
        dfs(e[nn][i], m+t[e[nn][i]]);
    }
}
int main(){//bai_lan_la:D
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> n >> m >> k;
    int m = mm;
    while(mm--){
        int u, v;
        cin >> u >> v >> t[m-mm];
        e[u].push_back(v);
    }
    cout << dfs(1, 0) <<endl;
    return 0;
}
