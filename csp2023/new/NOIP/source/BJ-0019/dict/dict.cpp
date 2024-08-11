//BJ-0019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = (s); i <= (t); ++i)
#define per(i, s, t) for(int i = (t); i >= (s); --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 3e3 + 5;

int n, m;
string str[N], st[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

	cin >> n >> m;
	rep(i, 1, n) {
		cin >> str[i];
		sort(str[i].begin(), str[i].end());
		st[i] = str[i];
		reverse(str[i].begin(), str[i].end());
	}
	string mi = *min_element(str + 1, str + n + 1);
	rep(i, 1, n) cout << (st[i] <= mi);
	cout << "\n";

	return 0;
}