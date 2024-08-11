#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vint> vvint;

ll read() {
	ll a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

map<string, int> sty;
struct node {
	int ty;
	string id;
	ll adr, siz;
};
struct typ {
	string name;
	int dq;
	ll siz;
	vector<node> a;
	map<string, int> sid;
} s[110];
int cnt;

void cre(string name) {
	sty[name] = ++cnt;
	s[cnt].name = name;
}
ll UP(ll a, int b) {
	while (a % b) ++a;
	return a;
}
void add(int i, string t, string n) {
	int ty = sty[t];
	s[i].dq = max(s[i].dq, s[ty].dq);
	s[i].sid[n] = s[i].a.size();
	node A; A.ty = ty; A.id = n; A.siz = s[ty].siz;
	if (s[i].a.size()) A.adr = UP(s[i].a.back().adr + s[i].a.back().siz, s[ty].dq);
	else A.adr = 0;
	s[i].a.push_back(A);
	s[i].siz = UP(A.adr + A.siz, s[i].dq);
}

int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cre("1");
	cre("byte"); s[cnt].dq = 1, s[cnt].siz = 1;
	cre("short"); s[cnt].dq = 2, s[cnt].siz = 2;
	cre("int"); s[cnt].dq = 4, s[cnt].siz = 4;
	cre("long"); s[cnt].dq = 8, s[cnt].siz = 8; 
	int T = read();
	while (T--) {
		int op = read();
		if (op == 1) {
			string n; cin >> n; cre(n);
			int k = read();
			while (k--) { string t, n; cin >> t >> n; add(cnt, t, n); }
			cout << s[cnt].siz << ' ' << s[cnt].dq << '\n';
		} else if (op == 2) {
			string t, n; cin >> t >> n;
			add(1, t, n);
			cout << s[1].a[s[1].sid[n]].adr << '\n';
		} else if (op == 3) {
			string st, nw; cin >> st; st += ".";
			vector<string> qw;
			for (char c : st) {
				if (c == '.') qw.push_back(nw), nw = "";
				else nw += c;
			}
			int w = 1; ll adr = 0;
			for (string st : qw) {
				int i = s[w].sid[st];
				adr += s[w].a[i].adr;
				w = s[w].a[i].ty;
			}
			cout << adr << '\n';
		} else if (op == 4) {
			ll adr = read();
			int w = 1;
			vector<string> qw;
			while (1) {
				if (s[w].a.size() == 0) {
					if (adr < s[w].siz) {
						for (int i = 0; i < qw.size(); ++i) cout << qw[i] << (".\n"[i + 1 == qw.size()]);
					} else cout << "ERR\n";
					break;
				}
				int pos = s[w].a.size() - 1;
				for (int i = 1; i < s[w].a.size(); ++i) if (s[w].a[i].adr > adr) { pos = i - 1; break; }
				qw.push_back(s[w].a[pos].id);
				adr -= s[w].a[pos].adr;
				w = s[w].a[pos].ty;
			}
		}
	}
	return 0;
}