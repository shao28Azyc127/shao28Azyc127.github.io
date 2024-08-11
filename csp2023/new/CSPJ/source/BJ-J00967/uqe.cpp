// T3写了半天调不对 开摆了
#include <cstdio>
#include <cmath>
#define int long long
#define isdigit(x) ((x)>='0'&&(x)<='9')
#define max(x,y) (((x)>(y))?(x):(y))
// #define min(x,y) (((x)<(y))?(x):(y))
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
const int M = 1005;
const int N = 305.1145141919810;
int read()
{
	char ch = getchar(); int w = 1, x = 0;
	while (!isdigit(ch))
	{
		if (ch = '-')
			w = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}
void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
}
/*
int prime[N], cnt;
bool notprime[M];
void init(int n)
{
	notprime[1] = notprime[0] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (!notprime[i])
		{
			prime[++cnt] = i;
			for (int j = 2; j <= n; ++j)
			{
				if (i * j > n)
					break;
				notprime[i * j] = true;
			}
		}
	}
}
int gcd(int x, int y)
{
	if (x == y)
		return x;
	if (x == 1 || y == 1)
		return 1;
	if (x == 0 || y == 0)
		return max(x, y);
	return gcd(y, x % y);
}
void sqrt(int x, int &q1, int &q2, int &r) // sqrt(x) = q1 * sqrt(r) / q2
{
	int tmp, tmpq1, tmpq2, tmpr, tmpg; r = abs(x), q1 = q2 = 1;
	for (int i = 1; i <= cnt && prime[i] * prime[i] <= x; ++i)
	{
		tmp = prime[i] * prime[i];
		if (r % tmp == 0)
		{
			tmp = gcd(r, tmp);
			sqrt(tmp, tmpq1, tmpq2, tmpr);
			q1 *= tmpr * tmpq1 * tmpq1;
			q2 *= tmpq2 * tmpq2;
			r /= tmp;
		}
		tmpg = gcd(q1, q2);
		q1 /= tmpg, q2 /= tmpg;
	}
}
void solve()
{
	int a = read(), b = read(), c = read();
	int delta = b * b - 4 * a * c;
	// printf("delta = : %lld\n", delta);
	if (delta < 0)
	{
		printf("NO\n");
		return;
	}
	if (delta == 0)
	{
		int x = -b / (2 * a);
		if (x * 2 * a == -b)
		{
			write(x), putchar('\n');
			return;
		}
		x = -b; int y = 2 * a;
		int tmp = gcd(x, y);
		x /= tmp, y /= tmp;
		if (y < 0)
			x = -x, y = -y;
		write(x), putchar('/'), write(y), putchar('\n');
	}
	int qd1, qd2, rd;
	sqrt(delta, qd1, qd2, rd);
	printf("qd1 = : %lld\n", qd1);
	printf("qd2 = : %lld\n", qd2);
	printf("rd = : %lld\n", rd);
	int q1 = -b / (2 * a), q21, q22;
	printf("q1 = : %lld\n", q1);
	qd2 *= 2 * a;
	printf("qd2 = : %lld\n", qd2);
	int tmpg = gcd(qd1, qd2);
	printf("tmpg = : %lld\n", tmpg);
	qd1 /= tmpg, qd2 /= tmpg;
	printf("qd1 = : %lld\n", qd1);
	printf("qd2 = : %lld\n", qd2);
	if (rd == 1 || rd == 0)
	{
		q21 = qd1 * rd, q22 = qd2;
		if (q1 * 2 * a == -b)
		{
			write(q1), putchar('\n');
			return;
		}
		q1 = -b + rd;
		int tq2 = 2 * a;
		tmpg = gcd(q1, tq2);
		q1 /= tmpg, tq2 /= tmpg;
		if (tq2 < 0)
			q1 = -q1, tq2 = -tq2;
		write(q1);
		if (tq2 != 1)
			putchar('/'), write(tq2);
		if (q21 == 0)
		{
			putchar('\n');
			return;
		}
		putchar('+');
		tmpg = gcd(q21, q22);
		q21 /= tmpg, q22 /= tmpg;
		if (q22 < 0)
			q21 = -q21, q22 = -q22;
		if (q22 == 1)
		{
			write(q21), putchar('\n');
			return;
		}
		write(q21), putchar('/'), write(q22), putchar('\n');
		return;
	}
	if (q1 * 2 * a == -b)
		write(q1);
	else
	{
		q1 = -b;
		int tq2 = 2 * a;
		tmpg = gcd(q1, tq2);
		q1 /= tmpg, tq2 /= tmpg;
		if (tq2 < 0)
			q1 = -q1, tq2 = -tq2;
		write(q1), putchar('/'), write(tq2);
	}
	putchar('+');
	q21 = qd1, q22 = qd2;
	write(q21), putchar('/'), printf("sqrt(%lld)", rd), putchar('*'), write(q22), putchar('\n');
}
*/
void solve()
{
	int a = read(), b = read(), c = read();
	int delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		printf("NO\n");
		return;
	}
	int ans = -b + sqrt(delta);
	ans /= 2 * a;
	write(ans), putchar('\n');
}
signed main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t = read(), m = read();
	// init(m);
	// printf("prime : ");
	// for (int i = 1; i <= cnt; ++i)
	// 	printf("%lld ", prime[i]);
	// putchar('\n');
	do
	{
		solve();
	} while (--t);
	return 0;
}

