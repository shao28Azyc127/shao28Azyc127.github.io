#include <cstdio>
#include <cstring>
#include <algorithm>
const int NX = 3005, CX = 123;
int n = 0, m = 0, amn = 0;
char a[NX][NX] = {CX};
char b[NX][NX] = {CX};
bool cmp(char a, char b)
{
	return a > b;
}
int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)	
		scanf(" %s", a[i]);
	for (int i = 1; i <= n; i++)
	{
		strcpy(b[i], a[i]);
		std::sort(&a[i][0], &a[i][m]);
		std::sort(&b[i][0], &b[i][m], cmp);
	}
	for (int i = 1; i <= n; i++)
		strcmp(b[i], b[amn]) < 0 && (amn = i);
	strcpy(a[0], b[amn]);
	for (int i = 1; i <= n; i++)
	for (int i = 1; i <= n; i++)
		printf("%d", strcmp(a[i], a[0]) <= 0);
	printf("\n");
	return 0;
}
