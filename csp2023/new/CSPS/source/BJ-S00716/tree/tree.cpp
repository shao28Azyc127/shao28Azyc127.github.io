#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1e5 + 5;

int n;
LL a[MAXN], b[MAXN], c[MAXN];
vector<int> e[MAXN];

bool calc(int i, int l, int r) {
    __int128 res = 0;
    if (c[i] >= 0) {
        res += (__int128)b[i] * (r - l + 1);
        if (res >= a[i]) return 1;
        res += (__int128)c[i] * (r - l + 1) * (l + r) / 2;
        return res >= a[i];
    }
    int L = l, R = r + 1;
    while (L < R) {
        int mid = L + R >> 1;
        if (b[i] + mid * c[i] <= 0) R = mid;
        else L = mid + 1;
    }
    res += r - L + 1;
    r = L - 1;
    res += (__int128)b[i] * (r - l + 1);
    res += (__int128)c[i] * (r - l + 1) * (l + r) / 2;
    return res >= a[i];
}

int lim[MAXN];
void dfs(int u, int fa) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u), lim[u] = min(lim[u], lim[v] - 1);
    }
}

int cnt[MAXN];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        if (calc(i, n, mid)) lim[i] = n << 1;
        else if (!calc(i, 1, mid)) return 0;
        else {
            int l = 1, r = n;
            while (l < r) {
                int Mid = l + r >> 1;
                if (calc(i, l, mid)) l = Mid + 1;
                else r = Mid;
            }
            lim[i] = l - 1;
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (lim[i] <= 0) return 0;
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (lim[i] > n) lim[i] = n;
        cnt[lim[i]]++;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += cnt[i];
        if (tot > i) return 0;
    }
    return 1;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    int l = n, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}