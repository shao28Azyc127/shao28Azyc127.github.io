#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
typedef long long ll;
const int N = 3e5 + 5;
int C, T, n, m;
namespace solve1 {
    int a[15], b[15], ans;
    struct Query {
        char op;
        int x, y;
    } qy[15];
    inline void dfs(int x, int cnt) {
        if (x > n){
            memcpy(b, a, sizeof(a));
            for (int i = 1; i <= m; i++)
                if (qy[i].op == '+')
                    b[qy[i].x] = b[qy[i].y];
                else if (qy[i].op == '-')
                    b[qy[i].x] = b[qy[i].y] == 2 ? 2 : b[qy[i].y] ^ 1;
                else
                    b[qy[i].x] = qy[i].op == 'T' ? 1 : (qy[i].op == 'F' ? 0 : 2);
            for (int i = 1; i <= n; i++)
                if (a[i] != b[i])
                    return;
            ans = min(ans, cnt);
            return;
        }
        a[x] = 0, dfs(x + 1, cnt);
        a[x] = 1, dfs(x + 1, cnt);
        a[x] = 2, dfs(x + 1, cnt + 1);
    }
    inline void main() {
        while (T--) {
            cin >> n >> m;
            for (int i = 1;i <= m; i++) {
                cin >> qy[i].op;
                if(qy[i].op == '+' || qy[i].op == '-')
                    cin >> qy[i].x >> qy[i].y;
                else
                    cin >> qy[i].x;
            }
            ans = 1e9, dfs(1, 0);
            cout << ans << '\n';
        }
    }
}
namespace solve2 {
    bool tag[N];
    inline void main() {
        while (T--) {
            memset(tag, 0, sizeof(tag));
            cin >> n >> m;
            for (int i = 1, x; i <= m; i++) {
                char op;
                cin >> op >> x;
                tag[x] = op == 'U';
            }
            int ans = 0;
            for (int i = 1; i <= n; i++)
                ans += tag[i];
            cout << ans << '\n';
        }
    }
}
namespace solve3 {
    int head[N], to[N], nxt[N], etot, pos[N];
    inline void link(int u, int v) {
        to[etot] = v;
        nxt[etot] = head[u];
        head[u] = etot++;
    }
    inline void dfs(int x) {
        for (int i = head[x]; ~i; i = nxt[i])
            if (pos[to[i]] > 0)
                pos[to[i]] = -1, dfs(to[i]);
    }
    inline void main() {
        while (T--) {
            memset(head, -1, sizeof(head)), etot = 0;
            cin >> n >> m;
            for (int i = 1; i <= n; i++)
                pos[i] = i;
            for (int i = 1, x, y; i <= m; i++){
                char op;
                cin >> op >> x;
                if (op == 'U')
                    pos[x] = -1;
                else
                    cin >> y, pos[x] = pos[y];
            }
            for (int i = 1; i <= n; i++)
                if (pos[i] > 0 && pos[i] != i)
                    link(pos[i], i);
            for (int i = 1; i <= n; i++)
                if (pos[i] == -1)
                    dfs(i);
            int ans = 0;
            for (int i = 1; i <= n; i++)
                ans += pos[i] == -1;
            cout << ans << '\n';
        }
    }
}
namespace solve4 {
    int head[N], to[N], nxt[N], etot, pos[N], st[N];
    int dfn[N], low[N], cnt, id[N], tot, stk[N], top, vis[N], sum[N], sz[N];
    inline void link(int u, int v) {
        to[etot] = v;
        nxt[etot] = head[u];
        head[u] = etot++;
    }
    inline void tarjan(int x) {
        dfn[x] = low[x] = ++cnt;
        stk[++top] = x, vis[x] = 1;
        for (int i = head[x]; ~i; i = nxt[i])
            if (!dfn[to[i]]) {
                tarjan(to[i]);
                low[x] = min(low[x], low[to[i]]);
            }
            else if (vis[to[i]])
                low[x] = min(low[x], dfn[to[i]]);
        if (dfn[x] == low[x]) {
            tot++;
            do {
                id[stk[top]] = tot;
                vis[stk[top]] = 0;
                sum[tot] += st[stk[top]];
                sz[tot]++;
                top--;
            } while (stk[top + 1] != x);
        }
    }
    inline void main() {
        for(int t = 1; t <= T; t++){
            memset(head, -1, sizeof(head)), etot = 0;
            memset(dfn, 0, sizeof(dfn)), cnt = tot = 0;
            memset(sum, 0, sizeof(sum));
            cin >> n >> m;
            for (int i = 1; i <= n; i++)
                pos[i] = i, st[i] = 0;
            for (int i = 1, x, y; i <= m; i++) {
                char op;
                cin >> op >> x >> y, pos[x] = pos[y], st[x] = op == '-';
            }
            for (int i = 1; i <= n; i++)
                if (pos[i] != i)
                    link(i, pos[i]);
            for (int i = 1; i <= n; i++)
                if (!dfn[i])
                    tarjan(i);
            int ans = 0;
            for (int i = 1; i <= tot; i++)
                ans += sz[i] * (sum[i] & 1);
            cout << "0\n";
        }
    }
}
int main()
{
    freopen("tribool.in","r", stdin);
    freopen("tribool.out","w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C >> T;
    if (C <= 2)
        solve1::main();
    else if (C <= 4)
        solve2::main();
    else if (C <= 6)
        solve3::main();
    else
        solve4::main();
    return 0;
}