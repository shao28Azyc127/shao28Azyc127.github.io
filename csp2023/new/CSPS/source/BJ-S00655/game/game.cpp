#include<cstdio>
#include<iostream>
#include<cstring>
using namespace  std;
const int N = 1e4 + 5;
typedef long long ll;
ll dp[N][N];
ll c[N][N];
int n;
char s[N];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n; 
    cin >> (s + 1);

    ll ans = 0;
    for(int len  = 2; len <= n; len += 1) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if(s[r] == s[l] && (l + 1 == r || dp[l+1][r-1]) ) {
                dp[l][r] += 1;
                c[l][r] = 1;
            }
            int pos = -1;
            ll t = 0 ;
            for(int k = l; k < r; k++) {
                // left & right ok
                t = max(t, dp[l][k] + dp[k+1][r] + c[l][k] * c[k+1][r]);
                if(c[l][k] && c[k+1][r]) {
                    c[l][r] = c[l][k] + c[k+1][r];
                }
            }

            dp[l][r] += t;
            ans = max(ans, dp[l][r]);
        }
    }
    cout << ans << endl;
    return 0;
}