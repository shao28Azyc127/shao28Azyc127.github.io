#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int cnt = 0, where = 0;
bool done = false;

signed main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	while (n) {
		cnt++;
		if (!done && n % 3 == 1) where = cnt, done = true;
		n -= ceil(n / 3.0);
	}
	cout << cnt << " " << where << endl;
	return 0;
}