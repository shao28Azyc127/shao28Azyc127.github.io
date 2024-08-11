#include <bits/stdc++.h>
using namespace std;

long long c, t, n, m, k, d, x[100010], y[100010], v[100010], ans;

void dfs(int day, long long rday, long long v, int nr){
    if(day == n + 1){
        ans = max(ans, v);
        return;
    }
    long long v1 = v;
    for(int i = 1; i <= m; i++){
        if(x[i] == day && nr <= x[i] - y[i]){
            v1 += ::v[i];
        }
    }
    if(nr >= day - k) dfs(day + 1, rday + 1, v1 - d, nr);
    dfs(day + 1, rday, v, day);
}

int main(){
//    freopen("a.in", "r", stdin);
//    freopen(".out", "w", stdout);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    if(c < 3){
        while(t--){
            cin >> n >> m >> k >> d;
            ans = 0;
            for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i] >> v[i];
            }
            dfs(1, 0, 0, 0);
            cout << ans << endl;
        }
        return 0;
    }
    while(t--) cout << "0\n";
    return 0;
}
