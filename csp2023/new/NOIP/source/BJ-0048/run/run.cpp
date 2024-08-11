#include<bits/stdc++.h>
using namespace std;

const int MR = 1e5;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int sid, T, n, m, K, an;
int a2[MR + 5];
long long ans, D, v1[1005][1005], v2[MR + 5][105], dp1[1005][1005], dp2[MR + 5][105];

struct A {
    int x, y, v;
} a[MR + 5];

void work() {
    cin >> n >> m >> K >> D;
    an = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].v;
        a2[++an] = a[i].x;
    }
    sort(a2 + 1, a2 + an + 1);
    an = unique(a2 + 1, a2 + an + 1) - a2 - 1;
    if(sid <= 9) {
        memset(v1, 0, sizeof(v1));
        for(int i = 1; i <= m; i++) {
            int p = lower_bound(a2 + 1, a2 + an + 1, a[i].x) - a2;
            if(a[i].y <= K) {
                v1[p][a[i].y] += a[i].v;
            }
        }
        for(int i = 1; i <= an; i++) {
            for(int j = 1; j <= K; j++) {
                v1[i][j] += v1[i][j - 1];
            }
        }
        memset(dp1, -0x3f, sizeof(dp1));
        for(int j = 0; j <= min(K, a2[1]); j++) {
            dp1[1][j] = v1[1][j] - D * j;
        }
        for(int i = 2; i <= an; i++) {
            long long mx = -inf;
            for(int j = 0; j <= K; j++) {
                mx = max(mx, dp1[i - 1][j]);
            }
            for(int j = 0; j <= K; j++) {
                if(j < a2[i] - a2[i - 1]) {
                    dp1[i][j] = mx + v1[i][j] - D * j;
                }
                else {
                    dp1[i][j] = dp1[i - 1][j - (a2[i] - a2[i - 1])] + v1[i][j] - D * (a2[i] - a2[i - 1]);
                }
            }
        }
        ans = -inf;
        for(int j = 0; j <= K; j++) {
            ans = max(ans, dp1[an][j]);
        }
        cout << ans << '\n';
    }
    else if(sid >= 15 && sid <= 16) {
        memset(v2, 0, sizeof(v2));
        for(int i = 1; i <= m; i++) {
            int p = lower_bound(a2 + 1, a2 + an + 1, a[i].x) - a2;
            if(a[i].y <= K) {
                v2[p][a[i].y] += a[i].v;
            }
        }
        for(int i = 1; i <= an; i++) {
            for(int j = 1; j <= K; j++) {
                v2[i][j] += v2[i][j - 1];
            }
        }
        memset(dp2, -0x3f, sizeof(dp2));
        for(int j = 0; j <= K; j++) {
            dp2[1][j] = v2[1][j] - D * j;
        }
        for(int i = 2; i <= an; i++) {
            long long mx = -inf;
            for(int j = 0; j <= K; j++) {
                mx = max(mx, dp2[i - 1][j]);
            }
            for(int j = 0; j <= K; j++) {
                if(j < a2[i] - a2[i - 1]) {
                    dp2[i][j] = mx + v2[i][j] - D * j;
                }
                else {
                    dp2[i][j] = dp2[i - 1][j - (a2[i] - a2[i - 1])] + v2[i][j] - D * (a2[i] - a2[i - 1]);
                }
            }
        }
        ans = -inf;
        for(int j = 0; j <= K; j++) {
            ans = max(ans, dp2[an][j]);
        }
        cout << ans << '\n';
    }
    else if(sid >= 17 && sid <= 18) {
        ans = 0;
        for(int i = 1; i <= m; i++) {
            if(a[i].y <= K && a[i].v - D * a[i].y >= 0) {
                ans += a[i].v - D * a[i].y;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> sid >> T;
    while(T--) work();

    return 0;
}