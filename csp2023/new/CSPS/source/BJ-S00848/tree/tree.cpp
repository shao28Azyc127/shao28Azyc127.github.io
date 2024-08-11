#include<iostream>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;
int n;
int a[maxn], b[maxn], c[maxn];

struct edge {
    int to, nxt;
} e[maxn * 2];
int cnt, head[maxn];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

int height[maxn];

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    for (int i = 1;i < n;i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        add(u, v), add(v, u);
    }
    for (int x = 1;;x++) {
        bool flag = 1;
        for (int i = 1;i <= min(x, n);i++) {
            height[i] += max(b[i] + x * c[i], 1ll);
            if (height[i] < a[i]) {
                flag = 0;
            }
        }
        if (flag && min(x, n) == n) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
