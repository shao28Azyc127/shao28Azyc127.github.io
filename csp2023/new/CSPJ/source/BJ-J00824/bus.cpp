#include <bits/stdc++.h>
using namespace std;


int n, m, k, u, v, a, mxa, mia = 2147483647, ans = 2147483647;
int rd[10005][10005];

void dfs(int step, int t){
    if (step == n){
        if (((int)ceil((double)t / k) * k) == t)
            ans = min(ans, (int)ceil((double)t / k) * k);
        return;
    }

    for (int i = 1; i <= n; i++){
        if (rd[step][i] > -1 && rd[step][i] <= t){
            dfs(i, t + 1);
        }
    }
}

int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    memset(rd, -1, sizeof(rd));

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> u >> v >> a;
        rd[u][v] = a;
        mxa = max(a, mxa);
        mia = min(a, mia);
    }

    for (int i = mia / k; i <= (mxa + k - 1) / k; i++) dfs(1, i*k);

    if (ans == 2147483647) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
