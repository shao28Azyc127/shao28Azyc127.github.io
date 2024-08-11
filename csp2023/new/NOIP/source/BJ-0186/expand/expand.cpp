#include <cstdio>
#include <cstdlib>
using namespace std;

int c, n, m, q;
int a[100010], b[100010];

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	if (c==1)
	{
		for (int i=1;i<=n;i++)
			scanf("%d", &a[i]);
		for (int i=1;i<=m;i++)
			scanf("%d", &b[i]);
		if (a[1]!=b[1])
			printf("1");
		else printf("0");
		for (int i=1;i<=q;i++)
		{
			int ta=a[1], tb=b[1];
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			for (int i=1;i<=kx;i++)
			{
				int px, vx;
				scanf("%d%d", &px, &vx);
				a[px]=vx;
			}
			for (int i=1;i<=ky;i++)
			{
				int py, vy;
				scanf("%d%d", &py, &vy);
				a[py]=vy;
			}
			if (a[1]!=b[1])
				printf("1");
			else printf("0");
		}
	}
	return 0;
}
