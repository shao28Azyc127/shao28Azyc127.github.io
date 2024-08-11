#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 6;

struct edge {
    int u, v, next;
} E[maxn];
int p[maxn], eid;

int n, m;
int dfn[maxn], low[maxn], in[maxn], val[maxn], t;
bool vis[maxn];
stack<int> sta;

void insert(int u, int v) {
    //if (eid < 1000) printf("insert:u=%d, v=%d\n", u, v);
    eid++;
    E[eid].u = u;
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid;
}

void dfs(int u) {
   /* if (dfn[u] != 0) {
       // printf("error\n");
        return;
    }*/
   // if (t < 1000) printf("u=%d\n", u); else return;
    dfn[u] = low[u] = t++;
    sta.push(u);
    for (int i = p[u]; i != -1; i = E[i].next) {
        int v = E[i].v;
      //  if (t < 1000) printf("u=%d, v=%d\n", u, v);
        if (in[v] != 0) {
            continue;
        } else if (dfn[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        while (1) {
            int x = sta.top();
            sta.pop();
            in[x] = u;
         //   printf("u=%d, x=%d\n", u, x);
            if (x == u) {
                break;
            }
        }
    }
    return;
}

void dfs2(int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = true;
    for (int i = p[u]; i != -1; i = E[i].next) {
        int v = E[i].v;
        dfs2(v);
    }
}

void solve() {
    memset(p, -1, sizeof(p));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    t = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        val[i] = i;
       // if (i < 100000 && i > 90000) printf("i=%d, val=%d\n", i, val[i]);
    }
    for (int k = 1; k <= m; k++) {
        char v;
        int i, j;
        scanf(" %c", &v);
        if (v == '+') {
            scanf("%d %d", &i, &j);
            val[i] = val[j];
         //   if (k < 10000) printf("v=%c, i=%d, j=%d, val=%d\n", v, i, j, val[i]);
        } else if (v == '-') {
            scanf("%d %d", &i, &j);
          //  if (k < 10000) printf("v=%c, i=%d, j=%d, val=%d\n", v, i, j, val[i]);
            val[i] = -val[j];
        } else if (v == 'U') {
            scanf("%d", &i);
            val[i] = n * 2 + 1;
          //  if (k < 10000) printf("v=%c, i=%d, val=%d\n", v, i, val[i]);
        } else {
            scanf("%d", &i);
        }
    }
    for (int i = 1; i <= n; i++) {
   //     if (eid < 10000) printf("i=%d, val=%d\n", i, val[i]);
        if (abs(val[i]) == n * 2 + 1) {
            insert(n * 2 + 1, i);
        } else {
            int u = abs(val[i]);
            if (val[i] < 0) {
                insert(u + n, i);
                insert(u, i + n);
            } else {
                insert(u, i);
                insert(u + n, i + n);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == in[i + n]) {
            insert(n * 2 + 1, i);
        }
    }
    dfs2(n * 2 + 1);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] || vis[i + n]) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, q;
    scanf("%d %d", &c, &q);
    for (int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}
