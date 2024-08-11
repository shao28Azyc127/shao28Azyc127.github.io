#include<bits/stdc++.h>

using namespace std;

int t, m;
int a, b, c;

int f(int x)
{
	for (int i = 0; ; i++)
		if (i * i == x)
			return i;
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	scanf("%d%d", &t, &m);
	while (t--)
	{
		scanf("%d%d%d", &a, &b, &c);
		int delta = b * b - 4 * a * c;
		if (delta < 0) printf("NO\n");
		else printf("%d\n", max((-b + f(delta)) / 2 / a, (-b - f(delta)) / 2 / a));
	}
	
	return 0;
}
