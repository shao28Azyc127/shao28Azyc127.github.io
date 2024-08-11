#include <bits/stdc++.h>
using namespace std;

int a[100005], q[100005], b[100005], n, dp[100005], d, y[100005];

void ans1() {
	memset(dp, 0x7f, sizeof(dp));
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			int k = q[i] - q[j] - y[j];
			int h = k / d;
			if(k % d != 0) ++h;
			y[i] = h * d - (q[i] - q[j]);
			dp[i] = min(dp[i], dp[j] + h * b[j]);
		}
	}
	cout << dp[n];
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin >> n >> d;
    int minn = 2e9, minni = 1;
    for (int i = 1; i <= n - 1; ++i) {
    	cin >> a[i];
    	q[i + 1] = q[i] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if(b[i] < minn) {
			minn = b[i];
			minni = i;
		}
	}
	if(n <= 10000) ans1();
	else if(minni == 1) {
		int k = q[n] / d;
		if(q[n] % d != 0) k++;
		cout << k * b[1];
	} else {
		cout << 1;
	}
    return 0;
}