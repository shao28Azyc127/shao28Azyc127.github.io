#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

bool check(int x) {
	int k = sqrt(x);
	if (k * k == x) return true;
	return false;
}

void print(int a, int b) {
	int ansa = a, ansb = b;
	ansa /= gcd(a, b), ansb /= gcd(a, b);
	if (ansb < 0) ansa *= -1, ansb *= -1;
	if (ansb == 1) cout << ansa;
	else cout << ansa << "/" << ansb;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = b * b - 4 * a * c, mx = (2 * a < 0 ? 0 : 1);
	if (x < 0) {
		puts("NO");
		return;
	}
	else if (x == 0) {
		print(-b, 2 * a);
		cout << endl;
	}
	else {
		if (check(x)) {
			print(-b + (mx == 1 ? sqrt(x) : -sqrt(x)), 2 * a);
			cout << endl;
		}
		else {
			if (-b) {
				print(-b, 2 * a);
				cout << "+";
			}
			int ta = 1, tb = 2 * a, t1;
			for (int i = 3000; i >= 1; i -- ) 
				if (x % (i * i) == 0) {
					t1 = i;
					break;
				}
			if (tb < 0) t1 *= -1, tb *= -1;
			t1 = abs(t1);
			int g = gcd(t1, tb);
			if (t1 % tb == 0) {
				if (t1 / tb == 1) cout << "sqrt(" << x / t1 / t1 << ")" << endl;
				else cout << t1 / tb << "*sqrt(" << x / t1 / t1 << ")" << endl;
			}
			else {
				if (t1 == g) cout << "sqrt(" << x / t1 / t1 << ")/" << tb / g << endl;
				else {
					x /= t1, x /= t1;
					t1 /= g, tb /= g;
					cout << t1 << "*sqrt(" << x << ")/" << tb << endl;
				}
			}
		}
	}
}
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, m;
	cin >> T >> m;
	while (T -- ) solve();
	return 0;
}
