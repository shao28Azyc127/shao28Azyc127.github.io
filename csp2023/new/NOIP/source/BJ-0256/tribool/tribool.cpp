#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10;
int c, T, n, m, tim, top, cnt, pos[N], book[N], a[N], dfn[N], low[N], ins[N], st[N], sum[N], scc[N], w[N], in[N], bj[N];
vector<int> g[N];
struct node {
    int y, w;
};
vector<node> v[N];
queue<int> q;
void tarjan(int x) {
    dfn[x] = low[x] = ++tim;
    ins[x] = 1, st[++top] = x;
    for (auto y : v[x]) {
        if (!dfn[y.y]) {
            tarjan(y.y);
            low[x] = min(low[x], low[y.y]);
        }
        else if (ins[y.y]) low[x] = min(low[x], dfn[y.y]);
    }
    if (low[x] == dfn[x]) {
        cnt++;
        while (1) {
            int y = st[top--];
            scc[y] = cnt;
            ins[y] = 0;
            if (!book[y]) sum[cnt]++;
            if (y == x) break;
        }
    }
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &T);
      if (c == 3 || c == 4) {
        while (T--) {
            memset(a, 0, sizeof(a));
            int ans = 0;
            scanf("%d%d", &n, &m);
            while (m--) {
                char ch;
                cin >> ch;
                int x;
                scanf("%d", &x);
                a[x] = ch - '0';
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] == 'U' - '0') ans++;
            }
            printf("%d\n", ans);
        }
        return 0;
    }
    while (T--) {
        memset(book, 0, sizeof(book));
        memset(a, 0, sizeof(a));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(ins, 0, sizeof(ins));
        memset(st, 0, sizeof(st));
        memset(sum, 0, sizeof(sum));
        memset(scc, 0, sizeof(scc));
        memset(w, 0, sizeof(w));
        memset(in, 0, sizeof(in));
        memset(bj, 0, sizeof(bj));
        scanf("%d%d", &n, &m);
        int tot = n, ans = 0;
        tim = top = cnt = 0;
        for (int i = 1; i <= n; i++) pos[i] = i;
        while (m--) {
            char ch;
            cin >> ch;
            if (ch >= 'A' && ch <= 'Z') {
                int x;
                scanf("%d", &x);
                if (bj[x]) {
                    book[pos[x]] = 1;
                    pos[x] = ++tot;
                    a[pos[x]] = ch - '0';
                }
                else a[pos[x]] = ch - '0';
                bj[x] = 1;
            }
            else {
                int x, y;
                scanf("%d%d", &x, &y);
                if (ch == '+') {
                    if (bj[x]) {
                        book[pos[x]] = 1;
                        pos[x] = ++tot;
                        v[pos[x]].push_back({pos[y], 0});
                    }
                    else v[pos[x]].push_back({pos[y], 0});
                    bj[x] = 1;
                }
                else {
                    if (bj[x]) {
                        book[pos[x]] = 1;
                        pos[x] = ++tot;
                        v[pos[x]].push_back({pos[y], 1});
                    }
                    else v[pos[x]].push_back({pos[y], 1});
                    bj[x] = 1;
                }
            }
        }
        for (int i = 1; i <= tot; i++) {
            if (!dfn[i]) tarjan(i);
        }
        for (int x = 1; x <= tot; x++) {
            if (a[x] == 'U' - '0') {
                w[scc[x]] = 3;
                continue;
            }
            for (auto y : v[x]) {
                if (scc[x] == scc[y.y]) w[scc[x]] += y.w;
                else {
                    g[scc[x]].push_back(scc[y.y]);
                    in[scc[y.y]]++;
                }
            }
        }
        for (int i = 1; i <= cnt; i++) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            //if (w[x] & 1) ans += sum[x];
            for (int y : g[x]) {
                in[y]--;
                sum[y] += sum[x];
                if (!in[y]) q.push(y);
            }
        }
        for (int i = 1; i <= cnt; i++) {
            if (w[i] & 1) ans += sum[i];
        }
        printf("%d\n", ans);
        for (int i = 1; i <= tot; i++) v[i].clear();
        for (int i = 1; i <= cnt; i++) g[i].clear();
    }
    return 0;
}