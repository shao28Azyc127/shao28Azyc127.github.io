#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, m;
int a, b, c;

int delta(int a, int b, int c) { return b * b - 4 * a * c; }

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }

bool issqrt(int x) { return (int)(sqrt(x)) * (int)(sqrt(x)) == x; }

bool isprime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int check(int d) {
	if (isprime(d)) return -1;
	for (int i = 2; i < d; i++)
		if (d % i == 0 && issqrt(d / i)) return sqrt(d / i);
	return -1;
}

signed main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while (t--) {
		cin >> a >> b >> c;
		if (delta(a, b, c) < 0) cout << "NO" << endl;
		else {
			if (!delta(a, b, c)) {
				int p = -b, q = 2 * a;
				if (p < 0) {
					int GCD = gcd(-p, q);
					int P = -p;
					int realp = 0 - P / GCD, realq = q / GCD;
					if (realq == 1) cout << realp << endl;
					else {
						if (realp > 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						else if (realp < 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						cout << realp << "/" << realq;
					}
				}
				else {
					int GCD = gcd(p, q);
					int realp = p / GCD;
					int realq = q / GCD;
					if (realq == 1) cout << realp<< endl;
					else {
						if (realp > 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						else if (realp < 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						cout << realp << "/" << realq;		
					}
				}
			}
			else {
				int p = -b, q = 2 * a;
				
				int realp = 0, realq = 0;
				int _p = 0, _q = 0;
				int GCD1;
				
				bool int1 = false, int2 = false;
				if (p < 0) {
					GCD1 = gcd(-p, q);
					int P = -p;
					realp = 0 - P / GCD1, realq = q / GCD1;
					if (realq == 1) int1 = true;
				}
				else {
					GCD1 = gcd(p, q);
					realp = p / GCD1, realq = q / GCD1;	
					if (realq == 1) int1 = true;			
				}
				
				int d = delta(a, b, c);
				int xishu = 0, aaa = 0;
				int q1 = 2 * a;
				int sq = false;
				int GCD;
				if (issqrt(d)) {
					int p1 = sqrt(d);
					GCD = gcd(p1, q1);
					_p = p1 / GCD, _q = q1 / GCD;
					_p = labs(_p), _q = labs(_q);
					if (_q == 1) int2 = true;
					sq = true;
				}
				else {
					q1 = 2 * a;
					xishu = check(d);
					if (xishu == -1) xishu = 1, aaa = d;
					else aaa = d / (xishu * xishu);
				}
				
				if (int1 && int2) cout << realp + _p << endl;
				else {
					bool done = false;
					if (sq) {
						int ppp = realp * GCD1 + _p * GCD, qqq = 2 * a;
						int gcd2 = gcd(ppp, qqq);
						ppp /= gcd2, qqq /= gcd2;
						if (qqq == 1 && qqq == -1) cout << labs(ppp) << endl;
						else cout << ppp << "/" << labs(qqq) << endl;
						done = true;
					}
					
					if (done) continue;
					
					if (int1)
						{if (realp) cout << realp;}
					else {
						if (realp > 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						else if (realp < 0 && realq < 0) realp = 0 - realp, realq = 0 - realq;
						cout << realp << "/" << realq;
					}
					
					if (int2) cout << _p;
					else {
						if (xishu && realp) cout << "+";
						else if (!xishu) continue;
						int GCD = gcd(xishu, q1);
						xishu /= GCD, q1 /= GCD;
						if (xishu != 1 && xishu != -1) cout << labs(xishu) << "*";
						cout << "sqrt(" << aaa << ")";
						if (q1 != 1 && q1 != -1) cout << "/" << labs(q1) << endl;
						else cout << endl;
					}
				}
			}
		}
	}
	return 0;
}
