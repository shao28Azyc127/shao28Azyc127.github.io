#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long n, d, u[N], a[N], ans;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i < n; i ++ )
	{
		scanf("%lld", &u[i]);
	}
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	long long last = a[1];
	long long sum = 0;
	long long num = 0;
	long long cnt = 1;
	while (cnt < n)
	{
		cnt ++;
		sum += u[cnt - 1];
		if (a[cnt] < last)
		{
			if ((sum - num) % d == 0)
			{
//				cout << lastid << ' ' << num << ' ' << (sum - num) / d << endl;
				ans += (sum - num) / d * last;
				sum = 0;
				num = 0;
			}
			else
			{
//				cout << lastid << ' ' << num << ' ' << (sum - num) / d + 1 << endl;
				ans += ((sum - num) / d + 1) * last;
				num = ((sum - num) / d + 1) * d - sum + num;
				sum = 0;
			}
			last = a[cnt];
		}
		if (cnt == n)
		{
			if ((sum - num) % d == 0)
			{
//				cout << lastid << ' ' << num << ' ' << (sum - num) / d << endl;
				ans += (sum - num) / d * last;
			}
			else
			{
//				cout << lastid << ' ' << num << ' ' << (sum - num) / d + 1 << endl;
				ans += ((sum - num) / d + 1) * last;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
