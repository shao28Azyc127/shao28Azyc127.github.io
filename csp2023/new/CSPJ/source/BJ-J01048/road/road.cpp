#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int v[200010], a[200010], m[200010];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> v[i];
	}
	memset(m, 0x6f, sizeof(m));
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[i] = min(m[i - 1], a[i]);
		m[1] = a[1];
	} 
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = ceil(1.0 * v[i] / d);
		ans += x * m[i];
		v[i + 1] -= x * d - v[i];

	}
	cout << ans << endl;
	return 0;
}