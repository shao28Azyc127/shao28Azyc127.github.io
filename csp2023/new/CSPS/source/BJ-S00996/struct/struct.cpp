#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 205;
int tot = 4;
ll sz[N] = {0, 1, 2, 4, 8}, bs[N] = {0, 1, 2, 4, 8};
vector<ll> pos[N]; // pos
vector<int> id[N];// stname
vector<string> stn[N];
map<string, int> m, nm[205];// nm:pos in id
ll to(ll x, ll y) {
	return (x / y + !!(x % y)) * y;
}
int sc(vector<ll> &pos, ll x) {
	int l = 0, r = pos.size() - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (pos[mid] <= x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}
int main() {
	/*
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	*/
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	m["byte"] = 1;
	m["short"] = 2;
	m["int"] = 3;
	m["long"] = 4;
	int n;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		//cerr << n << ' ' << op << ";\n";
		if (op == 1) {
			string s;
			int k;
			cin >> s >> k;
			m[s] = ++tot;
			for (int i = 0; i < k; i++) {
				string t, na;
				cin >> t >> na;
				id[tot].push_back(m[t]);
				nm[tot][na] = i;
				stn[tot].push_back(na);
				if (i) {
					pos[tot].push_back(to(pos[tot][i - 1] + sz[id[tot][i - 1]], bs[id[tot][i]]));
				} else {
					pos[tot].push_back(0);
				}
				bs[tot] = max(bs[tot], bs[id[tot][i]]);
			}
			sz[tot] = to(pos[tot][k - 1] + sz[id[tot][k - 1]], bs[tot]);
			//cerr << n << "qq\n";
			cout << sz[tot] << ' ' << bs[tot] << '\n';
		} else if (op == 2) {
			string t, na;
			cin >> t >> na;
			id[0].push_back(m[t]);
			int now = id[0].size() - 1;
			nm[0][na] = now;
			stn[0].push_back(na);
			if (now) {
				pos[0].push_back(to(pos[0][now - 1] + sz[id[0][now - 1]], bs[id[0][now]]));
			} else {
				pos[0].push_back(0);
			}
			cout << pos[0][now] << '\n';
		} else if (op == 3) {
			int now = 0;
			ll p = 0;
			string s;
			cin >> s;
			string cur;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '.') {
					int now2 = nm[now][cur];
					p += pos[now][now2];
					now = id[now][now2];
					cur = "";
				} else
					cur += s[i];
				//cerr << now << ' ' << i << ' ' << cur << "?\n";
			}
			int now2 = nm[now][cur];
			p += pos[now][now2];
			now = id[now][now2];
			//cerr << p << "?\n";
			cout << p << '\n';
		} else if (op == 4) {
			ll addr;
			cin >> addr;
			int now = 0;
			string res;
			while (1) {
				int p = sc(pos[now], addr);
				if (p == -1) {
					cout << "ERR\n";
					break;
				}
				//cerr << now << ' ' << addr << ' ' << p << ' ' << res << "!\n";
				addr -= pos[now][p];
				if (now)
					res += ".";
				res += stn[now][p];
				now = id[now][p];
				if (addr >= sz[now]) {
					cout << "ERR\n";
					break;
				}
				if (now > 0 && now < 5) {
					cout << res << '\n';
					break;
				}
				//cerr << p << "?\n";
			}
		}
	}
	return 0;
}
