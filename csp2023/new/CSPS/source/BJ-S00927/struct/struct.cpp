#include <bits/stdc++.h>
#define ll long long
#define y1 jiajia
using namespace std;
void read(int &x) {
	int f = 1; x = 0; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
map<string, int> mp;
struct son {
	int id;
	ll dt;
	string nm;
};
struct node {
	string nm;
	vector<son> vec;
	ll mem, rest;
	// memory, start mem, restriction on memory
} a[205];
int tot = 0;
struct nd {
	int id;
	ll stmem;
	string nm;
};
vector<nd> Mem;
int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	++tot; a[tot].nm = "byte";  a[tot].mem = 1; a[tot].rest = 1; mp[a[tot].nm] = tot;
	++tot; a[tot].nm = "short"; a[tot].mem = 2; a[tot].rest = 2; mp[a[tot].nm] = tot;
	++tot; a[tot].nm = "int";   a[tot].mem = 4; a[tot].rest = 4; mp[a[tot].nm] = tot;
	++tot; a[tot].nm = "long";  a[tot].mem = 8; a[tot].rest = 8; mp[a[tot].nm] = tot;
	ll nwmemory = 0;
	while (n--) {
		int op; cin >> op;
		if (op == 1) {
			string s, t; int k;
			cin >> s >> k;
			++tot; a[tot].nm = s; mp[s] = tot;
			ll nwmem = 0, mxres = 0;
			for (int i = 0; i < k; i++) {
				cin >> t >> s;
				son tq; tq.nm = s; tq.id = mp[t];
				mxres = max(mxres, a[tq.id].rest);
				if (nwmem % a[tq.id].rest == 0) {
					tq.dt = nwmem;
				} else {
					tq.dt = nwmem - (nwmem % a[tq.id].rest) + a[tq.id].rest;
				}
				nwmem = tq.dt + a[tq.id].mem;
				a[tot].vec.push_back(tq);
			}
			if (nwmem % mxres != 0) {
				nwmem = nwmem - (nwmem % mxres) + mxres;
			}
			a[tot].mem = nwmem;
			a[tot].rest = mxres;
			cout << a[tot].mem << ' ' << a[tot].rest << '\n';
		} else if (op == 2) {
			string s, n; cin >> s; cin >> n;
			nd tq; tq.id = mp[s]; tq.nm = n;
			if (nwmemory % a[tq.id].rest == 0) tq.stmem = nwmemory;
			else {
				tq.stmem = nwmemory - (nwmemory % a[tq.id].rest) + a[tq.id].rest;
			}
			nwmemory = tq.stmem + a[tq.id].mem;
			Mem.push_back(tq);
			cout << tq.stmem << '\n';
		} else if (op == 3) {
			string s;
			cin >> s;
			vector<string> vec;
			s += ".";
			string t;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '.') {
					vec.push_back(t);
					t = "";
				} else t += s[i];
			}
			reverse(vec.begin(), vec.end());
			ll mem = 0; int id = -1;
			for (nd x : Mem) {
				if (x.nm == vec.back()) {
					id = x.id;
					mem = x.stmem;
					vec.pop_back();
					break;
				}
			}
			while (!vec.empty()) {
				for (son x : a[id].vec) {
					if (x.nm == vec.back()) {
						id = x.id;
						mem = mem + x.dt;
						vec.pop_back();
						break;
					}
				}
			}
			cout << mem << '\n';
		} else {
			ll addr; cin >> addr;
			int id = -1;
			string s = "";
			for (nd x : Mem) {
				if (x.stmem <= addr && x.stmem + a[x.id].mem - 1 >= addr) {
					id = x.id;
					s += x.nm;
					addr -= x.stmem;
				}
			}
			//cout << id << '\n';
			if (id == -1) {cout << "ERR\n"; goto end;}
			while (id > 4) {
				bool bj = 0;
				for (son x : a[id].vec) {
					//cout << x.id << ' ' << x.dt << ' ' << x.dt + a[x.id].mem - 1 << ' ' << addr << '\n';
					if (x.dt <= addr && x.dt + a[x.id].mem - 1 >= addr) {
						id = x.id;
						s += ".";
						s += x.nm;
						addr -= x.dt;
						bj = 1;
						//cout << id << '\n';
						break;
					}
				}
				if (!bj) {cout << "ERR\n"; goto end;}
			}
			cout << s << '\n';
			end:;
		}
	}
	return 0;
}