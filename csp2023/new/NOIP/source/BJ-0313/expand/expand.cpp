#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;
int c, n, m, q;
int a[N], b[N];

/*
tooooo easy
I am farfar(luogu) remember me.
*/

bool chk(int a, int b, int c, int d) {
	if (a == b || c == d) return true;
	int x = a - b, y = c - d;
	if (x > 0 && y < 0) return true;
	if (x < 0 && y > 0) return true;
	return false;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++ ) scanf("%d", &b[i]);
	if (1) {
		if (chk(a[1], b[1], a[n], b[m])) cout << '0';
		else cout << '1';
		while (q -- ) {
			int x = a[1], y = b[1];
			int xx = a[n], yy = b[m];
			int cnt1, cnt2;
			cin >> cnt1 >> cnt2;
			while (cnt1 -- ) {
				int pos, v;
				cin >> pos >> v;
				if (pos == 1)	x = v;
				if (pos == n) xx = v;
			}
			while (cnt2 -- ) {
				int pos, v;
				scanf("%d%d", &pos, &v);
				if (pos == 1) y =v;
				if (pos == m) yy = v;
			}
			if (chk(x, y, xx, yy)) cout << '0';
			else cout << '1';
		}
	}
	return 0;
}
