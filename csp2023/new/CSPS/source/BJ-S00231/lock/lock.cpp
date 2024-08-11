#include <cstdio>
#include <vector>

using namespace std;

int n, ans, p[10], a[10][10];

void dfs(int c) {
    if (c > 5) {
        for (int i = 1; i <= n; ++i) {
            vector<int> v;
            v.reserve(3);
            for (int j = 1; j <= 5; ++j) {
                if (a[i][j] != p[j]) {
                    v.push_back(j);
                    if (v.size() > 2) return;
                }
            }
            if (v.size() == 0) return;
            if (v.size() == 1) continue;
            if (v[0] + 1 != v[1]) return;
            if (a[i][v[0]] - p[v[0]] != a[i][v[1]] - p[v[1]] && a[i][v[0]] - p[v[0]] + 10 != a[i][v[1]] - p[v[1]] && a[i][v[0]] - p[v[0]] != a[i][v[1]] - p[v[1]] + 10) return;
        }
        ++ans;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        p[c] = i;
        dfs(c + 1);
    }
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) scanf("%d", &a[i][j]);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}