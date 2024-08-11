#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Task {
    int x, y, v;

    Task(int a = 0, int b = 0, int c = 0) {
        x = a;
        y = b;
        v = c;
    }

    friend bool operator < (Task A, Task B) {
        return A.x < B.x || A.x == B.x && A.y < B.y;
    }
} Tk[100001];

int c, t, n, m, k, d;
long long dp[1001][1001];
long long v[100001];
long long dp2[100001][2];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for(int i = 1, x, y, v;i <= m;i++) {
            scanf("%d%d%d", &x, &y, &v);
            Tk[i] = Task(x, y, v);
        }
        if(c <= 9) {
            sort(Tk + 1, Tk + m + 1);
            memset(dp, 0x80, sizeof(dp));
            long long ans = dp[0][0];
            dp[0][0] = 0;
            for(int i = 1, t = 1;i <= n;i++) {
                dp[i][0] = dp[i - 1][0];
                long long vs = -d;
                for(int j = 1;j <= i && j <= k;j++) {
                    while(t <= m && Tk[t].x == i && Tk[t].y == j) vs += Tk[t++].v;
                    dp[i][0] = max(dp[i][0], dp[i - 1][j]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + vs);
                    ans = max(ans, dp[i][j]);
                }
            }
            printf("%lld\n", ans);
        } else if(c >= 15 && c <= 18) {
            long long ans = 0;
            for(int i = 1;i <= m;i++) {
                if(Tk[i].y > k) continue;
                v[i] = max(0LL, (long long) Tk[i].v - 1LL * d * Tk[i].y);
            }
            long long l = 0, r = 0, s = 0;
            for(int i = 1;i <= m;i++) {
                dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]);
                dp2[i][1] = dp2[i - 1][0];
                if(Tk[i].x - Tk[i].y <= Tk[i - 1].x) {
                    r++;
                    if(Tk[r].x - (Tk[l].x - Tk[l].y) > k) {
                        while(l <= r && Tk[r].x - (Tk[l].x - Tk[l].y) > k) l++;
                        if(l == r) {
                            r = l = i;
                            s = dp2[i - 1][0] + v[i];
                        } else if(l <= r) {
                            s = 0;
                            for(int j = l;j <= r;j++) {
                                s = max(s, max(dp2[j - 1][0], dp2[j - 1][1])) + v[j];
                            }
                        } else s = 0;
                    } else s = dp2[i][0] + v[i];
                } else r = l = i, s = dp2[i][0] + v[i];
                dp2[i][1] = s;
            }
            printf("%lld\n", max(dp2[m][0], dp2[m][1]));
        }
    }
    return 0;
}
