#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; ++i)
#define per(i, s, t) for(int i = t; i >= s; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 105;

int q, tt;
map<string, int> mem;
ll siz[N], mx[N];
vector<pair<pair<int, string>, ll>> adj[N];
ll pos0;

void init(string str, int sz) {
	int t = ++tt;
	mem[str] = tt;
	siz[tt] = mx[tt] = sz;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);

	cin >> q;
	init("byte", 1);
	init("short", 2);
	init("int", 4);
	init("long", 8);
	while(q--) {
		int op; cin >> op;
		if(op == 1) {
			string str; int k;
			cin >> str >> k;
			int t = ++tt;
		   	mem[str] = t;
			adj[t].resize(k);
			ll pos = 0;
			for(auto& v : adj[t]) {
				string type, name;
				cin >> type >> name;
				int id = mem[type];
				mx[t] = max(mx[t], mx[id]);
				if(pos % mx[id]) {
					pos += mx[id] - pos % mx[id];
				}
				v = mp(mp(id, name), pos);
				pos += siz[id];
			}
			siz[t] = pos;
			if(siz[t] % mx[t]) siz[t] += mx[t] - siz[t] % mx[t];
			cout << siz[t] << " " << mx[t] << "\n";
		} else if(op == 2) {
			string type, name; cin >> type >> name;
			int id = mem[type];
			if(pos0 % mx[id]) {
				pos0 += mx[id] - pos0 % mx[id];
			}
			cout << pos0 << "\n";
			adj[0].emplace_back(mp(id, name), pos0);
			pos0 += siz[id];
		} else if(op == 3) {
			string word; cin >> word;
			int p = 0;
			ll pos = 0;
			int id = 0;
			while(p < word.size()) {
				string cur = "";
				while(p < word.size() && word[p] != '.') cur += word[p++];
				++p;
				for(const auto& v : adj[id]) if(v.fi.se == cur) {
					pos += v.se;
					id = v.fi.fi;
					break;
				}
			}
			cout << pos << "\n";
		} else if(op == 4) {
			ll x; cin >> x;
			int id = 0;
			string ans = "";
			while(1) {
				if(adj[id].empty()) break;
				int j = -1;
				for(int k = 0; k < adj[id].size(); ++k) if(adj[id][k].se <= x) {
					j = k;
				}
				if(adj[id][j].se + siz[adj[id][j].fi.fi] <= x) {
					break;
				}
				if(id) ans += ".";
				ans += adj[id][j].fi.se;
				x -= adj[id][j].se;
				id = adj[id][j].fi.fi;
			}
			if(1 <= id && id <= 4) cout << ans << "\n";
			else cout << "ERR" << "\n";
		}
	}

	return 0;
}