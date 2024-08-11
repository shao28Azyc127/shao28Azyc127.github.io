#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
struct realnum {
	int a, b, c, d, e;
	// x = (a/b) + (c/d) * sqrt(e);
	// b, d > 0
};
int t, m;
void sqr(realnum &p, int delta) {
	int s ;
	for (int i = sqrt(delta); i > 0; i--) {
		if (delta % (i * i) == 0) {
			s = i;
			break;
	    }
	}
	if (delta - s * s) {
		p = {0, 1, s, 1, delta - s * s};
	} else {
		p = {s, 1, 0, 1, 0};
	}
}
void calc(int b, realnum &p, int q) {
	// ans = (p+b) / q;
	p.a += b * p.b;
	int g = gcd(p.a, p.b);
	p.a /= g, p.b /= g;
	
	if (q < 0) {
		p.a = -p.a;
		p.c = -p.c;
		q = -q;
	}
	p.b *= q; p.d *= q;
	g = gcd(p.a, p.b);
	p.a /= g, p.b /= g;
	g = gcd(p.c, p.d);
	p.c /= g, p.d /= g;
}
void output(realnum ans) {
	if (ans.a != 0) {
		printf("%d", ans.a);
		if (ans.b != 1) {
			printf("/%d", ans.b);
		}
    }
	if (ans.c != 0) {
		printf("+%d", ans.c);
		if (ans.d != 1) {
			printf("/%d", ans.d);
		}
		printf("*sqrt(%d)", ans.e);
	}
	printf("\n");
	return;
}
int main() {
freopen("uqe.in", "r", stdin);
freopen("uqe.out", "w", stdout);
	scanf("%d%d", &t, &m);
	while (t--) {
		int aa, bb, cc;
		scanf("%d%d%d", &aa, &bb, &cc);
		int delta = bb * bb - 4 * aa * cc;
		if (delta < 0) {
			// no real root
			printf("NO\n");
			continue;
		}
		// ans = p / q;
		realnum p = {0, 1, 0, 1, 0}; // p == delta
		sqr(p, delta);
		if (aa < 0) {
			p.a = -p.a;
	        p.c = -p.c;
		}
		calc(-bb, p, 2 * aa);
		output(p);
	}
	return 0;
}
