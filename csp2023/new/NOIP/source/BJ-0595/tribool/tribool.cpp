#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i <= int (b); i ++)

using namespace std;

const int Maxn = 3010;

int x[Maxn] = {};

namespace C3C4 {
	void solve() {
		int n, m;
		int ans = 0;
		cin >>n >>m;
		vector <char> x(n + 1);
		rep (i, 1, m){
			char opt;
			int tot;
			cin >>opt >>tot;
			//cout <<char(opt) <<tot <<endl;
			x[tot] = opt;
		}
		rep (i, 1, n) {
			if (x[i] == 'U')
				ans ++;
		}
		printf ("%d\n", ans);
	}
};

namespace C5C6 {
	struct Node {
		int fa;
		int val;
		int cyc;
	} x[Maxn];
	void solve() {
		//cout <<"solve  c5c6" <<endl;
		int n, m, cnt = 0;
		cin >>n >>m;
		rep (i, 1, m){
			char opt;
			cin >>opt;
			if (opt == 'U') {
				int tot;
				cin >>tot;
				x[tot].val = opt;
				cnt ++;
			} else {
				//opt == '+'
				int u, v;
				cin >>u >>v;
				x[u] = x[v];
			}
		}
		cout <<cnt;
		int ans = 0;
		rep (i, 1, n) {
			cout <<x[i].val <<" ";
			if (x[i].val == 'U')
				ans ++;
		}
		cout <<ans <<endl;
	}
};

namespace C1C2 {
	struct Opt {
		char opt;
		int u;
		int v;
	}o[Maxn];
	int x [15] = {-1, -1, -1, -1, -1, -1 ,-1, -1 ,-1 ,-1 ,-1};
	int xx[14] = {};
	void next() {
		int tot = 1;
		x[tot] ++;
		while (x[tot] == 2) {
			x[tot] = -1, x[tot + 1] ++;
			tot ++;
		}
	}
	void solve() {
		//cout <<"solve  c1c2" <<endl;
		int n, m;
		cin >>n >>m;
		rep (i, 1, m){
			char opt;
			int u, v;
			cin >>opt;
			if (opt == '+' || opt == '-')
				cin >>u >>v;
			else 
				cin >>u;
			o[i] = (Opt) {opt, u, v};
		}
		int nn = pow (3, 10);
		int ans = INT_MAX;
		rep (k, 1, nn) {
			rep (j, 1, 10)
				xx [j] = x[j];
			rep(i, 1, m){
				if (o[i].opt == '+')
					xx[o[i].u] = xx[o[i].v];
				if (o[i].opt == '-')
					xx[o[i].u] = -xx[o[i].v];
				if (o[i].opt == 'U')
					xx[o[i].u] = 'U';
				if (o[i].opt == 'F')
					xx[o[i].u] = 'F';
				if (o[i].opt == 'T')
					xx[o[i].u] = 'T';
			}
			cout <<"----";
			rep (j, 1, 10)
				cout <<xx[j]<<" ";
			int cnt = 0;
			rep(i, 1, n) {
				//cout <<xx[i] <<" ";
				if (xx[i] != x[i])
					goto nne;
				if (xx[i] == 0)
					cnt++;
			}
			cout <<endl;
			ans = max(ans, cnt);
			//rep(j, 1, n)
			//	cout <<x[j] <<" ";
			//cout <<endl;
			nne:
			next();
		}
		cout <<ans <<endl;
	}
};

int main () {
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	int c, T;
	scanf("%d %d", &c, &T);
	while (T --) {
		if (c == 1 || c == 2)
			C1C2::solve();
		if (c == 3 || c == 4) {
			C3C4::solve();
		} else if(c == 5 || c == 6){
			C5C6::solve();
		}
	}
	return 0;
}

/*
 * T = ~F | U = 0
 * F = ~T | T = 1
 * U = ~U | F = -1
*/
 
