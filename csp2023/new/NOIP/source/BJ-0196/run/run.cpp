#include <bits/stdc++.h>
using namespace std;
long long c, t, n, m, k, d, x[100005], y[100005], v[100005], bk[100005], su[100005], mx = -1e18;
void dfs(long long now){
    if (now == n + 1){
        long long ans = 0;
        for (long long i = 1; i <= n; i++){
            if (bk[i]){
                ans -= d;
            }
        }
        for (long long i = 1; i <= n; i++){
            if (bk[i] == 1){
                su[i] = su[i - 1] + 1;
            }else{
                su[i] = su[i - 1];
            }
        }
        bool flg = true;
        for (long long i = 1; i <= n; i++){
            long long s = i - k;
            if (s <= 0){
                continue;
            }
            if (su[i] - su[s - 1] == k + 1){
                flg = false;
                break;
            }
        }
        if (!flg){
            return ;
        }
        for (long long i = 1; i <= m; i++){
            long long p = x[i] - y[i] + 1;
            if (p <= 0){
                continue;
            }
            if (su[x[i]] - su[p - 1] == y[i]){
                ans += v[i];
            }
        }
        mx = max(mx, ans);
        return ;
    }
    bk[now] = 0;
    dfs(now + 1);
    bk[now] = 1;
    dfs(now + 1);
    return ;
}
int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> m >> k >> d;
        for (long long i = 1; i <= m; i++){
            cin >> x[i] >> y[i] >> v[i];
        }
        mx = -1e18;
        dfs(1);
        cout << mx << endl;
    }
    return 0;
}