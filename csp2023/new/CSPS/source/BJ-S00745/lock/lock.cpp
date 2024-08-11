#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, ans;
struct lock {
	int a[6];
} input[15];
bool judge(int ind, int a, int b, int c, int d, int e) {
	int arr[6] = {0, a, b, c, d, e};
	int cnt = 0;
	for (int i = 1; i <= 5; ++i) {
		if (arr[i] != input[ind].a[i]) ++cnt;
		// cerr << arr[i] << endl;
	}
	// cerr << cnt << endl;
	if (cnt == 1) return true;
	if (cnt == 2) {
		int diff1 = 0, diff2 = 0;
		for (int i = 1; i <= 5; ++i) {
			if (arr[i] != input[ind].a[i]) {
				if (diff1) diff2 = i;
				else diff1 = i;
			}
		}
		if (abs(diff1 - diff2) != 1) return false;
		// cerr << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
		// cerr << diff1 << ' ' << diff2 << endl;
		// if (((arr[diff1] - input[ind].a[diff1] + 10) % 10 == (arr[diff2] - input[ind].a[diff2] + 10) % 10) || ((input[ind].a[diff1] - arr[diff1] + 10) % 10 == (input[ind].a[diff2] - arr[diff2] + 10) % 10)) {
		// 	// cerr << (arr[diff1] - input[ind].a[diff1] + 10) % 19 <<  ' ' << (arr[diff2] - input[ind].a[diff2] + 10) % 10 << ' ' << (input[ind].a[diff1] - arr[diff1] + 10) % 10 << ' ' << (input[ind].a[diff2] - arr[diff2] + 10) % 10 << endl;
		// }
		return ((arr[diff1] - input[ind].a[diff1] + 10) % 10 == (arr[diff2] - input[ind].a[diff2] + 10) % 10) || ((input[ind].a[diff1] - arr[diff1] + 10) % 10 == (input[ind].a[diff2] - arr[diff2] + 10) % 10);
	}
	return false;
}
signed main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cin >> input[i].a[j];
		}
	}
	// cerr << judge(1, 1, 2, 1, 1, 5) << endl;
	for (int a = 0; a <= 9; ++a) {
		for (int b = 0; b <= 9; ++ b) {
			for (int c = 0; c <= 9; ++c) {
				for (int d = 0; d <= 9; ++d) {
					for (int e = 0; e <= 9; ++e) {
						bool flag = true;
						for (int i = 1; i <= n; ++i) {
							if (!judge(i, a, b, c, d, e)) {
								flag = false; break;
							}
						}
						ans += flag;
						// if (flag) {
						// 	cerr << a << b << c << d << e << endl;
						// }
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}