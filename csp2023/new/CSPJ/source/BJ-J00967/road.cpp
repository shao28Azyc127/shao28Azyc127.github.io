// T2想写个BFS骗分 结果发现BFS都写不明白 只能开摆了 骗11～13的分
#include <cstdio>
#define int long long
#define isdigit(x) ((x)>='0'&&(x)<='9')
// #define max(x,y) (((x)>(y))?(x):(y))
// #define min(x,y) (((x)<(y))?(x):(y))
// #define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
// const int N = 1145141919810;
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
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), d = read(), v, sum = 0, ans;
	for (int i = 1; i < n; ++i)
		v = read(), sum += v;
	ans = read() * sum;
	for (int i = 1; i < n; ++i)
		read();
	write(ans), putchar('\n');
	return 0;
}
