#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int n, d, v[100005], a[100005], dp[1000005];

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int len = 0;
    for(int i = 1; i <= n; i++)
        len += v[i];
    cout << a[1] * len << endl;

	return 0;
}
