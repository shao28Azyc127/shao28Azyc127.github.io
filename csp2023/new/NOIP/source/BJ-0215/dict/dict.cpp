#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3030;
int n, m;
struct node { char ch; int id; } t1[N], t2[N]; //t1 for min, t2 for max
bool cmp1(node x, node y) { return x.ch == y.ch ? x.id > y.id : x.ch < y.ch; }
bool cmp2(node x, node y) { return x.ch == y.ch ? x.id > y.id : x.ch > y.ch; }
char s[N][N], minn[N][N], maxn[N][N];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n == 1) { cout << 1; return 0; }
	for (int i = 1;i <= n;i++)
	{
		scanf("%s", s[i]);
		for (int j = 0;j < m;j++) t1[j].ch = s[i][j], t1[j].id = j, t2[j] = t1[j];
		sort(t1, t1 + m, cmp1);
		sort(t2, t2 + m, cmp2);
		strcpy(minn[i], s[i]);
		strcpy(maxn[i], s[i]);
		bool flag1 = false, flag2 = false;
		for (int j = 0;j < m;j++)
		{
			if (!flag1 && s[i][j] != t1[j].ch)
			{
				flag1 = true, swap(s[i][j], s[i][t1[j].id]), strcpy(minn[i], s[i]);
				swap(s[i][j], s[i][t1[j].id]);
			}
			if (!flag2 && s[i][j] != t2[j].ch)
			{
				flag2 = true, swap(s[i][j], s[i][t2[j].id]), strcpy(maxn[i], s[i]);
				swap(s[i][j], s[i][t2[j].id]);
			}
		}
	}
	char tmp[N], tmp2[N];
	strcpy(tmp, maxn[1]);
	int p = 2;
	while(strcmp(maxn[p], maxn[1]) == 0) p++;
	strcpy(tmp2, maxn[p]);
	int num = 0;
	for (int i = 1;i <= n;i++)
	{
		if (strcmp(tmp, maxn[i]) > 0) strcpy(tmp2, tmp), strcpy(tmp, maxn[i]), num = 1;
		else if (strcmp(tmp, maxn[i]) == 0) num++;
	}
	for (int i = 1;i <= n;i++)
	{
		if (num == 1 && strcmp(maxn[i], tmp) == 0 && strcmp(minn[i], tmp2) < 0) cout << 1;
		else if (strcmp(minn[i], tmp) < 0) printf("1");
		else printf("0");
	}
	return 0;
}
