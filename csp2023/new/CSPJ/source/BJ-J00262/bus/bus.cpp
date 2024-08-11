#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, a, k;
vector<pair<int, int>> e[10010];
queue<pair<int, int>> q;

void bfs(){
    int u, x;
    q.push({1, k});
    while(!q.empty()){
        pair<int, int> j = q.front();
        q.pop();
        u = j.first;
        x = j.second;
        if(u == n && !(x % k)){
            cout << x << endl;
            return;
        }
        for(pair<int, int> i : e[u]){
            if(x >= i.second)
                q.push({i.first, x + 1});
        }
    }
    cout << -1 << endl;
}

int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> a;
        e[u].push_back({v, a});
    }
    if(n < 11){
        bfs();
    }else cout << -1;
    return 0;
}

