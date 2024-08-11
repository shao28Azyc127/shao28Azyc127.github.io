#include <bits/stdc++.h>
using namespace std;
#define ll long long
void file() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
}
map <string, int > base, addr, elem;
map <int, string > use;
int last;
void solve() {
	int op; cin >> op;
	if(op == 1) {
		string s, tp, name; int k, ans = 0, tot = 0;
		cin >> s >> k;
		for(int i = 1; i <= k; ++i) {
			cin >> tp >> name;
			for(int j = addr[s] + 1; ; ++j) {
				if(j % base[tp] == 0) {
					addr[s] = j;
					break;
				}
			}
			elem[name] = addr[s];
			use[elem[name]] = name;
			for(int i = elem[name]; i <= elem[name] + base[tp] - 1; ++i) use[elem[name]] = name;
			//elem[name] += base[tp] - 1;
			addr[s] += base[tp] - 1;
			ans = max(ans, base[tp]);
			tot += base[tp];
		}
		base[s] = addr[s];
		cout << addr[s] + 1 << " " << ans << endl;
	}else if(op == 2) {
		string s, x; cin >> s >> x;
		if(!last) {
			cout << 0 << endl;
			use[0] = use[1] = use[2] = use[3] = use[4] = use[5] = use[6] = use[7] = x;
		}
		else cout << last + 1 << endl;
		elem[x] = last + 1;
		for(int i = elem[x]; i <= elem[x] + addr[s] - 1; ++i) use[i] = x;
		last += addr[s] - 1;
		
	}else if(op == 3) {
		string s, str = ""; cin >> s;
		cout << elem[s] << endl;
	}else {
		int pos; cin >> pos;
		if(use[pos] != "") cout << use[pos] << endl;
		else cout << "ERR" << endl;
	}
		
	
	
}
int main() {
	file();
	base["byte"] = 1, base["short"] = 2, base["int"] = 4, base["long"] = 8;
	addr["long"] = 8;
	int T; cin >> T;
	while(T--) solve();
}
