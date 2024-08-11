#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; ++i)
#define per(i, s, t) for(int i = t; i >= s; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 5;

int n;
char s[N];
int las[N][26];
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	cin >> n;
	cin >> (s+1);
	ll ans = 0;
	rep(i, 1, n) las[i][s[i]-'a'] = i;
	rep(i, 1, n) {
		if(las[i-1][s[i]-'a']) {
			int j = las[i-1][s[i]-'a'];
			f[i] = f[j-1] + 1;
			memcpy(las[i], las[j-1], sizeof las[i]);
			las[i][s[i]-'a'] = i;
		}
		ans += f[i];
	}
	cout << ans << "\n";

	return 0;
}