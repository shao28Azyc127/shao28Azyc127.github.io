#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
struct Ground{
    ll a, b, c;
}g[100005];
int n;

namespace Subtask1{
    const int N = 22;
    int p[N], reach[N];
    ll h[N], ans = 1e9, day;
    bool vis[N];
    vector<int> e[N];

    void dfs(int now){
        if (now > n){
            memset(h, 0, sizeof(h));
            printf("the perm: \n");
            for (int i=1; i<=n; i++) printf("%d ", p[i]);
            printf("\n");
            day = n;
            for (int i=1; i<=n; i++) for (int j=i; j<=n; j++){
                h[p[i]] += max(g[p[i]].b + j * g[p[i]].c, 1ll);
            }
            bool flg = 1;
            for (int i=1; i<=n&&flg; i++) flg &= (h[p[i]] >= g[p[i]].a);
            if (flg){
                printf("ans of this perm(equal n): %d\n", n);
                ans = min(ans, 1ll * n);
                return;
            }
            while (1){
                day++;
                for (int i=1; i<=n; i++) h[p[i]] += max(g[p[i]].b + day * g[p[i]].c, 1ll);
                flg = 1;
                for (int i=1; i<=n&&flg; i++) flg &= (h[p[i]] >= g[p[i]].a);
                if (flg) break;
            }
            ans = min(ans, day);
            printf("ans of this perm: %lld\n", ans);
            return;
        }
        for (int i=1; i<=n; i++) if (reach[i] && !vis[i]){
            vis[i] = 1; p[now] = i;
            for (auto v: e[i]) reach[v]++;
            dfs(now + 1);
            vis[i] = 0; p[now] = 0;
            for (auto v: e[i]) reach[v]--;
        }
    }

    void solve(){
        int u, v;
        for (int i=1; i<n; i++){
            scanf("%d%d", &u, &v);
            e[u].pb(v); e[v].pb(u);
        }
        reach[1] = 1e9;
        dfs(1);
        printf("%lld\n", ans);
    }
}

namespace Subtask2{
    const int N = 100005;
    vector<int> e[N];
    ll need[N], d[N];//the longest time needed in subtree(d)
    int p[N], tot;
    bool vis[N];
    bool cmp(int x, int y){return d[x] > d[y];}

    void dfs(int u, int fa){
        d[u] = need[u];
        for (auto v: e[u]) if (v != fa){
            dfs(v, u);
            d[u] = max(d[u], d[v]);
        }
    }
    void solve(){
        for (int i=1; i<=n; i++) need[i] = (g[i].a + g[i].b - 1) / g[i].b;
        int u, v;
        for (int i=1; i<n; i++){
            scanf("%d%d", &u, &v);
            e[u].pb(v); e[v].pb(u);
        }
        dfs(1, 0);
        priority_queue<pair<ll, int> > q;
        p[++tot] = 1; vis[1] = 1;
        for (auto v: e[1]) q.push(make_pair(d[v], v));
        while (!q.empty()){
            u = q.top().second; q.pop();
            p[++tot] = u; vis[u] = 1;
            for (auto v: e[u]) if (!vis[v]) q.push(make_pair(d[v], v));
        }
        ll ans = 0;
        for (int i=1; i<=n; i++) ans = max(ans, (i - 1) + need[p[i]]);
        printf("%lld\n", ans);
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    bool flgA = 1;
    for (int i=1; i<=n; i++){
        scanf("%lld%lld%lld", &g[i].a, &g[i].b, &g[i].c);
        flgA &= (!g[i].c);
    }
    if (flgA){
        Subtask2::solve();
        return 0;
    }
    if (n <= 20){
        Subtask1::solve();
        return 0;
    }
    return 0;
}
