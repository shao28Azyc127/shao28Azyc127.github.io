#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+5;
long long a[N], day, cnt, num, ti;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	num = n;
	while (num > 0)
	{
		cnt = 1;
		day++;
		for (int i = 1; i <= n; i++)
		{
			if (cnt == 4)
			{
				cnt = 1;
			}
			if (cnt == 1 && a[i] != 0)
			{
				num--;
				if (i == n && a[i] != 0)
				{
					ti = day;
				}
				a[i] = 0;
				cnt++;
			}
			if (a[i] != 0)
			{
				cnt++;
			}
		}
	}
	cout << day << " " << ti;
	return 0;
}