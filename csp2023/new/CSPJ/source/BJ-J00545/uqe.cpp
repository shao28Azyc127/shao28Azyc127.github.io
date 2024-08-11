#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef pair<int, int> P;
vector<int> p;
P spf(int r) {
	P res = {1, 1};
	for (int i = 0; i < p.size(); i++) {
		int n = 0;
		while (r % p[i] == 0) {
			n++;
			r /= p[i];
		}
		if (n & 1) {
			res.second *= p[i];
		}
		while (n > 1) {
			n -= 2;
			res.first *= p[i];
		}
	}
	res.second *= r;
	return res;
}
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}
void out(int x, int y) {
	if (abs(y) == 1) {
		cout << x / y;
	} else if (x < 0 && y < 0) {
		cout << -x << "/" << -y;
	} else if (x < 0 || y < 0) {
		cout << "-" << abs(x) << "/" << abs(y);
	} else {
		cout << x << "/" << y;
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	for (int i = 2; i <= M; i++) {
		bool flag = true;
		for (int n : p) {
			if (i % n == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			p.push_back(i);
		}
	}
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int Delta = b * b - 4 * a * c;
		if (Delta < 0) {
			cout << "NO" << endl;
			continue;
		}
		int p1 = -b, p2 = 2 * a;
		int d = gcd(abs(p1), abs(p2));
		p1 /= d, p2 /= d;
		if (Delta == 0) {
			out(p1, p2);
			cout << endl;
			continue;
		}
		P res = spf(Delta);
		int q1 = (res.first * (a > 0 ? 1 : -1)), q2 = 2 * a;
		if (res.second == 1) {
			int t1 = p1 * q2 + p2 * q1, t2 = p2 * q2;
			d = gcd(abs(t1), abs(t2));
			out(t1 / d, t2 / d);
			cout << endl;
			continue;
		}
		d = gcd(abs(q1), abs(q2));
		q1 /= d, q2 /= d;
		if (p1 != 0) {
			out(p1, p2);
			if ((q1 < 0) ^ (q2 < 0)) {
				cout << "-";
			} else {
				cout << "+";
			}
		}
		q1 = abs(q1), q2 = abs(q2);
		if (q1 == 1) {
			cout << "sqrt(" << res.second << ")";
			if (q2 != 1) {
				cout << "/" << q2;
			}
		} else {
			cout << q1 << "*sqrt(" << res.second << ")";
			if (q2 != 1) {
				cout << "/" << q2;
			}
		}
		cout << endl;
	}
	return 0;
}
/*
9 1000
1 -1 0
-1 -1 -1
1 -2 1
1 5 4
4 4 1
1 0 -432
1 -3 1
2 -4 1
1 7 1
*/