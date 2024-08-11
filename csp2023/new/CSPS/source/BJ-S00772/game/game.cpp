#include <bits/stdc++.h>

using namespace std;
const int base = 131;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2000005;
map<ull, int> mp;
int n, nd;
char s[N];
int stac[N], top;
ull num[N];					
ll f[N];
ll cnt[N][26];
ll ans;																							
																				
int getid(ull x) {
	if(mp.find(x) == mp.end()) mp[x] = ++nd;
	return mp[x];
}

int main() {

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; ++i) {
		if(top > 0 && s[stac[top]] == s[i]) {
			f[i] = f[stac[top] - 1] + 1;
			--top;
			cnt[getid(num[top])][s[i] - 'a'] = f[i - 1] + 1;
		}
		else {
			f[i] = cnt[getid(num[top])][s[i] - 'a'];
			stac[++top] = i, num[top] = num[top - 1] * base + s[i];
		}
		ans += f[i];
	}
	cout << ans << '\n';

	cout.flush();
	return 0;
}
