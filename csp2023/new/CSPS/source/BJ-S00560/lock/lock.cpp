#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vint> vvint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

map<vint, int> mp;


int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n = read();
	for (int qwq = 0; qwq < n; ++qwq) {
		vint a(5); for (int &k : a) k = read();
		mp[a] = -100000;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j <= 9; ++j) {
				vint b = a; b[i] = (b[i] + j) % 10; mp[b]++;
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j <= 9; ++j) {
				vint b = a; b[i] = (b[i] + j) % 10, b[i + 1] = (b[i + 1] + j) % 10; mp[b]++;
			}
		}
	}
	int as = 0;
	for (auto [a, b] : mp) if (b == n) as++;
	cout << as << '\n';
	return 0;
}