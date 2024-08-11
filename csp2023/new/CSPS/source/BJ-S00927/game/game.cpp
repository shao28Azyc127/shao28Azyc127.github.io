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
const ll B1 = 0606, B2 = 1018;
const ll P1 = 1004535809, P2 = 998244853;
unordered_map<ll, int> mp;
inline ll trans(pair<ll, ll> x) {
	return x.first * P2 + x.second;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s; cin >> s;
	s = " " + s;
	vector<pair<int, pair<ll, ll> > > vec;
	vec.push_back({0, {0, 0}});
	mp[trans(vec.back().second)]++;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		pair<int, pair<ll, ll> > tmp = vec.back();
		if (tmp.first == s[i]) vec.pop_back();
		else {
			tmp.first = s[i];
			tmp.second.first = (tmp.second.first * B1 + s[i]) % P1;
			tmp.second.second = (tmp.second.second * B2 + s[i]) % P2;
			vec.push_back(tmp);
		}
		ans += mp[trans(vec.back().second)];
		mp[trans(vec.back().second)]++;
	}
	cout << ans << '\n';
	return 0;
}