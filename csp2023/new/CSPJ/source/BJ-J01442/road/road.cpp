//By Pr_159
//100pts
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, d, v[N], a[N];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1; i < n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	long long prv = a[1], dis = 0, oil = 0, cost = 0;
	for(int i = 2; i <= n; i++)
	{
		dis += v[i - 1];
		if(i == n)
		{
			long long length = dis - oil;
			long long tmp = ceil((double)length / d);
			cost += tmp * prv;
			break;
		}
		if(a[i] < prv)
		{
			//printf("dis=%d, oil=%d\n", dis, oil);
			long long length = dis - oil;
			long long tmp = ceil((double)length / d);
			//printf("length=%d\n", length);
			//printf("tmp=%d, prv=%d\n", tmp, prv);
			cost += tmp * prv;
			//printf("cost=%d\n", cost);
			prv = a[i];
			oil = tmp * d - length;
			dis = 0;
		}
	}
	cout << cost << endl;
	return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
