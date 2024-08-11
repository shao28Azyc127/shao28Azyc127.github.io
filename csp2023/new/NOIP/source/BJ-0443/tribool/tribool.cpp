#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

struct Var {
    bool flag;
    int id;
} vars[MAXN], T = { 0, -1 }, F = { 0, -2 }, U = { 0, -3 };

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        vars[i].flag = 0;
        vars[i].id = i;
    }
}

char id_to_ch(int id) {
    if (id == -1) return 'T';
    else if (id == -2) return 'F';
    else if (id == -3) return 'U';
    return '?';
}

void execute(char op, int x, int y) {
    if (op == 'T') vars[x] = T;
    else if (op == 'F') vars[x] = F;
    else if (op == 'U') vars[x] = U;
    else if (op == '+') vars[x] = vars[y];
    else if (op == '-') {
        vars[x] = vars[y];
        vars[x].flag = !vars[x].flag;
    }
}

void finalexec(int n) {
    for (int i = 1; i <= n; ++i) {
        if (vars[i].id < 0 && vars[i].flag) {
            if (vars[i].id == -1) vars[i].id = -2;
            else if (vars[i].id == -2) vars[i].id = -1;
            vars[i].flag = false;
        }
    }
}

namespace Sub1 {
    int n, m, ans;
    char a[15], tmp[15];
    struct Query {
        char op;
        int x, y;
    } qs[15];
    int check() {
        int ans = 0;
        for (int i = 1; i <= n; ++i) tmp[i] = a[i];
        for (int i = 1; i <= m; ++i) {
            if (qs[i].op == '+') {
                tmp[qs[i].x] = tmp[qs[i].y];
            } else if (qs[i].op == '-') {
                tmp[qs[i].x] = tmp[qs[i].y];
                if (tmp[qs[i].x] == 'T') tmp[qs[i].x] = 'F';
                else if (tmp[qs[i].x] == 'F') tmp[qs[i].x] = 'T';
            } else {
                tmp[qs[i].x] = qs[i].op;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (tmp[i] != a[i]) return 0x3f3f3f3f;
            ans += tmp[i] == 'U';
        }
        return ans;
    }
    void dfs(int i) {
        if (i > n) {
            ans = min(ans, check());
            return;
        }
        a[i] = 'T';
        dfs(i + 1);
        a[i] = 'F';
        dfs(i + 1);
        a[i] = 'U';
        dfs(i + 1);
        a[i] = 0;
    }
    void solve() {
        ans = 0x3f3f3f3f;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("\n%c %d", &qs[i].op, &qs[i].x);
            if (qs[i].op == '+' || qs[i].op == '-') scanf("%d", &qs[i].y);
        }
        dfs(1);
        printf("%d\n", ans);
    }
}

namespace Sub2 {
    int n, m;
    char a[MAXN];
    void solve() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) a[i] = '?';
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            char c;
            int x;
            scanf("\n%c %d", &c, &x);
            a[x] = c;
        }
        for (int i = 1; i <= n; ++i) if (a[i] == 'U') ++ans;
        printf("%d\n", ans);
    }
}

namespace Sub3 {
    int n, m, inde[MAXN];
    char a[MAXN];
    vector<int> G[MAXN];
    void toposort() {
        queue<pair<int, int> > q;
        for (int i = 1; i <= n; ++i) if (!inde[i]) q.push({ i, i });
        while (!q.empty()) {
            auto i = q.front(); q.pop();
            int u = i.first;
            a[u] = a[i.second];
            for (int v : G[u]) {
                --inde[v];
                if (!inde[v]) q.push({ v, u });
            }
        }
    }
    void solve() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            inde[i] = 0;
            G[i].clear();
        }
        init(n);
        for (int i = 1; i <= n; ++i) a[i] = '?';
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            char c;
            int x;
            scanf("\n%c %d", &c, &x);
            if (c == 'U') {
                execute(c, x, 0);
            } else {
                int y;
                scanf("%d", &y);
                execute(c, x, y);
            }
        }
        finalexec(n);
        for (int i = 1; i <= n; ++i) {
            if (vars[i].id < 0) {
                a[i] = id_to_ch(vars[i].id);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vars[i].id > 0) {
                G[vars[i].id].push_back(i);
                ++inde[i];
            }
        }
        toposort();
        for (int i = 1; i <= n; ++i) if (a[i] == 'U') ++ans;
        printf("%d\n", ans);
    }
}

namespace Sub4 {
    int n, m, inde[MAXN];
    char a[MAXN];
    vector<pair<int, int> > G[MAXN];
    void toposort() {
        queue<pair<pair<int, int>, int> > q;
        for (int i = 1; i <= n; ++i) if (!inde[i]) q.push({ { i, i }, 0 });
        while (!q.empty()) {
            auto i = q.front(); q.pop();
            int u = i.first.first, flag = i.second;
            a[u] = a[i.first.second];
            //printf("%d <- %d (%d)\n", u, i.first.second, flag);
            if (flag) {
                if (a[u] == 'T') a[u] = 'F';
                else if (a[u] == 'F') a[u] = 'T';
                else if (a[u] == '?') a[u] = '!';
                else if (a[u] == '!') a[u] = '?';
            }
            for (auto i : G[u]) {
                int v = i.first, flag = i.second;
                --inde[v];
                if (!inde[v]) q.push({ { v, u }, flag });
            }
        }
    }
    void solve() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            inde[i] = 0;
            G[i].clear();
        }
        init(n);
        for (int i = 1; i <= n; ++i) a[i] = '?';
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            char c;
            int x;
            scanf("\n%c %d", &c, &x);
            if (c == 'U') {
                execute(c, x, 0);
            } else {
                int y;
                scanf("%d", &y);
                execute(c, x, y);
            }
        }
        finalexec(n);
        for (int i = 1; i <= n; ++i) {
            if (vars[i].id < 0) {
                a[i] = id_to_ch(vars[i].id);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vars[i].id > 0) {
                G[vars[i].id].push_back({ i, vars[i].flag });
                ++inde[i];
            }
        }
        toposort();
        for (int i = 1; i <= n; ++i) if (a[i] != '?') ++ans;
        printf("%d\n", ans);
    }
}

namespace Normal {
    void solve() {
        ;
    }
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        if (c == 1 || c == 2) Sub1::solve();
        else if (c == 3 || c == 4) Sub2::solve();
        else if (c == 5 || c == 6) Sub3::solve();
        else if (c == 7 || c == 8) Sub4::solve();
        else Normal::solve();
    }
    return 0;
}