#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define pb push_back

using namespace std;

const int N = 105;
const int M = 2e6 + 5;

struct str {
    string tname;
    int a = 0, s;
    vector<string> v;
} st[N];

int n, cnt, tot;
map<string, int> to, id, ps;
string pos[M], typ[N], nm[N];

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    to["byte"] = 1;
    to["short"] = 2;
    to["int"] = 4;
    to["long"] = 8;

    cin >> n;
    while(n--) {
	int op; cin >> op;
	if(op == 1) {
	    int k;
	    ++cnt;
	    cin >> st[cnt].tname >> k;
	    id[st[cnt].tname] = cnt;
	    rep(i, 1, k) {
		cin >> typ[i] >> nm[i];
		st[cnt].a = max(st[cnt].a, to[typ[i]]);
	    }
	    int nw = 1;
	    while(nw <= k) {
		if(st[cnt].v.size() % to[typ[nw]] == 0) {
		    rep(i, 1, to[typ[nw]]) st[cnt].v.pb(nm[nw]);
		    ++nw;
		}
		else st[cnt].v.pb("ERR");
	    }
	    while(st[cnt].v.size() % st[cnt].a != 0) st[cnt].v.pb("ERR");
	    st[cnt].s = st[cnt].v.size();

	    cout << st[cnt].s << ' ' << st[cnt].a << '\n';
	}
	else if(op == 2) {
	    string tp, nam;
	    cin >> tp >> nam;

	    if(to.find(tp) != to.end()) {
		while(tot % to[tp] != 0) pos[tot++] = "ERR";

		cout << tot << '\n';

		ps[nam] = tot;
		rep(i, 1, to[tp]) pos[tot++] = nam;
		continue;
	    }
	    
	    int pid = id[tp];

	    while(tot % st[pid].a != 0) pos[tot++] = "ERR";

	    cout << tot << '\n';
	    ps[nam] = tot;
	    
	    for(string s : st[pid].v) {
		if(s == "ERR") {
		    pos[tot++] = s;
		    continue;
		}
		string nw = nam + "." + s;
		if(ps.find(nw) == ps.end()) ps[nw] = tot;
		pos[tot++] = nw;
	    }
	    while(tot % st[pid].a != 0) pos[tot++] = "ERR";
	}
	else if(op == 3) {
	    string s; cin >> s;
	    cout << ps[s] << '\n';
	}
	else {
	    int x; cin >> x;
	    if(x >= tot) cout << "ERR\n";
	    else cout << pos[x] << '\n';
	}
    }
    return 0;
}
