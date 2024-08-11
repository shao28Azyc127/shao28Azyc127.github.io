#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T;
	cin >> T;
	int M;
	cin >> M;
	while (T -- ) {
		double a, b, c;
		cin >> a >> b >> c;
		if (M <= 1) {
			if (a == 1) cout << 0 << endl;
			else cout << "NO" << endl;
			continue;
		}
		if (b * b - 4 * a * c < 0 || a == 0) {
			cout << "NO" << endl;
			continue;
		}
		int x = sqrt(b * b - 4 * a * c);
		if ((int)(-b + x) % (int)(2 * a) == 0) {
			cout << (int)(((-b) / (2 * a)) + (x / abs(2 * a))) << endl;
		} else {
			cout << (int)(abs(2 * a) / (2 * a) * (-b) + x) / gcd(abs(abs(2 * a) / (2 * a) * (-b) + x), abs(2 * a)) << '/' << (int)abs(2 * a) / gcd(abs(abs(2 * a) / (2 * a) * (-b) + x), abs(2 * a)) << endl;
		}
	}
}
