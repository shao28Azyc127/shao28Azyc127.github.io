#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int T, M;

int gcd(int a, int b) {
  if (a % b == 0) {
  	return b;
	}
	if (a > b) {
		a %= b;
		gcd(b, a);
	}
	if (b > a) {
		b %= a;
		gcd(a, b);
	}
}

int m(int x) {
	return x * x;
}

int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> T >> M;
  while (T--) {
  	int a, b, c;
    cin >> a >> b >> c;
    int delta = m(b) - 4 * a * c;
    if (delta < 0) {
    	cout << "NO" << endl;
    	continue;
		}
		
		int f = 0;
		for (int i = 1; i <= sqrt(delta); i++) {
			if (m(i) == delta) {
			  f = 1;
			  break;
			}
		}
		
		double x1, x2;
		if (f == 1) {
			if (delta == 0) {
				int g = gcd(-b, 2 * a);
				cout << -b / g << "/" << 2 * a / g << endl;
			} else if (delta > 0) {
				x1 = (-b + sqrt(delta) / (2 * a));
				x2 = (-b - sqrt(delta) / (2 * a));
				if (x1 > x2) {
					int g = gcd(-b + sqrt(delta), 2 * a);
					cout << (-b + sqrt(delta)) / g << "/" << 2 * a / g << endl;
				} else {
					int g = gcd(-b - sqrt(delta), 2 * a);
					cout << (-b - sqrt(delta)) / g << "/" << 2 * a / g << endl;
				}
			}
		} else if (f == 0) {
			if (delta = 0) {
				int g = gcd(-b, 2 * a);
				cout << -b / g << "/" << 2 * a / g << endl;
			} else if (delta > 0) {
				if (-b != 0) {
					int g = gcd(-b, 2 * a);
				  cout << -b / g << "/" << 2 * a / g << "+";
				}
				int q2n = 1;
				for (int i = 1; i <= sqrt(delta); i++) {
					if (delta % m(i) == 0) q2n = i;
				}
				int r = delta / q2n;
				if (q2n == (2 * a)) {
					cout << "sqrt(" << r << ")" << endl;
				} else if (q2n % (2 * a) == 0) {
					cout << q2n / (2 * a) << "*sqrt(" << r << ")" << endl;
				} else if ((2 * a) % q2n == 0) {
					cout << "sqrt(" << r << ")/" << 2 * a / q2n << endl;
				} else {
					int g = gcd(q2n, 2 * a);
					int c = q2n / g, d = 2 * a / g;
					cout << c << "*sqrt(" << r << ")/" << d << endl;;
				}
			}
		}
	}
  return 0;
}