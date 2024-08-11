#include<bits/stdc++.h>
using namespace std;
const int MX = 1005;
typedef long long LL;
LL c, t, n, m, k, d, cnt[MX][MX], dp[MX], flag[MX][MX];
struct Node {
    LL x, y, v;
} a[MX];
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> c >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        memset(flag, 0, sizeof(flag));
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i++) {
            cin >> a[i].x >> a[i].y >> a[i].v;
            flag[a[i].x - a[i].y + 1][a[i].x] += a[i].v;
        }
        for (int l = 1; l <= n; l++)
            for (int i = 1; i + l - 1 <= n; i++) {
                int j = i + l - 1;
                cnt[i][j] = cnt[i + 1][j] + cnt[i][j - 1] - cnt[i + 1][j - 1] + flag[i][j];
            }
        for (int i = 1; i <= n; i++) {
            if (i * 1ll <= k) dp[i] = cnt[1][i] - i * d;
            for (int j = 0; j <= min(k, 1ll * i - 1); j++)
                dp[i] = max(dp[i], dp[i - j - 1] + cnt[i - j + 1][i] - j * d);
        }
        cout << dp[n] << endl;
    }
    return 0;
}