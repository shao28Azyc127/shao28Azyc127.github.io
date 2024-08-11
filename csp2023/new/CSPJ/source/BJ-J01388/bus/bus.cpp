#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 20005
int nxt[M], to[M], tim[M], hd[N], tot;
struct ans { int d, m; };
vector<ans> a[N]; queue<int> q;
int Ceil(int a, int b) { return a / b + !!(a % b); }
int vis[N];
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int u, v, t; scanf("%d%d%d", &u, &v, &t);
        nxt[++tot] = hd[u]; to[tot] = v; tim[tot] = t; hd[u] = tot;
    }
    q.push(1); a[1].push_back((ans){ 0, 0 });
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = to[i]; if (!vis[v]) q.push(v); vis[v] = 1;
            for (ans j : a[u]) a[to[i]].push_back((ans){ j.d + 1, max(j.m, tim[i]) });
        }
    }
    int A = 0x3f3f3f3f;
    for (ans j : a[n]) if (j.d % k == 0) A = min(A, j.d + Ceil(j.m, k) * k);
    printf("%d\n", A == 0x3f3f3f3f ? -1 : A);
    return 0;
}