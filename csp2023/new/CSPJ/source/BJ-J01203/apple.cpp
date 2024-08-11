#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	int cnt = 0, ans = 0, i = 0;
	while (n) {
		i ++;
		if (n % 3 == 1 && !ans) ans = i;
		n -= (n + 2) / 3;
	}
	cout << i << " " << ans << endl;
	return 0;
}
