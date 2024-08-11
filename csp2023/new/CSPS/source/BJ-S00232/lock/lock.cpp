#include <bits/stdc++.h>
using namespace std;
using Node = array<int, 5>;

int hsh(Node x) {
	int h = 0;
	for (int i = 0; i < 5; ++i) h = h * 10 + x[i];
	return h;
}

int n;
int cnt[100005];

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		Node x;
		for (int j = 0; j < 5; ++j) cin >> x[j];
		for (int j = 0; j < 5; ++j) {
			for (int k = 1; k < 10; ++k) {
				x[j] = (x[j] + k) % 10;
				++cnt[hsh(x)];
				x[j] = (x[j] - k + 10) % 10;
			}
			if (j + 1 == 5) break;
			for (int k = 1; k < 10; ++k) {
				x[j] = (x[j] + k) % 10;
				x[j + 1] = (x[j + 1] + k) % 10;
				++cnt[hsh(x)];
				x[j] = (x[j] - k + 10) % 10;
				x[j + 1] = (x[j + 1] - k + 10) % 10;
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 100000; ++i) if (cnt[i] == n) ++ans;
	
	cout << ans << endl;
	
	return 0;
}