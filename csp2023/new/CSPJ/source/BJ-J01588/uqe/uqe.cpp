#include <bits/stdc++.h>
using namespace std;
bool sq[5000100];
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}
int ck(int x) {
	for(int i = sqrt(x); i > 1; --i) if(x % (i * i) == 0) return i;
	return 0;
}
void solve() {
	int a, b, c; cin >> a >> b >> c;
	if(a < 0) a = -a, b = -b, c = -c;
	int del = b * b - 4 * a * c;
	if(del < 0) {
		cout << "NO" << endl;
		return ;
	}
	//double x1 = (-b + sqrt(del)) / (2 * a), x2 = (-b - sqrt(del)) / (2 * a);
	if(sq[del] || del == 0) {
		int p, q = 2 * a;
		p = (-b + sqrt(del));
		//else p = (-b - sqrt(del));
		if(p % q == 0) {
			cout << p / q << endl;
			return ;
		}else {
			int pq = gcd(abs(p), abs(q));
			p /= pq, q /= pq;
			cout << p << "/" << q << endl;
			return ;
		}
	}
	int coef = 1;
	if(ck(del)) coef = ck(del), del /= (coef * coef);
	//int q1 = -b / (2 * a);
	if(-b != 0){
		int k1 = -b, k2 = 2 * a;
		if(k1 % k2 == 0) {
			cout << k1 / k2 << '+';
			//return ;
		}else {
			int kk = gcd(abs(k1), abs(k2));
			k1 /= kk, k2 /= kk;
			cout << k1 << "/" << k2 << '+';
			//return ;
		}
	}
	int gd = gcd(abs(coef), abs(2 * a));
	a *= 2;
	coef /= gd, a /= gd;
	if(coef == a) {
		printf("sqrt(%d)\n", del);
	}else if(coef % a == 0) {
		printf("%d*sqrt(%d)\n", coef / a, del);
	}else if(coef == 1 && 2 * a > coef) {
		printf("sqrt(%d)/%d\n", del, a);
    }else {
		
		printf("%d*sqrt(%d)/%d\n", coef, del, a);
    }
}
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M; cin >> T >> M;
	for(int i = 1; i <= 2230; ++i) sq[i * i] = 1;
	while(T--) solve();
}
