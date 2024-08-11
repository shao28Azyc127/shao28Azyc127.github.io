#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<string, string> PII;
const int N = 1e6 + 10;
int n;
pair<PII, pair<int, int> > all[N];
string _n[110];
vector<PII> s[110];
map<string, int> mp, m1, lenn, name;
map<string, int> m[110];
int cot = 0, cnt = 0, orz = 0;
	
int get_len(string a) {
	if (a == "byte") return 1;
	if (a == "int") return 4;
	if (a == "long") return 8;
	return 2;
}

int get(int pos) {
	int len = 0;
	for (int i = 0; i < s[pos].size(); i ++ ) len = max(len, get_len(s[pos][i].first));
	return len;
}

pair<int, int> nw(int len, string a) {
	int npos = all[cnt - 1].y.y, ll = get_len(a);
	npos += (ll - npos % ll) % ll;
	return make_pair(npos, npos + len - 1);
}

int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin >> n;
	while (n -- ) {
		int op;
		cin >> op;
		if (op == 1) {
			string a;
			int t;
			cin >> a >> t;
			mp[a] = ++ cot;
			int now = 0, mx = 0, farfar;
			while (t -- ) {
				string aa, bb;
				cin >> aa >> bb;
				s[cot].push_back(make_pair(aa, bb));
				farfar = get_len(aa);
				lenn[bb] = farfar;
				mx = max(mx, farfar), now += (farfar - now % farfar) % farfar;
				now += farfar - 1;
			}
			now += mx - farfar; 
			cout << now + 1 << " " << mx << endl;
		}
		else if (op == 2) {
			string a, b;
			cin >> a >> b;
			if (a == "short" || a == "long" || a == "int" || a == "byte") {
				cnt ++;
				all[cnt] = make_pair(make_pair(b, b), nw(get_len(a), a));
				m1[b] = cnt;
				lenn[b] = get_len(a);
				cout << all[cnt].y.x << endl;
			}
			else {
				int pos = mp[a], len = get(pos);
				name[b] = ++ orz;
				for (int i = 0; i < s[pos].size(); i ++ ) {
					string aaaaa = b + '.' + s[pos][i].second;
					m[orz][s[pos][i].second] = cnt + 1;
					cnt ++;
					all[cnt] = make_pair(make_pair(s[pos][i].second, aaaaa), nw((i == s[pos].size() - 1 ? len : get_len(s[pos][i].first)), s[pos][i].first));
					if (i == 0) {
						cout << all[cnt].y.x << endl;
					}
				}
			}
		}
		else if (op == 3) {
			string a;
			cin >> a;
			int pos = -1;
			for (int i = 0; i < a.size(); i ++ )
				if (a[i] == '.') pos = i; 
			if (pos == -1) {
				int k = m1[a];
				cout << all[k].y.x << endl;
			}
			else {
				string aa = a.substr(0, pos), bb = a.substr(pos + 1);
				int k = name[aa], z = m[k][bb];
				cout << all[z].y.x << endl;
			}
		}
		else {
			int pos;
			cin >> pos;
			for (int i = 1; i < cnt; i ++ ) 
				if (all[i].y.y >= pos) {
					if (all[i].y.x <= pos && all[i].y.x + lenn[all[i].x.x] - 1 >= pos) {
						cout << all[i].x.y << endl;
					}
					else puts("ERR");
					break;
				}
			if (all[cnt].y.y < pos) puts("ERR");
		}
	}
	return 0;
}
