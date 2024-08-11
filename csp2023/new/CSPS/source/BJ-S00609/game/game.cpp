#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)

using namespace std;

const int N = 805;

int n;
string s;
bool f[N][N];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n; cin >> s;
    s = ' ' + s;
    rep(i, 1, n - 1) if(s[i] == s[i + 1]) f[i][i + 1] = 1;
    for(int len = 4; len <= n; len += 2)
	rep(l, 1, n - len + 1) {
	    int r = l + len - 1;
	    if(s[l] == s[r] && f[l + 1][r - 1]) f[l][r] = 1;
	    else {
		for(int k = l + 1; k <= r; k += 2)
		    if(f[l][k] && f[k + 1][r]) {
			f[l][r] = 1;
			break;
		    }
	    }
	}
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n) if(f[i][j]) {
	// cout << i << ' ' << j << '\n';
	++ans;
    }
    cout << ans << '\n';
    return 0;
}
