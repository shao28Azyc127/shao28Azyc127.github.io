#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const int N = 500005;
int c, n, m, q;


void suo(vint &a) {
	int n = a.size();
	int mx = -1, mn = 2e9, px = 0, pn = 0;
	vint b, c;
	for (int i = 0; i < n; ++i) {
		if (mx < a[i]) mx = a[i], px = i;
		if (mn > a[i]) mn = a[i], pn = i;
	}
	if (mx == mn) { a = vint{a[0]}; return; }
	if (pn > px) swap(pn, px);
	b.push_back(a[max(px, pn)]);
	b.push_back(a[min(px, pn)]);
	c.push_back(a[min(px, pn)]);
	c.push_back(a[max(px, pn)]);
	vint pmx = a, pmn = a;
	for (int i = 1; i < pn; ++i) pmx[i] = max(pmx[i], pmx[i - 1]), pmn[i] = min(pmn[i], pmn[i - 1]);
	for (int i = pn - 1; i >= 0; ) {
		if (b.back() < b[b.size() - 2]) {
			b.push_back(pmx[i]);
			while (i >= 0 && pmx[i] == b.back()) --i;
		} else {
			b.push_back(pmn[i]);
			while (i >= 0 && pmn[i] == b.back()) --i;
		}
	}
	pmx = a, pmn = a;
	for (int i = n - 2; i > px; --i) pmx[i] = max(pmx[i], pmx[i + 1]), pmn[i] = min(pmn[i], pmn[i + 1]);
	for (int i = px + 1; i < n; ) {
		if (c.back() < c[c.size() - 2]) {
			c.push_back(pmx[i]);
			while (i < n && pmx[i] == c.back()) ++i;
		} else {
			c.push_back(pmn[i]);
			while (i < n && pmn[i] == c.back()) ++i;
		}
	}
	
	reverse(b.begin(), b.end()); b.pop_back(); b.pop_back();
	a = b; a.insert(a.end(), c.begin(), c.end());
}

int sol(vint &x, vint &y) {
	if (x[0] > y[0]) x.swap(y);
//	cout << '\n';
//	for (int i : x) cout << i << ' '; cout << '\n';
//	for (int i : y) cout << i << ' '; cout << '\n';
	if (x[0] == y[0] || x.back() == y.back() || x.back() > y.back()) return 0;
	suo(y);
	if (y.size() == 1) { for (int i : x) if (y[0] <= i) return 0; return 1; }
	suo(x);
//	for (int i : x) cout << i << ' '; cout << '\n';
//	for (int i : y) cout << i << ' '; cout << '\n';
	if (y[0] > y.back()) reverse(y.begin(), y.end()), reverse(x.begin(), x.end());
	
	if (8 <= c && c <= 14) {
		int p = 0;
		for (int i : x) {
			if (y[p] <= i) return 0;
			while (p + 1 < y.size() && y[p + 1] > i) ++p;
		}
		return p + 1 == y.size();
	} else {
		vint a(y.size()), b(y.size());
		a[0] = 1;
		for (int i : x) {
			for (int j = 0; j < y.size(); ++j) b[j] = (i < y[j]) && ((j && b[j - 1]) || a[j]);
			a.swap(b);
			b = vint(y.size());
		}
		return a.back();
	}
}


int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	vint x(n), y(m);
	for (int &i : x) i = read();
	for (int &i : y) i = read();
	vint rx = x, ry = y;
	cout << sol(rx, ry);
	while (q--) {
		rx = x, ry = y;
		int kx = read(), ky = read();
		while (kx--) { int p = read(), v = read(); rx[p - 1] = v; }
		while (ky--) { int p = read(), v = read(); ry[p - 1] = v; }
		cout << sol(rx, ry);
	}
	cout << '\n';
	
	return 0;
}