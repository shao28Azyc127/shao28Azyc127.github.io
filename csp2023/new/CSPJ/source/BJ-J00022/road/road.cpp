#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long v[N], a[N];
long long n, d, sum, sumv, cur, lo, cnt;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		cnt = i+1;
		sumv = v[i]-lo;
		while (a[i] <= a[cnt]) //只要后面的比前面的更贵，就多买
		{
			cnt++;
			sumv += v[cnt];
		}
		if (sumv % d == 0)
		{
			cur = sumv / d;
			lo = 0; //油刚好足够到达下一个地点
		}
		else
		{
			cur = sumv / d + 1;
			lo = cur*d - sumv; //剩下的油能走都少km
		}
		sum += cur*a[i];
		i = cnt-1;
	}
	cout << sum;
	return 0;
}