#include <bits/stdc++.h>
using namespace std;

int c, t;

const int N = 1e5 + 10;

int n, m;
int type[N];
int sgn[N], val[N];

int fa[N << 1], vis[N << 1];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
void merge(int x, int y) { fa[getfa(x)] = getfa(y);}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			type[i] = 0;
			sgn[i] = 0, val[i] = i;
		}
		
		while (m--) {
			char v;
			int x, y;
			cin >> v >> x;
			if (v == 'F') type[x] = 1, sgn[x] = 0, val[x] = 0;
			else if (v == 'T') type[x] = 1, sgn[x] = 0, val[x] = 1;
			else if (v == 'U') type[x] = 1, sgn[x] = 0, val[x] = 2;
			else {
				cin >> y;
				val[x] = val[y], type[x] = type[y];
				if (v == '+') sgn[x] = sgn[y];
				else sgn[x] = !sgn[y];
			}
		}
		
		for (int i = 1; i <= n; ++i) fa[i] = i, vis[i] = 0;
		for (int i = 1; i <= n; ++i) {
			if (type[i] == 1 && val[i] == 2) vis[i] = 1;
			else if (type[i] == 0) merge(i, val[i]);
		}
		
		int ans = 0;
		for (int i = 1; i <= n; ++i) vis[getfa(i)] |= vis[i];
		for (int i = 1; i <= n; ++i) {
			vis[i] = vis[getfa(i)];
			if (vis[getfa(i)]) ++ans;
		}
		
		for (int i = 1; i <= (n << 1); ++i) fa[i] = i;
		for (int i = 1; i <= n; ++i) if (!vis[i] && type[i] == 0) {
			if (sgn[i]) merge(i, val[i] + n), merge(i + n, val[i]);
			else merge(i, val[i]), merge(i + n, val[i] + n);
		} 
		for (int i = 1; i <= (n << 1); ++i) vis[i] = 0;
		for (int i = 1; i <= n; ++i) if (getfa(i) == getfa(i + n)) vis[getfa(i)] = 1;
		for (int i = 1; i <= n; ++i) if (vis[getfa(i)] || vis[getfa(i + n)]) ans++;
		
		cout << ans << "\n";
	}
	
	return 0;
}