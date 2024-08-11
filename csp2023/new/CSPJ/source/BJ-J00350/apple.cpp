#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int cnt = 0, ans = -1;
	while (n > 0)
	{
		cnt++;
		if (n % 3 == 1 && ans == -1)
			ans = cnt;
		n -= ceil(1.0 * n / 3);
	}
	printf("%d %d\n", cnt, ans);
	return 0;
}