#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int tot, now[N][2], st[N][2];
int f[N * 10];
inline int crt() {
	++tot;
	f[tot] = tot;
	return tot;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		tot = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		f[1] = crt();
		f[2] = crt();
		f[3] = crt();
		for (int i = 1; i <= n; i++) {
			st[i][0] = now[i][0] = crt();
			st[i][1] = now[i][1] = crt();
		}
		while (m--) {
			char v;
			int x;
			scanf(" %c%d", &v, &x);
			if (v == 'T') {
				now[x][0] = crt();
				now[x][1] = crt();
				f[now[x][0]] = 1;
				f[now[x][1]] = 2;
			} else if (v == 'F') {
				now[x][0] = crt();
				now[x][1] = crt();
				f[now[x][0]] = 2;
				f[now[x][1]] = 1;
			} else if (v == 'U') {
				now[x][0] = crt();
				now[x][1] = crt();
				f[now[x][0]] = 3;
				f[now[x][1]] = 3;
			} else {
				int y;
				scanf("%d", &y);
				int na = crt(), nb = crt();
				if (v == '+') {
					f[na] = find(now[y][0]);
					f[nb] = find(now[y][1]);
				} else {
					f[nb] = find(now[y][0]);
					f[na] = find(now[y][1]);
				}
				now[x][0] = na;
				now[x][1] = nb;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (find(now[i][0]) != find(st[i][0])) {
				f[find(now[i][0])] = find(st[i][0]);
			}
			if (find(now[i][1]) != find(st[i][1]))
				f[find(now[i][1])] = find(st[i][1]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			// #########################################
			// cerr << i << ' ' << now[i][0] << ' ' << now[i][1] << '\n';
			if (find(st[i][0]) == find(st[i][1])) {
				// cerr << t << ' ' << i << ' ' << now[i][0] << ' ' << now[i][1] << "!\n";
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
