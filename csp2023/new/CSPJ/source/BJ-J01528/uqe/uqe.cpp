#include <cmath>
#include <iostream>
#include <utility>

#define ONLINE

using namespace std;

inline int judge_poly(int a, int b, int c)
{
	return b * b - a * c * 4;
}

inline int sq_rt(int x)
{
	return sqrt(x) /* exp(log(x) / 2) */;
}

inline bool is_square(int x)
{
	int rt = sq_rt(x);
	// fprintf(stderr, "%d ** 2 == %d\n", rt, x);
	return rt * rt == x;
}

int gcd(int x, int y)
{
	x = abs(x);
	y = abs(y);
	
	return y == 0 ? x : gcd(y, x % y);
}

inline bool print_frac(int p, int q, bool newline = true, bool print_0 = false)
{
	if (q == 0 || (p / q == 0 && !print_0)) {
		if (newline)
			putchar('\n');
			
		return false;
	}
	
	if (p * q < 0)
		putchar('-');
		
	p = abs(p);
	q = abs(q);
	
	int d = gcd(p, q);
	
	p /= d;
	q /= d;
	
	if (q == 1)
		printf((newline ? "%d\n" : "%d"), p);
	else
		printf((newline ? "%d/%d\n" : "%d/%d"), p, q);
		
	return true;
}

// Make `sqrt(r)` into `p * sqrt(q)`.
pair<int, int> solve_rt(int r)
{
	int rt = sq_rt(r);
	
	if (rt * rt == r)
		return { abs(rt), 0 };
		
	for (int i = r / 2; i >= 4; --i) {
		if (r % i == 0 && is_square(i))
			return { abs(sq_rt(i)), r / i };
	}
	
	return { 1, r };
}

void solve_eq(int a, int b, int c)
{
	int delta = judge_poly(a, b, c);
	// fprintf(stderr, "delta = %d\n", delta);
	
	if (delta < 0) {
		puts("NO");
		return;
	}
	
	if (is_square(delta))
		print_frac(sq_rt(delta) - b, a * 2, true, true);
	else {
		bool res = print_frac(-b, a * 2, false, true);
		
		if (delta > 0) {
			if (res)
				putchar('+');
			
			pair<int, int> res(solve_rt(delta));
			int p = res.first, q = a * 2, r = res.second, d = gcd(p, q);
			
			p /= d;
			q /= d;
			
			if (r != 0) {
				if (p == 1 && q == 1)
					printf("sqrt(%d)\n", r);
				else if (p == 1 && q != 1)
					printf("sqrt(%d)/%d\n", r, q);
				else if (p != 1 && q == 1)
					printf("%d*sqrt(%d)\n", p, r);
				else
					printf("%d*sqrt(%d)/%d\n", p, r, q);
			} else {
				if (p == 1 && q == 1)
					puts("1\n");
				else if (p == 1 && q != 1)
					printf("1/%d\n", q);
				else if (p != 1 && q == 1)
					printf("%d\n", p);
				else
					printf("%d/%d\n", p, q);
			}
		} else
			putchar('\n');
	}
}

int main()
{
#ifdef ONLINE
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
#endif

	// freopen("uqe.out", "w", stdout);

	int t, m;
	scanf("%d %d", &t, &m);
	
	while (t-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		solve_eq(a, b, c);
	}
	
	fclose(stdout);
	return 0;
}

