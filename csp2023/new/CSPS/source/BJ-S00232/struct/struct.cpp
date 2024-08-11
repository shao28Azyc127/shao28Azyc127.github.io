#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e2 + 10;

int n, tot = 0;
vector<pair<int, string>> e[N];
ll siz[N], mx[N], cur = 0;
map<string, int> mp, type;
map<string, ll> pos;
map<ll, string> var;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);	
	
	cin >> n;
	tot = 4;
	siz[1] = mx[1] = 1, siz[2] = mx[2] = 2;
	siz[3] = mx[3] = 4, siz[4] = mx[4] = 8;
	mp["byte"] = 1, mp["short"] = 2, mp["int"] = 3, mp["long"] = 4;
	while (n--) {
		int op;
		cin >> op;
		if (op == 1) {
			string s; int k;
			cin >> s >> k;
			mp[s] = ++tot;
			for (int i = 1; i <= k; ++i) {
				string t, n;
				cin >> t >> n;
				int v = mp[t];
				e[tot].push_back({v, n});
				mx[tot] = max(mx[tot], mx[v]);
				while (siz[tot] % mx[v]) ++siz[tot];
				siz[tot] += siz[v];
			}
			while (siz[tot] % mx[tot]) ++siz[tot];
			cout << siz[tot] << " " << mx[tot] << endl;
		}
		else if (op == 2) {
			string t, n;
			cin >> t >> n;
			int u = mp[t];
			while (cur % mx[u]) ++cur;
			cout << cur << endl;
			type[n] = u, pos[n] = cur;
			var[cur] = n;
			cur += siz[u];
		} else if (op == 3) {
			string s, n = "";
			cin >> s;
			int i = 0;
			for (; i < s.size() && s[i] != '.'; ++i) n += s[i];
			ll x = pos[n];
			int u = type[n];
			for (++i; i < s.size(); ++i) {
				n = "";
				for (; i < s.size() && s[i] != '.'; ++i) n += s[i];
				for (auto v: e[u]) {
					while (x % mx[v.first]) ++x;
					if (v.second == n) {
						u = v.first;
						break;
					}
					x += siz[v.first];
				}
			}
			cout << x << endl;
		} else {
			ll arr;
			cin >> arr;
			if (arr >= cur) {
				cout << "ERR" << endl;
				continue;
			}
			int u = 0; ll x = 0;
			string ans = "";
			for (auto v: var) {
				if (v.first > arr) break;
				x = v.first, u = type[v.second];
				ans = v.second;
			}
			int f = 1;
			for (; !e[u].empty() && f; ) {
				ans += '.';
				int nu, f2 = 0; string n;
				for (auto v: e[u]) {
					while (x % mx[v.first]) ++x;
					x += siz[v.first];
					nu = v.first, n = v.second;
					if (x > arr) { 
						if (x - siz[v.first] > arr) { f = 0; break;}
						x -= siz[v.first]; f2 = 1;
						break;
					}
				}
				if (!f2) f = 0;
				ans += n;
				u = nu;
			}
			if (f) cout << ans << endl;
			else cout << "ERR" << endl;
		}
	}
	
	return 0;
}