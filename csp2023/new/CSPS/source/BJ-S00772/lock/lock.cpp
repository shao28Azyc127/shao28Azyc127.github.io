#include <bits/stdc++.h>

using namespace std;
int n;
int a[10][10];
int ans;
int v[10];

bool f(int a, int b, int c, int d) {
	for(int i = 1; i <= 10; ++i) {
		a = (a + 1) % 10, b = (b + 1) % 10;
		if(a == c && b == d) return true;
	}
	return false;
}

bool chk() {
	for(int i = 1; i <= n; ++i) {
		int p1 = -1, p2 = -1, cnt = 0;
		for(int j = 1; j <= 5; ++j) {
			if(v[j] != a[i][j]) {
				++cnt;
				if(p1 == -1) p1 = j;
				else p2 = j;
			}
		}
		if(cnt == 0) return false;
		if(cnt == 2 && p1 + 1 != p2) return false;
		if(cnt == 2 && !f(a[i][p1], a[i][p2], v[p1], v[p2])) return false;
		if(cnt > 2) return false;
	}
	return true;
}

void dfs(int dep) {
	if(dep == 6) {
		if(chk() == true) ++ans;
		return;
	}
	for(int i = 0; i < 10; ++i) {
		v[dep] = i;
		dfs(dep + 1);
	}
}


int main() {

	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= 5; ++j) {
			cin >> a[i][j];
		}
	}
	dfs(1);
	cout << ans << '\n';

	cout.flush();
	return 0;
}