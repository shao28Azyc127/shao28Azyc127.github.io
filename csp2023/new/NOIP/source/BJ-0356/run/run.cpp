#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, m, k, d, s[100005], dp[1005][1005];
struct lim{
    int x, y, v;
    lim(){
    }
    lim(int _x, int _y, int _v){
        x = _x;
        y = _y;
        v = _v;
    }
    inline bool operator <(const lim _m)const{
        if(x == _m.x){
            return y < _m.y;
        }
        return x < _m.x;
    }
}a[100005];
signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> m >> k >> d;
        for(int i = 1;i <= m;i++){
            cin >> a[i].x >> a[i].y >> a[i].v;
        }
        sort(a + 1, a + m + 1);
        s[0] = 0;
        for(int i = 1;i <= m;i++){
            s[i] = s[i - 1] + a[i].v;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 0;i < n;i++){
            int l = lower_bound(a + 1, a + m + 1, lim(i + 1, 0, 0)) - a;
            int r = l - 1;
            for(int j = 0;j <= min(k, i);j++){
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
                while(a[r + 1].x == i + 1 && a[r + 1].y <= j + 1){
                    r++;
                }
                dp[i + 1][j + 1] = dp[i][j] - d + s[r] - s[l - 1];
            }
        }
        int ans = 0;
        for(int j = 0;j <= min(k, n);j++){
            ans = max(ans, dp[n][j]);
        }
        cout << ans << "\n";
    }
    return 0;
}
