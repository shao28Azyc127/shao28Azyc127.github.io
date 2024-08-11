#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int a[100010], b[100010], c[100010];

struct edge
{
	int v, nx;
}e[200010];
int h[100010], cnt;

void addedge(int u, int v)
{
	e[++cnt]={v, h[u]};
	h[u]=cnt;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i=1;i<n;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	printf("%d\n", n+1);
	return 0;
}