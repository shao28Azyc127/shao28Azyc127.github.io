#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <LL, LL> PII;
int t, m;
LL a, b, c, dlt;
PII x, y;
LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
void f(PII &a)
{
	LL tmp = gcd(a.first, a.second);
	a.first /= tmp; a.second /= tmp;
}
void f2(LL a)
{
	LL tmp = sqrt(a);
	for (LL i = tmp; i >= 1ll; --i)
	{
		if (a % (i * i) == 0)
		{
			y = make_pair(i, a / i / i);
			break;
		}
	}
	if (dlt == 0) y = make_pair(0, 0);
}
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	scanf("%d %d", &t, &m);
	while (t--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		dlt = b * b - a * 4 * c;
		if (dlt < 0) printf("NO\n");
		else
		{
			b = -b;
			f2(dlt);
			if (y.second == 1)
			{
				if (2*a>=0&&b>=0) b += y.first;
				else if (2*a<0&&b>=0) b -= y.first;
				else if (2*a>0&&b<0) b += y.first;
				else b -= y.first;
				dlt = 0;
			}
			x = make_pair(abs(b), abs(2 * a));
			f(x);
			if (b * 2 * a < 0) x.first *= -1;
			if (x.first)
			{
				if (x.second != 1) printf("%lld/%lld", x.first, x.second);
				else printf("%lld", x.first);
			}
			if (dlt)
			{
				PII z = make_pair(abs(y.first), abs(2 * a));
				f(z);
				if (z.first && z.second != 1)
				{
					if (z.first != 1) printf("%s%lld*sqrt(%lld)/%lld", (z.first > 0&&x.first) ? "+" : 
"", z.first, y.second, z.second);
					else printf("%ssqrt(%lld)/%lld", x.first ? "+" : "", y.second, z.second);
				}
				else if (z.first && z.first != 1)
					printf("%s%lld*sqrt(%lld)", (z.first > 0 && x.first) ? "+" : 
"", z.first, y.second);
				else printf("%ssqrt(%lld)", x.first ? "+" : "", y.second);
			}
			if (!x.first && !dlt) printf("0"); 
			printf("\n");
		}
	}
	return 0;
}