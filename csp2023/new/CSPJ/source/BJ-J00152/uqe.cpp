#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int bac = b*b - 4*a*c;
		if (bac < 0) {
			cout << "NO" << endl;
			continue;
		}
		else {
			int num = sqrt(bac);
			if (num * num == bac) {
				int anss = 0 - b + num;
				int ansm = 2 * a;
				if (ansm == 1) cout << anss << endl;
				else if (anss == 0) cout << 0 << endl;
				else {
					int t = gcd(anss, ansm);
					while (t != 1) {
						anss /= t;
						ansm /= t;
						t = gcd(anss, ansm);
					}
					if (anss < 0) {
						cout << "-";
						anss = 0-anss;
					}
					if (ansm < 0) {
						cout << "-";
						ansm = 0-ansm;
					}
					if (ansm == 1) cout << anss << endl;
					else cout << anss << "/" << ansm << endl;
				}
			}
			else {
				int anss = 0 - b;
				int ansm = 2 * a;
				if (ansm == 1) cout << anss << "+";
				else if (anss != 0) {
					int t = gcd(anss, ansm);
					while (t != 1) {
						anss /= t;
						ansm /= t;
						t = gcd(anss, ansm);
					}
					if (anss < 0) {
						cout << "-";
						anss = 0-anss;
					}
					if (ansm < 0) {
						cout << "-";
						ansm = 0-ansm;
					}
					if (ansm == 1) cout << anss << "+";
					else cout << anss << "/" << ansm << "+";
				}
				int rs = 1, rm = 2 * a;
				for (int i = 2; i * i <= bac; i++) {
					if (bac % (i * i) == 0) {
						rs *= i;
						bac /= (i * i);
					}
				}
				if (rs == 1) cout << "sqrt(" << bac << ")/" << rm << endl; 
				else {
					int t = gcd(rs, rm);
					while (t != 1) {
						rs /= t;
						rm /= t;
						t = gcd(rs, rm);
					}
					if (rm == 1) {
						if (rs == 1) cout << "sqrt(" << bac << ")" << endl;
						else cout << rs << "*sqrt(" << bac << ")" << endl;
					}
					else {
						if (rs == 1) cout << "sqrt(" << bac << ")/" << rm << endl;
						else cout << rs << "*sqrt(" << bac << ")/" << rm << endl;
					}
				}
				
			}
		}
	}
	return 0;
}