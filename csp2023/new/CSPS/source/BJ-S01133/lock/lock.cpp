#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; ++i)
#define per(i, s, t) for(int i = t; i >= s; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 15;

int n;
int a[N][6], b[6], c[6];

bool check() {
	rep(i, 1, n) {
		rep(j, 1, 5) c[j] = (10 + b[j] - a[i][j]) % 10;
		int cc = 0;
		rep(j, 1, 5) cc += !c[j];
		if(cc == 4) continue;
		if(cc < 3) return 0;
		bool ok = 0;
		rep(j, 1, 4) if(c[j] && c[j] == c[j+1]) ok = 1;
		if(!ok) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);

	cin >> n;
	rep(i, 1, n) rep(j, 1, 5) cin >> a[i][j];

	int ans = 0;
	for(b[1] = 0; b[1] <= 9; ++b[1]) 
	for(b[2] = 0; b[2] <= 9; ++b[2]) 
	for(b[3] = 0; b[3] <= 9; ++b[3]) 
	for(b[4] = 0; b[4] <= 9; ++b[4]) 
	for(b[5] = 0; b[5] <= 9; ++b[5]) 
		if(check()) ++ans;

	cout << ans << "\n";

	return 0;
}