#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
struct tz {
    int x;
    int y;
    int v;
    bool operator<(const tz &B) const {
        return x < B.x || x == B.x && y < B.y;
    }
};
tz a[100005];
int mp[200005];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    if (c < 10) {// n <= 1000
        long long f[1005][1005];
        while (t--) {
            memset(f, 0, sizeof(f));
            int n, m, k, d;
            scanf("%d%d%d%d", &n, &m, &k, &d);
            for (int i = 1; i <= m; ++i) {
                scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
            }
            sort(a + 1, a + m + 1);
            int cur = 1;
            long long ans = 0;
            for (int i = 1; i <= n; ++i) {
                long long sum = 0;
                while (a[cur].x < i && cur <= m) ++cur;
                for (int j = 1; j <= k && j <= i; ++j) {
                    while (a[cur].x == i && j >= a[cur].y) sum += a[cur].v, cur++;
                    f[i][j] = f[i-1][j-1] - d + sum;
                }
                for (int j = 0; j <= k && j < i; ++j) f[i][0] = max(f[i][0], f[i-1][j]);
            }
            for (int i = 0; i <= k && i <= n; ++i) ans = max(ans, f[n][i]);
            printf("%lld\n", ans);
            return 0;
        }
    }
    if (c == 17 || c == 18) {// ri < li+1
        while (t--) {
            int n, m, k, d;
            scanf("%d%d%d%d", &n, &m, &k, &d);
            long long ans = 0;
            for (int i = 1; i <= m; ++i) {
                scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
                if (a[i].y <= k && (long long)d * a[i].y < a[i].v) ans += a[i].v - (long long)d * a[i].y;
            }
            printf("%lld\n", ans);
        }
        return 0;
    } else {
        while (t--) printf("0\n");
    }
    // while (t--) {
    //     int n, m, k, d;
    //     scanf("%d%d%d%d", &n, &m, &k, &d);
    //     long long ans = 0;
    //     int tot = 0;
    //     set<int> s;
    //     s.insert(0);
    //     for (int i = 1; i <= m; ++i) {
    //         scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
    //         s.insert(a[i].x), s.insert(a[i].x - a[i].y);
    //     }
    //     for (auto x : s) {
    //         mp[tot++] = x;
    //     }
    // }
    return 0;
}