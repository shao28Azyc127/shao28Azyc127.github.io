#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 jiajia
void read(int &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
}
int n, m, k, d; 
inline int gt(int x) {
	return (x % (k + 1) + (k + 1)) % (k + 1);
}
const int MAXM = 12000005;
struct node {
	int ls, rs;
	ll mx, tag;
	ll a0;
} a[MAXM];
bool hd[MAXM];
int tot = 0;
ll D;
int newnode() {
	++tot;
	a[tot].ls = a[tot].rs = 0;
	a[tot].mx = a[tot].tag = 0;
	a[tot].a0 = hd[tot] = 0;
	return tot;
}
void pd(int rt, int l, int r) {
	if (hd[rt]) {
		if (!a[rt].ls) a[rt].ls = newnode();
		if (!a[rt].rs) a[rt].rs = newnode();
		a[a[rt].ls].tag = 0; a[a[rt].rs].tag = 0;
		hd[a[rt].ls] = hd[a[rt].rs] = 1;
		int mid = (l + r) >> 1;
		a[a[rt].ls].a0 = a[rt].a0; a[a[rt].rs].a0 = (mid - l + 1) * D + a[rt].a0;
		a[a[rt].ls].mx = a[a[rt].ls].a0; a[a[rt].rs].mx = a[a[rt].rs].a0;
		a[rt].a0 = 0; hd[rt] = 0;
	}
	if (a[rt].tag != 0) {
		if (!a[rt].ls) a[rt].ls = newnode();
		if (!a[rt].rs) a[rt].rs = newnode();
		a[a[rt].ls].mx += a[rt].tag;
		a[a[rt].ls].tag += a[rt].tag;
		a[a[rt].rs].mx += a[rt].tag;
		a[a[rt].rs].tag += a[rt].tag;
		a[rt].tag = 0;
	}
}
void up(int rt) {a[rt].mx = max(a[a[rt].ls].mx, a[a[rt].rs].mx);}
void add(int &rt, int l, int r, int ql, int qr, ll k) {
	if (ql > qr) return;
	if (!rt) rt = newnode();
	if (ql <= l && qr >= r) {
		a[rt].tag += k;
		a[rt].mx += k;
		return;
	}
	int mid = (l + r) >> 1;
	pd(rt, l, r);
	if (ql <= mid) add(a[rt].ls, l, mid, ql, qr, k);
	if (qr > mid) add(a[rt].rs, mid + 1, r, ql, qr, k);
	up(rt);
}
void modify(int &rt, int l, int r, int ql, int qr, ll a0) {
	//cout << "MODIFY" << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << a0 << ' ' << d << '\n';
	if (ql > qr) return;
	if (!rt) rt = newnode();
	if (ql <= l && qr >= r) {
		a[rt].tag = 0;
		a[rt].a0 = a0 + (l - ql) * D; 
		hd[rt] = 1;
		a[rt].mx = a[rt].a0;
		return;
	}
	int mid = (l + r) >> 1;
	pd(rt, l, r);
	if (ql <= mid) modify(a[rt].ls, l, mid, ql, qr, a0);
	if (qr > mid) modify(a[rt].rs, mid + 1, r, ql, qr, a0);
	up(rt);
}
ll get(int &rt, int l, int r, int t) {
	if (!rt) rt = newnode();
	//cout << rt << ' ' << l << ' ' << r << ' ' << a[rt].mx << ' ' << a[rt].a0 << ' ' << a[rt].d << '\n';
	if (l == r) return a[rt].mx;
	int mid = (l + r) >> 1;
	pd(rt, l, r);
	if (t <= mid) return get(a[rt].ls, l, mid, t);
	else return get(a[rt].rs, mid + 1, r, t);
}
struct nd {
	int x, y, v;
} pp[100005];
bool operator<(nd x, nd y) {
	return x.x < y.x;
}
ll inf = 10000000000000000ll;
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t; read(c); read(t);
	while (t--) {
		read(n); read(m); read(k); read(d);
		tot = 0;
		for (int i = 1; i <= m; i++) {
			read(pp[i].x); read(pp[i].y); read(pp[i].v);
		}
		D = -d;
		++m;
		pp[m].x = n; pp[m].y = 1; pp[m].v = 0;
		sort(pp + 1, pp + 1 + m);
		ll dt = 0; 
		// dp[0] == dp[i][dt]
		// dp[j - dt] == dp[i][j]
		int rt = 0;
		ll lst = 0;
		add(rt, 0, k, 1, k, -inf);
		for (int i = 1; i <= m; i++) {
			lst = dt;
			dt = pp[i].x;
			ll mx = a[rt].mx;
			ll w = gt(-dt);
			if (dt != lst) {
				if (dt - lst > k) {
					modify(rt, 0, k, w, k, mx);
					modify(rt, 0, k, 0, w - 1, mx - (k - w + 1) * d);
				} else {
					ll l = gt(dt - lst - dt), r = gt(k - dt);
					//cerr << l << ' ' << r << "$" << '\n';
					if (r >= l) {
						add(rt, 0, k, l, r, (dt - lst) * (-d));
						modify(rt, 0, k, r + 1, k, mx);
						modify(rt, 0, k, 0, l - 1, mx - (k - (r + 1) + 1) * d);
					} else {
						//add(rt, 0, k, r + 1, l - 1, (dt - lst) * d);
						add(rt, 0, k, 0, k, (dt - lst) * (-d));
						modify(rt, 0, k, r + 1, l - 1, mx);
					}
				}
			}
			/*
			for (int j = 0; j <= k; j++) cout << get(rt, 0, k, gt(j - dt)) << ' ';
			cout << '\n';
			*/
			if (pp[i].y <= k) {
				ll l = gt(pp[i].y - dt), r = gt(k - dt);
				if (r >= l) {
					add(rt, 0, k, l, r, pp[i].v);
				} else {
					add(rt, 0, k, r + 1, l - 1, -pp[i].v);
					add(rt, 0, k, 0, k, pp[i].v);
				}
			}
			/*
			cout << dt << '\n';
			for (int j = 0; j <= k; j++) cout << get(rt, 0, k, gt(j - dt)) << ' ';
			cout << '\n';
			*/
		}
		cout << a[rt].mx << '\n';
	}
	return 0;
}