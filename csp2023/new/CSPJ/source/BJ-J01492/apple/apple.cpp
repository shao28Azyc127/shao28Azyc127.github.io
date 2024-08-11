#include <iostream>
#include <cstdio>
using namespace std;
bool a[1000000005];
int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	long long n;
	cin >> n;
	int cnt = 2;
	long long k = n;
	long long ans = 0;
	long long d = 0;
	while (k) {
		d++;
		cnt = 2;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) continue;
			if (cnt == 2) {
				cnt = 0;
				a[i] = 1;
				k--;
				if (i == n) ans = d;
			}
			else cnt++;
		}
	}
	cout << d << " " << ans;
	return 0;
}