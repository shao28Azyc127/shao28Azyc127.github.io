#include <cstdio>
#include <bitset>
using namespace std;

typedef long long LL;

int c, t, n, m, k, d, l[115], r[115], v[115];
LL ans;
bitset<20> s[20];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d %d", &c, &t);
    LL cnt;
    int x, y;
    bool flag;
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &v[i]);
            x--;
            r[i] = x;
            if (x - y + 1 < 0) {
                l[i] = 0;
            }
            else {
                l[i] = x - y + 1;
            }
        }
        // for (int i = 0; i < m; i++) {
        //     printf("(%d, %d, %d)\n", l[i], r[i], v[i]);
        // }
        for (int i = 0; i < 1 << n; i++) {
            // printf("%d\n", i);
            x = 0;
            y = -1;
            cnt = 0;
            flag = 1;
            for (int j = 0; j < n; j++) {
                s[j].reset();
            }
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    cnt -= d;
                    y++;
                }
                else {
                    if (y - x + 1 > k) {
                        flag = 0;
                        break;
                    }
                    for (int p = x; p <= y; p++) {
                        for (int q = p; q <= y; q++) {
                            s[p][q] = 1;
                        }
                    }
                    // printf("(%d, %d)\n", x, y);
                    x = j + 1;
                    y = j;
                }
            }
            if (!flag || y - x + 1 > k) {
                continue;
            }
            // printf("(%d, %d)\n", x, y);
            for (int p = x; p <= y; p++) {
                for (int q = p; q <= y; q++) {
                    s[p][q] = 1;
                }
            }
            for (int j = 0; j < m; j++) {
                if (s[l[j]][r[j]]) {
                    cnt += v[j];
                }
            }
            if (ans < cnt) {
                // printf("%lld\n", cnt);
                // printf("%d\n", i);
                for (int p = 0; p < n; p++) {
                    for (int q = p; q < n; q++) {
                        if (s[p][q]) {
                            // printf("(%d, %d)\n", p, q);
                        }
                    }
                }
                ans = cnt;
            }
        }
        printf("%lld\n", ans);
        ans = 0;
    };
    return 0;
}