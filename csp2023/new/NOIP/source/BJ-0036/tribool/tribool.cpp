#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int N = 1e5 + 5;
inline void read(int &x) {
    x = 0; int f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f *= -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    x *= f;
}
int fa[N << 1];
int find(int u) { return u == fa[u] ? u : (fa[u] = find(fa[u])); }
inline void Merge(int u, int v) { fa[find(u)] = find(v); }
bool fAns[N << 1];
struct Node {
    int op, x;
} p[N];
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Case, T; cin >> Case >> T;
    for (int n, m; T--; ) {
        cin >> n >> m;
        for (int i = 1; i <= (n << 1) + 3; i++) fa[i] = i;
        for (int i = 1; i <= n; i++) p[i] = {1, i};
        for (int i = 1; i <= m; i++) {
            char op; int x, y; cin >> op;
            if (op == '+') {
                cin >> x >> y;
                p[x] = p[y];
            } else if (op == '-') {
                cin >> x >> y;
                p[x] = p[y]; p[x].op *= -1;
            } else if (op == 'T') {
                cin >> x; p[x] = {0, 1};
            } else if (op == 'F') {
                cin >> x; p[x] = {0, -1};
            } else if (op == 'U') {
                cin >> x; p[x] = {0, 0};
            } else assert(0);
        }
        for (int i = 1; i <= n; i++) {
            if (p[i].op == 1) {
                Merge(i, p[i].x); Merge(i + n, p[i].x + n);
            } else if (p[i].op == -1) {
                Merge(i, p[i].x + n); Merge(i + n, p[i].x);
            } else if (p[i].x == 1) {
                Merge(i, (n << 1) + 1); Merge(i + n, (n << 1) + 2);
            } else if (p[i].x == -1) {
                Merge(i, (n << 1) + 2); Merge(i + n, (n << 1) + 1);
            } else if (p[i].x == 0) {
                Merge(i, (n << 1) + 3); Merge(i + n, (n << 1) + 3);
            } else assert(0);
        }
        memset(fAns, 0, sizeof fAns);
        for (int i = 1; i <= n; i++) if (find(i) == find(i + n)) {
            fAns[find(i)] = 1;
        }
        int Ans = 0;
        for (int i = 1; i <= n; i++) if (fAns[find(i)]) Ans++;
        cout << Ans << '\n';
        // printf("%d\n", Ans);
    }
    return 0;
}