#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int c, t, n, m;
int a[MAXN];

inline int id(int ch) {
    if (ch == 'T') return 0; 
    if (ch == 'F') return 1;
    if (ch == 'U') return 2;
    if (ch == '+') return 3;
    if (ch == '-') return 4;
}

struct Q {
    int type, p, q;
} s[MAXN];

namespace Subtask1 {
    int b[MAXN], ans;

    inline bool check() {
        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
        }
        for (int i = 1; i <= m; i++) {
            if (s[i].type < 3) {
                int p = s[i].p;
                b[p] = s[i].type;
            }
            if (s[i].type == 3) {
                int p = s[i].p, q = s[i].q;
                b[p] = b[q];
            }
            if (s[i].type == 4) {
                int p = s[i].p, q = s[i].q;
                if (b[q] == 2) b[p] = 2;
                else b[p] = b[q] ^ 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }

    void dfs(int cur, int cnt) {
        if (cur == n + 1) {
            if (check()) ans = min(ans, cnt);
            return;
        }
        a[cur] = 0;
        dfs(cur + 1, cnt);
        a[cur] = 1;
        dfs(cur + 1, cnt);
        a[cur] = 2;
        dfs(cur + 1, cnt + 1);
        a[cur] = -1;
    }

    inline void solve() {
        ans = n + 1;
        for (int i = 1; i <= n; i++) {
            a[i] = -1;
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }
}

namespace Subtask2 {
    inline void solve() {
        for (int i = 1; i <= m; i++) {
            a[s[i].p] = s[i].type;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) cnt++;
        }
        printf("%d\n", cnt);
    }
}

namespace Subtask3 {
    int b[MAXN];

    inline void solve() {
        for (int i = 1; i <= n; i++) {
            a[i] = -1;
        }
        while (1) {
            for (int i = 1; i <= n; i++) {
                b[i] = a[i];
            }
            for (int i = 1; i <= m; i++) {
                int type = s[i].type, p = s[i].p, q = s[i].q;
                if (q) a[p] = a[q];
                else a[p] = 2;
            }
            for (int i = 1; i <= m; i++) {
                int type = s[i].type, p = s[i].p, q = s[i].q;
                if (q) a[p] = a[q];
                else a[p] = 2;
            }
            bool ok = 1;
            for (int i = 1; i <= n; i++) {
                if (b[i] != a[i]) ok = 0;
            }
            if (ok) break;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) cnt++;
        }
        printf("%d\n", cnt);
    }
}

inline void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1, p, q; i <= m; i++) {
        char op[2];
        scanf("%s", op);
        int num = id(op[0]);
        if (num < 3) {
            scanf("%d", &p);
            s[i] = {num, p};
        } else {
            scanf("%d%d", &p, &q);
            s[i] = {num, p, q};
        }
    }
    if (c <= 2) {
        Subtask1::solve();
        return;
    }
    if (c <= 4) {
        Subtask2::solve();
        return;
    }
    if (c <= 6) {
        Subtask3::solve();
        return;
    }
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) solve();
}