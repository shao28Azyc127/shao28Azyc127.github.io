#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n , a[1000005] , id[1000005] , ans , v[1000005] , d , ans1 , a1[100005];
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	a[0] = 2e9;
	cin >> n >> d;
	for(int i = 1 ; i < n ; i ++)
		cin >> v[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		long long b;
		cin >> b;
		if(b < a[i - 1])
		{
			a[i] = b;
			id[i] = i;
		}
		else
		{
			a[i] = a[i - 1];
			id[i] = id[i - 1];
		}
	}
	for(int i = 1 ; i < n ; i ++)
		a1[id[i]] += v[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		if(a1[i] >= ans1)
		{
			a1[i] -= ans1;
			ans1 = 0;
		}
		else 
		{
			ans1 -= a1[i];
			a1[i] = 0;
		}
		if(a1[i] % d == 0)
			ans += a1[i] / d * a[i];
		else
		{
			ans += (a1[i] / d + 1) * a[i];
			ans1 += d - a1[i] % d;
		}
	}
	cout << ans << endl;
	return 0;
}