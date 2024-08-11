#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const int N = 3005;
char s[N], mn[N], mx[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		mn[i] = 'z', mx[i] = 'a';
		for (int j = 0; j < m; ++j) mn[i] = min(mn[i], s[j]), mx[i] = max(mx[i], s[j]);
	}
	for (int i = 0; i < n; ++i) {
		int g = 1;
		for (int j = 0; j < n && g; ++j) if (i != j) {
			if (mn[i] >= mx[j]) g = 0;
		}
		cout << g;
	}
	cout << '\n';
	
	return 0;
}