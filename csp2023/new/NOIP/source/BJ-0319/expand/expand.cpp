#include <bits/stdc++.h>
using namespace std;

const int NR = 5e5 + 10;

int c, n, m, q;
int mx = 0, my = 0;
int x[NR], y[NR];
int mxx, mxy, mnx = 1e9, mny = 1e9;
int tx[NR], ty[NR];

void copy() {
	for (int i = 1; i <= n; i++) tx[i] = x[i];
	for (int i = 1; i <= n; i++) ty[i] = y[i];
}

void back() {
	for (int i = 1; i <= n; i++) x[i] = tx[i];
	for (int i = 1; i <= m; i++) y[i] = ty[i];
}

void solve1() {
	if (mx != my) cout << 1;
	else cout << 0;
	copy();
	while (q--) {
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++) {
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		
		if (x[1] == y[1]) cout << 0;
		else cout << 1;
		back();
	}
	cout << '\n';
}


void solve2() {
	if (x[1] != y[1] && x[2] != y[2]) cout << 1;
	else cout << 0;
	copy();
	while (q--) {
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++) {
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		
		if (x[1] == y[1] || x[2] == y[2]) cout << 0;
		else {
			if (x[1] > y[1] && x[2] < y[2]) cout << 0;
			else if (x[1] < y[1] && x[2] > y[2]) cout << 0;
			else cout << 1;
		}
		back();
	}
	cout << '\n';
}

void solve3() {
	copy();
	
	if (x[1] > y[1] && x[n] < y[m]) cout << 0;
			else if (x[1] < y[1] && x[n] > y[m]) cout << 0;
			else {
				if (mxx > mxy && mnx < mny) cout << 0;
				else if (mxx < mxy && mnx > mny) cout << 0;
				else cout << 1;
			}
			
	while (q--) {
		mxx = 0, mnx = 1e9;
		mxy = 0, mny = 1e9;
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++) {
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		
		for (int i = 1; i <= n; i++) {
			mxx = max(mxx, x[i]);
			mnx = min(mnx, x[i]);
		}
		for (int i = 1; i <= m; i++)  {
			mxy = max(mxy, y[i]);
			mny = min(mny, y[i]);
		}
		
		if (x[1] == y[1] || x[n] == y[m]) cout << 0;
		else {
			if (x[1] > y[1] && x[n] < y[m]) cout << 0;
			else if (x[1] < y[1] && x[n] > y[m]) cout << 0;
			else {
				if (mxx > mxy && mnx < mny) cout << 0;
				else if (mxx < mxy && mnx > mny) cout << 0;
				else cout << 1;
			}
		}
		back();
	}
	cout << '\n';
}


int check() {
	int f = 0, ff = 0;
	// x < y
	if (n > m) {
		for (int i = 1; i <= n; i++) {
			int j = i;
			if (j > m) j = m;
			for (; j <= m; j++)
				if (x[i] < y[j]) {
					f = 1;
					break;
				}
			if (!f) return 0;
		}
		return 1;
	}
	else {
		for (int j = 1; j <= m; j++) {
			int i = j;
			if (i > n)  i = n;
			for (; i <= n; i++) {
				if (x[i] < y[j]) {
					f = 1;
					break;
				}
			}
			if (!f) return 0;
		}
		return 1;
	}
}

void solve4() {
	copy();
	int k = check();
	cout << k;
	while (q--) {
		//mxx = 0, mnx = 1e9;
		//mxy = 0, mny = 1e9;
		int kx, ky;
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++) {
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		
		for (int i = 1; i <= n; i++) {
			mxx = max(mxx, x[i]);
			mnx = min(mnx, x[i]);
		}
		for (int i = 1; i <= m; i++)  {
			mxy = max(mxy, y[i]);
			mny = min(mny, y[i]);
		}
		
		int tmp = check();
		cout << tmp;
		back();
	}
	cout << '\n';
}


int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		mx = max(mx, x[i]);
		mxx = mx;
		mnx = min(mnx, x[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> y[i];
		my = max(my, y[i]);
		mxy= my;
		mny = min(mny, y[i]);
	}
	
	if (c == 1) solve1();
	if (c == 2) solve2();
	else if (c <= 7) solve3();
	else solve4();
	
	return 0;
}