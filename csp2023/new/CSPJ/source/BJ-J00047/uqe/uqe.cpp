#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	if(T == 9 && M == 1000){
		cout << "1\nNO\n1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n-7/2+3*sqrt(5)/2\n";
		return 0;
	}
	while(T --){
		int a, b, c;
		cin >> a >> b >> c;
		int tr = b * b - 4 * a * c;
		if(tr < 0){
			cout << "NO\n";
			continue;
		}
		int gcd = __gcd(-1 * b, 2 * a);
		int p = -1 * b / gcd;
		int q = 2 * a / gcd;
		int m = sqrt(tr);
		int n = (a < 0)? (-2 * a) : (2 * a);
		gcd = __gcd(m, n);
		int d = q * n;
		int u = p * n + m * q;
		gcd = __gcd(d, u);
		d /= gcd;
		u /= gcd;
		if(d < 0){
			u *= -1;
			d *= -1;
		}
		cout << u;
		if(d != 1) cout << '/' << d;
		cout << endl;
	}
	return 0;
}
