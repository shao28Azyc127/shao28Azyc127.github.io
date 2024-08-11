#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;

int n, m, c, T;

struct node {
	int i, j;
	char sg;
}q[NR];
int a[NR], b[NR], ans, tot;
int lst[NR];

void check() {

	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 1; i <= m; i++) {
		char sg = q[i].sg;
		int x = q[i].i, y = q[i].j;
		
		if (sg == '+') a[x] = a[y];
		else if (sg == '-') {
			if (a[y] == 2) a[x] = 2;
			else a[x] = !a[y];
		}
		else if (sg == 'T') a[x] = 1;
		else if (sg == 'F') a[x] = 0;
		else if (sg == 'U') a[x] = 2;
	}	
	int cnt = 0, f = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) f = 0;
		if (a[i] == 2) cnt++;
	}
	for (int i = 1; i <= n; i++) a[i] = b[i];
	if (f == 0) return ;
	//cout << "yesyesyes";
	ans = min(ans, cnt);
	//for (int i = 1; i <= n; i++)
		//cout << b[i] << ' ';
	//cout << '\n';
	return ;
}

void dfs(int step) {
	if (step == n + 1) {
		//cout << "123124124314";
		check();
		//for (int i = 1; i <= n; i++) cout << a[i] << " ";
		//cout << '\n';
		return ;
	}
	a[step] = 0;
	dfs(step + 1);
	a[step] = 1;
	dfs(step + 1);
	a[step] = 2;
	dfs(step + 1);
}

void solve1() {
	while (T--) {
		cin >> n >> m;
		ans = 1e9;
		for (int i = 1; i <= m; i++) {
			cin >> q[i].sg;
			char sg = q[i].sg;
			if (sg == '+' || sg == '-')
				cin >> q[i].i >> q[i].j;
			else cin >> q[i].i;
		}
		tot = 0;
		dfs(1);
		//cout << tot << '\n';
		cout << ans << '\n';
	}
}

void solve2(){
	while (T--) {
		cin >> n >> m;
		ans = 0;
		for (int i = 1; i <= m; i++) {
			char sg;
			int x;
			cin >> sg >> x;
			if (sg == 'T') a[x] = 1;
			if (sg == 'F') a[x] = 0;
			if (sg == 'U') a[x] = 2;
		}		
		for (int i = 1; i <= n; i++)
			if (a[i] == 2) ans++;
		cout << ans << '\n';
	}
}

void solve3() {
	while (T--) {
		memset(lst, 0, sizeof(lst));
		cin >> n >> m;
		ans = 0;
		for (int i = 1; i <= n; i++) a[i] = 0;
		for (int i = 1; i <= n; i++) {
			char sg;
			int x, y;
			cin >> sg >> x;
			if (sg == '+') {
				cin >> y;
				lst[x] = y;
				a[x] = a[y];
			}
			else {
				a[x] = 2;
				lst[x] = x;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == 2) ans++;
		}
		cout << ans << '\n';
	}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> T;
	if (c == 1 || c == 2) solve1();
	if (c == 3 || c == 4) solve2();
	if (c == 5 || c == 6) solve3();
	return 0;
}