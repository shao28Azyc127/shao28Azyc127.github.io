#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	long long a, b, c;
	cin >> t >> m;
	while(t--) {
		cin >> a >> b >> c;
		long long h = b * b - 4 * a * c;
		if(h < 0) {
			cout << "NO\n";
		} else {
			long long k = (sqrt(h) - b) / (2 * a);
			long long k2 = (-sqrt(h) - b) / (2 * a);
			cout << max(k, k2) << "\n";
		}
	}
    return 0;
}
