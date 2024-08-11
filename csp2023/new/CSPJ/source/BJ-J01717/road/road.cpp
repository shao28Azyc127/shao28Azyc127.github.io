#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int z = 1e5;
long long v[z + 5] , a[z + 5] , s[z + 5] , f[z + 5];
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n,d;
	cin >> n >> d;
	for(int i = 2;i <= n;i++) scanf("%lld" , &v[i]);
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	long long minn = 9e18 , s = 0;
	for(int i = 1;i <= n;i++)
	{
		minn = min(minn , a[i]);
		f[i] = f[i - 1] + ceil(1.0 * (v[i + 1] - s) / d) * minn;
		s += ceil(1.0 * (v[i + 1] - s) / d) * d;
		s -= v[i + 1];
	}
	printf("%lld" , f[n]);
	return 0;
}