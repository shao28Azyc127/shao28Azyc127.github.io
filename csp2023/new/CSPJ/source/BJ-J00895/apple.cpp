#include <bits/stdc++.h>

using namespace std;

long long n, cnt, ans, flag;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%lld", &n);
	while (n)
	{
		cnt ++;
		if ((n - 1) % 3 == 0)
		{
			ans = cnt;
			flag = 1;
		}
		if (n % 3 == 0)
		{
			n -= n / 3;
		}
		else n -= n / 3 + 1;
		if (flag) break;
	}
	while (n)
	{
		cnt ++;
		if (n % 3 == 0)
		{
			n -= n / 3;
		}
		else n -= (n / 3 + 1);
	}
	printf("%lld %lld", cnt, ans);
	return 0;
}
