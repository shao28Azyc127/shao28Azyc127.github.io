#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
bool dp[805][805];
string a;
signed main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> a;
    memset(dp, 0, sizeof(dp));
    for(int i = 1;i <= n;i++){
        dp[i][i - 1] = 1;
    }
    for(int t = 2;t <= n;t += 2){
        for(int l = 1;l <= n - t + 1;l++){
            int r = l + t - 1;
            dp[l][r] |= ((a[l - 1] == a[r - 1]) & dp[l + 1][r - 1]);
            for(int k = l + 1;k < r;k += 2){
                dp[l][r] |= (dp[l][k] & dp[k + 1][r]);
            }
            ans += dp[l][r];
        }
    }
    cout << ans << "\n";
	return 0;
}
