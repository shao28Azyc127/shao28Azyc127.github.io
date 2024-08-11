#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
const ll inf = 1e18;
int c, t, n, m, k, d; ll ans = -inf; bool vis[N]; pair<ll,int> add[N];
void dfs(int step, int con) {
    if(step == n + 1) {
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            int y = add[i].second; ll v = add[i].first;
            if(!y || !vis[i]) continue;
            int cnt = 1;
            for(int j = i - 1; j >= 1; j--) {
                if(!vis[j]) break;
                cnt++;
            }
            if(cnt >= y) sum += v;
        }
        for(int i = 1; i <= n; i++)
            if(vis[i]) sum -= d;
        ans = max(ans, sum);
        return ;
    }
    if(con < k) { vis[step] = true; dfs(step + 1, con + 1); }
    vis[step] = false; dfs(step + 1, 1);
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        memset(add, 0, sizeof(add));
        memset(vis, 0, sizeof(vis));
        ans = -inf;
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for(int i = 1; i <= m; i++) {
            int x, y, v; scanf("%d%d%d", &x, &y, &v);
            add[x] = {v, y};
        }
        dfs(1, 0); printf("%lld\n", ans);
    }
    return 0;
}