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
		while (a[i] <= a[cnt]) //ֻҪ����ı�ǰ��ĸ��󣬾Ͷ���
		{
			cnt++;
			sumv += v[cnt];
		}
		if (sumv % d == 0)
		{
			cur = sumv / d;
			lo = 0; //�͸պ��㹻������һ���ص�
		}
		else
		{
			cur = sumv / d + 1;
			lo = cur*d - sumv; //ʣ�µ������߶���km
		}
		sum += cur*a[i];
		i = cnt-1;
	}
	cout << sum;
	return 0;
}