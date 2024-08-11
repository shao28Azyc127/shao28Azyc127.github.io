#include<bits/stdc++.h>
#define MAXN 10010
using namespace std;

int n, d, v[MAXN], a[MAXN];
int ans;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int c;
		if(i == 1)
		{
			int x = ceil(v[1] / d);
			ans += x * a[i];
			c = x * d - v[1];
		}
		else if(a[i + 1] < a[i])
		{
			int x = ceil(v[i] / d);
			ans += x * a[i];
			c = x * d - v[i];
		}
		else if(a[i + 1] > a[i])
		{
			int x = ceil((v[i] + v[i + 1] - c) / d);
			ans += x * a[i];
			c = x * d - (v[i] + v[i + 1]);
		}
	}
	sort(a + 1, a + n + 1);
	cout << ans - a[n] << endl;
	return 0;
}
