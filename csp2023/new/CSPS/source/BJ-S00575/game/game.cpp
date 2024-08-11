#include<bits/stdc++.h>
using namespace std;
int n, ans=0;
string s;
stack<char> sta;
int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = i+1; j < s.length(); j++) {
			string ss = "";
			for (int k = i; k <= j; k++) ss += s[k];
			while (sta.size()) sta.pop();
			for (int k = 0; k < ss.length(); k++) {
				if (sta.empty()) sta.push(ss[k]);
				else if (sta.top() == ss[k]) sta.pop();
				else sta.push(ss[k]);
			}
			if (sta.empty() && ss != "") ans++;
		}
	cout << ans << '\n';
	return 0;
}