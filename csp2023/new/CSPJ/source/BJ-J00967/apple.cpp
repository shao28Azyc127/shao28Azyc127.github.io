// T1Ë®Ìâ Ãëµô
#include <cstdio>
#define int long long
#define isdigit(x) ((x)>='0'&&(x)<='9')
// #define max(x,y) (((x)>(y))?(x):(y))
// #define min(x,y) (((x)<(y))?(x):(y))
// #define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
// const int N = 114514.1919810;
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
signed main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n = read(), ans1 = 0 , ans2 = 0;
	int tail = n;
	while (n)
	{
		++ans1;
		if (tail % 3 == 1 && ans2 == 0) ans2 = ans1;
		n -= (n - 1) / 3 + 1;
		if (ans2 == 0)
			tail = n;
	}
	write(ans1), putchar(' '), write(ans2), putchar('\n');
	return 0;
}
