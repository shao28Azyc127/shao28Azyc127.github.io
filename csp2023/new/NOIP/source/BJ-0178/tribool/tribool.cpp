#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, m;
struct tri {
	bool v, p;
} num[100005], df[100005];
void st(tri &x, char c) {
	if (c == 'U') x.p = 1;
	else {
		x.p = 0;
		x.v = c == 'T';
	}
}
int proa[100005], prob[100005];
char proc[100005];
void pd() {
	for (int i = 1; i <= m; i++) {
	    if (proc[i] == '+') {
			st(num[proa[i]], (num[prob[i]].p) ? 'U' : ((num[prob[i]].v) ? 'T' : 'F'));
		} else if (proc[i] == '-') {
			st(num[proa[i]], (num[prob[i]].p) ? 'U' : ((num[prob[i]].v) ? 'F' : 'T'));
		} else {
			st(num[proa[i]], proc[i]);
		}
    }
}
int ans = 0x3f3f3f3f;
void dfs(int x) {
	if (ans == 0) return; // jianzhi
	if (x == n) {
		for (int i = 1; i <= n; i++) {
			num[i] = (tri){df[i].v, df[i].p};
		}
		pd();
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (df[i].p != num[i].p || (df[i].p == num[i].p && df[i].v != num[i].v && df[i].p == 0)) {
				return;
			}
			res += df[i].p;
		}
		ans = min(ans, res);
		return;
	}
	st(df[x + 1], 'U');
	dfs(x + 1);
	st(df[x + 1], 'T');
	dfs(x + 1);
	st(df[x + 1], 'F');
	dfs(x + 1);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			char s; int a;
			cin >> s >> a;
			proc[i] = s; proa[i] = a;
			if (s == '+' || s == '-') {
				int b;
				cin >> b;
				prob[i] = b;
			} 
	    }
	    ans = 0x3f3f3f3f;
	    dfs(0);
	    cout << ans << endl;
	}
    return 0;
}
