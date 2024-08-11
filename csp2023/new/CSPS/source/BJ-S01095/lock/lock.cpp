#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, e, ans, cnt;
map <pair<int, string>, bool> mp;
string res[100010];
void dfs(int a, int b, int c, int d, int e, int st, int op) {
	string s = to_string(a) + to_string(b) + to_string(c) + to_string(d) + to_string(e);
	if(mp[{op, s}]) return ;
	if(st) mp[{op, s}] = 1;
	if(op == 1 && st) res[++cnt] = s;
	if(st == 1) return ;
	for(int i = 0; i <= 9; ++i) {
		if(i != a) dfs(i, b, c, d, e, st + 1, op);
		if(i != b) dfs(a, i, c, d, e, st + 1, op);
		if(i != c) dfs(a, b, i, d, e, st + 1, op);
		if(i != d) dfs(a, b, c, i, e, st + 1, op);
		if(i != e) dfs(a, b, c, d, i, st + 1, op);
	}
	for(int i = 1; i <= 9; ++i) {
		dfs((a + i) % 10, (b + i) % 10, c, d, e, st + 1, op);
		dfs(a, (b + i) % 10, (c + i) % 10, d, e, st + 1, op);
		dfs(a, b, (c + i) % 10, (d + i) % 10, e, st + 1, op);
		dfs(a, b, c, (d + i) % 10, (e + i) % 10, st + 1, op);
	}
}
void dfs2(int a, int b, int c, int d, int e, int st, int op) {
	string s = to_string(a) + to_string(b) + to_string(c) + to_string(d) + to_string(e);
	if(mp[{op, s}]) return ;
	mp[{op, s}] = 1;
	ans++;
	if(op == 1) res[++cnt] = s;
	if(st == 1) return ;
	for(int i = 0; i <= 9; ++i) {
		if(i != a) dfs2(i, b, c, d, e, st + 1, op);
		if(i != b) dfs2(a, i, c, d, e, st + 1, op);
		if(i != c) dfs2(a, b, i, d, e, st + 1, op);
		if(i != d) dfs2(a, b, c, i, e, st + 1, op);
		if(i != e) dfs2(a, b, c, d, i, st + 1, op);
	}
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	/*if(n > 2 && n <= 8) {
		int ct = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a >> b >> c >> d >> e;
			dfs2(a, b, c, d, e, 0, i);
	    }
	    for(int i = 1; i <= cnt; ++i) {
			int fl = 1;
			for(int j = 1; j <= n; ++j) {
				if(!mp[{j, res[i]}]) {
					fl = 0;
					break;
				}
			}
			if(fl) ++ct;
		}
		cout << ct;
		return 0;
    }*/
	for(int i = 1; i <= n; ++i) {
		cin >> a >> b >> c >> d >> e;
		dfs(a, b, c, d, e, 0, i);
	}
	int ct = 0;
	for(int i = 1; i <= cnt; ++i) {
		int fl = 1;
		for(int j = 1; j <= n; ++j) {
			if(!mp[{j, res[i]}]) {
				fl = 0;
				break;
			}
		}
		if(fl) {
			++ct;
			//cout << res[i] << endl;
		}	
	}
	cout << ct;
	
}
