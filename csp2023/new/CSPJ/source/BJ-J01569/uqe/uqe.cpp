#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, c;
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	scanf("%d %d", &T, &M);
	while (T--) {
		scanf("%d %d %d", &a, &b, &c);
		if (b * b < 4 * a * c) {
			printf("NO\n");
			continue;
		}
		double n = b * b - 4 * a * c;
		if (n == 0) {
			double p = (-b + sqrt(n));
			double q = 2 * a;
			int fp = 1;
			int fq = 1;
			//cout << p << " " << q << endl;
			if (p < 0) fp = -1;
			if (q < 0) fq = -1;
			while (__gcd((int)p, (int)q) != 1) {
				int t = p;
				p /= __gcd((int)p, (int)q);
				q /= __gcd((int)abs(t), (int)q);
			}
			//cout << fp << " " << fq << endl;
			p *= fp;
			q *= fq;
			//cout << p << " " << q << endl;
			if (q > 0) {
				if (q == 1) printf("%.lf\n", p);
				else printf("%.lf/%.lf\n", p, q);
			}
		} else {
		    double p = (-b + sqrt(n));
			double q = 2 * a;
			int fp = 1;
			int fq = 1;
			//cout << p << " " << q << endl;
			if (p < 0) fp = -1;
			if (q < 0) fq = -1;
			while (__gcd((int)p, (int)q) != 1) {
				int t = p;
				p /= __gcd((int)p, (int)q);
				q /= __gcd((int)abs(t), (int)q);
			}
			//cout << fp << " " << fq << endl;
			p *= fp;
			q *= fq;
			//cout << p << " " << q << endl;
			if (q > 0) {
				if (q == 1) printf("%.lf\n", p);
				else printf("%.lf/%.lf\n", p, q);
			}
		}
	}
	return 0;
}
