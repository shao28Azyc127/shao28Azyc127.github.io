#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 2e5 + 5;
int _, n, m;
enum { T, F, U };
enum { CZ, CL };  // chu zhi, chang liang
int typ[N], val[N];
bool visu[N + N], vis[N + N];
vector<int> e[N + N];
int PT, PF, PU;
queue<int> qu;
int cnt = 0, blo[N + N];
void dfs(int u) {
    vis[u] = 1; blo[u] = cnt;
    for (auto &v: e[u]) if (!vis[v]) {
        dfs(v);
    }
}
signed main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    for (scanf("%*d%d", &_); _; --_) {
        scanf("%d%d", &n, &m);
        PT = n + n + 1, PF = PT + 1, PU = PF + 1;
        rep(i, 1, n) typ[i] = CZ, val[i] = i;
        rep(i, 1, PU) visu[i] = 0, vis[i] = 0, e[i].clear();
        rep(__, 1, m) {
            char s[10];
            int i, j;
            scanf("%s%d", s + 1, &i);
            if (s[1] == 'T') {
                typ[i] = CL; val[i] = T;
            } else if (s[1] == 'F') {
                typ[i] = CL; val[i] = F;
            } else if (s[1] == 'U') {
                typ[i] = CL; val[i] = U;
            } else if (s[1] == '+') {
                scanf("%d", &j);
                typ[i] = typ[j];
                val[i] = val[j];
            } else {
                scanf("%d", &j);
                typ[i] = typ[j];
                if (typ[i] == CL) {
                    val[i] = (val[j] == T ? F : (val[j] == F ? T : U));
                } else {
                    val[i] = -val[j];
                }
            }
        }
        rep(i, 1, n) {
            // printf("de:%d %d\n", typ[i], val[i]);
            if (typ[i] == CZ) {
                if (val[i] < 0) e[i].emplace_back(n - val[i]), e[n - val[i]].emplace_back(i);
                else e[i].emplace_back(val[i]), e[val[i]].emplace_back(i);
                if (val[i] < 0) e[n + i].emplace_back(-val[i]), e[-val[i]].emplace_back(n + i);
                else e[n + i].emplace_back(val[i] + n), e[val[i] + n].emplace_back(i + n);
            } else {
                if (val[i] == T) {
                    e[i].emplace_back(PT), e[PT].emplace_back(i);
                    e[i + n].emplace_back(PF), e[PF].emplace_back(i + n);
                } else if (val[i] == F) {
                    e[i].emplace_back(PF), e[PF].emplace_back(i);
                    e[i + n].emplace_back(PT), e[PT].emplace_back(i + n);
                } else {
                    e[i].emplace_back(PU), e[PU].emplace_back(i);
                    e[i + n].emplace_back(PU), e[PU].emplace_back(i + n);
                    qu.emplace(i);
                }
            }
        }
        rep(i, 1, PU) if (!vis[i]) {
            ++cnt; dfs(i);
        }
        rep(i, 1, n) if (blo[i] == blo[i + n]) qu.emplace(i);
        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            if (visu[u]) continue;
            visu[u] = 1;
            if (u <= n + n) {
                int v = u + n;
                if (u > n) v = u - n;
                if (!visu[v]) qu.emplace(v);
            }
            for (auto &v: e[u]) if (!visu[v]) qu.emplace(v);
        }
        int ans = 0;
        rep(i, 1, n) if (visu[i]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}