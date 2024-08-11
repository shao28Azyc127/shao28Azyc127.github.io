#include <bits/stdc++.h>

using namespace std;
int q, nd;
map<string, int> mp;
string s[105];

int getid(string na) {
	if(mp.find(na) == mp.end()) mp[na] = ++nd, s[nd] = na;
	return mp[na];
}

int ta[10000005];
int st[105];
int lst = -1;

int main() {

	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> q;
	while(q--) {
		int op;
		string t, na;
		int addr;
		cin >> op;
		if(op == 2) {
			cin >> t >> na;
			int x = getid(na), y;
			if(t == "byte") y = 1;
			else if(t == "short") y = 2;
			else if(t == "int") y = 4;
			else y = 8;
			for(int i = lst + 1; ; ++i) {
				if(i % y == 0) { 
					cout << i << '\n';
					for(int j = i; j < i + y; ++j) ta[j] = x;
					lst = i + y - 1, st[x] = i;
					break;
				}
			}
		}
		else if(op == 3) {
			cin >> na;
			cout << st[getid(na)] << '\n';
		}
		else {
			cin >> addr;
			if(ta[addr] == 0) cout << "ERR\n";
			else cout << s[ta[addr]] << '\n';
		}
	}

	cout.flush();
	return 0;
}