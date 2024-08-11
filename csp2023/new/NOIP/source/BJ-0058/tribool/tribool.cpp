#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;
const int N = 100005, D = 800000;
int subID, T, nd;
int n, m;
int lst[N];
int fa[N * 16];
map<pii, int> id;
int val[N * 16];
int a[N * 16];

int find(int u) {
	return (fa[u] == u ? u : fa[u] = find(fa[u]));
}

void merge(int u, int v) {
	int rtu = find(u), rtv = find(v);
	if(rtu != rtv) fa[rtu] = rtv;
}

int get(int i, int t) {
	if(id.find(mp(i, t)) == id.end()) id[mp(i, t)] = ++nd;
	return id[mp(i, t)];
}

int main() {

	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> subID >> T;
	for(int i = 1; i <= 1600000; ++i) fa[i] = i;
	while(T--) {
		memset(lst, 0, sizeof lst);
		memset(val, -1, sizeof val);
		memset(a, -1, sizeof a);
		id.clear(); nd = 0;
		cin >> n >> m;
		int x, y;
		for(int t = 1; t <= m; ++t) {
			char op;
			int i, j;
			cin >> op;
			if(op == '+') { // x[i] = x[j]
				cin >> i >> j;
				x = get(j, t - 1), y = get(i, t);
				merge(x, y);
				merge(x + D, y + D);
				if(lst[j] != t - 1) {
					x = get(j, lst[j]), y = get(j, t - 1);
					merge(x, y);
					merge(x + D, y + D);
				}
				lst[j] = t - 1;
				lst[i] = t;
			} 
			else if(op == '-') { // x[i] = !x[j]
				cin >> i >> j;
				x = get(j, t - 1), y = get(i, t);
				merge(x + D, y);
				merge(x, y + D);
				if(lst[j] != t - 1) {
					x = get(j, lst[j]), y = get(j, t - 1);
					merge(x, y);
					merge(x + D, y + D);
				}
				lst[j] = t - 1;
				lst[i] = t;
			}
			else {
				cin >> i;
				x = get(i, t);
				if(op == 'F') val[x] = 0;
				if(op == 'T') val[x] = 1;
				if(op == 'U') val[x] = 2;
				lst[i] = t;
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(lst[i] != m) {
				x = get(i, lst[i]), y = get(i, m);
				merge(x, y);
				merge(x + D, y + D);
			}
		}
		for(int i = 1; i <= n; ++i) {
			x = get(i, m), y = get(i, 0);
			merge(x, y);
			merge(x + D, y + D);
		}
		for(int i = 1; i <= nd; ++i) {
			if(val[i] != -1) {
				a[find(i)] = val[i];
				if(val[i] == 2) a[find(i + D)] = 2;
			}
		}
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			if(find(get(i, 0) + D) == find(get(i, m)) || a[find(get(i, 0))] == 2) {
				++res;
			}
		}
		cout << res << '\n';
		for(int i = 1; i <= nd; ++i) {
			fa[i] = i, fa[i + D] = i + D;
		}
	}

	cout.flush();
	return 0;
}