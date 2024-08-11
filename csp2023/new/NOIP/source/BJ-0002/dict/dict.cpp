#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 jiajia
struct node {
	int id;
	string s;
} a[6005];
bool operator<(node x, node y) {
	if (x.s == y.s) return x.id < y.id;
	else return x.s < y.s;
}
int ans[6005];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s; a[i].id = i;
		a[i + n].s = a[i].s; a[i + n].id = i + n;
		sort(a[i].s.begin(), a[i].s.end());
		sort(a[i + n].s.begin(), a[i + n].s.end());
		reverse(a[i + n].s.begin(), a[i + n].s.end());
	}
	sort(a + 1, a + 1 + n + n);
	int cnt = 0;
	for (int i = n + n; i >= 1; i--) {
		if (a[i].id > n) ++cnt;
		else {
			if (cnt == n) ans[a[i].id] = 1;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i];
	cout << '\n';
	return 0;
}