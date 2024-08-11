#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[100010], smax[100010], smin[100010];
multiset <char > st;
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	if(n == 1) return cout << 1, 0;
	if(m == 1) {
		for(int i = 1; i <= n; ++i) {
			bool ag = 1;
			for(int j = 1; j <= n; ++j) {
				if(j == i) continue;
				if(s[i] >= s[j]) {ag = 0; break;}
			}
			cout << (ag ? 1 : 0);
		}
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		st.clear();
		string str = "";
		for(int j = 0; j < m; ++j) st.insert(s[i][j]);
		for(auto it : st) str += it;
		smin[i] = str;
		reverse(str.begin(), str.end());
		smax[i] = str;
	}
	for(int i = 1; i <= n; ++i) {
		//cout << smin[i] << " " << smax[i] << endl;
		bool ag = 1;
		for(int j = 1; j <= n; ++j) {
			if(j == i) continue;
			if(smin[i] >= smax[j]) {ag = 0; break;}
		}
		cout << (ag ? 1 : 0);
	}
				
}
