#include <cstdio>
#include <vector>
const int MX = 100005;
const long long NINF = -9e18;
struct S
{
	int a = 0;
	long long b = 0;
	S(int x = 0, long long y = 0): a(x), b(y) {;}
};
int c = 0, t = 0, n = 0, m = 0, k = 0, d = 0, x[MX] = {}, y[MX] = {}, v[MX] = {};
namespace slv1
{
	const int NX = 1005;
	long long s = 0, b[NX][NX] = {};
	std::vector<S> a[MX];
	inline long long mx(long long x, long long y)
	{
		return x > y ? x : y;
	}
	long long main()
	{
		s = 0;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i <= m; i++)
			a[x[i]].push_back(S(y[i], v[i]));
		b[0][0] = 0;
		for (int j = 1; j <= k; j++)
			b[0][j] = NINF;
		for (int i = 1; i <= n; i++)
		{
			b[i][0] = b[i - 1][0];
			for (int j = 1; j <= k; j++)	
				b[i][j] = b[i - 1][j - 1] - d, b[i][0] = mx(b[i][0], b[i - 1][j]);
			for (int j = 0; j < (int)a[i].size(); j++)
				for (int l = a[i][j].a; l <= k; l++)
					b[i][l] += a[i][j].b;
			for (int j = 0; j <= k; j++)
				s = mx(s, b[i][j]);
		}
		return s;
	}
}
int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &x[i], &y[i], &v[i]);
		if (c <= 9)
			printf("%lld\n", slv1::main());
	}
	return 0;
}
