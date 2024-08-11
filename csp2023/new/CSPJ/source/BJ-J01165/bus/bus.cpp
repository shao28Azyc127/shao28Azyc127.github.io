#include<bits/stdc++.h>
#define MAXN 20010
using namespace std;

int n, m, k, u[MAXN], v[MAXN], a[MAXN];

int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> a[i];
		ans += a[i];
	}
	cout << ans + 1 << endl;
	return 0;
}
