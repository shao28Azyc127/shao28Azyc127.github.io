# include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 10;
int n;
int l[MAXN], dui[MAXN];
int sz[MAXN], st[MAXN];
vector <pair <int, int> > vec[MAXN];
vector <int> son[MAXN];
map <string, int> mp_name, mp_type;
string name2[MAXN];
int fa[MAXN], yname[MAXN];
int totname = 0, tottype = 0, totsize = 0, tot = 0;
int dingyi(int x, int y) {
	if (totsize % dui[x] != 0) totsize = (totsize / dui[x] + 1) * dui[x];
	l[++tot] = totsize;
	if (x <= 4) {
		for (int i = l[tot]; i <= l[tot] + sz[x] - 1; i++) {
			st[i] = tot;
		}
	totsize = l[tot] + sz[x];
	yname[tot] = y;
		return tot;
	}
	int id = tot;
	for (auto p : vec[x]) {
		son[id].push_back(tot + 1);
		fa[dingyi(p.first, p.second)] = id;
	}
	yname[id] = y;
	totsize = l[id] + sz[x];
	return id;
}
int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	memset(st, -1, sizeof st);
	cin >> n;
	mp_type["byte"] = ++tottype;
	dui[tottype] = sz[tottype] = 1;
	mp_type["short"] = ++tottype;
	dui[tottype] = sz[tottype] = 2;
	mp_type["int"] = ++tottype;
	dui[tottype] = sz[tottype] = 4;
	mp_type["long"] = ++tottype;
	dui[tottype] = sz[tottype] = 8;
	for (int i = 1; i <= n; i++) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			string s;
			cin >> s;
			int k;
			cin >> k;
			mp_type[s] = ++tottype;
			for (int j = 1; j <= k; j++) {
				string t, name;
				cin >> t >> name;
				if (!mp_name.count(name)) mp_name[name] = ++totname, name2[totname] = name;
				vec[tottype].push_back(make_pair(mp_type[t], mp_name[name]));
				dui[tottype] = max(dui[tottype], dui[mp_type[t]]);
				if (sz[tottype] % dui[mp_type[t]] != 0) {
					sz[tottype] = (sz[tottype] / dui[mp_type[t]] + 1) * dui[mp_type[t]];
				}
				sz[tottype] += sz[mp_type[t]];
			}
			if (sz[tottype] % dui[tottype] != 0) {
				sz[tottype] = (sz[tottype] / dui[tottype] + 1) * dui[tottype];
			}
			cout << sz[tottype] << " " << dui[tottype] << endl ;
		} else if (opt == 2) {
			string t, name;
			cin >> t >> name;
			if (!mp_name.count(name)) mp_name[name] = ++totname, name2[totname] = name;
			vec[0].push_back(make_pair(mp_type[t], mp_name[name]));
			int id = dingyi(mp_type[t], mp_name[name]);
			son[0].push_back(id);
			fa[id] = 0;
			cout << l[id] << endl ;
		} else if (opt == 3) {
			string s;
			cin >> s;
			s = s + '.';
			string name = "";
			int nod = 0, len = s.size(), lie = 0;
			for (int i = 0; i < len; i++) {
				if (s[i] != '.') {
					name = name + s[i];
					continue;
				}
				//cout << i << " " << nod << endl ;
				for (int j = 0; j < vec[lie].size(); j++) {
					if (vec[lie][j].second == mp_name[name]) {
						nod = son[nod][j];
						lie = vec[lie][j].first;
						//cout << "! " << nod << endl ;
						break;
					}
				}
				name = "";
			}
			cout << l[nod] << endl ;
		} else if (opt == 4) {
			int x;
			cin >> x;
			if (st[x] == -1) {
				cout << "ERR\n" ;
				continue;
			}
			string ans = "";
			int nod = st[x];
		//	cout << nod << " " << yname[nod] << " " << name2[yname[nod]] << endl ;
			while (nod) {
				ans = "." + name2[yname[nod]] + ans;
				nod = fa[nod];
			}
			for (int i = 1; i < ans.size(); i++) cout << ans[i] ;
			cout << endl ;
		}
	}
	return 0;
}