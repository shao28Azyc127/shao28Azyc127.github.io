#include <cstdio>
int n, s = 0, a[10][10];
inline int m(int x) {return x < 0 ? x % 10 + 10 : x % 10;}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	if (n == 1)
	{
		printf("81\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d%d", &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
	for (int i = 0; i < 10; i++)
		for (int ii = 0; ii < 10; ii++)
			for (int iii = 0; iii < 10; iii++)
				for (int iv = 0; iv < 10; iv++)
					for (int v = 0; v < 10; v++)
					{
						int f = 1;
						for (int j = 1; j <= n; j++)
						{
							int t = 0 + (a[j][1] == i) + (a[j][2] == ii) + (a[j][3] == iii) + (a[j][4] == iv) + (a[j][5] == v);
							if ((t == 3 && (
								(a[j][1] != i && a[j][2] != ii && m(a[j][1] - i) == m(a[j][2] - ii)) ||
								(a[j][2] != ii && a[j][3] != iii && m(a[j][2] - ii) == m(a[j][3] - iii)) ||
								(a[j][3] != iii && a[j][4] != iv && m(a[j][3] - iii) == m(a[j][4] - iv)) ||
								(a[j][4] != iv && a[j][5] != v && m(a[j][4] - iv) == m(a[j][5] - v))
								)) || t == 4)
								;
							else
							{
								f = 0;
								break;
							}
						}
						if (f)
							s++;
					}
	printf("%d\n", s);
	return 0;
}
