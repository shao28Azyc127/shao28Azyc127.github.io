#include <bits/stdc++.h>
using namespace std;

void ct_1(int a, int b) {
	if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
		a = abs(a);
		b = abs(b);
		int k = __gcd(a, b);
		a /= k;
		b /= k;
		if (b == 1 || b == -1) {
			printf("-%d", a/b);
		}else {
			printf("-%d/%d", a, b);
		}
	} else {
		a = abs(a);
		b = abs(b);
		int k = __gcd(a, b);
		a /= k;
		b /= k;
		if (b == 1 || b == -1) {
			printf("%d", a/b);
		}else {
			printf("%d/%d", a, b);
		}
	}
	return;
}

void ct_2(int a, int b) {
	a = abs(a);
	a *= 2;
	int c = 1;
	int i = 2;
	while (b) {
		if (b % (i * i) == 0) {
			c *= i;
			b /= (i * i);
		} else {
			i++;
		}
		if (i * i > b) {
			break;
		}
	}
	int k = __gcd(a, c);
	a /= k;
	c /= k;
	if (c == a) {
		printf("sqrt(%d)", b);
	} else if (a == 1) {
		printf("%d*sqrt(%d)", c/a, b);
	} else if (c == 1) {
		printf("sqrt(%d)/%d",b, a);
	} else {
		printf("%d*sqrt(%d)/%d", c, b, a);
	}
}

bool check(int b) {
	int i = 2;
	while (b) {
		if (b % (i * i) == 0) {
			b /= (i * i);
		} else {
			i++;
		}
		if (i * i > b) {
			break;
		}
	}
	if (b == 1) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T, M;
	scanf("%d %d", &T, &M);
	while (T--) {
		int a, b, c;
		scanf("%d %d %d\n", &a, &b, &c);
		int temp = b * b - 4 * a * c;
		if (temp < 0) {
			printf("NO\n");
			continue;
		} else if (temp == 0) {
			if (b == 0) {
				printf("0\n");
				continue;
			} else {
				ct_1(b, a * 2);
				printf("\n");
			}
		} else {
			if (check(temp)) {
				if (a < 0) {
					ct_1(b + sqrt(temp), a * 2);
				} else {
					ct_1(b - sqrt(temp), a * 2);
				}
				printf("\n");
				continue;
			}
			if (b != 0) {
				ct_1(b, a * 2);
				printf("+");
				ct_2(a, temp);
				printf("\n");
			} else {
				ct_2(a, temp);
				printf("\n");
			}
		}
	}
	return 0;
}