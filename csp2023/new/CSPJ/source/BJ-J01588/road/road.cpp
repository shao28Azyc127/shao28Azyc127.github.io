#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, d, a[100010], v[100010], p[100010], ans, Min = 1e18, tot, Mi = 1e18, sum;
void dfs(int x, ll sum, int oil, int pos) {
	if(x == n) {
		Min = min(Min, sum);
		return ;
	}
	if(pos + oil * d >= p[x + 1] && oil) dfs(x + 1, sum, oil - 1, pos + d);
	if(pos >= p[x]) {
		if(pos + oil * d < p[x + 1]) {
			int cnt = 0, i;
			if((p[x + 1] - pos) % d == 0) i =  (p[x + 1] - pos) / d;
			else i = (p[x + 1] - pos) / d + 1;
			for(;i <= 10; ++i) {
				dfs(x + 1, sum + i * a[x], oil + i, pos + i * d);
			}
		}else {
			int cnt = 0;
			dfs(x + 1, sum, oil - 1, pos + d);
			for(int i = 1; i <= 10; ++i) {
				dfs(x + 1, sum + i * a[x], oil + i, pos + i * d);
			}
		}
    }
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1; i < n; ++i) cin >> v[i], tot += v[i];
	for(int i = 2; i <= n; ++i) p[i] = p[i - 1] + v[i];
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] < Mi) Mi = i;
	}
	if(Mi == 1) {
		if(tot % d == 0) cout << tot / d * a[1];
		else cout << tot / d * a[1] + 1;
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << Min;
}
