#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;

int c, T;
int n, m, k, d;

bool t[NR], tt[NR];

struct day {
	int x, y, v;
	bool operator < (const day &x) {return v > x.v;}
}a[NR];

bool check() {
	int f = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= i + k; j++) 
			if (!t[j]) f = 0;
		if (f && t[i + k + 1]) return false;
	}
	return true;
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m >> k >> d;
		for (int i = 1; i <= m; i++) {
			cin >> a[i].x >> a[i].y >> a[i].v;
			a[i].y = a[i].x - a[i].y + 1;
			swap(a[i].x, a[i].y);
		}
		sort(a + 1, a + 1 + m);
		int tmp = 0;
		for (int i = 1; i <= m; i++) {
			int l = a[i].y - a[i].x + 1;
			if (l > k) continue;
			for (int j = a[i].x; j <= a[i].y; j++) tt[i] = t[i];
			for (int j = a[i].x; j <= a[i].y; j++) t[i] = 1;
			
			if (!check()) {
				for (int j = a[i].x; j <= a[i].y; j++) t[i] = tt[i];
				continue;
			}
			//cout << i << "\n";
			tmp = tmp - l * d;
			//cout << tmp << " ";
			tmp += a[i].v;
			//cout << tmp << " ";
		}
		cout << max(tmp, 0) << '\n';
	}
	return 0;
}