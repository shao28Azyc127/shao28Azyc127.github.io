#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
	int ff = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') x ^= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') ff = ff * 10 + ch - 48, ch = getchar();
	return x ? -ff : ff;
}
ll n, m, k, d, cas, ans = -1e9; 
struct node {
	int need, val;
}a[100010];
void dfs(ll day, ll hp, ll last) {
	if(day >= n) {
		ans = max(ans, hp);
		return ;
	}
	if(a[day].need && last >= a[day].need) hp += a[day].val;
	if(last == k) dfs(day + 1, hp, 0);
	else {
		dfs(day + 1, hp, 0);
		dfs(day + 1, hp - d, last + 1);
	}
}
void solve() {
	cin >> n >> m >> k >> d;
	ans = -1e9;
	for(int i = 1, x; i <= m; ++i) cin >> x >> a[x].need >> a[x].val;
	//if(cas <= 2) {
		dfs(0, 0, 0);
		cout << ans << endl;
	//}
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int T; cin >> cas >> T;
	while(T--) solve();
}
