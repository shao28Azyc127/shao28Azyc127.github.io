#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int n, m, k;
vector<pair<int, int> > e[20005];
void dfs(int u, int t){
    if(u == n){
        if(t % k == 0){
            cout << t;
            exit(0);
        }
        return;
    }
    for(auto i : e[u]){
        if(t >= i.second){
            dfs(i.first, t + 1);
        }
    }
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    int l = 0, c;
    for(int i = 1 ;i <= m; i++){
        int u, v, a;
        cin >> u >>v >> a;
        l = max(a, l);
        c = min(c, a);
        e[u].push_back(make_pair(v, a));
    }
    for(int i = c / k * k; i <= l + m; i += k){
        dfs(1, i);
    }
    cout << -1;
    return 0;
}
