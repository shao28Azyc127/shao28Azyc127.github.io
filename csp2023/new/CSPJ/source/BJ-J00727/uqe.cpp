#include <bits/stdc++.h>
using namespace std;
int a [5005], b [5005], c [5005];
int gs (int a, int b) {
	int n = 1;
	for (int i = 2; i <= max (a, b); i++) {
		while (a % i == 0 && b % i == 0) {
			a /= i;
			b /= i;
			n *= i;
		}
	}
	return n;
}
int main () {
	freopen ("uqe.in", "r", stdin);
        freopen ("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	for (int i = 1; i <= T; i++) {
		cin >> a [i] >> b [i] >> c [i];
	}
	
	for (int k = 1; k <= T; k++) {
		if (b [k] * b [k] < 4 * a [k] * c [k]) cout << "NO" << endl;
		else {
			int d = b [k] * b [k] - 4 * a [k] * c [k], d1, d2, dr;
			if (sqrt (d) * sqrt (d) == d) {
				d1 = sqrt(d);
				d2 = 0;
				dr = 0;
			} else {
				d2 = 1;
				dr = 1;
				for (int i = 2; d > 1; i++){
					int m = 0;
					while (d % i == 0) {
						m++;
						d /= i;
					}
					if (m >= 2) {
						for (int j = 1; j <= m / 2; j++) {
							d1 *= i;
						}
					}
					if (m % 2 == 1) dr *= i;
				}
			}
			int x1p, x1q, x2p, x2q, xr;
			if (d2 == 0 && dr == 0) {
				x1p = d1 - b [k];
				x1q = 2 * a [k];
				int s = gs (x1p, x1q);
				x1p /= s;
				x1q /= s;
				if (x1q < 0) x1p *= -1;
				if (x1q == 1) cout << x1p;
				else cout << x1p << '/' << x1q;
			} else {
				x1p = -1 * b [k];
				x1q = 2 * a [k];
				int s1 = gs (x1p, x1q);
				x1p /= s1;
				x1q /= s1;
				if (x1q < 0) x1p *= -1;
				if (x1q == 1) cout << x1p << '+';
				else if (x1p != 0) cout << x1p << '/' << x1q << '+';
				x2p = d2;
				xr = dr;
				x2q = 2 * a [k];
				int s2 = gs (x1p, x1q);
				x2p /= s2;
				x2q /= s2;
				if (x2q < 0) x2p *= -1;
				if (x2p == 1 && x2q == 1) cout << "sqrt(" << xr << ')';
				else if (x2q == 1) cout << x2q << "*sqrt(" << xr << ')';
				else if (x2p == 1) cout << "sqrt(" << xr << ")/" << x2q;
				else cout << x2p << "*sqrt(" << xr << ")/" << x2q;
			}
			cout << endl;
		}
	}
	return 0;
}
