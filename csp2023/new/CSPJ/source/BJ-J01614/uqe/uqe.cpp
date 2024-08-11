#include<bits/stdc++.h>

using namespace std;

int gcd (int n, int m) {
	if (n > m) {
		return (gcd(m, n));
	}
	if (m % n == 0) {
		return sqrt(n * n);
	}
	if (m == 1 || n == 1) {
		return 1;
	}
	return gcd(m % n, n);
}

int main() {
	freopen("uqe.in","r", stdin);
	freopen("uqe.out","w", stdout);
	int a, b, c;
	int n, m;
	cin >> n >> m;
       for (int i = 0; i < n; i++) {
       		cin >> a >> b>> c;
		int q = b * b - 4 * a * c;
 		if (q < 0) {
			cout << "NO" << endl;
		} else {
			int x1 = -b + sqrt(q);
			int x2 = -b - sqrt(q);
			if (x2 > x1) {
				int t = x1;
				x1 = x2;
				x2 = t;
			}
			if (a < 0) {
				x1 = - x1;
				a= -a;
			}
			if (x1 % (2 * a) == 0) {
				cout << x1 / 2 / a << endl;
			} else {
				cout << x1 / gcd(x1, 2 * a)  << '/' << 2 * a / gcd(x1,2 * a) << endl;
			}
		}
       }

	return 0;
}