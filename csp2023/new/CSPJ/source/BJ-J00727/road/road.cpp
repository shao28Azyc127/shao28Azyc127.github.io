#include <bits/stdc++.h>
using namespace std;
int a [100005], v [100005], arr [100005];
int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    int n, d;
    bool x = 1;
    int cnt = 0;
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v [i];
    for (int i = 1; i <= n; i++) cin >> a [i];
    for (int i = 1; i <= n; i++) {
		if (a [1] > a [i]) x = 0;
	}
	if (x == 1) {
		int s = 0;
		for (int i = 1; i < n; i++) {
			s += v [i];
		}
		if (s % d == 0) cout << s / d * a [1];
		else cout << (s / d + 1) * a [1];
		return 0;
	}
    for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a [j] < a [i]) {
				arr [i] = j;
				break;
			}
		}
	}
	int i = 1;
	while (i <= n) {
		int v0 = 0;
		for (int k = i; k < arr [i]; k++) v0 += v [i];
		cnt += v0 / d * a [i];
		if (arr [i] == 0 && i != n) break;
		i = arr [i];
	}
	int v1 = 0;
	for (int k = i; k < n; k++) v1 += v [i];
	cnt += v1 / d * a[i];
	cout << cnt;
    return 0;
}
