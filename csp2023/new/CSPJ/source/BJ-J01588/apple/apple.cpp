#include <bits/stdc++.h>
using namespace std;
#define ll long long
set <int > s, s2;
int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	ll n, cnt = 0, ans; cin >> n;
	/*if(n == 8) cout << "5 5";
	else if(n == 9) cout << " "*/
	for(int i = 1; i <= n; ++i) s.insert(i);
	while(s.size()) {
		++cnt;
		int ct = 1;
		for(auto i : s) {
			if(ct % 3 == 1) {
				if(i == n) ans = cnt;
			}
			else s2.insert(i);
			ct++;
		}
		s.clear();
		for(auto i : s2) {
			//cout << i << " ";
			s.insert(i);
		}
		s2.clear();
    }
    cout << cnt << " " << ans;
}
