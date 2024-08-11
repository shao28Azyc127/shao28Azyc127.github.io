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

const int N = 2000006;
int n;
ll ans;
char s[N];
int tr[N][26], rt = 1, cnt = 1, su[N];


int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(); scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		int c = s[i] - 'a';
		su[rt]++;
		if (!tr[rt][c]) tr[rt][c] = ++cnt;
		int nt = tr[rt][c];
		tr[rt][c] = 0;
		tr[nt][c] = rt;
		rt = nt;
		ans += su[rt];
	}
	cout << ans << '\n';
	return 0;
}